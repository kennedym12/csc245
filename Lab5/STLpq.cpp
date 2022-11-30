#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

//functions
void addNames(priority_queue<string> &q);
void print(priority_queue<string> q);

main(){
	priority_queue<string> pq;
	addNames(pq);
	print(pq);
}

void addNames(priority_queue<string> &q){
	string names[]={"Kennedy","Mur","Asia","Noah","Kaitlin","Emmanuel","Shamya","Shelby","Hilary","Dami"};
	for(int i=0;i<10;i++){
		q.push(names[i]);
	}
}

void print(priority_queue<string> q){
	while(!q.empty()){
		cout<<""<<q.top()<<setw(5);
		q.pop();
	}
	cout<<endl;
}
