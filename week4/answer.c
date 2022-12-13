#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
  char buffer[1000];
  
  FILE* lRdf;
  lRdf = fopen("Question4.A", "r");
  int liRn;
  
  if (lRdf == NULL)
  {
    printf("file open error. please try again!\n");
  }
  else 
  {
    fgets(buffer, 1000, lRdf);
    
    char* lRStr = strtok(buffer, " ");
    
    FILE* lOtf; 
    lOtf = fopen("Answer4.txt", "w");
    while (lRStr != NULL)
    {
      liRn = atoi(lRStr);
      lRStr = strtok(NULL, " "); 
      printf("%c",liRn);         
    }
    
    fclose(lOtf);
  }

  fclose(lRdf);
  
  return 0;
  
}