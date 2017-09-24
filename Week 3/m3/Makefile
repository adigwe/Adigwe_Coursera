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
#   Simple Makefile for native and cross-compile builds
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      	  <FILE>.o - Builds <FILE>.o object file
#	  <FILE>.i - Builds <FILE>.i preprocessed output file	
#	  <FILE>.asm - Builds <FILE>.asm assembly output file	
#	  compile-all - compiles all object files without linking	
#	  build - builds and links all source files
#	  clean - Removes all generated files
#
#
#
#------------------------------------------------------------------------------
SOURCES = main.c misc.c
INCLUDES = -I./

# Architectures Specific Flags
LINKER_FILE = msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs

# Compiler Flags and Defines


CC := arm-none-eabi-gcc
CFLAGS := -g -O0 -Wall -Werror -std=c99 -mcpu=$(CPU) -m$(ARCH) -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS) 
LD = arm-none-eabi-ld
LDFLAGS = -Wl,-Map=$(BASENAME).map -T $(LINKER_FILE) 
CPPFLAGS = -E
DEPFLAGS = -MMD -MF $(BASENAME).d
BASENAME = c1m3
TARGET = $(BASENAME).out

OBJS = $(SOURCES:.c=.o)
CPPF = $(SOURCES:.c=.i)


.PHONY: build
build: $(TARGET)


$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(INCLUDES) $(DEPFLAGS) $(LDFLAGS) -o $@ $^


%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDES) -o $@ $< 

# Preprocessor output files
%.i: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -o $@ $<




#********************************************************
# Remove generated files
#********************************************************

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET) $(CPPF) $(BASENAME).map $(BASENAME).d

