./a.out infile "cat" "wc -w" outfile
cat outfile

./pipex infile "ls -l" "wc" outfile
#上記の結果が異なってしまう、バイト数が原因？？？