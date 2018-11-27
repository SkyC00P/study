inc := -I../
ptree := parent_tree/ParentTree.c parent_tree/ParentTree-test.c

all: ptree

ptree: 
	gcc -g -Wall $(ptree) -o $@ $(inc)
	@echo "\n------------------ Test $@ ------------------\n"
	@./$@
	@rm $@
	@echo "\n--------------------------------------------------\n"
