#include <stdio.h>
#include <time.h>
// #include <windows.h> 
int main() 
{
    int roop = 0;
    struct tm *t; //구조체 
    time_t timer; // time_t는 산술 시간 유형 
    timer = time(NULL); //time()함수는 시스템의 현재시간을 time_t 값으로 반환 
    t = localtime(&timer); // localtime()은 'time_t' 값을 달력시간으로 변환하고 tm 구조체에 대한 포인터 반환
    int liSec = t -> tm_sec; // (0-59초)를 얻는다. 
    char ampm[2]; // 오전 & 오후 판별
    char wday[4]; // 요일 
    
    while(1)
    {   
        if( roop == 1 && t -> tm_sec == 0 && liSec == 59) // 59초가 되거나 0초 즉 한바퀴를 돌게 되면 다시 0으로 돌아간다.
        {
            system("clear"); // 콘솔 화면 출력 지워주는 함수
            liSec = t -> tm_sec; // 다시 0부터 시작
            roop = 0; // 0바퀴      
        }
        
        timer = time(NULL); // 인자에 NULL 을 넘길 경우, 현재까지의 시간을 초 단위로 반환함.  
        t = localtime(&timer);
        
        switch(t -> tm_wday)
        {      
            case 0 :
                wday[0] = 'S';
                wday[1] = 'u';
                wday[2] = 'n';
                wday[3] = '\0';
                break;
            case 1 :
                wday[0] = 'M';
                wday[1] = 'o';
                wday[2] = 'n';
                wday[3] = '\0'; 
                break;
            case 2 :
                wday[0] = 'T';
                wday[1] = 'u';
                wday[2] = 'e';
                wday[3] = '\0';; 
                break;
            case 3 :
                wday[0] = 'W';
                wday[1] = 'e';
                wday[2] = 'd';
                wday[3] = '\0'; 
                break;
            case 4 :
                wday[0] = 'T';
                wday[1] = 'h';
                wday[2] = 'u';
                wday[3] = '\0'; 
                break;
            case 5 :
                wday[0] = 'F';
                wday[1] = 'r';
                wday[2] = 'i';
                wday[3] = '\0'; 
                break;
            case 6 :
                wday[0] = 'S';
                wday[1] = 'a';
                wday[2] = 't';
                wday[3] = '\0'; 
                break;
        } 
        
        if (t -> tm_hour >= 12)
        {
            ampm[0] = 'P'; 
            ampm[1] = 'M';
            ampm[2] = '\0'; 
        }
        else 
        {
            ampm[0] = 'A'; 
            ampm[1] = 'M';
            ampm[2] = '\0'; 
        }
        if (roop == 0) //0바퀴로 다시 초기화 된 경우 
        {       
            printf("%s, %d %d %d %02d:%02d:%02d [%s]\n",
              wday, t->tm_mday,t->tm_mon + 1,t->tm_year + 1900, 
              t->tm_hour, t->tm_min, t->tm_sec, ampm);      
              roop = 1; 
              
        }
        else if(roop == 1 && liSec + 1 == t -> tm_sec)
        {
            system("clear");
            liSec = t -> tm_sec;
            roop = 0;                  
        }
    }   
    return 0;
}

/*struct tm {
   int tm_sec;         // 초,  range 0 to 59      
   int tm_min;         // 분, range 0 to 59             
   int tm_hour;        // 시간, range 0 to 23  
   int tm_mday;        // 일, range 1 to 31  
   int tm_mon;         // 월, range 0 to 11     
   int tm_year;        // 1900년 부터의 년                
   int tm_wday;        // 요일, range 일(0) to 토(6) 
   int tm_yday;        // 1년 중 경과 일, range 0 to 365 
   int tm_isdst;       // 섬머타임 실시 여부 (양수, 0, 음수)        
}; */



