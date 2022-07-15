# filename 
PRJ=$(shell basename $(CURDIR))

# Compiler
CC=gcc

# List files s .c
SRC=$(wildcard ./src/*.c)

# List files .h
INCLUDE=$(wildcard ./include/*.h)

# object files
OBJ=$(subst .c,.o,$(subst src,objects,$(SRC)))

# Compile all .c and .h files
all: $(PRJ)

$(PRJ): $(OBJ)
	$(CC) $^ -o $@

./objects/%.o: ./src/%.c ./include/%.h
	$(CC) -c -Wall -Iinclude $< -o $@
	
./objects/main.o: ./src/main.c $(INCLUDE)
	$(CC) -c -Wall -Iinclude $< -o $@

# remove file .o
clean:
	rm  ./objects/*.o $(PRJ)
