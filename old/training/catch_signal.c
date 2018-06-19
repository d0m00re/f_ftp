#include <signal.h>
#include <stdio.h>

static volatile int keepRunning = 1;

void intHandler(int dummy)
{
	keepRunning = 0;
}

int main(void)
{
	signal(SIGINT, intHandler);

	while (keepRunning)
	{
	}
	printf("--> end ....\n");
	return (1);
}
   
