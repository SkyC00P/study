inc := -I../../
src := loop_link_list.c test.c

all: tail Run

tail: $(src)
	gcc -Wall $^ -o test $(inc)

head: $(src)
	gcc -Wall -DHEAD $^ -o debug $(inc) 
	@echo "\n------------------ Test Use Head LinkList ------------------\n"
	@./debug
	@rm -rf debug
	@echo "\n------------------------------------------------------------\n"
	
Run: test
	@echo "\n------------------ Test Use Tail LinkList ------------------\n"
	@./$^
	@rm -rf test
	@echo "\n------------------------------------------------------------\n"