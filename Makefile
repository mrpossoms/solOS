include vars.mk

.check_git:
	$(shell scripts/check/git)

ext:
	mkdir ext

cfg.h: ext
	git clone https://github.com/mrpossoms/cfg.h.git ext/$@
