#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

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

/*
** PERMET DE SAVOIR SI UN TYPE DE FICHIER EXISTE PUIS ON LE COMPARERA AVEC REP
*/
int is_type_file_exist(const char *path)
{
        struct stat path_stat;

        if ((stat(path, &path_stat)) == -1)
                return (0);
        return (1);
}

/*
** purpose : trouver si le path correspont a autres choe q un  fichier
** 1 : si un leement eest present mais pas un ficheir
** 0 : si c est un fichier qui est present
*/

int is_not_file_but_other(const char *path)
{
	if (is_type_file_exist(path) == 0)
		return (0);
	return (!(is_file(path)));
}
