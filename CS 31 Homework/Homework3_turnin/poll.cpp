//
//  main.cpp
//  Homework3
//
//  Created by Allen Liu on 10/22/18.
//  Copyright © 2018 Vincent Liu. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
using namespace std;

const string state [50] = { "AL","AK","AZ","AR","CA","CO","CT","DE","FL","GA","HI","ID","IL","IN","IA","KS","KY","LA","ME","MD","MA","MI","MN","MS","MO","MT","NE","NV","NH","NJ","NM","NY","NC","ND","OH","OK","OR","PA","RI","SC","SD","TN","TX","UT","VT","VA","WA","WV","WI","WY"};

bool format(string pds)
{
    for (int i =0; i != pds.size(); i++)
    {
        if (!isdigit(pds[i]) && !isalpha(pds[i]) && pds[i] != ',')
            return false;
    }
    return true;
}

string upperlize(string pds)
{
    string upperpds = "";
    for (int k=0; k != pds.size(); k++)
    {
        upperpds += toupper(pds[k]);
    }
    return upperpds;
}

bool stateCode(string pds)
{
    if (pds == "")
        return true;
    
    bool a = false;
    string head = pds.substr(0,2);
    for (int k =0; k != 50; k++)
    {
        if (head == state[k])
            a = true;
    }
    if (a != true)
        return false;
    
    for (int i=2; i != pds.size(); i++)
    {
        
        if (pds[i] == ',')
        {
            if (i+3 > pds.size())
                return false;
            if (!isalpha(pds[i-1]) || !isalpha(pds[i+1]) || !isalpha(pds[i+2]))
                return false;
            head = pds.substr(i+1,2);
            for (int j =0; j != 50; j++)
            {
                if (head == state[j])
                    a = true;
            }
            if (a != true)
                return false;
        }
    }
    return a;
}

bool alpha(string pollData)
{
    bool a = false;
    for (int i = 2; i != pollData.size(); i++)
    {
        if (isalpha(pollData[i]))
        {
            if((pollData[i-2] == ','&& isalpha(pollData[i-1])) || pollData[i-1] == ',')
                continue;
            else if (isdigit(pollData[i-1]) && isalpha(pollData[i-2]))
                a = true;
            else if (isdigit(pollData[i-1]) && isdigit(pollData[i-2]) && isalpha(pollData[i-3]))
                a = true;
            else
                return false;
        }
    }
    return a;
}

bool hasProperSyntax(string pds)
{
    if (pds == "")
        return true;
    pds = upperlize(pds);
    if (stateCode(pds) && format(pds) && alpha(pds))
        return true;
    else
        return false;
}

int tallySeats(string pollData, char party, int& seatTally)
{
    if (!hasProperSyntax(pollData))
        return 1;
    if (! isalpha(party))
        return 2;
    pollData = upperlize(pollData);
    party = toupper(party);
    if (pollData == "")
    {
        seatTally = 0;
        return 0;
    }
    seatTally = 0;
    for (int i=3; i != pollData.size(); i++)
    {
        if (pollData[i] == party)
        {
            if (isdigit(pollData[i-1]) && isalpha(pollData[i-2]))
                seatTally += pollData[i-1]-'0';
            else if (isdigit(pollData[i-1]) && isdigit(pollData[i-2]))
                seatTally += pollData[i-1]-'0'+(pollData[i-2]-'0')*10;
        }
    }
    return 0;
}

int main() {
    string pds;
    char party = ' ';
    int seatTally;
    int result;
    
    cout << "Enter poll data string: ";
    getline(cin, pds);
    cout <<"poll data is: "<<pds<<endl;
    cout << "Enter party: ";
    cin >> party;
    cout << "Enter seatTally: ";
    cin >> seatTally;
    
    cout << "hasProperSyntax returns ";
    if (hasProperSyntax(pds))
        cout << "true"<<endl;
    else
        cout << "false"<<endl;
    
    result = tallySeats(pds, party, seatTally);
    cout << "seaTally is: "<< seatTally<<endl;
    cout << "result is: "<<result<<endl;
    return result;

}
