#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#include <stdio.h>

/*
** CRATION D UN FICHIER ET ENREGISTRER LA CHAINE DATA
*/


/*
** 0: good | < 0 error
*/
int ft_file_write_begin(char *path, char *data, size_t size)
{
	int fd;
	int ret;

	if (!path || !data)
		return (-1);
	if ((fd = open(path, O_CREAT | O_WRONLY, 0777)) == -1)
		return (-2);
	if ((ret = write(fd, (void *)data, size)) == -1)
		return (-3);
	close(fd);
	return (0);
}

int ft_file_write_end(char *path, char *data, size_t size)
{
	int fd;

	if (!path || !data)
		return (-1);
	if ((fd = open(path, O_APPEND | O_WRONLY, 0777)) == -1)
		return (-2);
	if ((write(fd, data, size)) == -1)
		return (-3);
	close(fd);
	return(fd);
}
/*
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc != 4)
		return (1);
	ft_file_write_begin(argv[1], argv[2], strlen(argv[2]));
	ft_file_write_end(argv[1], argv[3], strlen(argv[3]));
	printf("%s|%s|%lu\n", argv[1], argv[2], strlen(argv[2]));
	return (1);
}
*/
