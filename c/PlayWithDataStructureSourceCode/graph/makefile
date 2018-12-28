inc := -I../
mgraph := MGraph/*.c

all: mgraph

mgraph: 
	gcc -g -Wall $(mgraph) -o $@ $(inc)
	@echo "\n------------------ Test $@ ------------------\n"
	@./$@
	@rm $@
	@echo "\n--------------------------------------------------\n"