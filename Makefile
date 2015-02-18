#Author: Hanh Kieu

myrsvp.out: vector.o course.o rsvp.o
	gcc -g   -Wall -o myrsvp.out vector.o course.o rsvp.o

vector.o: vector.c vector.h
	gcc -c  -Wall -g vector.c

course.o: course.c course.h vector.h
	gcc -c -Wall -g course.c 

rsvp.o: rsvp.c course.h
	gcc -c -Wall -g rsvp.c

clean:
	rm -f myrsvp.out vector.o course.o rsvp.o