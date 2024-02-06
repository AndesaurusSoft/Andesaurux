CC = gcc
NASM = nasm

CFLAGS = -Wall -Werror
LDFLAGS = -lm

SRC_DIR = usr/src
BOOT_DIR = boot
INIT_DIR = sbin/init

MINIAN = $(SRC_DIR)/shell/minian.c
BOOT_FILES = $(BOOT_DIR)/boot.asm
INIT_FILES = $(INIT_DIR)/init.c

OBJ_FILES = $(MINIAN:.c=.o) $(BOOT_FILES:.asm=.o) $(INIT_FILES:.c=.o)

all: minian boot init

minian: $(MINIAN)
	$(CC) $(CFLAGS) -c $^ -o $(MINIAN:.c=.o)
	$(CC) $(OBJ_FILES) -o minian $(LDFLAGS)

boot: $(BOOT_FILES)
	$(NASM) -felf64 $^ -o $(BOOT_FILES:.asm=.o)
	$(CC) $(OBJ_FILES) -o boot $(LDFLAGS)

init: $(INIT_FILES)
	$(CC) $(CFLAGS) -c $^ -o $(INIT_FILES:.c=.o)
	$(CC) $(OBJ_FILES) -o init $(LDFLAGS)

clean:
	rm -f $(OBJ_FILES) minian boot init

.PHONY: all minian boot init clean
