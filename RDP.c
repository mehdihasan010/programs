/*
recursive descent parser grammar:

E –> T E’
E’ –> + T E’ | e
T –> F T’
T’ –> * F T’ | e
F –> ( E ) | a

*/

#include<stdio.h>
#include<string.h>

#define SUCCESS 1
#define FAILED 0

int E(),Edash(),T(),Tdash(),F();

const char *p;
char str[100];

int main()
{
    printf("Enter Your Input:");
    gets(str);
    p = str;
    if(E() && *p=='\0')
    {
        printf("String is accepted");
    }
    else
    {
        printf("String is not accepted");
    }
    return 0;
}

int E()
{

    if(T())
    {
        if(Edash())
        {
            return SUCCESS;
        }
        else
        {
            return FAILED;
        }
    }
    else
    {
        return FAILED;
    }

}

int Edash()
{

    if(*p=='+')
    {
        p++;
        if(T())
        {
            if(Edash())
            {
                return SUCCESS;
            }
            else
            {
                return FAILED;
            }
        }
        else
        {
            return FAILED;
        }
    }
    else
    {
        return SUCCESS;
    }
}

int T()
{
    if(F())
    {
        if(Tdash())
        {
            return SUCCESS;
        }
        else
        {
            return FAILED;
        }
    }
    else
    {
        return FAILED;
    }
}

int Tdash()
{
    if(*p=='*')
    {
        p++;
        if(F())
        {
            if(Tdash())
            {
                return SUCCESS;
            }
            else
            {
                return FAILED;
            }
        }
        else
        {
            return FAILED;
        }
    }
    else
    {
        return SUCCESS;
    }
}

int F()
{
    if(*p=='(')
    {
        p++;
        if(E())
        {
            if(*p==')')
            {
                p++;
                return SUCCESS;
            }
            else
            {
                return FAILED;
            }
        }
        else
        {
            return FAILED;
        }
    }
    else if(*p=='a')
    {
        p++;
        return SUCCESS;
    }
    else
    {
        return FAILED;
    }
}


