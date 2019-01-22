#include "header.hpp"
#include <iostream>
#include <string.h>//strlen - dlugosc ciagu char, ciag jest zakonczony '\0'
#include <stack>
#include <stdlib.h>  //atoi - zamiana znakow na liczby
using namespace std;
int priority(char symbol)
{
    switch(symbol)
    {
    case '+' : return 1;
    case '-' : return 1;
    case '*' : return 2;
    case '/' : return 2;
    case '^' : return 3;
    }
    return 0;
}
bool If_Operator(char symbol)  //sprawdzenie czy postfix[i] jest operatorem
{
    if(symbol=='+' || symbol=='-' || symbol=='*' || symbol=='/' || symbol=='^')
        return true;
    else
        return false;
}
int Power(int num1, int num2) //funkcja potegi
{
    if(num2<=0)
        return 1;
    return num1 * Power(num1, num2-1);
}
double Do_Operation(double num1, double num2, char op) //wykonanie operacji liczbowych
{
    double result=0;
    switch(op)
    {
    case '+' : result = num2 + num1;
               break;
    case '-' : result = num2 - num1;
               break;
    case '*' : result = num2 * num1;break;
    case '/' : if(num1!=0)
                result = num2 / num1;
               break;
    case '^' : result = Power(num2,num1);
    }
    return result;
}
double InfixToPostfix(char * infix)
{
    int i=0, j=0, p=0;
    char symbols[1000],postfix[1000];
    while(true)
    {
        if(infix[i] == '=')
        {
            while(p)
            {
            postfix[j++]=' ';
            postfix[j++]=symbols[--p];
            }
            break;
        }

        switch(infix[i])
        {
        case ' ' : break;
        case '(' : symbols[p++] = '(';
                   break;
        case ')' : postfix[j++]=' ';
                   while(symbols[p-1] != '(')
                   {
                    postfix[j++]=symbols[--p];
                   }
                   p--;
                   break;
        case '+' :;
        case '-' :;
        case '*' :;
        case '/' :;
        case '^' :
            postfix[j++]=' '; //rozdzielanie znakow
            while(p)
            {
                if((priority(infix[i])==3) || (priority(infix[i])>priority(symbols[p - 1]))) //priorytety operatorow
                    break;
                postfix[j++]=symbols[--p];
            }
            symbols[p++]=infix[i];
            break;
        default : postfix[j]=infix[i];
                  j++;
                  break;
        }
    i++;
    }
    char buffer[15];
    int len, x;
    double num1, num2;
    j = 0;
    stack<double> S;
    len = strlen(postfix);

        for(int i=0; i<len; i++)
        {
            if(postfix[i]>='0' && postfix[i]<='9')
            {
                buffer[j++] = postfix[i];
            }
            else if(postfix[i]==' ')
            {
                if(j>0)
                {
                    buffer[j] = '\0';
                    x = atoi(buffer);
                    S.push(x);
                    j = 0;
                }
            }
            else if(If_Operator(postfix[i]))
            {
                num1 = S.top();
                S.pop();
                num2 = S.top();
                S.pop();
                S.push(Do_Operation(num1, num2, postfix[i]));
            }
        }
    return S.top();
}
