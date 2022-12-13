#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 

void print(char* psInput)
{ 
  int liMax = 1000000000;
  printf("output : ");

  for(int i = 0; i < strlen(psInput); i++)
  {
    if(isdigit(psInput[i])==0)
    {
      printf("You can only enter numbers.");
      break; 
    }
    else if(atoi(psInput) > liMax || atoi(psInput) < 1)
    {
      printf("You can only enter numbers from 1 to 1 billion.");
      break;
    }
    else
    { 
      printf("%c",psInput[i]);     
    }
  }
}

void sort(char* psInput, int piLen)
{
  char lsTmp;  
  for (int liStp = 0; liStp < piLen; liStp++)
  {
    for(int i = 0; i < piLen - liStp; i++)
    {
      if (psInput[i] < psInput[i + 1])
      {
          lsTmp = psInput[i];
          psInput[i] = psInput[i + 1];
          psInput[i + 1] = lsTmp; 
      }
    }
  }
  print(psInput);
}
void in_out()
{
  int liLen;
  char lsInput[10], lsTmp;
  printf("input : ");
  scanf("%s", lsInput);
  
  liLen = strlen(lsInput) - 1; 
  sort(lsInput,liLen);
}


