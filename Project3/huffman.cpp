#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
using namespace std;

HuffmanTree:: HuffmanTree()
	: numChars(0), built(false) {}

void HuffmanTree:: insert(char ch, int weight) {
    HNode newNode = {ch, weight, -1, -1}; 
    built = false;
    nodes.push_back(newNode);
    numChars++;

}

bool HuffmanTree:: inTree(char ch) {
//loop through nodes vector, only returns true if the value is found
	if(lookUp(ch)!=-1){
   return true;
  }
	return false;
}

int HuffmanTree:: GetFrequency(char ch) {
//searches for the index of a given char
  int i = lookUp(ch);
	return GetFrequency(i);
}

int HuffmanTree:: GetFrequency(int i) {
//returns the weight of a node at the given index; end index returns 0
	if(i==-1){
		cout<<"This char isn't in the tree..."<<endl;
		return 0;
	}	
	else{ 
		return nodes[i].weight;
	}
} 

void HuffmanTree:: SetFrequency(char ch, int f){
//gets the index of the char whose freq to change
  int i=lookUp(ch);
  SetFrequency(i,f);
}

void HuffmanTree:: SetFrequency(int i, int f){
//changes the frequency 
  nodes[i].weight=f;
}

int HuffmanTree:: lookUp(char ch) {
//returns the index of a char in nodes
	for(int i=0;i<nodes.size(); i++){
		if(nodes[i].ch==ch){return i;}
	}
	return -1;
}

string HuffmanTree:: GetCode(char ch) {
//get the index of the char then get the encoding string
  int i=lookUp(ch);
  return GetCode(i);
}


string HuffmanTree:: GetCode(int i) {
//use recursion to return the encoding string for a char
  if(nodes[i].parent==-1){
    return "";
  }
  stringstream ss;
  int code=nodes[i].childType;
  string encoding;
  ss<<code;ss>>encoding;
  return GetCode(nodes[i].parent)+encoding;
} 

void HuffmanTree:: PrintTable() {
//print the char, weight, parent, & childType, preferable formatted well
  cout<<endl;
  cout<<"~~~~~~~~~~~~~~~~Huffman Table~~~~~~~~~~~~~~~~"<<endl;
  cout<<setw(9)<<"Index"<<setw(6)<<"Char"<<setw(9)<<"Weight"<<setw(7)<<"Parent"<<setw(10)<<"ChildType"<<endl;
  for(int i=0;i<nodes.size();i++){
    string ch;
    ch+=nodes[i].ch;
    if(nodes[i].ch==32){ch="sp";}
    if(nodes[i].ch==10){ch="nl";}
    cout<<setw(5)<<i<<setw(7)<<ch<<setw(7)<<nodes[i].weight<<setw(7)<<nodes[i].parent<<setw(7)<<nodes[i].childType<<endl;
  }
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
} 

int HuffmanTree:: numNodes() {
  //returns the number of nodes in nodes
  return nodes.size();
}

void HuffmanTree:: build() {
//create huffman tree using the nodes vector
  int parentLess=numChars;
  
  //loop through until 1 nodes has parent=-1 (root)
  while(parentLess!=1){
    //cout<<"nodes w/o parents: "<<parentLess<<endl;
     int a=-1;//default index that doesn't have a parent node
    int b=-1;//different default index that doesn't have a parent node
    int ind=0;
    while(a<0 || b<0){
      if(nodes[ind].parent==-1 & a<0){a=ind;}
      else if(nodes[ind].parent==-1 & b<0){b=ind;}
      ind++;
    }
    //loop through to find smallest 
  for(int i=0;i<nodes.size(); i++){
    if(i!=b){
		if(nodes[i].weight<nodes[a].weight & nodes[i].parent==-1){
      a=i;   
    }
    }
	}
   //loop through again checking every other for second smallest (allows for repeat weights)
  for(int i=0;i<nodes.size(); i++){
		if(i!=a){
     if(nodes[i].weight<=nodes[b].weight & nodes[i].parent==-1){
      b=i;   
    }
   }
	}
   //cout<<"children are: "<<a<<" & "<<b<<endl;
   //create the parent node
   int weight = nodes[a].weight+nodes[b].weight;
   insert('T',weight);
   
   //set the children's parent loc to the last tree entry
   nodes[a].parent=nodes.size()-1; nodes[a].childType=0;
   nodes[b].parent=nodes.size()-1; nodes[b].childType=1;
   
   //decrement num of parentless nodes
   parentLess-=1;
  }
  built=true;
} 
