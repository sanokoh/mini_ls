#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "libft.h"

// int main(int argc, char **argv)
// {
// 	DIR *d;
// 	struct dirent *dp;
// 	struct stat stat_buf;
// 	char *path;

// 	path = "./";

// 	d = opendir(path);
// 	dp = readdir(d);
// 	while (dp != NULL)
// 	{
// 		printf("%s\n", dp->d_name);
// 		if (stat(dp->d_name, &stat_buf) < 0)
// 			return (1);
// 		printf("%ld\n", stat_buf.st_atime);
// 		dp = readdir(d);
// 	}

// 	// char *err_m;
// 	// err_m = ft_strdup("Do not input commandline arguments.");
// 	// write(2, err_m, ft_strlen(err_m));
// 	// write(0, "\n", 1);
// 	// free(err_m);
// 	if (d != NULL)
// 		closedir(d);
// 	return 0;
// }

int main(int argc, char **argv)
{
	DIR *d;
	struct dirent *dp;
	struct stat stat_buf;
	char *path;

    printf("\033[31m");

	path = "./";

	d = opendir(path);
	dp = readdir(d);
	while (dp != NULL)
	{
		printf("%s\n", dp->d_name);
		if (stat(dp->d_name, &stat_buf) < 0)
			return (1);
		printf("%ld\n", stat_buf.st_atime);
		dp = readdir(d);
	}

	// char *err_m;
	// err_m = ft_strdup("Do not input commandline arguments.");
	// write(2, err_m, ft_strlen(err_m));
	// write(0, "\n", 1);
	// free(err_m);
	if (d != NULL)
		closedir(d);
	return 0;
}
