inc := -I../
src_sqstack := test.c impl/sqstack.c
link_stack := test.c impl/link_stack.c

all: sqstack link_stack share_stack

sqstack: $(src_sqstack)
	gcc -Wall -DSQ_STACK $^ -o $@ $(inc)
	@echo "\n------------------ Test $@ ------------------\n"
	@./$@
	@rm $@
	@echo "\n--------------------------------------------------\n"

link_stack: $(link_stack)
	gcc -Wall $^ -o $@ $(inc)
	@echo "\n------------------ Test $@ ------------------\n"
	@./$@
	@rm $@
	@echo "\n--------------------------------------------------\n"

fib : apply/fibonacci.c
	gcc -Wall $^ -o $@  $(inc)

share_stack : impl/share_stack.c 
	gcc -Wall $^ -o $@ $(inc)
	@echo "\n------------------ Test $@ ------------------\n"
	@./$@
	@rm $@
	@echo "\n--------------------------------------------------\n"