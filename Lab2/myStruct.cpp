
#include <iostream>
#include <string> 
using namespace std;

const int SIZE = 100;

struct DateType
{
	string month;
	int day;
	int year;
};

// Insert EventType definition HERE
struct EventType
{
	string place;
	struct DateType
	{
		string month;
		int day;
		int year;
	}inner;
};


void PrintStruct (DateType Holiday);
void AssignMonth (EventType Dates[]);

int main()
{
	DateType Holiday;
	Holiday.month="September";
	Holiday.day=7;
	Holiday.year=2022;

	EventType Dates[SIZE];



	PrintStruct (Holiday);
	AssignMonth (Dates);
	return 0;
}

void PrintStruct (DateType Holiday)
{
	// pre  : Holiday is intialized with three field values
	// post : Function prints date of Holiday in form mm dd, yy
	cout<<Holiday.month<<" ";
	if(Holiday.day<10)
		cout<<'0';
	cout<<Holiday.day<<", ";
	cout<<Holiday.year<<endl;



}

void AssignMonth (EventType Dates[])
{
	// pre  : none 
	// post : The month field of every date record in array is assigned a month 
	for(int i=0;i<SIZE;i++)
		Dates[i].inner.month="February";


}


