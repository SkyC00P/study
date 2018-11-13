inc := -I../../
src := link_list.c test.c

all: Compile Run

Compile: $(src)
	gcc -Wall $^ -o test $(inc)

book: $(src)
	gcc -Wall -DDEBUG $^ -o debug $(inc)
	@echo "\n------------------ Test From Book Code ------------------\n"
	@./debug
	@rm -rf debug
	@echo "\n---------------------------------------------------------\n"
	
Run: test
	@echo "\n------------------ Test -------------------------\n"
	@./$^
	@echo "\n-------------------------------------------------\n"
	
clean: 
	@rm -rf test