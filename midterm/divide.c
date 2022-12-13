#include <stdio.h> 
#include <math.h> 

int main()
{
    int input1;
    int input2;
    printf("input1 : ");
    scanf("%d", &input1);
    printf("input2 : ");
    scanf("%d", &input2);
    int mod;
    mod = (int)fmod(input2,input1);
    int i; 
    int j = 0;
    for(int i = 0; i <= input2; j++)
    {   
        i += input1;
    }
    printf("output : %d and %d",j-1,mod);
} 