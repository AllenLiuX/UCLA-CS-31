//
//  main.cpp
//  Original
//
//  Created by Allen Liu on 10/5/18.
//  Copyright © 2018 Vincent Liu. All rights reserved.
//

#include <iostream>
using namespace std;   // pp. 38-39 in Savitch 6/e explains this line

int main()
{
    int numberSurveyed;
    int forNewsom;
    int forCox;
    
    cout << "How many registered voters were surveyed? " // Here is a Compile error expecting a ;
    cin >> numberSurveyed;
    cout << "How many of them say they will vote for Newsom? ";
    cin >> forNewsom;
    cout << "How many of them say they will vote for Cox? ";
    cin >> forCox;
    
    double pctNewsom = 100.0 * forNewsom / numberSurveyed;
    double pctCox = 100.0 * forCox / numberSurveyed;
    
    cout.setf(ios::fixed);       // see pp. 32-33 in Savitch 6/e
    cout.precision(1);
    
    cout << endl;
    cout << pctNewsom << "% say they will vote for Newsom." << endl;
    count << pctCox << "% say they will vote for Cox." << endl;  //Here is a compile error with spelling error "count" rather than correct one "cout"
    
    if (forNewsom > forCox)
        cout << "Newsom is predicted to win the election." << endl;
    else
        cout << "Cox is predicted to win the election." << endl;
}
