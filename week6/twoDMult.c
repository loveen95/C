#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void twoDMult(int** pspArr1, int** pspArr2, int** pspArr3, int row, int col) 
{
    for(int i = 0; i < row; i++)
    {
        for(int j=0; j < col; j++)
        {
            int liSum = 0; 
            for(int k = 0; k < col)
            {     
                liSum += (*(*(pspArr1 + i) + k)) * (*(*(pspArr2 + k) + j)); 
            } 
            *(*(pspArr3 + i) + j) = liSum;    
        }     
    }
}

void ArrayPrint(int** pspArr1, int row, int col) 
{
    printf("Array[%d][%d]", row, col); 
    for(int i =0; i < col; i++)
    {
        for(int j= 0; j < row; j++)
        {
            printf("%d ", pspArr1[i][j]); 
        }
        printf("\n"); 
    }
}

