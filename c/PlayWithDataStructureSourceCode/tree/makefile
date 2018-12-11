inc := -I../
ptree := parent_tree/ParentTree.c parent_tree/ParentTree-test.c
ctree := child_tree/ChildTree.c child_tree/ChildTree-test.c child_tree/double_link_list.c
bctree := child_brother_tree/ChildBrotherTree.c child_brother_tree/ChildBrotherTree-main.c child_brother_tree/double_link_list.c
all: ptree ctree bctree

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