
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
void addNum(int len); 
void sortNum(int len);
int fileOpen(char *fp); 


void writeFile()
{
    FILE *wrFp; 
    wrFp = fopen("sortingNumFinal.txt", "wt"); 
    Node *newNum = head; 
    while(newNum != NULL)
    {
        
        fprintf(wrFp,"%d ", newNum->val); 
        newNum = newNum->link;      
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
            printf("DATA : %d, ADDR : %p \n", tail->val, &tail->link);
            tail = tail->link; 
        }
        else 
        {
            printf("DATA : %d, ADDR : NULL\n", tail->val); 
            break; 
        }
    }
} 

void addNum(int liLen)
{
    char lsAddNum[2000];
    int k = liLen;
    
    while (1)
    {
        printf("number input (Q-Quit): ");
        scanf("%[^\n]s", lsAddNum);
        getchar(); 
        if (strcmp(lsAddNum,"Q") == 0 || strcmp(lsAddNum,"q") == 0)
        {
            return; 
        }

        for (int i = 0; i < strlen(lsAddNum); i++)
        {
            if(isdigit(lsAddNum[i]) == 0)
            {
                printf("input error");
            }
        }
        
        lkdNode(atoi(lsAddNum)); 
        k++; 
        sortNum(k); 
        numPrint(); 
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
            if (tail->val <= tail->link->val)
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
    printf("Sorting is completed!!\n"); 
    numPrint(); 
    addNum(size);
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
