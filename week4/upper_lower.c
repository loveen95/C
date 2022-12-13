#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <ctype.h>

void change(char* psInput)
{ 
    for (int i = 0; i < strlen(psInput); i++)
    {
        if(psInput[i] >= 'a' && psInput[i] <= 'z')
        {  
            psInput[i] -= 32;
        }
        else if (psInput[i] >= 'A' && psInput[i] <= 'Z' )
        {  
            psInput[i] += 32;
        }
    }
    printf("output : ");
    printf("%s\n", psInput); 

}
int main()
{
    char lsInput[100];
    printf("Converting uppercase and lowercase letters\n");
    printf("Please enter a string\nInput : ");
    scanf("%[^\n]s",lsInput);
    
    for (int i = 0; i < strlen(lsInput); i++)
    {
        if ((int)strlen(lsInput) == 0)
        {
            printf("Please enter at least one sentence.");
            return 0;
            break;
        }
        else
        {
            change(lsInput);
            break; 
        }
        
    } 
    return 0; 
}

