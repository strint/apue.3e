#include "apue.h"

int
main(void)
{
    off_t pos;
	if ((pos = lseek(STDIN_FILENO, 2, SEEK_CUR)) == -1)
		printf("cannot seek\n");
	else
		printf("seek OK, %ld\n", (long)pos);
	exit(0);
}
