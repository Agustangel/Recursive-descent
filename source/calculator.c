#include <stdio.h>
#include "calculator.h"
#include "debug.h"


char* S = NULL;
//=========================================================================
int getG(char* str)
{
    S = str;

    int val = getE();
    CHECK(*S == '\0', ERROR);

    return val;
}

//-------------------------------------------------------------------

int getN()
{
    int val = 0;
    char* sOld = S;

    while((*S >= '0') && (*S <= '9'))
    {
        val = (val * 10) + (*S - '0');
        ++S;
    }
    CHECK(S > sOld, ERROR);

    return val;
}

//-------------------------------------------------------------------

int getE()
{
    int val = getT();

    while((*S == '+') || (*S == '-'))
    {
        char op = *S;
        ++S;

        int val_2 = getT();
        if(op == '+')
        {
            val += val_2;
        }
        else
        {
            val -= val_2;
        }
    }

    return val;
}

//-------------------------------------------------------------------

int getT()
{
    int val = getP();

    while((*S == '*') || (*S == '/'))
    {
        char op = *S;
        ++S;

        int val_2 = getP();
        if(op == '*')
        {
            val *= val_2;
        }
        else
        {
            val /= val_2;
        }
    }

    return val;    
}

//-------------------------------------------------------------------

int getP()
{
    int val = 0;
    if(*S == '(')
    {
        ++S;
        val = getE();
        CHECK(*S == ')', ERROR);
        ++S;
    }
    else
    {
        val = getN();
    }

    return val;
}

//-------------------------------------------------------------------
