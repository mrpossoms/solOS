CC=gcc
CFLAGS=
INC=
LINK_DIR=
LINK=

%.o: %
	$(CC) $(CFLAGS) $(INC) -c $< -o $@ $(LINK)
