typedef struct largeInt *LI;
LI LIinit(char *);
LI LIadd(LI, LI);
void printLI(LI);
void LIdestroy(LI);
LI LImult(LI, LI);
LI LIsub(LI, LI);
int LIgreater(LI, LI);