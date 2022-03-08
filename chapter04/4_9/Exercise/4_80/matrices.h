typedef struct matrice *MA;

MA initMatrice(int*, int, int);
MA matriceAddSub(MA, MA, int);
MA matriceMul(MA, MA);
void destroyMatrice(MA);
void printMatrice(MA);
MA matriceDiv(MA, int);
