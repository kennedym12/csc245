#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "huffman.h"
using namespace std;

main(int argc, char** argv)
{
  //check for valid input here
  string f=argv[1];
  ifstream file;
  string contents,temp;
  double numChars, numBits, ratio;
  file.open(f.c_str(),ios::in);
  if(file.is_open()){
    //reads in all content as a single string
    while(getline(file,temp)){
      contents+="\n"+temp;
    }
  } 
  HuffmanTree htree;
  vector<char> chars;
  cout<<contents<<endl;
  //check for the char in the map, adding its frequency each time
  for(int i=0;i<contents.size();i++){
    char ch=contents[i];
    if(htree.inTree(ch)){
      int nf=htree.GetFrequency(ch)+1;
      htree.SetFrequency(ch,nf);
    }
    else{
      htree.insert(ch,1);
      chars.push_back(ch);
    }
  }
  //build & check tree
   htree.build();
   htree.PrintTable();
   
  //create & write to .zip file
  string outfile=f+".zip";
  ofstream zfile;
  zfile.open(outfile.c_str(),ios::out);
  //append the number of encodings
  zfile<<chars.size()<<endl;
  //append the encoding map
  for(int i=0;i<chars.size();i++){
    //convert the char to ascii
    stringstream ss; string t; string code;
    int temp=int(chars[i]);
    ss<<temp;ss>>t;
    //retrieve its encodings
    code=htree.GetCode(chars[i]);
    //cout<<chars[i]<<" : "<<t<<" : "<<code<<endl;
    //append ascii & code line by line in the zip file
    zfile<<t<<" "<<code<<endl;
  }
  //append the data
  string encoding="";
  for(int i=0;i<contents.size();i++){
    string code=htree.GetCode(contents[i]);
    encoding+=code;
  }
  //cout<<"encoding: "<<encoding<<endl; 
  zfile<<encoding;
  //close the file
  zfile.close();
  //get the compression ratio
  numBits+=encoding.length();
  numChars=contents.length();
  ratio=1-(numBits/(numChars*8));
  cout<<"The file was successfully compressed to "<<numBits<<" bits or "<<ratio*100<<"% its original size"<<endl;
}
