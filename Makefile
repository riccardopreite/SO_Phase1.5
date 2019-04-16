# Cross toolchain variables
# If these are not in your path, you can make them absolute.
XT_PRG_PREFIX = mipsel-linux-gnu-
CC = $(XT_PRG_PREFIX)gcc
LD = $(XT_PRG_PREFIX)ld

# uMPS2-related paths

# Simplistic search for the umps2 install. prefix. If you have umps2
# installed on some weird location, set UMPS2_DIR_PREFIX by hand.

UMPS2_DIR_PREFIX = /usr/local

UMPS2_DATA_DIR = $(UMPS2_DIR_PREFIX)/share/umps2
UMPS2_INCLUDE_DIR = $(UMPS2_DIR_PREFIX)/include/umps2

# Compiler options
CFLAGS_LANG = -ffreestanding
CFLAGS_MIPS = -mips1 -mabi=32 -mno-gpopt -G 0 -mno-abicalls -fno-pic -mfp32
CFLAGS = $(CFLAGS_LANG) $(CFLAGS_MIPS) -I$(UMPS2_INCLUDE_DIR) -Wall -O0

# Linker options
LDFLAGS = -G 0 -nostdlib -T $(UMPS2_DATA_DIR)/umpscore.ldscript

# Add the location of crt*.S to the search path
VPATH = $(UMPS2_DATA_DIR)
.PHONY : all clean

all: kernel.core.umps

kernel.core.umps: kernel
	umps2-elf2umps -k $<

kernel:  source/main.o crtso.o libumps.o source/scheduler.o source/pcb.o source/asl.o source/interrupts.o source/scheduler.o source/syscall.o source/p1.5test_rikaya_v0.o source/utils.o
	$(LD) -o $@ $^ $(LDFLAGS)

clean:
	find . -name "*.o" -o -name "kernel" -o -name "kernel.*.umps" -o -name "term*.umps" -type f|xargs rm -f

# Pattern rule for assembly modules
%.o : %.S
	$(CC) $(CFLAGS) -c -o $@ $<
