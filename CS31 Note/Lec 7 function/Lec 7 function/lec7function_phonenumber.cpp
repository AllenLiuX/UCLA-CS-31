//
//  main.cpp
//  Lec 7 function
//
//  Created by Allen Liu on 10/22/18.
//  Copyright © 2018 Vincent Liu. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
using namespace std;



bool isValidPhoneNumber(string pn)
{
    int numberOfDigits = 0;
    for (int k=0; k != pn.size(); k++)
    {
        if (isdigit(pn[k]))
            numberOfDigits ++;
    }
    return (numberOfDigits == 10);
}

string digitsOf(string pn)
{
    string digits = "";
    for (int k=0; k != pn.size(); k++)
    {
        if (isdigit(pn[k]))
            digits = digits + pn[k];
    }
    return digits;
}

int main() {
//    cout<<"Enter a phone number: ";
//    string phone;
//    getline(cin, phone);
//    while ( ! isValidPhoneNumber(phone))
//    {
//        cout<<"A phone number must have 10 digits"<<endl;
//        cout<<"Enter a phone number: ";
//        getline(cin, phone);
//    }
//    cout<<"The digits in the number are "<< digitsOf(phone)<<endl;
//  ===>
 
    string phone;
    while (true) // equals to "for ( ; true; );" or "for (;;);"
    {
        cout<<"Enter a phone number: ";
        getline(cin, phone);
        if (isValidPhoneNumber(phone))
            break;
        cout<<"A phone number must have 10 digits, try again."<<endl;
    }
    cout<<"The digits in the number are "<< digitsOf(phone)<<endl;

}
