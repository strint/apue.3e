#include "apue.h"
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";
char buf3[10];

int main(void) {
    int fd;

    if ((fd = open("file.hole", O_RDWR | O_CREAT | O_TRUNC, FILE_MODE)) < 0) {
        err_sys("create error");
    }

    if (write(fd, buf1, 10) != 10) {
        err_sys("buf1 write error");
    }
    /* offset now = 10 */
    printf("offset now = %ld\n", lseek(fd, 0, SEEK_CUR));

    if (lseek(fd, 16384, SEEK_SET) == -1) {
        err_sys("lseek error");
    }
    /* offset now = 16384 */
    printf("offset now = %ld\n", lseek(fd, 0, SEEK_CUR));

    if (write(fd, buf2, 10) != 10) {
        err_sys("buf2 write error");
    }
    /* offset now = 16394 */
    printf("offset now = %ld\n", lseek(fd, 0, SEEK_CUR));

    if (lseek(fd, 0, SEEK_SET) == -1) {
        err_sys("lseek error");
    }
    /* offset now = 0*/
    printf("offset now = %ld\n", lseek(fd, 0, SEEK_CUR));

    ssize_t len = 0;
    if ( (len = read(fd, (void *)buf3, 10)) != 10) {
        err_sys("read error");
    }
    printf("buf3 = %s\n", buf3);
    /* offset now = 10*/
    printf("offset now = %ld\n", lseek(fd, 0, SEEK_CUR));

    exit(0);
}
