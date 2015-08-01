# COMPILERS
CC = arm-none-eabi-gcc
CXX = arm-none-eabi-g++
LD = arm-none-eabi-gcc

# OPENCM3 LIBRARY 
OPENCM3_DIR = ../libopencm3
LDSCRIPT = ../stm32f3-discovery.ld
DEFS		= -DSTM32F3
LIBNAME		= opencm3_stm32f3
INCLUDE_DIR	= $(OPENCM3_DIR)/include
LIB_DIR		= $(OPENCM3_DIR)/lib

# BUILD FLAGS
FP_FLAGS	?= -mfloat-abi=hard -mfpu=fpv4-sp-d16
ARCH_FLAGS	= -mthumb -mcpu=cortex-m4 $(FP_FLAGS)

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
LDFLAGS		+= -specs=nano.specs -specs=nosys.specs

LDLIBS		+= -l$(LIBNAME)
#LDLIBS		+= -Wl,--start-group -lc -lgcc -lnosys -Wl,--end-group

# BUILD RULES
%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(ARCH_FLAGS) -o $(*).o -c $(*).c

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(ARCH_FLAGS) -o $(*).o -c $(*).cpp

# PROJECT DEFINES
BINARY = miniblink
SOURCE = gpio.c main.cpp
OBJS = gpio.o main.o
HEADERS = gpio.h

all: $(BINARY).elf

$(OBJS): $(SOURCE)

$(BINARY).elf: $(OBJS) $(HEADERS)
	$(LD) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) $(OBJS) $(LIB_DIR)/lib$(LIBNAME).a -o $(BINARY).elf $(ARCH_FLAGS) 

clean:
	$(RM) *.o *.d *.elf *.bin *.hex *.srec *.list *.map