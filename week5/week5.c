// question 1
int memoryCompare(char* n1, char* n2, int num)
{
    int i = 0; 
    int cnt = 0; 
    while(n1[i] != '\0' || n2[i] != '\0') // n1, n2가 '\0'이 아닌동안 반복한다.
    {
        for(int i = 0; i < num; i++)
        {
           if(n1[i] != n2[i])
            {
                cnt++;
            }
            else 
            {
                continue;  
            } 
        }
        return cnt;
    }

    return 0; 
} 

void stringCopy(char* n1, char* n2) // n1의 문자열을 n2의 문자열에 복사하기 
{
    int i = 0; 
    while(n1[i] != '\0')
    {
        n2[i] = n1[i];
        i++;
    }    
    printf("result : %s", n2);  
}

void stringNumCopy(char* n1, char* n2, unsigned int num)
{
    unsigned int i = 0; 
    int liLen;
    
    while(i < num) 
    {
        n2[i] = n1[i];
        ++i;
    }
    
    for (liLen = 0; n1[liLen]; liLen++);
    
    if (liLen < num) // n1의 길이 < n2의 길이 =  error 처리 
    {
        printf("You cannot enter a number longer than the length of inputA.");
    }
    else 
    {
        printf("result : %s ", n2); 
    }
}

int stringLength(char* str) // 문자열 길이 반환 함수 
{
    int liLen;
    for (liLen = 0; str[liLen]; liLen++);
    
    return liLen; 

}

//  int main() {
//     char inputA[50]; 
//     char inputB[50];
//     printf("inputA : ");
//     gets(inputA); 
//     printf("inputB : ");
//     gets(inputB); 
//     int num; 
//     printf("num : ");
//     scanf("%d", &num);
    
//     //stringCopy(inputA, inputB);
//     // printf("%d",stringLength(inputA));  
//     // printf("%d", memoryCompare(inputA, inputB, num)); 
//     // stringNumCopy(inputA, inputB, num); 

//     return 0;
//  }


