#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * infinite_while - Run an infinite while loop.
 * Return: (EXIT_SUCCESS) - SAFE EXIT.
 */
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (EXIT_SUCCESS);
}

/**
 * main - Creates five zombie processes.
 * Return: (EXIT_SUCCESS) - SAFE EXIT.
 */
int main(void)
{
	pid_t pid;
	char i = 0;

	while (i < 5)
	{
		pid = fork();
		if (pid > 0)
		{
			printf("Zombie process created, PID: %d\n", pid);
			sleep(1);
			i++;
		}
		else
			exit(0);
	}

	infinite_while();

	return (EXIT_SUCCESS);
}
