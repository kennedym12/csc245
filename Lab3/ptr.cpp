#include <iostream>
#include <cstring>
using namespace std;

struct RecType
{
	int age;
	float weight;
	char gender;
};

main()
{
	int num = 5;
	int *intPtr=NULL;
	intPtr = &num; 
	*intPtr*=10;
	cout<<*intPtr<<" is the int pointed to by intPtr"<<endl;

	RecType *recPtr = new RecType;
	recPtr->age=25; 
	recPtr->weight=190;
	recPtr->gender='M';
	recPtr->age+=5;
	cout<<recPtr->age<<" "<<recPtr->weight<<" "<<recPtr->gender<<endl;

	delete recPtr;
	recPtr=NULL;

	char *strPtr = new char[50];
	strcpy(strPtr, "Operating Systems");
	cout<<strPtr<<endl;
	int lowerC;
	for(int i=0; i<strlen(strPtr);i++){
		if(islower(*(strPtr+i))){
			lowerC+=1;
		}
	}
	cout<<"There are "<<lowerC<<" lower case letters."<<endl;
	strPtr+=10;
	cout<<"The new string is "<<strPtr<<endl;
	strPtr-=10;
	cout<<"The string  "<<strPtr<<" should be back to normal."<<endl;
	delete strPtr;
}
