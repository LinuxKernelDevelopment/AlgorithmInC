typedef struct largeInt *LI;
LI LIinit(char *);
LI LIadd(LI, LI);
void printLI(LI);
void LIdestroy(LI);
LI LImult(LI, LI);
