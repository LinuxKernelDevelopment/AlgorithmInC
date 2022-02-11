#include <stdio.h>
#include "Item.h"
#include "STACK.h"

void execute(char *line)
{
	Item item;
	STACKinit(200);
	for (int i = 0; line[i] != '\n'; i++) {
		switch (line[i]) {
		case '*':
			item = STACKpop();
			printf("%c\n", item);
			break;
		case ' ':
			continue;
		default:
			item = line[i];
			STACKpush(item);
			break;
		}
	}
			
}

int main(int argc, char *argv[])
{
	char *filename = argv[1];
	FILE *file = fopen(filename, "r");
	char line[256];

	fgets(line, sizeof(line), file);

	execute(line);
	fclose(file);
	return 0;
}
