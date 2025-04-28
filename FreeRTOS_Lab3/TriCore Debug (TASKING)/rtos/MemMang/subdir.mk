################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../rtos/MemMang/heap_2.c" 

COMPILED_SRCS += \
"rtos/MemMang/heap_2.src" 

C_DEPS += \
"./rtos/MemMang/heap_2.d" 

OBJS += \
"rtos/MemMang/heap_2.o" 


# Each subdirectory must supply rules for building sources it contributes
"rtos/MemMang/heap_2.src":"../rtos/MemMang/heap_2.c" "rtos/MemMang/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/SWs/Tools/InfD_WS/FreeRTOS_Lab3/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"rtos/MemMang/heap_2.o":"rtos/MemMang/heap_2.src" "rtos/MemMang/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-rtos-2f-MemMang

clean-rtos-2f-MemMang:
	-$(RM) ./rtos/MemMang/heap_2.d ./rtos/MemMang/heap_2.o ./rtos/MemMang/heap_2.src

.PHONY: clean-rtos-2f-MemMang

