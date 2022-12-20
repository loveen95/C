
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node
{
    int val;
    struct Node *link;
} Node;  

Node *head = NULL;
Node *tail = NULL; 

void writeFile(); 
void lkdNode(int val);  
void numPrint(); 
void sortNum(int len);
int fileOpen(char *fp); 


void writeFile()
{
    FILE *wrFp; 
    wrFp = fopen("reverseNum.txt", "wt"); 
    Node *reverse = head; 
    while(reverse != NULL)
    {
        
        fprintf(wrFp,"%d", reverse->val); 
        reverse = reverse->link;      
    }
    fclose(wrFp);     
} 

void lkdNode(int val)
{
    Node *NewNode; 
    NewNode = (Node *)malloc(sizeof(Node));
    NewNode->val = val;
    NewNode->link = NULL;  
 
    if (head != NULL)
    { 
        tail->link = NewNode; 
        tail = NewNode; 
    }
    else
    {
        head = NewNode;
        tail = NewNode;     
    }         
} 

void numPrint()
{
    tail = head; 

    while(tail != NULL)
    {
        if(tail->link != NULL)
        {
            printf("REVERSE DATA : %d, ADDR : %p \n", tail->val, &tail->link);
            tail = tail->link; 
        }
        else 
        {
            printf("REVERSE DATA : %d, ADDR : NULL\n", tail->val); 
            break; 
        }
    }
} 


void sortNum(int liLen)
{
    int lsTmp; 
    tail = head;
    for (int i = 0; i < liLen; i++)
    {
        if(tail->link == NULL)
        {
            break;
        }
        for (int j = 0; j < (liLen - 1) - i; j++)
        {
            if (tail->val >= tail->link->val)
            {
                lsTmp = tail->val;
                tail->val = tail->link->val;
                tail->link->val = lsTmp;
            }
            tail = tail->link;
        }
        tail = head; 
    }
} 

int fileOpen(char *fpOpen)
{
    char lsNum[1000];
    int size = 0;
    FILE *fp;
    fp = fopen(fpOpen, "r");

    if (fp == NULL)
    {
        printf("open error"); 
        return -1;
    }

    head = tail = NULL;

    fgets(lsNum, sizeof(lsNum), fp); 

    char *lstxt = strtok(lsNum, " "); 
    while (lstxt != NULL)
    {
        lkdNode(atoi(lstxt));
        lstxt = strtok(NULL, " "); 
        size++;
    }
    fclose(fp); 
    sortNum(size); 
    printf("reverse is completed!!\n"); 
    numPrint(); 
    writeFile(); 

    return 0;
}


int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        if (i == 1)
        {
            fileOpen(argv[1]);
        }
    }
    return 0;
}
