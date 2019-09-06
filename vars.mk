CC=gcc
CFLAGS=
INC=-Iext/cfg.h/src -Isrc 
LINK_DIR=
LINK=

%.c.o: %.c deps
	$(CC) $(CFLAGS) $(INC) -c $< -o $@ $(LINK)
