#include "server.h"
#include <sys/stat.h>

int check_good_path(t_server_integ *in)
{
	struct stat sb;

	if (stat(in->full_path_server, &sb) == 0) // lien ver
	{
		in->valid_path = 1;
		return (1);
	}
	if (sb.st_mode == S_IFDIR)
	{
		in->valid_path = 1;
		in->rep_is_create = 1;
		in->valid_ftp = 1;
	}
	return (1);
}

int create_reper_server(t_server_integ *in)
{
	if (in->rep_is_create == 1)
		return (1);
	mkdir(in->name_server ,0777);
	in->valid_ftp = 1;
	in->rep_is_create = 1;
	return (1);
}
