#include <stdio.h> 
#include <string.h>
int romanToInt(char* psRmNum)
{
    int liChgNum = 0; 
    
    for (int i = 0; i < strlen(psRmNum); i++)
    {
        
        if (psRmNum[i] == 'I' && psRmNum[i+1] == 'V')
        {
            liChgNum += 4; 
            i++;
            continue;
        }
        else if(psRmNum[i] == 'I' && psRmNum[i+1] == 'X')
        {
            liChgNum += 9;
            i++;
            continue;
        }
        else if(psRmNum[i] == 'X' && psRmNum[i+1] == 'L')
        {   
            liChgNum += 40;
            i++;
            continue;
        }
        else if(psRmNum[i] == 'X' && psRmNum[i+1] == 'C')
        {   
            liChgNum += 90;
            i++;
            continue;
        }   
        else if(psRmNum[i] == 'C' && psRmNum[i+1] == 'D')
        {   
            liChgNum += 400;
            i++;
            continue;
        }
        else if(psRmNum[i] == 'C' && psRmNum[i+1] == 'M')
        {   
            liChgNum += 900;
            i++;
            continue;
        }
        else 
        {
            switch(psRmNum[i])
            {
                case 'I' :
                    liChgNum += 1;
                    break; 
                case 'V' :
                    liChgNum += 5;
                    break; 
                case 'X' :
                    liChgNum += 10;
                    break; 
                case 'L' :
                    liChgNum += 50;
                    break; 
                case 'C' :
                    liChgNum += 100;
                    break; 
                case 'D' :
                    liChgNum += 500;
                    break; 
                case 'M' :
                    liChgNum += 1000;
                    break; 
            } 
        }
        if (psRmNum[i] == 'V' && psRmNum[i] == 'L' && psRmNum[i] == 'D')
        {
            
        }
    }
    
    return liChgNum; 
} 

int main()
{
    char lsInput[100];
	printf("input : ");
	gets(lsInput);
    printf("output : %d \n", romanToInt(lsInput));
    
    return 0; 
} 

