#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char *ft_read_file_size(char *path, size_t *size)
{
	struct stat sb;
	char *str;
	int fd;

	if (!path)
		return (0);
	if (lstat(path, &sb) == -1)
	{
		printf("Error ...\n");
		return (0);
	}
	//if (sb.st_mode != S_IFREG)
	//{
	//	printf("This is not a file. Fucking idiot ... : %d\n", sb.st_mode);
	//	return (0);
	//}
	*size = sb.st_size;
	if ((fd = open(path, O_RDONLY)) == -1)
		return (0);
	if ((str = malloc((*size + 1) * sizeof(char))) == 0)
		return (0);
	if ((read(fd, str, *size)) == -1)
		return (0);
	str[*size - 1] = 0;
	return (str);
}

char *ft_read_file(char *path)
{
	size_t size;

	return (ft_read_file_size(path, &size));
}

/*
int main(int ac, char **av)
{
	size_t size;

	if (ac != 2)
		return (1);
	printf("%s", ft_read_file_size(av[1], &size));
	return (1);
}
*/
