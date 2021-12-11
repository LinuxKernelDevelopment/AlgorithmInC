#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void computeLPS(char *pat, int M, int* lps)
{
	int len = 0;

	lps[0] = 0;

	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else {
			if (len != 0) {
				len = lps[len-1];
			}
			else {
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMPSearch(char *pat, char *txt)
{
	int M = strlen(pat);
	int N = strlen(txt);

	int *lps = malloc(sizeof(int) * M);
	if (!lps) {
		perror("malloc failed");
		exit(-1);
	}

	computeLPS(pat, M, lps);

	int i = 0, j = 0;
	while (i < N) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}
		if (j == M) {
			printf("Found pattern at index %d\n", i - j);
			j = lps[j - 1];
		} else if (i < N && pat[j] != txt[i]) {
			if (j != 0)
				j = lps[j - 1];
			else
				i += 1;
		}
	}
}

int main(int argc, char *argv[])
{
	char *pat = argv[1];
	char *line = NULL;
	int i;
	size_t len = 0;
	ssize_t lineSize = 0;
	//char txt[] = "ABABDABACDABABCABAB";
	//char pat[] = "ABABCABAB";
	printf("Please input a string(txt):");
	lineSize = getline(&line, &len, stdin);
	for (i = 0; line[i] != '\n'; i++) ;
	line[i] = 0;

	KMPSearch(pat, line);
	return 0;
}
