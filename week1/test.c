#include <stdio.h>
#include <math.h>
int main()
{
    char lcSgn;
    int liNumLft, liNumRgt;
    int liRst;  
    
    while(1)
    {
        printf("<Calculator program>\nex)'1234+5678',(+, -, /, * possibility)\nEnter 0+0 to exit\n>>");
        scanf("%d %c%d",&liNumLft,&lcSgn,&liNumRgt);
         
        if (liNumLft == 0 && lcSgn == '+' && liNumRgt == 0)
        {
            printf("The program exits.\n"); break;
        }
            
        if ((liNumLft <= 100000000 && liNumLft >= 1) && (liNumRgt <= 100000000 && liNumRgt >= 1))
        {
            switch(lcSgn)
            {
            case '+':
            liRst = liNumLft + liNumRgt;
            printf("%d + %d = %d\n", liNumLft,liNumRgt,liRst);
            break;
                    
            case '-':
            liRst = liNumLft - liNumRgt;
            printf("%d - %d = %d\n", liNumLft,liNumRgt,liRst);
            break;
                    
            case '*':
            liRst = liNumLft * liNumRgt;
            printf("%d * %d = %d\n", liNumLft,liNumRgt,liRst);
            break;
                  
            case '/':
            printf("%d / %d = %.2f\n", liNumLft,liNumRgt,(double)liNumLft/liNumRgt);
            break; 
                        
            default:
                printf("This is an operation symbol that cannot be used. Please re-enter\n"); break;
            }
        }else
        {
            while(getchar() != '\n');
            printf("You entered an invalid value.\n"); 
            
        }
    }
    return 0;
}
