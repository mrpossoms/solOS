include vars.mk

UNIT=$(shell basename ${PWD})
SRCS=$(wildcard src/*.c)
OBJS=$(SRCS:.c=.c.o)

.PHONY: all
all: bin bin/slsd 
	@echo "Built all"

.PHONY: which
which:
	@echo $(OBJS)
	@echo $(UNIT)

.check_git:
	$(shell scripts/check/git)

.PHONY: deps
deps: ext/cfg.h
	@echo "Fetched deps"

ext:
	mkdir $@
	
bin: deps
	mkdir $@

ext/cfg.h: ext
	git clone https://github.com/mrpossoms/cfg.h.git $@

bin/slsd: $(OBJS)
	@echo "Building" $@
	$(CC) $(CFLAGS) $(INC) $(LINK_DIR) $^ -o $@ $(LINK)
	@echo "Built" $@

clean:
	rm -rf bin
	rm -r src/*.o
