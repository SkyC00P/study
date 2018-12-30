inc := -I../
mgraph := MGraph/*.c

mgraph.bin:
	gcc -g -Wall $(mgraph) -o $@ $(inc)
	@echo "\n------------------ Test $@ ------------------\n"
	@-./$@
	@rm $@
	@echo "\n--------------------------------------------------\n"