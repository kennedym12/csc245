#include "time.h"
#include <iostream>
using namespace std;

main()
{
	int SIZE = 10;

	Time myTime(9,30,0);
	myTime.Write();
	myTime.WriteAmPm();
	myTime.Set(19,0,0);
	myTime.Write();
	myTime.Mealtime();

	Time Schedule[SIZE];
	cout<<endl<<"Now printing edited schedule array..."<<endl;
	for(int i=0; i<SIZE;i++)
	{
		Schedule[i].Set(11,0,0);
		Schedule[i].WriteAmPm();
	}
}


