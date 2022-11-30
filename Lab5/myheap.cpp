#include <iostream>
#include "BinaryHeap.h"
using namespace std;

main()
{
	//create the heap
	BinaryHeap<char> pq(50);

	//assign A-J to the heap
	for(int i=65;i<75;i++){
		//cast value to char
		char temp=char(i);
		//insert into the heap
		pq.insert(temp);
	}

	//delete the min
	pq.deleteMin();

	cout<<"Left Subtree: ";
	pq.printLtSubtree();
	cout<<endl;
	cout<<"Height: "<<pq.Height()<<endl;
	cout<<"Max Char: "<<pq.findMax()<<endl;
}
