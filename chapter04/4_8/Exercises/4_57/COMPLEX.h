#ifndef _COMPLEX_H_
#define _COMPLEX_H_

typedef struct { float Re; float Im; } Complex;
Complex COMPLEXinit(float, float);
float Re(Complex);
float Im(Complex);
Complex COMPLEXmult(Complex, Complex);

#endif
