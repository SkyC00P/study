inc := -I../
array_string := array_string/test.c array_string/string_book.c
jstring := jstring/test.c jstring/jstring.c
lstring := link_string/test.c link_string/lstring.c

all: book jstring lstring

book: 
	gcc -g -Wall -DBOOK $(array_string) -o $@ $(inc)
	@echo "\n------------------ Test $@ ------------------\n"
	@./$@
	@rm $@
	@echo "\n--------------------------------------------------\n"

jstring:
	gcc -g -Wall $(jstring) -o $@ $(inc)
	@echo "\n------------------ Test $@ ------------------\n"
	@./$@
	@rm $@
	@echo "\n--------------------------------------------------\n"

lstring:
	gcc -g -Wall $(lstring) -o $@ $(inc)
	@echo "\n------------------ Test $@ ------------------\n"
	@./$@
	@rm $@
	@echo "\n--------------------------------------------------\n"