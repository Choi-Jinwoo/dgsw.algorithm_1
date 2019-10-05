#include <stdio.h>

void main() {
	char string[] = "HELLO";
	char *pstr = string;
	while (*pstr) {
		putchar(*pstr++);
	}

	puts("");

	pstr--;	
	while (*pstr) {
		putchar(*pstr--);
		if (pstr == string) {
			putchar(*pstr--);
			break;
		}
	}
}