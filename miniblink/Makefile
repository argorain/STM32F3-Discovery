CC = arm-none-eabi-gcc
LD = arm-none-eabi-gcc

OPENCM3_DIR = ../libopencm3
LDSCRIPT = ../stm32f3-discovery.ld
DEFS		= -DSTM32F3
LIBNAME		= opencm3_stm32f3

FP_FLAGS	?= -mfloat-abi=hard -mfpu=fpv4-sp-d16
ARCH_FLAGS	= -mthumb -mcpu=cortex-m4 $(FP_FLAGS)

BINARY = miniblink

INCLUDE_DIR	= $(OPENCM3_DIR)/include
LIB_DIR		= $(OPENCM3_DIR)/lib

CFLAGS		+= -Os -g
CFLAGS		+= -Wextra -Wshadow -Wimplicit-function-declaration
CFLAGS		+= -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes
CFLAGS		+= -fno-common -ffunction-sections -fdata-sections

CPPFLAGS	+= -MD
CPPFLAGS	+= -Wall -Wundef
CPPFLAGS	+= $(DEFS) -I$(INCLUDE_DIR)

LDFLAGS		+= --static -nostartfiles
LDFLAGS		+= -L$(LIB_DIR)
LDFLAGS		+= -T$(LDSCRIPT)
LDFLAGS		+= -Wl,-Map=$(BINARY).map
LDFLAGS		+= -Wl,--gc-sections

LDLIBS		+= -l$(LIBNAME)
#LDLIBS		+= -Wl,--start-group -lc -lgcc -lnosys -Wl,--end-group

all: miniblink.elf

gpio.o: gpio.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(ARCH_FLAGS) -o gpio.o -c gpio.c

miniblink.o: miniblink.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(ARCH_FLAGS) -o miniblink.o -c miniblink.c

miniblink.elf: miniblink.o gpio.o gpio.h 
	$(LD) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) gpio.o miniblink.o $(LIB_DIR)/lib$(LIBNAME).a -o miniblink.elf

clean:
	$(RM) *.o *.d *.elf *.bin *.hex *.srec *.list *.map