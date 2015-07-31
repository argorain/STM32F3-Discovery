CC = arm-none-eabi-gcc
CXX = arm-none-eabi-g++
LD = arm-none-eabi-gcc

OPENCM3_DIR = ../libopencm3
LDSCRIPT = ../stm32f3-discovery.ld
DEFS		= -DSTM32F3
LIBNAME		= opencm3_stm32f3

FP_FLAGS	?= -mfloat-abi=hard -mfpu=fpv4-sp-d16
ARCH_FLAGS	= -mthumb -mcpu=cortex-m4 $(FP_FLAGS)

INCLUDE_DIR	= $(OPENCM3_DIR)/include
LIB_DIR		= $(OPENCM3_DIR)/lib

CFLAGS		+= -Os -g
CFLAGS		+= -Wextra -Wshadow -Wimplicit-function-declaration
CFLAGS		+= -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes
CFLAGS		+= -fno-common -ffunction-sections -fdata-sections

CXXFLAGS	+= -Os -g
CXXFLAGS	+= -Wextra -Wshadow -Wredundant-decls  -Weffc++
CXXFLAGS	+= -fno-common -ffunction-sections -fdata-sections

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

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(ARCH_FLAGS) -o $(*).o -c $(*).c

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(ARCH_FLAGS) -o $(*).o -c $(*).cpp

BINARY = miniblink
SOURCE = gpio.c miniblink.c
OBJS = gpio.o miniblink.o
HEADERS = gpio.h

all: $(BINARY).elf

$(OBJS): $(SOURCE)

$(BINARY).elf: $(OBJS) $(HEADERS)
	$(LD) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) $(OBJS) $(LIB_DIR)/lib$(LIBNAME).a -o $(BINARY).elf

#miniblink.elf: miniblink.o gpio.o gpio.h 
#	$(LD) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) gpio.o miniblink.o $(LIB_DIR)/lib$(LIBNAME).a -o miniblink.elf

clean:
	$(RM) *.o *.d *.elf *.bin *.hex *.srec *.list *.map