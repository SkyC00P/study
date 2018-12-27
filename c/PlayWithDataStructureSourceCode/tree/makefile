inc := -I../
ptree := parent_tree/ParentTree.c parent_tree/ParentTree-test.c
ctree := child_tree/ChildTree.c child_tree/ChildTree-test.c child_tree/double_link_list.c
bctree := child_brother_tree/*.c  child_brother_tree/help/*.c
btree := binary_tree/*.c binary_tree/help/*.c
tbtree:= thread_binary_tree/*.c
htree := huffman_tree/*.c huffman_tree/help/*.c

all: ptree ctree bctree btree tbtree htree

ptree: 
	gcc -g -Wall $(ptree) -o $@ $(inc)
	@echo "\n------------------ Test $@ ------------------\n"
	@./$@
	@rm $@
	@echo "\n--------------------------------------------------\n"

ctree: 
	gcc -g -Wall $(ctree) -o $@ $(inc)
	@echo "\n------------------ Test $@ ------------------\n"
	@./$@
	@rm $@
	@echo "\n--------------------------------------------------\n"

bctree: 
	gcc -g -Wall $(bctree) -o $@ $(inc)
	@echo "\n------------------ Test $@ ------------------\n"
	@./$@
	@rm $@
	@echo "\n--------------------------------------------------\n"

btree: 
	gcc -g -Wall $(btree) -lm -o $@ $(inc) 
	@echo "\n------------------ Test $@ ------------------\n"
	@./$@
	@rm $@
	@echo "\n--------------------------------------------------\n"

tbtree:
	gcc -g -Wall $(tbtree) -o $@ $(inc) 
	@echo "\n------------------ Test $@ ------------------\n"
	@./$@
	@rm $@
	@echo "\n--------------------------------------------------\n"

htree:
	gcc -g -Wall $(htree) -lm -o $@ $(inc) 
	@echo "\n------------------ Test $@ ------------------\n"
	@./$@
	#@rm $@
	@echo "\n--------------------------------------------------\n"