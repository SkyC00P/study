inc := -I../
mgraph := MGraph/*.c
algraph := ALGraph/*/*.c

mgraph.bin:
	gcc -g -Wall $(mgraph) -o $@ $(inc)
	@echo "\n------------------ Test $@ ------------------\n"
	@-./$@
	@rm $@
	@echo "\n--------------------------------------------------\n"

algraph.bin:
	gcc -g -Wall $(algraph) -o $@ $(inc)
	@echo "\n------------------ Test $@ ------------------\n"
	@-./$@
	@rm $@
	@echo "\n--------------------------------------------------\n"