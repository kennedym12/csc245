#include <iostream>
using namespace std;

bool sameVal(double *ptr1, double *ptr2);
bool sameAddr(double *ptr1, double *ptr2);

main()
{
	double *ptr1=new double;
	double *ptr2=new double;
	*ptr1=10.0;
	*ptr2=*ptr1;
	cout<<"They both contain 10.0"<<endl;
	cout<<"same value: "<<sameVal(ptr1,ptr2)<<endl;
	cout<<"same address: "<<sameAddr(ptr1,ptr2)<<endl;

	ptr2=ptr1;
	cout<<"They now have the same address"<<endl;
	cout<<"same value: "<<sameVal(ptr1, ptr2)<<endl;
	cout<<"same address: "<<sameAddr(ptr1, ptr2)<<endl;
	
}

bool sameVal(double *ptr1, double *ptr2)
{
	return *ptr1==*ptr2;
}

bool sameAddr(double *ptr1, double *ptr2)
{
	return ptr1==ptr2;
}
