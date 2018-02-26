#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, const char *argv[])
{
#if 0
	signal(SIGINT,SIG_IGN);
#endif

	while(1);
	return 0;
}
