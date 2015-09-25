#
# CMPSC311 - Utility Library 
# Code for the CMPSC311 Projects
#

# Make environment
INCLUDES=-I.
CC=gcc
CFLAGS=-I. -c -g -Wall $(INCLUDES)
LINKARGS=-lm
LIBS=-lm

# Files
OBJECT_FILES=	cmpsc311-f15-assign1.o \
				a1support.o

# Productions
all : cmpsc311-f15-assign1

cmpsc311-f15-assign1 : $(OBJECT_FILES)
	$(CC) $(LINKARGS) $(OBJECT_FILES) -o $@ $(LIBS)

cmpsc311-f15-assign1.o : cmpsc311-f15-assign1.c a1support.h
	$(CC) $(CFLAGS) $< -o $@

a1support.o : a1support.c a1support.h 
	$(CC) $(CFLAGS) $< -o $@

output : test-output.txt test-output2.txt

test-output.txt : test-input.txt cmpsc311-f15-assign1
	./cmpsc311-f15-assign1 < test-input.txt > test-output.txt

test-output2.txt : test-input2.txt cmpsc311-f15-assign1
	./cmpsc311-f15-assign1 < test-input2.txt > test-output2.txt

clean : 
	rm -f cmpsc311-f15-assign1 $(OBJECT_FILES)
