#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

void BreakDown (string name, string& first, string& last, string& mi);
int main()
{
	string name, first, last, mi;

	cout << "Name? <Last, First MI.> ";
	getline (cin, name);
		
	BreakDown (name, first, mi, last);

	cout << "First Name Entered :  " << first << endl;
	cout << "Last Name Entered :  " << last << endl;
	cout << "Middle Initial Entered :  " << mi << endl;
	return 0;
}

void BreakDown (string name, string& first, string& mi, string& last)
{
	// pre  : name is initialized with a full name
	// post : first, mi, and last contain the individual components
        //        of that name
	//find comma, get substr that ends at comma, save as last name
	int comma=name.find(',');//index of comma
	last=name.substr(0,comma);
	mi=name.substr(name.size()-2,1);
	int space2=name.find(mi)-1;//index of second space
	first=name.substr(comma+2,space2-comma-2);



} 
