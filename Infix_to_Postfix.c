#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct
{
    char a[MAX];
    int top;
}STACK;

int balancedparanthesis(char infix[20])
{
    int i,count=0;
    for(i=0;infix[i]!='\0';i++)
    {
        if(infix[i]=='(')
        {
            count++;
        }
        else if(infix[i]==')')
        {
            count--;
        }
    }
    return count;
}

void push(STACK *p,char ce)
{
    if(isfull(*p))
    {
        printf("Stack overflow..\n");
    }
    else
    {
        p->a[++p->top]=ce;
    }
}

char pop(STACK *p)
{   char temp;
    if(isempty())
    {
        printf("Stack is empty...\n");
    }
    else
    {
        temp=p->a[p->top--];
    }
    return temp;
}

char peek(STACK p)
{
    return(p.a[p.top]);
}

int isfull(STACK p)
{
    if(p.top==MAX-1)
    {
        printf("Stack Overflow...\n");
        return 1;

    }
    else
    {
        return 0;
    }
}

int isempty(STACK p)
{
    if(p.top==-1)
    {
        printf("Stack Underflow...\n");
        return 1;
    }
    else
        return 0;
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

int getprecedence(char a)
{
    switch(a)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
}

void convert(char infix[20], char postfix[20])
{
    char ce,temp;
    int i,j;
    STACK s;

    s.top=-1;
    j=0;

    for(i=0;infix[i]!='\0';i++)
    {
        ce=infix[i];

        if(ce=='(')
        {
            push(&s,ce);
        }
        else if(isoperand(ce)==1)
        {
            postfix[j++]=ce;
        }
        else if(isoperator(ce)==1 && s.top==-1)
        {
            push(&s,ce);
        }
        else if(isoperator(ce)==1)
        {
            int p1,p2;
            p1=getprecedence(ce);
            p2=getprecedence(peek(s));
            if(p1<=p2 && p2!='(')
            {
                while(p1<=p2 && p2!='(')
                {
                    temp=pop(&s);
                    postfix[j++]=temp;
                    p2=getprecedence(peek(s));
                }
                push(&s,ce);
            }
            else
            {
                push(&s,ce);
            }
        }
        else if(ce==')')
        {
            do
            {
                temp=pop(&s);
                if(temp!='(')
                {
                    postfix[j++]=temp;
                }
                else
                    break;
            }while(1);
        }
        else
        {
            printf("Invalid operator...%c",ce);
            exit(0);
        }
    }

    for(i=s.top;i>=0;i--)
    {
        temp=pop(&s);
        if(temp!='(')
        {
            postfix[j++]=temp;
        }
    }
    postfix[j]='\0';
}

int main()
{
    char infix[20],postfix[20];
    printf("Enter the infix= ");
    scanf("%s",infix);

    if(balancedparanthesis(infix)!=0)
    {
        printf("Unbalanced paranthesis...\n");
        exit(0);
    }

    convert(infix,postfix);

    printf("Postfix= %s",postfix);
}
