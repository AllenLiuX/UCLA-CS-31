//
//  main.cpp
//  Homework6_Project
//
//  Created by Allen Liu on 11/20/18.
//  Copyright © 2018 Vincent Liu. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;


void removeS(char* ptr){
    while(*ptr != 0){
        if(*ptr == 's' || *ptr == 'S'){
            for(int i=0; *(ptr+i) != 0; i++)
                *(ptr+i) = *(ptr+i+1);
        }
        else
            ptr++;
    }
    
}


int main()
{
    char msg[50] = "She'll be a massless princess.";
    removeS(msg);
    cout << msg;  // prints   he'll be a male prince.
}

