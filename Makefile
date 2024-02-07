PREFIX = /usr/local

RAYLIB		= /usr/local/lib/
RAYLIBINC	= /usr/local/include/

INCS = -I${RAYLIBINC} -Iinclude/
LIBS = -L${RAYLIB} -lraylib

CFLAGS   = -std=c99 -Wall -O3 ${INCS}
LDFLAGS  = ${LIBS}
CC = cc

SRC = ${wildcard src/*.c}
OBJ = $(SRC:.c=.o)

all: paper

debug: CFLAGS += -g3 -O3
debug: paper

paper: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -f $(OBJ) paper

.PHONY: all clean