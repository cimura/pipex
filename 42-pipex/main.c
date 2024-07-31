#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "../libft/libft.h"

// void	pipex(int f1, int f2)
// {

// }

int	main(int argc, char *argv[], char *envp[])
{
	int	f1;
	int	f2;

	f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0 || f2 < 0)
		return (-1);
	char *Path_from_envp = ft_substr(*envp, 0, 3);
	// pipex(f1, f2, argv, envp);
	printf("%s\n", Path_from_envp);
	return (0);
}