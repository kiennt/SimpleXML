GCC = gcc
OBJECTS = simple_vector.o
TESTPRG = test

all: test

# Deps
simple_vector.o: simple_vector.h
test: test.c $(OBJECTS)
	$(GCC) $(OBJECTS) test.c -o $(TESTPRG)
	./$(TESTPRG)

clean:
	rm -rf *.o $(TESTPRG)
