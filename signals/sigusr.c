#include "apue.h"

static void	sig_usr(int);	/* one handler for both signals */
int step = 1;
int i = 0;

int
main(void)
{
	if (signal(SIGUSR1, sig_usr) == SIG_ERR)
		err_sys("can't catch SIGUSR1");
	if (signal(SIGUSR2, sig_usr) == SIG_ERR)
		err_sys("can't catch SIGUSR2");
	if (signal(SIGINT, sig_usr) == SIG_ERR)
		err_sys("can't catch SIGINT");
	for ( ; ; ) {
            /* pause();
            */
            i += step;
            printf("i=%d\n", i);
            sleep(1);
            if (500 < i) break;
        }
        return 0;
             
}

static void
sig_usr(int signo)		/* argument is signal number */
{
	if (signo == SIGUSR1)
		printf("received SIGUSR1\n");
	else if (signo == SIGUSR2)
		printf("received SIGUSR2\n");
        else if (signo == SIGINT)
                step++;
	else
		err_dump("received signal %d\n", signo);
}
