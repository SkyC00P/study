inc := -I../
map := HashMap.c HashMap-test.c

all: map

map: 
	gcc -g -Wall $(map) -o $@ $(inc)
	@echo "\n------------------ Test $@ ------------------\n"
	@./$@
	@rm $@
	@echo "\n--------------------------------------------------\n"