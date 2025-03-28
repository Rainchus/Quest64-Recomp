TARGET = patches.elf

CC      ?= clang
LD      ?= ld.lld

CFLAGS   := -target mips -mips2 -mabi=32 -O2 -G0 -mno-abicalls -mno-odd-spreg -mno-check-zero-division \
			-fomit-frame-pointer -ffast-math -fno-unsafe-math-optimizations -fno-builtin-memset \
			-Wall -Wextra -Wno-incompatible-library-redeclaration -Wno-unused-parameter -Wno-unknown-pragmas -Wno-unused-variable -Wno-missing-braces -Wno-unsupported-floating-point-opt
CPPFLAGS := -nostdinc -D_LANGUAGE_C -DMIPS -I dummy_headers -I ../lib/Quest64-Decomp/ -I ../lib/Quest64-Decomp/include -I ../lib/Quest64-Decomp/include/2.0H/ -I ../lib/Quest64-Decomp/include/2.0H/PR -I ../lib/Quest64-Decomp/src -I ../lib/Quest64-Decomp/src/libultra -I../lib/rt64/include
LDFLAGS  := -nostdlib -T patches.ld -T syms.ld -Map patches.map --unresolved-symbols=ignore-all --emit-relocs

# Find all C source files and assembly source files
C_SRCS    := $(wildcard *.c)
ASM_SRCS  := $(wildcard *.s)

# Create object lists for both C and assembly files
C_OBJS    := $(C_SRCS:.c=.o)
ASM_OBJS  := $(ASM_SRCS:.s=.o)

# Dependency files for C sources
C_DEPS := $(C_SRCS:.c=.d)

# Link target includes both C and assembly objects
$(TARGET): $(C_OBJS) $(ASM_OBJS) patches.ld syms.ld
	$(LD) $(C_OBJS) $(ASM_OBJS) $(LDFLAGS) -o $@

# Rule for compiling C files
$(C_OBJS): %.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -MMD -MF $(@:.o=.d) -c -o $@

# Rule for assembling .s files
%.o: %.s
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(C_OBJS) $(ASM_OBJS) $(TARGET) $(C_DEPS)

-include $(C_DEPS)

.PHONY: clean
