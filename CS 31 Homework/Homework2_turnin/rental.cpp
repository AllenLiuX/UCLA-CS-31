//
//  main.cpp
//  Rental
//
//  Created by Allen Liu on 10/10/18.
//  Copyright © 2018 Vincent Liu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
   
    cout <<"Odometer at start: ";
    int odometerStart;
    cin >> odometerStart;
    
    if (odometerStart < 0)
    {
        cout <<"---"<<endl;
        cout <<"The starting odometer reading must be nonnegative.";
        return 0;
    }
    
    
    cout <<"Odometer at end: ";
    int odometerEnd;
    cin >> odometerEnd;
    
    int distance = odometerEnd - odometerStart;
    if (distance < 0)
    {
        cout <<"---"<<endl;
        cout <<"The final odometer reading must be at least as large as the starting reading.";
        return 0;
    }
    
    cout <<"Rental days: ";
    int day;
    cin >> day;
    if (day <= 0)
    {
        cout <<"---"<<endl;
        cout <<"The number of rental days must be positive.";
        return 0;
    }
    
    cin.ignore(10000, '\n');
    
    cout <<"Customer name: ";
    string personName;
    getline(cin, personName);
    if (personName == "")
    {
        cout <<"---"<<endl;
        cout <<"You must enter a customer name.";
        return 0;
    }
    
    
    cout <<"Luxury car? (y/n): ";
    string luxury;
    cin >> luxury;
    if (luxury != "y" && luxury != "n")
    {
        cout <<"---"<<endl;
        cout <<"You must enter y or n.";
        return 0;
    }
    
    cout <<"Month (1=Jan, 2=Feb, etc.): ";
    int month;
    cin >> month;
    if(month > 12 || month < 1)
    {
        cout <<"---"<<endl;
        cout<<"The month number must be in the range 1 through 12.";
        return 0;
    }
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    double totalCharge = 0;
    
    if(luxury == "y")
        totalCharge = 61 * day;
    else
        totalCharge = 33 * day;
    
    if (distance <= 100)
    totalCharge = totalCharge + 0.27 * distance;
    
    else if (distance <= 400)
    {
        
        if (month == 12 || month <= 3)
            totalCharge = totalCharge + 27 + (distance-100) * 0.27;

        else
            totalCharge = totalCharge + 27 + (distance-100) * 0.21;
        
    }
    else if (distance > 400)
    {
        if (month == 12 || month <= 3)
            totalCharge = totalCharge + 27 + 300 * 0.27 + (distance-400) * 0.19;
        else
            totalCharge = totalCharge + 27 + 300 * 0.21 + (distance-400) * 0.19;
    }
    cout <<"---" << endl;
    cout <<"The rental charge for "<< personName <<" is $"<< totalCharge<<endl;
    return 0;
}

