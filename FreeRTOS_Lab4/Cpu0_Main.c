/**********************************************************************************************************************
 * \file Cpu0_Main.c
 * \copyright Copyright (C) Infineon Technologies AG 2019
 * 
 * Use of this file is subject to the terms of use agreed between (i) you or the company in which ordinary course of 
 * business you are acting and (ii) Infineon Technologies AG or its licensees. If and as long as no such terms of use
 * are agreed, use of this file is subject to following:
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the software and 
 * accompanying documentation covered by this license (the "Software") to use, reproduce, display, distribute, execute,
 * and transmit the Software, and to prepare derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including the above license grant, this restriction
 * and the following disclaimer, must be included in all copies of the Software, in whole or in part, and all 
 * derivative works of the Software, unless such copies or derivative works are solely in the form of 
 * machine-executable object code generated by a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE 
 * COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN 
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
 * IN THE SOFTWARE.
 *********************************************************************************************************************/
#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"
#include "IfxPort_PinMap.h"
#include "Port/Io/IfxPort_Io.h"
#include "IfxAsclin_Asc.h"
#include "string.h"
#include "stdio.h"
#include "UART_VCOM.h"

/* Scheduler includes */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#define LED_1                   IfxPort_P00_5               /* Port/Pin for LED 1 */
#define LED_2                   IfxPort_P00_6               /* Port/Pin for LED 2 */
#define BUTTON                  IfxPort_P00_7               /* Port/Pin for Button */

#define LED1_BLINKY_PERIOD_MS   (250)                       /* The period (in milliseconds) at which LED1 will blink */
#define BUTTON_PERIOD_MS        (25)                        /* The period (in milliseconds) */


IFX_ALIGN(4) IfxCpu_syncEvent g_cpuSyncEvent = 0;

char arr[64] = "\n";
Ifx_SizeT count = 0;
uint8 step = 0;

const char *msgs[7] = {"Red","Blue","Green","Yellow","Cyan","White","Pink"};
uint8 u8_msgs[7] = {1,2,3,4,5,6,7};

QueueHandle_t msg_queue;
QueueHandle_t u8_msg_queue;


static void T_Button_init(void)
{
    IfxPort_setPinMode(BUTTON.port, BUTTON.pinIndex, IfxPort_Mode_inputPullUp);
    IfxPort_setPinMode(LED_1.port, LED_1.pinIndex, IfxPort_Mode_outputPushPullGeneral);
}

static void T_Display_init(void)
{
    msg_queue =  xQueueCreate(10,sizeof(char *));
    u8_msg_queue =  xQueueCreate(10,sizeof(uint8));

    init_UART();
    IfxPort_setPinMode(LED_2.port, LED_2.pinIndex, IfxPort_Mode_outputPushPullGeneral);
}



void T_Button(void *arg)
{
    T_Button_init();

    while(1)
    {
        /* Check button is clicked */
        if(!IfxPort_getPinState(BUTTON.port, BUTTON.pinIndex))
        {
            step++;
            if (step >= 7)
            {
                step = 0;
            }
            xQueueSend(msg_queue, (const void * const)&msgs[step], 10);
            xQueueSend(u8_msg_queue, (const void * const)&u8_msgs[step], 10);

            /* Toggle LED1 state */
           IfxPort_setPinState(LED_1.port, LED_1.pinIndex, IfxPort_State_toggled);
        }
        vTaskDelay(100);
    }
}

void T_Display(void *arg)
{
    char * msg_to_display;
    uint8 u8_msg_to_display;


    T_Display_init();

    while(1)
    {
        if(xQueueReceive(msg_queue, (void * const)&msg_to_display, 10) == pdPASS)
        {
            strcpy(arr,"      ");
            strcpy(arr,msg_to_display);
            send_UART_message(arr,6);
                    }
        if(xQueueReceive(u8_msg_queue, (void * const)&u8_msg_to_display, 10) == pdPASS)
        {
            sprintf(arr,"%d",u8_msg_to_display);
            send_UART_message(arr,1);
            strcpy(arr,"\n\t");
            count = 2;
            send_UART_message(arr,count);
            /* Toggle LED2 state */
            IfxPort_setPinState(LED_2.port, LED_2.pinIndex, IfxPort_State_toggled);
        }
    }

}

void core0_main(void)
{
    BaseType_t res;

    IfxCpu_enableInterrupts();
    
    /* !!WATCHDOG0 AND SAFETY WATCHDOG ARE DISABLED HERE!!
     * Enable the watchdogs and service them periodically if it is required
     */
    IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
    IfxScuWdt_disableSafetyWatchdog(IfxScuWdt_getSafetyWatchdogPassword());
    
    /* Wait for CPU sync event */
    IfxCpu_emitEvent(&g_cpuSyncEvent);
    IfxCpu_waitEvent(&g_cpuSyncEvent, 1);
    
    res = xTaskCreate(T_Display, "Display", configMINIMAL_STACK_SIZE, NULL, 2, NULL);
    res |= xTaskCreate(T_Button, "Button", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    if (res != pdPASS)
    {
        configASSERT(res);
    }
    /* Start the scheduler (this function will never return) */
    vTaskStartScheduler();
    while(1)
    {
    }
}

/* Required FreeRTOS callback, called in case of a stack overflow.
 * For the sake of simplicity, this function will loop indefinitely
 * and the root cause can be confirmed by using a debugger
 */
void vApplicationStackOverflowHook (TaskHandle_t xTask, char *pcTaskName)
{

}
