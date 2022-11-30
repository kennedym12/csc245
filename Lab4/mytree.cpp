#include <iostream>
#include "bst.h"
using namespace std;

main(){
	BinarySearchTree<int> T(0);
	
	T.insert(6);
	T.insert(8);
	T.insert(2);
	T.insert(1);
	T.insert(4);
	T.insert(3);
	T.insert(9);	

	cout<<"Post Order Traversal:"<<endl;
	T.postOrder();
	cout<<"Height: "<<T.Height()<<endl;
	cout<<"Leaves: "<<T.numLeaves()<<endl;
	if(T.isBalanced()){
		cout<<"It's Balanced!"<<endl;
	}
	else{
		cout<<"It's Not Balanced"<<endl;
	}
}
