//
//  main.cpp
//  CS Review
//
//  Created by Allen Liu on 11/14/18.
//  Copyright © 2018 Vincent Liu. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

bool insert(char str[], int max, int ind, char c);
void strcat1(char str1[], char str2[]);
void eraseChar(char str[], char c);
void eraseDuplicates(char str[]);

int main() {
//    string name, major, hall;
//    cout << "Enter your name: ";
//    getline( cin, name );
//    cout << "Enter your UID: ";
//    int UID;
//    cin >> UID ;
//
//    cout << "Enter your Major: ";
//
//    getline(cin, major);
//    cout << "Enter your residence hall: ";
//    getline( cin , hall );
//    cout<<name<<endl<<UID<<endl<<major<<endl<<hall<<endl;
//
//    int a = 10;
//    int b = 22;
//    while (a / 2 >= 1) {
//        a--;
//        cout << a << endl;
//        if ((a + b) % 2 == 0) {
//             a--;
//             cout<< a << endl;
//            b /= 2;
//
//        }
//
//    }
    
    
    //#1    sum of digits
//    int number;
//    int sum = 0;
//    cout<<"Enter a number: ";
//    cin>>number;
//    string number1 = to_string(number);
//    for(int i = 0; i != number1.size(); i++)
//    {
//        sum += number1[i] - '0';
//    }
//    cout<< "sum is: "<<sum;
//
    //#5 print number matrix
//    int n;
//    cout << "Enter a positive integer: ";
//    cin >> n;
//    for (int i =0; i< n; i++)
//    {
//        for(int j =0; j<n; j++)
//        {
//            if(i>=j)
//                cout<<i+j<<" ";
//            else
//                cout<<"."<<" ";
//        }
//        cout<<endl;
//    }
    
    //#6 perfect number
//    int perfect;
//    cout << "Enter a number: ";
//    cin >> perfect;
//    int sum = 0;
//    for(int i=1; i<perfect; i++)
//    {
//        if(perfect % i == 0)
//            sum += i;
//    }
//    if (perfect == sum)
//        cout<<"Perfect number!";
//    else
//        cout<<"Not perfect.";
//
    //#7 cout factors
    
//    int perfect;
//    cout << "Enter a number: ";
//    cin >> perfect;
//    cout<<1;
//    for(int i=2; i<perfect+1; i++)
//    {
//        if(perfect % i == 0)
//            cout<<","<<i;
//    }
    
    //#8 count power number of 2
//    int number;
//    cout << "Enter a number: ";
//    cin >> number;
//    if (number < 1) {
//        cout << "error" << endl;
//        return 1; }
//    int pow = 0;
//    int powOf2 = 1;
//    while(powOf2<number){
//
//        powOf2 *= 2;
//        pow++;
//
//    }
//    cout<<pow-1;
//
    
    //#3 cstring add
//    char str1[20] = "Hello";
//    char str2[8] = " World!";
//    strcat1(str1, str2);
//    cout<<strlen(str1);
//    cout<<str1;
//
    //#1
//    char test[20] = "aaaaaaa";
//    bool res = insert(test, 20, 1, 'b');
//    cout<< test<<endl;
//
//    strcpy(test, "abcdefghijklmnopqrs");
//    res = insert(test, 20, 10, 'X');
//    cout<< test<<res<<endl;
//    if("\0")
//        cout<<"Hello";
//    int x = 'x';
//    cout<<x;

    //#2
//    char test[9] = "acacsdfa";
//    eraseChar(test, 'c');
//    cout<<test;
    
    char test[50] = "memesformeforfree123";
    eraseDuplicates(test);
    cout<<test;
}


void eraseOneChar(char str[], int index) {
    for (int i = index; str[i] != '\0'; i++)
        str[i] = str[i + 1];
}

void eraseDuplicates(char str[]){
    int i =1;
    bool unique = true;
    while (str[i] != '\0'){
        for(int k=0; k<i;k++){
            if (str[k] == str[i]){
                eraseOneChar(str, i);
                unique = false;
                break;
            }
        }
        if(unique)
            i++;
        unique = true;
    }
}
//void eraseDuplicates(char str[]) {
//    bool sawCharacter[256] = {false};
//    int i = 0;
//    while (str[i] != '\0') {
//        if (sawCharacter[str[i]])
//            eraseOneChar(str, i);
//        else {
//            sawCharacter[str[i]] = true;
//            i++;
//        }
//    }
//}

//#2
void eraseChar(char str[], char c){
    long length = strlen(str);
    int i =0;
    while (i<length)
    {
        if (str[i] == c)
        {
            for (int k=0;k<length-i;k++)
                str[i+k]=str[i+k+1];
        }
        else
            i++;
    }
}

bool insert(char str[], int max, int ind, char c){
    if(str[max] == '\0')
        return false;
    for (int i = max; i>ind; i--)
    {
        str[i+1] = str[i];
    }
    str[ind] = c;
    return true;
}

void strcat1(char str1[], char str2[]){
    long length = strlen(str1);
    long length2 = strlen(str2);
    for (int i=0; i<length2; i++)
        str1[length+i] = str2[i];
}
