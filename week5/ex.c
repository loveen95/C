#include<time.h>
#include<stdio.h>
#include<windows.h>

void gotoxy(int xpos, int ypos);
int select_num(int time_num,int pos_num);
int print_num(int printn, int loca_num);
int print_blank(void);

int main(void)
{
    int x, i;                                                                     
    int time_num[3] ;
       
    for(;;)                                                                    
    {  
        time_t timer;                                                             
        struct tm *t;                                                           
        timer = time(NULL);                                                     
        t = localtime(&timer);                                                    

        time_num[0] = t->tm_hour;                                                
        time_num[1] = t->tm_min;                                                 
        time_num[2] = t->tm_sec;                                                 

        gotoxy(0,3);
        if(time_num[0]>=13)                                                      
        {
             time_num[0] = time_num[0]-12;                                       
        }

        for(i = 0 ; i < 3 ; i++)                                              
        {
              x = time_num[i];                                                   
             select_num(x,i);                                                  
        }
        print_blank();  
        Sleep(1000);                                                                
     }
    System("PAUSE");                                                             
    return 0;
}