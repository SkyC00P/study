inc := -I../
src_sqstack := test.c impl/sqstack.c

all: sqstack 

sqstack: $(src_sqstack)
	gcc -Wall -DSQ_STACK $^ -o $@ $(inc)
	@echo "\n------------------ Test $@ ------------------\n"
	@./$@
	@rm $@
	@echo "\n--------------------------------------------------\n"
