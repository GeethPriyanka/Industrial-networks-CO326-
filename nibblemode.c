#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>

#define BASE 0x378
#define DATA BASE
#define STATUS BASE + 1
#define CONTROL BASE + 2

unsigned char a, b;

int main(){
	if(ioperm(BASE, 3, 1)) {
		fprintf(stderr, "Access denied to %x\n", BASE);
		exit(1);
	}

	outb(inb(CONTROL) | 0x01 ,CONTROL); /* Select Low Nibble (A)*/ 

	a = (inb(STATUS) & 0xF0); /* Read Low Nibble */ 
	a = a >> 4; /* Shift Right 4 Bits */
	a = a^0x01; 
	printf("test_a-%u\n", a);
	
	outb( inb(CONTROL) & 0xFE , CONTROL); /* Select High Nibble (B)*/
	sleep(1);
	
	b=(inb(STATUS) & 0xF0); /* Read High Nibble */
	b = b^0x10;
	printf("test_b-%u\n", b);
	
	a = a |b ;  /* can do at once a = a |(inb(STATUS) & 0xF0)*/
	printf("a %u\n", a);
	printf("TMP %u\n", a*400/255);
}	