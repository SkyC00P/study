inc := -I../
sqqueue := test.c impl/sqqueue.c

all: sqqueue

sqqueue: $(sqqueue)
	gcc -Wall -DSQ_QUEUE $^ -o $@ $(inc)
	@echo "\n------------------ Test $@ ------------------\n"
	@./$@
	@rm $@
	@echo "\n--------------------------------------------------\n"

