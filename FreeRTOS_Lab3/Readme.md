# Lab 3: FreeRTOS Kernal Control demo
This lab demonstrate the critical section usage and task suspend usage to acheive mutal exclusion.

# Used SW / HW:
1) TC375 Lite Kit

2) Free RTOS v202406.01-LTS

# Usage:
T_Count task is incrementing two global vars x and y

T_Check task is checking if x and y are equal or no 


1)Compile and flash

2)Open Terminal with baudrate 115200

3)msg "x and y don't match" will be there due to the need of critical section.

4)Edit task T_Count to add critical section and recompile.

5)Now no msg on the terminal.