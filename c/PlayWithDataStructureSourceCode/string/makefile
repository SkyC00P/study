inc := -I../
book := test.c impl/string_book.c

all: book

book: $(book)
	gcc -Wall -DBOOK $^ -o $@ $(inc)
	@echo "\n------------------ Test $@ ------------------\n"
	@./$@
	@rm $@
	@echo "\n--------------------------------------------------\n"
