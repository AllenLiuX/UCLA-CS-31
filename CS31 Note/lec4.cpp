#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "What is your name?";
	string personName;
	getline(cin, personName);

    cout <<"What is your age?";
    int age;
    cin >> age;
    
	cout << "What is your request?";
	string quest;
	getline(cin, quest);

	cout <<"Hello, brave " << personName << "!" << endl;
	cout <<"Your want " << quest << endl;
    cout <<"if you live, you will be " <<age + 1<< "years old next year";
    return 0;
}
