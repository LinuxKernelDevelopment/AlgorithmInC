#include <stdio.h>
#include <stdlib.h>


int palindrome(char *line, int sz)
{
	int i = 0, j = sz - 1;
	int ret = 0;
	while (i <= j) {
		while (line[i] == ' ')
			i++;
		while (line[j] == ' ')
			j--;
		if (line[i] != line[j]) {
			ret = 0;
			break;
		}
		i += 1;
		j -= 1;
	}
	if (i >= j)
		ret = 1;
	return ret;
}

int
main(int argc, char *argv[])
{
	char *line = NULL;
	int i;
	size_t len = 0;
	ssize_t lineSize = 0;
	lineSize = getline(&line, &len, stdin);
	for (i = 0; line[i] != '\n'; i++) ;
	line[i] = 0;
	printf("line:%s, %d\n", line, i);
	printf("%d\n", palindrome(line, i));
	return 0;
}
