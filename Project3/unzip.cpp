#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

main(int argc, char** argv)//FUNCTIONAL, CLEAN IT UP!!!!!!!!
{
  //retrieve the file from the command line
  //check for valid input here
  string f=argv[1];
  ifstream file;
  string contents; int numLines; int space;
  stringstream ss;map<string,string> codes; string decoded;
  //reads the contents
  file.open(f.c_str(),ios::in);
  if(file.is_open()){
    //read in the first line -> num lines to read
    getline(file,contents);
    ss<<contents; ss>>numLines;
    //cout<<numLines<<endl; //check for correct input
    while(numLines>0){
      string temp;string s;char ch;int t; stringstream stream;
      getline(file,contents);
      //separete contents into two values & add them to codes map
      space=contents.find(" ");
      temp=contents.substr(space+1);//string->int->string
      s=contents.substr(0,space);
      stream<<s;stream>>t;
      ch=static_cast<char>(t);
      codes[temp]=ch;
      //cout<<temp<<" : "<<codes[temp]<<endl;
      numLines--;
    }
    //read in the actual data
    getline(file,contents);
    //cout<<"data to decode: "<<contents<<endl;
  } 
   //loop through the data, creating the decoded string
   int end=1;
   while(contents.length()>0){//should be the length of the smallest encoding..
      string checker=contents.substr(0,end);
      //checks for valid code
      if(codes.count(checker)==1){
        decoded+=codes[checker];
        contents=contents.substr(end);
        end=1;
      }
      else{
        end++;
      }      
    }  
    //write the decoded string to the uncompressed version of the file
    string outfile=f.substr(0,f.length()-4)+".txt";
    ofstream ufile;
    ufile.open(outfile.c_str(),ios::out);
    ufile<<decoded<<endl;
    ufile.close();
    cout<<"File Successfully Inflated Back To Original."<<endl;     
    //cout<<"decoded data: "<<decoded<<endl;
}