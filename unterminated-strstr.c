// strstr requires null-terminated strings as arguments.
// This sample calls strstr with a needle that matches the beginning
// of an unterminated haystack string, to investigate what happens with
// the libc on various operating systems.

#include <sys/mman.h>
#include <err.h>
#include <stdio.h>
#include <string.h>

int
main (int argc, char *argv[])
{
	char *buf, *p;
	const size_t bufsize = 4096;

	buf = mmap(NULL, bufsize, PROT_READ | PROT_WRITE,
	    MAP_PRIVATE | MAP_ANON, -1, 0);
	if (buf == NULL)
		err(1, "mmap");
	printf("mmap buf=%p\n", buf);
	memset(buf, 0xff, bufsize);

	buf = buf + bufsize - 16;
	strncpy(buf, "hello world", 11);
	p = strstr(buf, "hello");
	printf("strstr p=%p\n", p);
	return 0;
}
