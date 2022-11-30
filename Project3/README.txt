Project 3
Kennedy Mays
CSC 245

Overview
- make a program that takes in a text file from the command line and (un)compresses it using the Huffman Algorithm

HUFFMAN
- huffman tree ADT class implemented using an array of structs

Build() (Huffman Algorithm)
- loop through the array, checking for the two smallest values w/o a parent, 
create a parent node Tn by calling Insert() & making its weight the sum of its children, 
setting the children's parent to the new Tn node, & setting its value to 0/1 corresponding to left/right
- continue until only 1 node doesn't have a parent(the root node)

PrintTable() (Huffman Algorithm Visualization)
- loop through the array, printing the: char, weight, parent, & child type

GetCode() (Huffman Algorithm Continued)
-use lookUp() to find the index of the entered char
-instantiate a string for the char's encoding
-given its index, append its child type, go to its parent's index, return its child type, etc until the a node w/o a child type(root)
-reverse the string then return it

ZIP
- takes in .txt file and returns a .zip(compressed) file

Main()
- take in the .txt file
- loop through the .txt file, creating a dictionary of chars & their frequencies
- instantiate a huffman tree
- loop through the dict of chars, inserting them & their respective frequencies into the tree
- call build() to orient the tree according to the huffman algorithm
- get the number of dictionary keys, writing it to the first line of the zip file
- loop through the dict keys, using getCode() from huffman.cpp to retreive each one's encoding
- write the char-encoding pairs to the zip file
- loop through the original .txt file again, writing the encoding in the .zip file as each char is encountered
- print (.zip bits)/(# chars*8)

UNZIP
- takes in the .zip file and turns it into a .txt file 

Main()
- take in the .zip file
- reads in the first line as an int (numLines)
- loops through the number of lines indicated by numLines, creating a dict for the ascii and compressed string
- then it'll traverse the data, checking for string recognition & adding the corresponding char to a string, deleting the encoding from the data, & continuing until there's no data left
- It'll output a string notifying the user that the string has been unzipped &, for debugging purposes, the original string
