#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Makefile for all source code in this folder
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
# 		Target can be object files (main.o, memory.o)
#		Executable (c1m2.out)
#		Assembly (main.asm, memory.asm)
#		Implementation (main.i, memory.i)
#
# Platform Overrides:
#		Two options for platform are HOST and MSP432.
#		HOST is for native compipler, MSP432 is for the micro
#
#------------------------------------------------------------------------------
include sources.mk

FLAGS = -g 		\
		-Werror	\
		-std=c99

# Directories
COMMON = ../include/common
# Platform Overrides
PLATFORM = HOST 

# Architectures Specific Flags
LINKER_FILE = -T msp432p401r.lds 
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs

# Compiler Flags and Defines
OBJS:=$(SOURCES:.c=.o)
TARGET = c1m2.out

ifeq ($(PLATFORM), MSP432)
CC = arm-none-eabi-gcc
else
CC = gcc
endif

LD = arm-none-eabi-ld
LDFLAGS = -Wl, -Map=$(TARGET).map
CFLAGS = -Wall -Werror -g -O0 -std=c99
CPPFLAGs =
ARMFLAG = -mcpu=$(CPU) -mthumb -march=armv7e-m -mfloat-abi=hard	\
	-mfpu=fpv4-sp-d16 --specs=nosys.specs

.PHONY: build
build: $(OBJS)
	$(CC) $(OBJS) -MP -o $(TARGET)
%.i : %.c
	$(CC) -D$(PLATFORM) $(INCLUDES) $(CFLAGS) -E $< -o $@
%.asm : %.c
	$(CC) -D$(PLATFORM) $(INCLUDES) $(CFLAGS) -S $< -o $@
%.asm : %.c
	$(CC) -D$(PLATFORM) $(INCLUDES) $(CFLAGS) -S $< -o $@		
%.o : %.c
	$(CC) -D$(PLATFORM) $(INCLUDES) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean :
		rm -rf *.o
		rm -rf *.i
		rm -rf *.asm
		rm -rf *.out