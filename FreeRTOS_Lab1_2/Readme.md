# Lab 1&2: FreeRTOS Task Creation and Task Utilities demo
This lab demonstrate the creation of tasks also how to use the utilities to get information about tasks


# Used SW / HW:
1) TC375 Lite Kit

2) Free RTOS v202406.01-LTS

3) ADS(Aurix Development Environment) IDE

# Usage:
T_Led task is control the led toggeling according to the shared variable step

T_Button task is checking the kit button and increment the shared variable step

T_Status task is priniting the status of button and led tasks.


1)Compile and flash

2)Open Terminal with baudrate 115200

3)If LED is toggling slow, you can see sometimes it's blocked till the delay expires.