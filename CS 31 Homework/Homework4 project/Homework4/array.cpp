//
//  main.cpp
//  Homework4
//
//  Created by Allen Liu on 11/1/18.
//  Copyright © 2018 Vincent Liu. All rights reserved.
//

#include <iostream>
#include <string>
#include <cassert>
#include <cstring>
using namespace std;

//#1 Append value to the end of each of the n elements of the array and return n.
int appendToAll(string a[], int n, string value){
    if (n < 0)
        return -1;  // exclude the situation that code will run out.
    for (int i = 0; i < n; i++)
    {
        a[i] += value;
    }
    return n;
}

//#2 Return the position of a string in the array that is equal to target; if there is more than one such string, return the smallest position number of such a matching string. Return −1 if there is no such string. As noted above, case matters: Do not consider "GReg" to be equal to "gReG".
int lookup(const string a[], int n, string target){
    for (int i = 0; i < n; i++)
    {
        if (a[i] == target)
            return i;
    }
    return -1;

}

//#3 Return the position of a string in the array such that that string is >= every string in the array. If there is more than one such string, return the smallest position number of such a string. Return −1 if the array has no interesting elements.
int positionOfMax(const string a[], int n){
    int c = 0;
    if (n <= 0) return -1;
    string b = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > b)
        {
            b = a[i];
            c = i;
        }
    }
    return c;
}

//#4 Eliminate the item at position pos by copying all elements after it one place to the left. Put the item that was thus eliminated into the last position of the array. Return the original position of the item that was moved to the end.
int rotateLeft(string a[], int n, int pos){
    if (n <= 0 || pos < 0 || pos >= n)
        return -1;
    string b = a[pos];
    for (int i = pos; i < n-1; i++)
    {
        a[i] = a[i+1];
    }
    a[n-1] = b;

    return pos;
}

//#5 Return the number of sequences of one or more consecutive identical items in a.
int countRuns(const string a[], int n){
    if (n < 0)
        return -1;  // exclude the situation that code will run out.
    if (n == 0)
        return 0;
    int x = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i-1])
            x++;
    }
    return x;
}

//#6 Reverse the order of the elements of the array and return n.
int flip(string a[], int n){
    if (n < 0)
        return -1;  
    string b = "";
    for (int i = 0; i < n/2; i++)
    {
        b = a[i];
        a[i] = a[n-i-1];
        a[n-i-1] = b;
    }
    
    return n;
}

//#7 Return the position of the first corresponding elements of a1 and a2 that are not equal. n1 is the number of interesting elements in a1, and n2 is the number of interesting elements in a2. If the arrays are equal up to the point where one or both runs out, return whichever value of n1 and n2 is less than or equal to the other.
int differ(const string a1[], int n1, const string a2[], int n2){
    if (n1 < 0 || n2 < 0)
        return -1;
    int x;
    if (n1 < n2)
        x = n1;
    else x = n2;
    for (int i = 0; i < x; i++)
    {
        if (a1[i] != a2[i])
            return i;
    }
    return x;
}

//#8 If all n2 elements of a2 appear in a1, consecutively and in the same order, then return the position in a1 where that subsequence begins. If the subsequence appears more than once in a1, return the smallest such beginning position in the array. Return −1 if a1 does not contain a2 as a contiguous subsequence. (Consider a sequence of 0 elements to be a subsequence of any sequence, even one with no elements, starting at position 0.)
int subsequence(const string a1[], int n1, const string a2[], int n2){
    bool c = false;
    if ( n1 < 0 || n2 < 0 || n1 < n2)
        return -1;
    if ( n2 == 0)
        return 0;
    for (int i = 0; i < n1; i++)
    {
        if (a2[0] == a1[i])
        {
            c = true;   //temporarily set c true when there's char in a1 equals to the first char of a2
            for (int k = 0; k < n2 && i+k < n1; k++)
                if (a2[k] != a1[i+k])
                    c = false;  //c is false when a2 is not the same as a1
        }
        if (c)
            return i;
    }
    return -1;
}

//#9 Return the smallest position in a1 of an element that is equal to any of the n2 elements in a2. Return −1 if no element of a1 is equal to any element of a2.
int lookupAny(const string a1[], int n1, const string a2[], int n2){
    for (int i = 0; i < n1; i++)
    {
        for (int k=0; k< n2; k++)
        {
            if (a2[k] == a1[i])
                return i;
        }
    }
    return -1;
}

//#10 Rearrange the elements of the array so that all the elements whose value is < divider come before all the other elements, and all the elements whose value is > divider come after all the other elements. Return the position of the first element that, after the rearrangement, is not < divider, or n if there are no such elements.
int divide(string a[], int n, string divider){
    if (n <= 0)
        return -1;
    string b = "";
    string c = "";
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= divider)
        {
            for (int k = i+1; k < n; k++)
            {
                if (a[k] < divider)
                {
                    b = a[i];
                    a[i] = a[k];
                    a[k] = b;
                }
            }
        }
    }
    //put the str bigger or equal to divide to the end.
    
    for (int j = 0; j < n; j++)
    {
        if (a[j] >= divider)
        {
            x = j;
            break;
        }
    }
    //find the position of devider.
    for (int z = x; z < n; z++)
    {
        if (a[z] == divider)
        {
            for (int p = 0; p < z; p++)
            {
                if (a[p] > divider)
                {
                    c = a[z];
                    a[z] = a[p];
                    a[p] = c;
                }
            }
        }
    }
    //put all the elements equal to devider before the ones greater than devider
        
    
    return x;
}

int main() {
//  #1
//    string people[5] = { "dianne", "fiona", "ed", "xavier", "greg" };
//    int j = appendToAll(people, 3, "!!!");  // returns 5
//    for(int i = 0; i != 5; i++)
//        cout<<people[i]<<endl;
//
    
//  #3
//    string candidate[6] = { "dianne", "fiona", "gavin", "xavier", "ed", "betty" };
//    int k = positionOfMax(candidate, 6);
//    cout<<k<<endl;
//  #4
//    string politician[5] = { "eleni", "dianne", "fiona", "kevin", "gavin" };
//    int m = rotateLeft(politician, 5, 1);
//    for(int i = 0; i != 5; i++)
//            cout<<politician[i]<<endl;

//   #5
//    string d[9] = {
//        "xavier", "betty", "john", "john", "ed", "ed", "ed", "john", "john"
//    };
//    int p = countRuns(d, 9);
//    cout<<p;
    
//   #6
//    string folks[6] = { "betty", "john", "", "xavier", "kevin", "dianne" };
//    int q = flip(folks, 4);
//    for (int k = 0; k < 6; k++)
//        cout<<folks[k]<<endl;
    
    //#7
    
//    string folks[6] = { "betty", "john", "", "xavier", "kevin", "dianne" };
//    string group[5] = { "betty", "john", "dianne", "", "xavier" };
//    int r = differ(folks, 6, group, 5);  //  returns 2
//    int s = differ(folks, 2, group, 1);
//    cout<<r<<endl<<s<<endl;

    // #8
//    string names[10] = { "eleni", "gavin", "kevin", "greg", "betty", "fiona" };
//    string names1[10] = { "gavin", "kevin", "greg" };
//    int t = subsequence(names, 6, names1, 3);  // returns 1
//    string names2[10] = { "eleni", "greg" };
//    int u = subsequence(names, 5, names2, 2);  // returns -1
//    cout<<t<<endl<<u<<endl;
    
    //#9
//    string names[10] = { "eleni", "gavin", "kevin", "greg", "betty", "fiona" };
//    string set1[10] = { "dianne", "betty", "greg", "gavin" };
//    int v = lookupAny(names, 6, set1, 4);  // returns 1 (a1 has "gavin" there)
//    string set2[10] = { "xavier", "ed" };
//    int w = lookupAny(names, 6, set2, 2);  // returns -1 (a1 has none)
//    cout<<v<<endl<<w<<endl;
    
    //#10
//    string candidate[6] = { "dianne", "fiona", "gavin", "xavier", "ed", "betty" };
//    int x = divide(candidate, 6, "!");
//    for (int k = 0; k < 6; k++)
//        cout<<candidate[k]<<endl;
//    cout<<x<<endl;
//
//    string candidate2[4] = { "gavin", "kevin", "fiona", "john" };
//    int y = divide(candidate2, 4, "john");
//    for (int z = 0; z < 4; z++)
//        cout<<candidate2[z]<<endl;
//    cout<<y;
    
    string a[7] = { "greg", "gavin", "ed", "xavier", "john", "eleni", "fiona" };
    string space[5] = {" ", "dianne", " ", "gavin", "john"};
    string null[0] = {};
    const string const1[5] = {"gavin", "ed", "xavier", "john", "eleni"};
    string double1[4] = { "greg", "gavin", "ed", "greg"};
    
//    flip(a, 4);
//    string q = a[0];
//    assert(q == "xavier");
    flip(a, 5);
    string q = a[1];
    assert(q == "xavier");
    
    string h[7] = { "greg", "gavin", "ed", "xavier", "", "eleni", "fiona" };
    assert(lookup(h, 7, "eleni") == 5);
    assert(lookup(h, 7, "ed") == 2);
    assert(lookup(h, 2, "ed") == -1);
    assert(positionOfMax(h, 7) == 3);
    
    string g[4] = { "greg", "gavin", "fiona", "kevin" };
    assert(differ(h, 4, g, 4) == 2);
    assert(appendToAll(g, 4, "?") == 4 && g[0] == "greg?" && g[3] == "kevin?");
    assert(rotateLeft(g, 4, 1) == 1 && g[1] == "fiona?" && g[3] == "gavin?");
    
    string e[4] = { "ed", "xavier", "", "eleni" };
    assert(subsequence(h, 7, e, 4) == 2);
    
    string d[5] = { "gavin", "gavin", "gavin", "xavier", "xavier" };
    assert(countRuns(d, 5) == 2);
    
    string f[3] = { "fiona", "ed", "john" };
    assert(lookupAny(h, 7, f, 3) == 2);
    assert(flip(f, 3) == 3 && f[0] == "john" && f[2] == "fiona");
    
    assert(divide(h, 7, "fiona") == 3);
    
    cout << "All tests succeeded" << endl;
}
