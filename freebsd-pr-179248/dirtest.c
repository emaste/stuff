/* From https://bugs.freebsd.org/179248 */

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

int main(void)
{
	DIR *dirp;
	struct dirent *dp;
	long pos;

	if ((dirp = opendir(".")) == NULL) return 1;
	printf("telldir = %ld\n", telldir(dirp));

	if ((dp = readdir(dirp)) == NULL) return 1;
	printf("readdir = %s\n", dp->d_name);
	printf("telldir = %ld\n", telldir(dirp));

	if ((dp = readdir(dirp)) == NULL) return 1;
	printf("readdir = %s\n", dp->d_name);
	printf("telldir = %ld\n", telldir(dirp));

	if ((dp = readdir(dirp)) == NULL) return 1;
	printf("readdir = %s\n", dp->d_name);
	printf("telldir = %ld\n", pos = telldir(dirp));

	if ((dp = readdir(dirp)) == NULL) return 1;
	printf("readdir = %s\n", dp->d_name);
	printf("telldir = %ld\n", telldir(dirp));

	printf("seekdir to %ld\n", pos);
	seekdir(dirp, pos);

	if ((dp = readdir(dirp)) == NULL) return 1;
	printf("readdir = %s\n", dp->d_name);
	printf("telldir = %ld\n", telldir(dirp));

	printf("seekdir to %ld\n", pos);
	seekdir(dirp, pos);

	if ((dp = readdir(dirp)) == NULL) return 1;
	printf("readdir = %s\n", dp->d_name);
	printf("telldir = %ld\n", telldir(dirp));

	(void)closedir(dirp);
	return 0;
}

