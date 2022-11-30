#include "dlist.cpp"
#include <iostream>
#include <limits>
using namespace std;

//list client methods here
void PrintMenu();
void HeadInsert(DList<int>& d);
void TailInsert(DList<int>& d);
int AccessItem(DList<int>& d);
void FindandMove(DList<int>& d, int i);
void DeleteItem(DList<int>& d);
void PrintList(const DList<int>& d);
void PrintLength(const DList<int>& d);
int input(char f);

main()
{
  cout << "\033[2J\033[1;1H";//clears the screen
	DList<int> list;
	char sel;
   
  cout<<"Welcome to the Move to the Front Algorithm"<<endl;
  do{
    PrintMenu();
    cin>>sel;
    switch(toupper(sel)){
      case 'H': HeadInsert(list); break;
      case 'T': TailInsert(list); break;
      case 'A': AccessItem(list); break;
      case 'D': DeleteItem(list); break;
      case 'P': PrintList(list); break;
      case 'L': PrintLength(list); break;
      case 'Q': cout<<"\tExiting Program...\n"; break;
      default: cout<<"\tError, try entering a valid character"<<endl;
    }
  } while (toupper(sel)!='Q');
}

void PrintMenu(){
  cout<<endl;
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
  cout<<"Please select a character from the selection below."<<endl;
  cout<<"H - insert an integer at the head"<<endl;
  cout<<"T - insert an integer at the end"<<endl;
  cout<<"A - access an integer in the list"<<endl;
  cout<<"D - delete an integer in the list"<<endl;
  cout<<"P - print the list contents"<<endl;
  cout<<"L - print the length of the list"<<endl;
  cout<<"Q - quit the program"<<endl;
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}

void HeadInsert(DList<int>& d){
	int i=input('h');
  if(d.inList(i)){
    cout<<"This integer is already in the list, try again"<<endl;
  }
  else{
	  d.insertHead(i);
     cout<<i<<" has been added to the beginning of the list"<<endl;
  }
}

void TailInsert(DList<int>& d){
	int i=input('t');
  if(d.inList(i)){
    cout<<"This integer is already in the list, try again"<<endl;
  }
  else{
	  d.appendTail(i);
     cout<<i<<" has been added to the end of the list"<<endl;
   }
}

int AccessItem(DList<int>& d){
	int i=input('a');
  if(d.isEmpty()){
    cout<<"This list is empty"<<endl;
  }
  else if(d.inList(i)){
    FindandMove(d, i);
    cout<<i<<" has been accessed and move to the front of the list"<<endl;
  }
  else{
    cout<<i<<" is not in the list, try again"<<endl;
  }
}

void FindandMove(DList<int>& d, int i){
  d.moveItem(i);
} 

void DeleteItem(DList<int>& d){
  int i=input('d');
  if(d.isEmpty()){
    cout<<"This list is empty"<<endl;
  }
  else if(d.inList(i)){
    d.deleteItem(i);
    cout<<i<<" has been deleted"<<endl;
  }
  else{
    cout<<i<<" is not in the list, try again"<<endl;
  }
} 

void PrintList(const DList<int>& d){
  cout<<"Printing list contents to the screen..."<<endl;
  d.print();
}
  
void PrintLength(const DList<int>& d){
  int len=d.lengthIs();
  cout<<"This list has "<<len<<" integers"<<endl; 
}

//exception handling!!!!!!!!!!!
int input(char f){
  int i;
  switch(f){
    case 'h': cout<<"Integer to add to the beginning of the list: "; break;
    case 't': cout<<"Integer to add to the end of the list: "; break;
    case 'a': cout<<"Integer to access & move to front: "; break;
    case 'd': cout<<"Integer to delete: "; break;
    default: cout<<"";
  }
  cin>>i;
  while(cin.fail()){
    cin.clear();
    cout<<"\tError, try entering an integer"<<endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    cin>>i;
  }
  return i;
}