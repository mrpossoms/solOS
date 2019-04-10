CC=gcc
CFLAGS=
INC=-Iext/cfg.h/src -Isrc 
LINK_DIR=
LINK=

%.c.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@ $(LINK)
