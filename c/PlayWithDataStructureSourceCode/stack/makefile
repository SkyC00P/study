inc := -I../
src_sqstack := test.c impl/sqstack.c

all: sqstack 

sqstack: $(src_sqstack)
	gcc -Wall -DSQ_STACK $^ -o sqstack $(inc)
	@echo "\n------------------ Test sqstack ------------------\n"
	@./sqstack
	@rm sqstack
	@echo "\n--------------------------------------------------\n"
