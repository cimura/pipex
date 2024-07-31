#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>  // strncpyを使うために追加

int	main(int argc, char *argv[], char *envp[])
{
	int	f1;
	int	f2;

	if (argc != 5) {
		fprintf(stderr, "Usage: %s infile cmd1 cmd2 outfile\n", argv[0]);
		return 1;
	}

	f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0 || f2 < 0) {
		perror("open");
		return -1;
	}

	// 環境変数が正しく渡されているか確認する
	if (envp == NULL || *envp == NULL) {
		fprintf(stderr, "No environment variables found.\n");
		return 1;
	}

	// 最初の環境変数の最初の3文字をコピーする
	char Path_from_envp[4];  // 3文字 + 終端文字
	strncpy(Path_from_envp, envp[0], 31);
	Path_from_envp[3] = '\0';  // 文字列の終端を追加

	printf("First 3 characters of the first environment variable: %s\n", Path_from_envp);

	close(f1);
	close(f2);

	return 0;
}
