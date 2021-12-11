#include <stdlib.h>
#include <stdio.h>

int Josephus_init(int *JosephusArray, int N) 
{
	int i;
	for (i = 1; i < N; i++) {
		JosephusArray[i] = i + 1;
	}
	JosephusArray[i] = 1;
	return 0;
}

int Josephus_algorithm(int *JosephusArray, int N, int M)
{
	int i = 1;
	int j = i, index, del;
	while (JosephusArray[i] != i) {
		//index = i;
		del = M - 2;
		for (j = 0; j < del; j++) {
			//index = JosephusArray[index];
			i = JosephusArray[i];	
		}
		JosephusArray[i] = JosephusArray[JosephusArray[i]];
		i = JosephusArray[i];
	}
	return i;
}

int
main(int argc, char *argv[])
{
	int *JosephusArray;
	int N = atoi(argv[1]);
	int M = atoi(argv[2]);
	JosephusArray = malloc(sizeof(int) * N);
	if (!JosephusArray) {
		perror("malloc failed.\n");
		exit(-1);
	}

	Josephus_init(JosephusArray, N);

	int i = Josephus_algorithm(JosephusArray, N, M);
	printf("%d\n", JosephusArray[i]);
	return 0;
}
