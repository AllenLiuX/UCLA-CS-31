//
//  main.cpp
//  CS31 Note
//
//  Created by Allen Liu on 11/7/18.
//  Copyright © 2018 Vincent Liu. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

//const int NWEEKS = 5;
//const int NDAYS = 7;
//int atendance[NWEEKS][NDAYS];
//const string dayName[NDAYS] = {"Monday", "Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
//int grandTotal = 0;
//
//double meanForADay (const int a[][NWEEKS], int nRows, int dayNumber){
//    if (nRows <=0)
//        return 0;
//    int total = 0;
//    for (int r =0; r <nRows; r++)
//        total += a[r][dayNumber];
//    return static_cast<double>(total) /nRows;
//}

void makeUpperCase(string& s)
{
    for (int k = 0; k != s.size(); k++)
        s[k] = toupper(s[k]);
         
}

void makeUpperCase1(char s[])
{
    for (int k = 0; s[k] != '\0'; k++)
        s[k] = toupper(s[k]);
}

const int MAX_WORD_LENGTH = 6;
int countLength(const char a[][MAX_WORD_LENGTH+1], int n, int targetLength);

//
//int main() {
//    string s;
//    char x[5][3];
//    cout<<"input: ";
//    getline(cin, s);
//    makeUpperCase(s);
//    cout<<s<<endl;
//    cout <<"again: ";
//    int i =0;
//    while (i < 4){
//        cin>>x[i];
//        i++;
//    }
//    cout << x[1];
//
//
//    const int MAX_PETS = 5;
//    char pets[MAX_PETS][MAX_WORD_LENGTH+1] = {"cat","mouse","eel","feeret","horse"};    //string pets[MAX_PETS] = {
//
//    cout<<countLength(pets, MAX_PETS, 5);
//
//
////    int attendance[NWEEKS][NDAYS];
////    for (int d = 4/* Friday */; d < NDAYS; d++)
////    {
////        int t =0;
////        for (int w = 0; w<NWEEKS; w++)
////            t += attendance[w][d];
////        cout << "The total for week " << w << " is " << t <<endl;
////        grandTotal += t;
////    }
////    cout << "Over the course of " << NWEEKS<<" weeks, weekend attendance was "<<grandTotal <<endl;
//
//
//
//}
//
//
//int countLength(const char a[][MAX_WORD_LENGTH+1], int n, int targetLength){
//    int total = 0;
//    for (int k = 0; k < n; k++)
//    {
//        if (strlen(a[k]) == targetLength)
//            total++;
//    }
//    return total;
//
//}
//
////C++ String:
//int countLength2(const string a[], int n, int targetLength){
//    int total = 0;
//    for (int k = 0; k < n; k++)
//    {
//        if (a[k].size() == targetLength)
//            total++;
//    }
//    return total;
//
//}


void polarToCartesian (double rho, double theta, double& xx, double& yy);

int main(){
//    double r;
//    double angle;
//    //get values for r and angle
//    double x;
//    double y;
//    polarToCartesian(r, angle, x, y);
//    //...
//    double y2;
//    polarToCartesian(2*r, angle, x, y2);
//
//}
//
//void polarToCartesian (double rho, double theta, double& xx, double& yy){
//    xx = rho * cos(theta);
//    yy = rho * sin(theta);
//
    double a = 3.2;
    double b = 5.1;
    double* p = &a;
    //double* q = 7.6; doesn't work
    double c = a;
    //double d = p; doesn't work
    double d = *p;  //follow the pointer p
    *p += 4;
    cout <<d<<endl;
    cout <<&d<<endl;
    cout <<* &d<<endl;
    cout <<a<<endl;
    
    
    double& dd = d; //no pointer involved here
    d=1;
    cout <<dd<<endl;
    
    double* q;
    //*q = 4.7;     undefined behavior! q is uninitialized
    q = p;
    double* r = &a;
    *r = b;
    if (p == r)     //false -- comparing pointers   ???
        cout<<"Hello!";
    if (p ==q)      //true -- comparing pointers
        cout<<"World!";
    if(*p == *q)        //true -- compareing doubles
        cout;
    const int MAXSIZE = 5;
    double da[MAXSIZE];
    int k;
    double* dp;
    
    for (k = 0; k < MAXSIZE; k++)
        da[k] = 3.6;
    
    for (dp = da; dp <da + MAXSIZE; dp++)
        *dp = 3.6;
    
    int e[5] = {1,2,3,4,5};
    cout<<endl<<&e[1]<<endl;
    
    int f = &e[2] - &e[0];
    cout<<f;

    
}

//POINTER

double a = 3.2;
double b = 5.1;
double* p = &a;
    //double* q = 7.6; doesn't work
double c = a;
    //double d = p; doesn't work
double d = *p;  //follow the pointer p
double& dd = d; //no pointer involved here

//*p = b;  //assigning one double to another √
//p = &b; // Assigning one pointer to another √
//*p += 4;

int k = 7;
//p = &k; //can't, because int address can't be assigned to double address

//a == *&a; √
//cout << (k * p); //doesn't work
//cout << (k * *p); √
//cout << (*z**p); √
//cout << (*z * *p) √

double* q;
    //*q = 4.7;     undefined behavior! q is uninitialized
//q = p;
//double* r = &a;
//*r = b;
//if (p == r)     //false -- comparing pointers
    //cout<<"Hello!";


