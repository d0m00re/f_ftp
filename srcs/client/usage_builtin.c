#include "ft_display.h"
#include "server.h"

#include "setting.h"

void ft_usage_builtin(int num)
{

	if (num == PUT)
		ft_putstr(USAGE_PUT);
	else if (num == GET)
		ft_putstr(USAGE_GET);
	else if (num == PWD)
		ft_putstr(USAGE_PWD);
	else if (num == CD)
		ft_putstr(USAGE_CD);
	else if (num == MKDIR)
		ft_putstr(USAGE_MKDIR);
	else if (num == LS)
		ft_putstr(USAGE_LS);
	else
		ft_putstr(USAGE_BUILTIN);
}
