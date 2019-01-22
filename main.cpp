#include <stdio.h>  //gets - bufor na znaki
#include <iostream>
#include <fstream> //obsluga strumieni plikow
#include "header.hpp"
using namespace std;

int main()
{
    cout<<"o-----------------------------------o\n| Author: Jagodzinski Wojciech      |\n| Index: 426145                     |\n| Project: Infix Calculator         |\no-----------------------------------o\n";
//----------
    double result=0;
    char infix[1000];
    fstream plik;
    plik.open("equation.txt", ios::out|ios::app);//otwarcie pliku, dane sa dopisywane
//----------przyklady (((((4-2)*2)-1)*4)/6)^5=    (1212-335)^2+125*1156/23+(12-45)=   (87+93)*(41-62)^2/6=  (8+9)*(4-6)^4=
    cout<<"Type in your equation (e.g. '((87+93)*(41-62)^2)/6=' ) \nDont forget to finish it with '=' symbol \n>>";
    gets(infix);
    plik<<infix<<endl;
    result=InfixToPostfix(infix);
    cout<<"\nThe result is "<<result<<"\n";
    plik<<result<<endl<<endl;
    plik.close();

    return 0;
}

