#include <stdio.h>

int main()
{
    int liLowNum;
    int liUppNum;
    int liCnt;
    
    printf("Enter the lowest and highest numbers.\n");
    printf("lowest number>>");
    scanf("%d",&liLowNum);
    printf("highest number>>");
    scanf("%d",&liUppNum);
    
    printf("Prime numbers between %d-%d : ", liLowNum,liUppNum);
     
    for(int i = liLowNum; i <= liUppNum; i++)
    {
       liCnt = 0; 
       for (int j = 2; j <= i; j++)
       {
           if(i % j == 0)
                liCnt++;
       }
       
       if (liCnt == 1)
            printf("%d ",i);
    }
    return 0;
}
