#include <stdio.h>

int main(int argc, const char *argv[])
{
	fputs("hell\0o world\n",stdout);
	puts("he\0llo world\n");
	return 0;
}
