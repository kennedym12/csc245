#include <cstddef> 
#include <iostream>
#include "dlist.h"

using namespace std;

template<class ItemType>
struct NodeType
{
	ItemType info;
	NodeType<ItemType>*	next;
	NodeType<ItemType>*	back;
};

template <class ItemType>		
DList<ItemType>::DList() 		// Class constructor
{
    length = 0;
    head = NULL;
}

template <class ItemType>
DList<ItemType>::~DList   ()		
{
	// Post: List is empty; All items have been deallocated.
	//NodeType<ItemType> curr=head;
	//while(curr!=NULL){
	//	deleteLocation(curr);
	//}
}

template <class ItemType>
void DList<ItemType>::makeEmpty()
{
    // Post: List is empty; all items have been deallocated.
	if(isEmpty()){cout<<"The list is already empty"<<endl;}
	else{
		NodeType<ItemType>* curr=head;
		while(head!=NULL){
			deleteLocation(head);
		}
	}
}

template <class ItemType>
void DList<ItemType>::deleteItem (ItemType item)	
{
	//  Pre :  item to be deleted is passed in via parameter 
        // Post :  item is deleted if it exists in list 
	if(inList(item)){
		NodeType<ItemType>* currLoc=location(item);
		deleteLocation(currLoc);			
	}
	else{
		cout<<"This item doesn't exist."<<endl;
	}	
}

template <class ItemType>
bool DList<ItemType>::inList (ItemType item) const
{
	//  Pre :  item to be located is passed in via parameter 
        // Post :  function returns bool value if item is found 
	NodeType<ItemType>* curr=head;
	for(int i=0; i<length;i++){
		if((curr->info)==item){
			return true;
		}
		curr=curr->next;
	}	
	return false;
}

template <class ItemType>
bool DList<ItemType>::isEmpty() const		
{
	// Post : function returns true if list is empty, false otherwise
	return(head==NULL); 		
}

template <class ItemType>
void DList<ItemType>::print() const	
{
	// Pre  : List is not empty 
	// Post : Items in List have been printed to screen
	NodeType<ItemType>* curr=head;
	while(curr!=NULL){
		cout<<curr->info<<" ";
		curr=curr->next;
	}
	cout<<endl;
}
	
template <class ItemType>
void DList<ItemType>::insertHead(ItemType item)	
{
	//  Pre : item to be inserted is passed in via parameter
        // Post : item is inserted at head of list;  Former first node is 
        //        linked back to this new one via double link;
        //        Length incremented;  Special case handled if list is empty 
	NodeType<ItemType> *newHead=new NodeType<ItemType>;
	newHead->info=item;
	newHead->back=NULL;
	newHead->next=head;
	if(!isEmpty()){
		head->back=newHead;
	}
	head=newHead;
	length+=1;
}

template <class ItemType>
void DList<ItemType>::appendTail(ItemType item)
{
	//  Pre :  item to be inserted is passed in via parameter
        // Post :  item is added to tail of list; Former last node
        //         is linked to this new one via double link 
	NodeType<ItemType>* newLast=new NodeType<ItemType>;
	newLast->info=item;
	newLast->next=NULL;
	NodeType<ItemType>* currLast=last();
	newLast->back=currLast;
	if(!isEmpty()){
		currLast->next=newLast;
	}
	else{
		head=newLast;
	}
	length+=1;
}

template <class ItemType>
int DList<ItemType>::lengthIs() const	
{
	// Post : Function returns current length of list  
	return length;
}

template <class ItemType>
void DList<ItemType>::moveItem(ItemType item) 
{
  //moves the item, passed by parameter to the front of the list
  if(inList(item)){
    NodeType<ItemType>* loc=location(item);
    NodeType<ItemType>* tempNext=loc->next;
    
    while(loc!=head){
      loc->next=loc->back;//move selected item's pointers
      loc->back=loc->back->back;
      loc->next->back=loc;//move node that the selected node swaps with
      loc->next->next=tempNext;
      if(loc->next!=head){
        loc->back->next=loc;//update left-most node
      }
      if(loc->next==head){
        head=loc;
      }
      if(tempNext!=NULL){
        tempNext->back=loc->next;//update right-most node
      }
    }
	}
	else{
		cout<<"This item doesn't exist."<<endl;
  }
}

template <class ItemType>
NodeType<ItemType>* DList<ItemType>::location(ItemType item) const	
{
	//  Pre : item to be located is passed in via parameter 
        // Post : function returns address of item being searched for --
        //        if not found, NULL is returned  
	NodeType<ItemType>* curr=head;
	for(int i=0; i<length; i++){
		if(curr->info==item){
			return curr;//use ->next->back if needed
		}
		curr=curr->next;
	}
	return curr;//should return NULL
}

template <class ItemType>
NodeType<ItemType>* DList<ItemType>::last() const	
{
	// Post : Function returns location of current last item in list
	NodeType<ItemType>* currLast = head;
	if(length==0){
		return currLast;
	}
	while(currLast->next!=NULL){
		currLast=currLast->next;
	}	
	return currLast;
}

template <class ItemType>
void DList<ItemType>::deleteLocation (NodeType<ItemType>* delPtr)	
{

	//  Pre : Item to be deleted exits in list and its location
        //        is passed in via parameter
                   
	// Post : Location passed in is removed from list;  Length
        //        is decremented, and location is deallocated 

        // Special Cases Handled for Deleting Only One Item in List,
        // The Head Item of List, and the Tail Item of List
	NodeType<ItemType>* curr=head;
	NodeType<ItemType>* currLast=last();
	if(length==0){
		cout<<"There's no values in the list to delete"<<endl;
	}
	else if(delPtr==head & delPtr==currLast){//1 val in list
		head=NULL;
		delete delPtr;
		length-=1;
		cout<<"head & last are the same"<<endl;
	}
	else if(delPtr==head){
		head=head->next;
		head->back->next=NULL;
		head->back=NULL;
		delete delPtr;
		length-=1;
		cout<<"deleting the head"<<endl;
	}
	else if(delPtr==currLast){
		currLast=currLast->back;
		currLast->next->back=NULL;
		currLast->next=NULL;
		delete delPtr;
		length-=1;	
		cout<<"deleting the last"<<endl;
	}
	else{
		while(curr->next!=NULL){
			if(curr!=delPtr){
				curr=curr->next;
			}
			else{
				curr->next->back=curr->back;
				curr->back->next=curr->next;
				curr->next=NULL;
				curr->back=NULL;
				curr=curr->next;
				delete delPtr;
				length-=1;
				cout<<"deleting some node in the middle"<<endl;
				break;
			}
		}
	}
}
