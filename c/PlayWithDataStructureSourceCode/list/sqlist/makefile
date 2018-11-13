inc := -I../../
src := sqlist.c test.c

all: Compile Run

Compile: $(src)
	gcc -Wall $^ -o test $(inc)

Run: test
	@echo "\n------------------ Test -------------------------\n"
	@./$^
	@echo "\n-------------------------------------------------"
	
clean: 
	@rm -rf test