#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 20

typedef struct
{
    char a[MAX];
    int top;
}STACK;

void push(STACK *p,float ce)
{
        p->a[++p->top]=ce;
}

float pop(STACK *p)
{   float temp;
        temp=p->a[p->top--];
    return temp;
}

int isoperand(char a)
{
    if((a>=97 && a<=122) || (a>=65 && a<=90))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isoperator(char a)
{
    switch(a)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
        return 1;
    default:
        return 0;
    }
}

float evaluate(char postfix[20])
{
    char ce;
    int i;
    float result,var1,var2,var;
    STACK s;

    s.top=-1;

    for(i=0;postfix[i]!='\0';i++)
    {
        ce=postfix[i];

        if(isoperand(ce)==1)
        {
            printf("Enter value for %c=",ce);
            scanf("%f",&var);
            push(&s,var);
        }

        else if(isoperator(ce)==1)
        {
            var2=pop(&s);
            var1=pop(&s);
            switch(ce)
            {
               case '+':
                   result=var1+var2;
                   break;
               case '-':
                   result=var1-var2;
                   break;
               case '*':
                   result=var1*var2;
                   break;
               case '/':
                   result=var1/var2;
                   break;
               case '^':
                   result=pow(var1,var2);
                   break;
            }
            push(&s,result);
        }
    }
    result=pop(&s);
    return result;
}

int main()
{
    char postfix[20];
    float result;

    printf("Enter the postfix= ");
    scanf("%s",postfix);

    result=evaluate(postfix);

    printf("Result= %f\n",result);
}

