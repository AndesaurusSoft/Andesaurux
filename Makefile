CC = gcc
NASM = nasm

CFLAGS = -Wall -Werror
LDFLAGS = -lm

SRC_DIR = minian
BOOT_DIR = boot
INIT_DIR = sbin/init

SRC_FILES = $(SRC_DIR)/minian.c
BOOT_FILES = $(BOOT_DIR)/boot.asm
INIT_FILES = $(INIT_DIR)/init.c

OBJ_FILES = $(SRC_FILES:.c=.o) $(BOOT_FILES:.asm=.o) $(INIT_FILES:.c=.o)

all: minian boot init

minian: $(SRC_FILES)
	$(CC) $(CFLAGS) -c $^ -o $(SRC_FILES:.c=.o)
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
