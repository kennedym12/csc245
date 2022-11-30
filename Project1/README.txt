Project 1
Kennedy Mays 
9/14/22 

Overview
- use a non-circular deque to display self-adjustment
- self-adjustment is when an item moves to the front every time it's searched for, essentially making the common-case efficient to execute
- the DList class makes use of a template so the list can contain objects of any data type

dlist.cpp
- each component within the file mkaes use of 
- finish the contents of the impl file to reflect the pre-existing outline of the spec file
-isEmpty() returns the status of the list based on whether head is NULL
-lengthIs() returns the length attribute of the list 
-last() loops through the list, calling next until the length/final node is reached
-inList() loops through the list, starting at the head, checking the contents of each node for the input value, returns false if it's never found
-insertHead() creates a new nodeType that holds an item passed by the parameter, points to whatever the current head is and its back always points to NULL, also increments length
-appendTail() creates a new nodeType that holds an item passed by the parameterm points to the current tail (retrieved by last()) and its next always points to NULL
if the list is empty, head will point to the tail, also length is incremented
-print() loops through the list until the length is reached, printing the info within each node along the way
-deleteLocation (while taking into account situations where list length is less than or equal to 1) deletes the address passed by the parameter, it also decrements the length of the list, nothing happens if the location isn't in the list
- deleteItem() makes use of deleteLocation() and deletes the item passed by the parameter, it does this by first checking that the item is even in the list sing inList() then retrieving the item's location using location() and passing the address to deleteLocation()
-location() retrieves the address of whatever item is passed into it
-makeEmpty() iterates through the list, using deleteLocation(), until head=NULL
- moveItem() get the location of an item, if it's in the list, then loops through swapping the item's node with its back node until the item node is the head (implements the move to the front algorithm)

MoveFront.cpp
- the client file make use of the class functions within main() and prints words to the screen to update the client on the list's state
- each function also makes use of the '&'
- input() is the function used to call for and accept input, it also includes code for handling invalid inputs
- HeadInsert() uses inserthead()
- TailInsert() uses appendTail()
- AccessItem() uses FindandMove(), a client function
- FindandMove() uses moveItem()
- DeleteItem() uses deleteItem()
- PrintList() uses print() and uses const in the parameter
- PrintLength() uses lengthIs() and uses const in the parameter
