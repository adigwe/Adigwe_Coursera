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
#
# Platform Overrides:
#      PLATFORM - Target platform ( HOST, MSP432)
#
#
#------------------------------------------------------------------------------
include sources.mk


# $projectroot
#                              
#              +
#              |            
#           course1/          
#              |           
#       +------+-----+     
#       |            |     
#    include/       src/ 



# Platform Overrides
PLATFORM = MSP432

# Architectures Specific Flags
LINKER_FILE = ./msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs

# Compiler Flags and Defines


CC := arm-none-eabi-gcc
CFLAGS := -g -O0 -Wall -Werror -std=c99 -mcpu=$(CPU) -m$(ARCH) -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS) \
-D$(PLATFORM)
LD = arm-none-eabi-ld
SIZE = arm-none-eabi-size
LDFLAGS = -T $(LINKER_FILE) 
ASFLAGS = -S
CPPFLAGS = -E
BASENAME = course1
TARGET = $(BASENAME).out

OBJS = $(SOURCES:.c=.o)
CPPF = $(SOURCES:.c=.i)
ASMF = $(SOURCES:.c=.asm)
DEP = $(SOURCES:.c=.d)

.PHONY: build
build: $(TARGET)

.PHONY: compile-all



ifeq ($(PLATFORM),HOST)
CC = gcc
CFLAGS = -g -O0 -Wall -Werror -std=c99 -D$(PLATFORM)
 

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ 
	$(SIZE) -Atd $(TARGET)  		  
else
$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^
	$(SIZE) -Atd $(TARGET) 
endif

# Generate object files without linking
compile-all: $(OBJS) 
%.o : %.c 
	$(CC) -c $(CFLAGS) $(INCLUDES) -o $@ $<	 

# Preprocessor output files
%.i : %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -o $@ $< 


#Assembly output files
%.asm : %.c
	$(CC) $(CFLAGS) $(INCLUDES) $(ASFLAGS) -o $@ $<


#Dependency Files
%.d : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -MM -MF -o $@ $< 


#********************************************************
# Remove generated files
#********************************************************

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET) $(CPPF) $(ASMF) $(DEP) $(BASENAME).map

