
#include <stdio.h>

int anagramCheck (char[], char[]); 

int main()
{
    char input1[50], input2[50]; 
    printf("input1 : ");
    scanf("%s", input1);
    printf("input2 : ");
    scanf("%s", input2);
    int count;
    int i = 0;
    
    count = anagramCheck(input1, input2); 
    if(count == 1)
    {
        printf("output : anagram"); 
    }
    else
    {
        printf("output : Not anagram");    
    }
    return 0; 
}    
int anagramCheck(char n1[], char n2[])
{
    int num1[20] = {0};
    int num2[20] = {0};
    int i = 0;
    
    while (n1[i] != '\0')
    {
        num1[n1[i]-'a']++; 
        i++;
    }
    i = 0;
    
    while (n2[i] != '\0')
    {
        num2[n2[i]-'a']++; 
        i++;
    }
    
    for (int i = 0; i < 20; i++)
    {
        if (num1[i] != num2[i])
        {
            return 0; 
        }
        return 1;
    }
}


