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

int blankLongest(char *line, int strLen, int *longestParam, int *longestPosParam)
{
	int blankLen = 0;
	int blankStatus = 0;
	int firstBlank = 0;
	int longest = 0, longestPos = 0;
	int i;
	for (i = 0; i < strLen; i++) {
		if (!blankStatus) {
			if (line[i] == ' ') {
				blankStatus = 1;
				firstBlank = i;
				blankLen = 1;
			} else {
				if (blankLen > longest) {
					longest = blankLen;
					longestPos = firstBlank;
				}
				blankLen = 0;
				blankStatus = 0;
			}
		} else {
			if (line[i] == ' ') {
				blankLen += 1;
			} else {
				blankStatus = 0;
			}
		}
	}
	*longestParam = longest;
	*longestPosParam = longestPos;
	return 0;
}

int
main(int argc, char *argv[])
{
	int strLen;
	char *line = NULL;
	size_t len;
	int longest, longestPos;

	strLen = getInput(&line, &len);
	blankLongest(line, strLen, &longest, &longestPos);
	printf("longest:%d, longestPos:%d\n", longest, longestPos);
	return 0;
}
