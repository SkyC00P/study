inc := -I../
sqqueue := test.c impl/sqqueue.c
LinkQueue := test.c impl/link_queue.c
all: sqqueue LinkQueue

sqqueue: $(sqqueue)
	gcc -Wall -DSQ_QUEUE $^ -o $@ $(inc)
	@echo "\n------------------ Test $@ ------------------\n"
	@./$@
	@rm $@
	@echo "\n--------------------------------------------------\n"

LinkQueue:$(LinkQueue)
	gcc -Wall $^ -o $@ $(inc)
	@echo "\n------------------ Test $@ ------------------\n"
	@./$@
	@rm $@
	@echo "\n--------------------------------------------------\n"