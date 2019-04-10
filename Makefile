include vars.mk

UNIT=$(shell basename ${PWD})
SRCS=$(wildcard src/*.c)
OBJS=$(SRCS:.c=.c.o)


.PHONY: which
which:
	@echo $(OBJS)
	@echo $(UNIT)

.check_git:
	$(shell scripts/check/git)

ext:
	make -C .. $@
	ln -s ../$@ $@
	
bin:
	mkdir $@

cfg.h: ext
	git clone https://github.com/mrpossoms/cfg.h.git ext/$@

$(UNIT): $(OBJS)
	@echo "Building" $@
	$(CC) $(CFLAGS) $(INC) $(LINK_DIR) $^ -o $@ $(LINK)
	@echo "Built" $@

clean:
	rm -r src/*.o
