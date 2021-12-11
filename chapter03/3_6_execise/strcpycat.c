#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strcpy_aic(char **dest, const char *src)
{
	int len = 0;
	int i, j;
	for (i = 0; src[i] != '\0'; i++);
	*dest = (char *) malloc(sizeof(char) * i);
	if (!*dest) {
		fprintf(stderr, "malloc failed");
		exit(-1);
	}
	for (j = 0; j != i; j++)
		(*dest)[j] = src[j];
	return *dest;
}

char *strcat_aic(char **dest, const char *src)
{
	int di, si, tl, i;
	for (di = 0; (*dest)[di] != '\0'; di++) ;
	for (si = 0; src[si] != '\0'; si++) ;
	tl = di + si;
	*dest = realloc(*dest, tl + 1);
	if (!*dest) {
		fprintf(stderr, "realloc failed");
		exit(-1);
	}
	for (i = 0; i < si; i++)
		(*dest)[di + i] = src[i];
	return *dest;
}

int main(int argc, char *argv[])
{
	char *dest = NULL;
	char *src = "fuck you";

	strcpy_aic(&dest, src);
	printf("%s\n", dest);

	char *src2 = malloc(6);
	strcpy(src2, "fuck ");
	char *dest2 = malloc(4);
	strcpy(dest2, "you");
	strcat_aic(&dest2, src2);
	printf("%s\n", dest2);
	return 0;
}
