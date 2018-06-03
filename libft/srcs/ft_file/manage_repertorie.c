#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>


int rep_exist(char *name)
{
	DIR *dirp;

	if ((dirp = opendir(name)) == NULL)
		return (1);
	return (0);
}

// -1 error
int get_rep_size_without_hide(char *name)
{
	DIR *dirp;
	struct dirent *dp;
	int len;

	len = 0;
	dirp = opendir(name);
        if (dirp == NULL)
                return (-1);
	while ((dp = readdir(dirp)) != NULL)
	{
		if (dp->d_name[0] != '.')
			len += dp->d_namlen + 1;
	}
	(void)closedir(dirp);
	return (len);
}

char *get_rep_string_without_hide_with_size(char *name, int len)
{
        DIR *dirp;
        struct dirent *dp;
	char *str;

	dirp = opendir(name);
	if (!(str = malloc(10 * len * sizeof(char))))
		return (0);
	strcpy(str, "");
        while ((dp = readdir(dirp)) != NULL)
        {
                if (dp->d_name[0] != '.')
		{
			strcat(str, dp->d_name);
			strcat(str, " ");
		}
        }
	str[len - 1] = 0;
        (void)closedir(dirp);
        return (str);
}

char *get_rep_string(char *name, int *len)
{
	*len = get_rep_size_without_hide(name);
	return (get_rep_string_without_hide_with_size(name, *len));
}

/*
int main()
{
	int size;
	char *str;

	str = get_rep_string(".", &size);
	printf("Size : %d\n", size);
	printf("Data : %s\n", str);
	printf("rep exist -> %d | %d\n", rep_exist("cosfdsdfs"), rep_exist("."));
	return (1);
}
*/
