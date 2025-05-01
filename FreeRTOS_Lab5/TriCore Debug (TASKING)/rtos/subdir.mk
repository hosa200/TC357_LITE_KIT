################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../rtos/list.c" \
"../rtos/queue.c" \
"../rtos/tasks.c" \
"../rtos/timers.c" 

COMPILED_SRCS += \
"rtos/list.src" \
"rtos/queue.src" \
"rtos/tasks.src" \
"rtos/timers.src" 

C_DEPS += \
"./rtos/list.d" \
"./rtos/queue.d" \
"./rtos/tasks.d" \
"./rtos/timers.d" 

OBJS += \
"rtos/list.o" \
"rtos/queue.o" \
"rtos/tasks.o" \
"rtos/timers.o" 


# Each subdirectory must supply rules for building sources it contributes
"rtos/list.src":"../rtos/list.c" "rtos/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/SWs/Tools/InfD_WS/FreeRTOS_Lab5/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"rtos/list.o":"rtos/list.src" "rtos/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"rtos/queue.src":"../rtos/queue.c" "rtos/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/SWs/Tools/InfD_WS/FreeRTOS_Lab5/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"rtos/queue.o":"rtos/queue.src" "rtos/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"rtos/tasks.src":"../rtos/tasks.c" "rtos/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/SWs/Tools/InfD_WS/FreeRTOS_Lab5/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"rtos/tasks.o":"rtos/tasks.src" "rtos/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"rtos/timers.src":"../rtos/timers.c" "rtos/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/SWs/Tools/InfD_WS/FreeRTOS_Lab5/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"rtos/timers.o":"rtos/timers.src" "rtos/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-rtos

clean-rtos:
	-$(RM) ./rtos/list.d ./rtos/list.o ./rtos/list.src ./rtos/queue.d ./rtos/queue.o ./rtos/queue.src ./rtos/tasks.d ./rtos/tasks.o ./rtos/tasks.src ./rtos/timers.d ./rtos/timers.o ./rtos/timers.src

.PHONY: clean-rtos

