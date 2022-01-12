typedef struct {
	char *symbol;
	int val;
} stEntry;

char *infixToPostfix(char *a);
void initSymbolTable(void);
void initSymbolTable(void);
void evalPostfix(char *a);
