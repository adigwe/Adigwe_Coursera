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
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------

PLATFORM = HOST
include sources.mk

BASENAME = c1m2
TARGET = $(BASENAME).out

CFLAGS =	-Werror	\
		-Wall	\
 		-g	\
 		-std=c99

LDFLAGS =       -Wl,-Map=$(BASENAME).map

# Architectures Specific Flags

ifeq ($(PLATFORM),HOST)

CC = gcc
SZ = size
LD = ld

else

CPU = cortex-m4
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
SZ = arm-none-eabi-size
LDFLAGS += -T ../msp432p401r.lds
ARCH = thumb
SPECS = nosys.specs
CFLAGS +=  
		-mcpu=$(CPU)      \
 		-m$(ARCH)	  \
		-mfloat-abi=hard  \
	        -march=armv7e-m   \
		-mfpu=fpv4-sp-d16 \
		--specs=$(SPECS)

endif

LINKER_FILE = $(PLATFORM).map
CPPFLAGS = -E 
OBJS = $(SOURCES:.c=.o)
ASMS = $(SOURCES:.c=.asm)


%.i:  %.c
	$(CC) $< $(CPPFLAGS) $(INCLUDES) -D$(PLATFORM) -o $@

%.asm:  %.i
	$(CC) $< -S -o $@

%.o:  %.c
	$(CC) -c $< $(CFLAGS) $(INCLUDES) -D$(PLATFORM) -o $@

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

$(TARGET): $(OBJS) 
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@
	$(SZ) -Atd $@

.PHONY: clean
clean:
	rm -f *.i  *.o *.asm *.map *.out 





