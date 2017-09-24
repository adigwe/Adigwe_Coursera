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
PLATFORM = HOST
include sources.mk
BASENAME = C1M2
TARGET = $(BASENAME).out
CFLAGS = 		\
-Wall 	\
-Werror	\
-O0			\
-g			\
-std=c99
LDFLAGS = 							\
-Wl,-Map=$(BASENAME).map

ifeq ($(PLATFORM),HOST)

CC = gcc
LD = ld
SZ = size
else

CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
SZ = arm-none-eabi-size
LDFLAGS += -T ../msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs

CFLAGS +=  						\
-mcpu=$(CPU)			\
-m$(ARCH)					\
-march=armv7e-m 	\
-mfloat-abi=hard 	\
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
all: $(TARGET)

$(TARGET): $(OBJS) 
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@
	$(SZ) -Atd $@

.PHONY: clean
clean:
	rm -f *.i *.asm *.o *.out *.map


