typedef struct poly *Poly;
void showPOLY(Poly);
Poly POLYterm(int, int);
Poly POLYadd(Poly, Poly);
Poly POLYmult(Poly, Poly);
float POLYeval(Poly, float);
Poly POLYintegral(Poly);
Poly POLYdiff(Poly);
Poly POLYignore(Poly, int);
Poly POLYsub(Poly, Poly);
int POLYdivision(Poly, Poly, Poly*, Poly*);
