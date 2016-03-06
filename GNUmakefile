#Makefile for EC-Marked
#GCCPREFIX=./$(PLATFORM)/gcc-arm-none-eabi-5_2-2015q4/bin/arm-none-eabi-
GCCPREFIX=/usr/bin/

# Files to include
C_SRC  = $(wildcard *.cpp)

OBJECTS = $(patsubst %.cpp,%.o,$(C_SRC))

# Assembler, compiler, and linker flags
AFLAGS  =
CFLAGS = $(AFLAGS)
CFLAGS  = $(AFLAGS) -std=c++11 -stdlib=libc++ -Wall
CFLAGS += -I. #so that #include <inc/<3.h> will work
LFLAGS  = $(CFLAGS) -L/usr/local/lib
LIBS =

# Targets
all: ec-marked.elf
clean:
	-rm -f $(OBJECTS) *.elf
ec-marked.elf: $(OBJECTS)
	$(GCCPREFIX)g++ $(LFLAGS) -o ec-marked.elf $(OBJECTS) $(LIBS)
%.o: %.cpp
	echo + cc $<
	@$(GCCPREFIX)g++ $(CFLAGS) -c -o $@ $<
fetchmail:
	./get-ec.py
