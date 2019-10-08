CC=gcc
CFLAGS=--std=c99 -D_POSIX_C_SOURCE=300000L
INC=-Iext/cfg.h/src -Isrc 
LINK_DIR=
LINK=

%.c.o: %.c deps
	$(CC) $(CFLAGS) $(INC) -c $< -o $@ $(LINK)
