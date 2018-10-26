inc := -I../
src := test.c

all: Build Run

Build: $(src)
	gcc -Wall $^ -o test $(inc)

Run: test
	@echo "\n------------------ Test Stack --------------------\n"
	@./$^
	@rm -rf test
	@echo "\n--------------------------------------------------\n"