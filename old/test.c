#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int is_rep(const char *path)
{
        struct stat path_stat;

        if ((stat(path, &path_stat)) == -1)
                return (0);
        return (S_ISDIR(path_stat.st_mode));
}

int is_file(const char *path)
{
        struct stat path_stat;

        if ((stat(path, &path_stat)) == -1)
                return (0);
        return (S_ISREG(path_stat.st_mode));
}

int is_type_file_exist(const char *path)
{
	struct stat path_stat;

	if ((stat(path, &path_stat)) == -1)
		return (0);
	return (1);
}

int is_not_file_but_other(const char *path)
{
        if (is_type_file_exist(path) == 0)
                return (0);
        return (!(is_file(path)));
}

int main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	printf("---> %d\n", is_not_file_but_other(av[1]));
	return (1);
}
