
static int g_sigint = 0;

int	get_sigint()
{
	return (g_sigint);
}

void	true_sigint()
{
	g_sigint = 1;
}

void false_sigint()
{
	g_sigint = 0;
}
