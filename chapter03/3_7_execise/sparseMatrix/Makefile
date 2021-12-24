TARGET := arr2sparse matrixMul

matrixMul : sparseMatrix.o matrixMul.o ../../malloc_2d/malloc2d.o
arr2sparse : sparseMatrix.o arr2sparse.o ../../malloc_2d/malloc2d.o
sparseMatrix.o : sparseMatrix.c 

-include ../../../build.rule
