#include <stdio.h>
#include <stdlib.h>

unsigned int
read16(int fd)
{
	unsigned char b[2];
	int ret;

	ret = read(fd, b, 2);
	if (ret < 2) {
		printf("eof!\n");
		exit(1);
	}
	return (b[1] << 8) | b[0];
}

unsigned int
read32(int fd)
{
	unsigned char b[4];
	int ret;

	ret = read(fd, b, 4);
	if (ret < 4) {
		printf("eof!\n");
		exit(1);
	}
	return (b[1] << 24) | (b[0] << 16) | (b[3] << 8) | b[2];
}

unsigned long
str4(char *s)
{
	return (s[3] << 24) | (s[2] << 16) | (s[1] << 8) | s[0];
}

char *
unstr4(unsigned long s)
{
	static char b[5];

	b[3] = s >> 24;
	b[2] = s >> 16;
	b[1] = s >> 8;
	b[0] = s;
	b[4] = 0;
	return b;
}