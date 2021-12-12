#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getInput(char **line, size_t *len)
{
	ssize_t lineSize = 0;
	int strLen = 0;
	int i;
	printf("Please input a string:\n");
	lineSize = getline(line, len, stdin);
	for (i = 0; (*line)[i] != '\n'; i++) ;
	(*line)[i] = 0;
	return i;
}

int removeBlank(char *line, int strLen)
{
	int blankLen = 0;
	int blankStatus = 0;
	int firstBlank = 0;
	int i;
	for (i = 0; i < strLen; i++) {
		if (!blankStatus) {
			if (line[i] == ' ') {
				blankStatus = 1;
				firstBlank = i;
				blankLen = 1;
			} else {
				blankStatus = 0;
			}
		} else {
			if (line[i] == ' ') {
				blankLen += 1;
			} else {
				memcpy(line+firstBlank+1, line+i, strLen - i + 1);
				blankStatus = 0;
			}
		}
	}
	return 0;
}

int
main(int argc, char *argv[])
{
	int strLen;
	char *line = NULL;
	size_t len;

	strLen = getInput(&line, &len);
	removeBlank(line, strLen);
	printf("str:%s\n", line);
	return 0;
}
