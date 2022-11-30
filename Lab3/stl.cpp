#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

void initialize(vector<int> &v);
void print(vector<int> v);
void reverse(vector<int> &v);

main()
{
	stack<string> s1, s2;
	s1.push("Kennedy");
	s2.push("Alexis");
	if(s1==s2){
		cout<<"The two strings are equal"<<endl;
	}
	else if(s1>s2){
		cout<<s2.top()<<" comes before "<<s1.top()<<endl;
	}
	else{
		cout<<s1.top()<<" comes before "<<s2.top()<<endl;
	}

	vector<int> v;
	cout<<"Adding integers to the vector..."<<endl;
	initialize(v);
	print(v);	
	cout<<"Reversing the vector..."<<endl;
	reverse(v);
	print(v);
	cout<<"Sorting the vector..."<<endl;
	sort(v.begin(), v.end());
	print(v);
}

void initialize(vector<int> &v)
{
	int temp;
	int total=0;
	while(total<5){
		cin>>temp;
		v.push_back(temp);			
		total++;
	}
}

void print(vector<int> v)
{
	for(int i=0;i<5;i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

void reverse(vector<int> &v)
{
	int temp;
	for(int i=0;i<2;i++){
		temp=v[i];
		v[i]=v[4-i];
		v[4-i]=temp;
	}
}
