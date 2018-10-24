inc := -I../../
src := double_link_list.c test.c

all: loop Run

loop: $(src)
	gcc -Wall $^ -o test $(inc)

single: $(src)
	gcc -Wall -DSINGLE $^ -o debug $(inc) 
	@echo "\n------------------ Test Use Single DulLinkList ------------------\n"
	@./debug
	@rm -rf debug
	@echo "\n-----------------------------------------------------------------\n"
	
Run: test
	@echo "\n------------------ Test Use Loop DulLinkList --------------------\n"
	@./$^
	@rm -rf test
	@echo "\n-----------------------------------------------------------------\n"