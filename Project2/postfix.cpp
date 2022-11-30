#include <iostream>
#include "stack.cpp"
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
using namespace std;

bool isValid(string s);

main()
{
 char go='Y';
 while(go=='Y'){
  //create stack for evaluating
  stack<int> eval(20);
  
  //accept user ~valid~ input
  string input;
  try{
    getline(cin,input,';');
    if(!isValid(input)){
      throw(input);
    }
  }
  catch(string in){
    cout<<"This input is invalid, please try again..."<<endl;
    cout<<"Valid characters: 1234567890 _+-*/%;"<<endl;
    exit(0);
  }
  
  //parse values & evaluate 
  int ind=0;
  int a,b;
  string val;
  input+=";";
  
  //evaluate the expression
  while(ind<input.size())
  {
    int temp=ind;
    switch(input[ind]){
      case ' ':
        ind++;
        break;
      case '_':
        val+="-";
        ind++;
        break;
      case '+':
        a=eval.top();eval.pop();
        b=eval.top();eval.pop();
        cout<<"Token: +"<<setw(15)<<"Pop: "<<a<<setw(15)<<"Pop: "<<b;
        cout<<setw(15)<<"Push: "<<b+a<<endl;
        eval.push(b+a); ind++;
        break;
      case '-':
        a=eval.top();eval.pop();
        b=eval.top();eval.pop();
        cout<<"Token: -"<<setw(15)<<"Pop: "<<a<<setw(15)<<"Pop: "<<b;
        cout<<setw(15)<<"Push: "<<b-a<<endl;
        eval.push(b-a); ind++;
        break;
      case '*':
        a=eval.top();eval.pop();
        b=eval.top();eval.pop();
        cout<<"Token: *"<<setw(15)<<"Pop: "<<a<<setw(15)<<"Pop: "<<b;
        cout<<setw(15)<<"Push: "<<b*a<<endl;
        eval.push(b*a); ind++;
        break;
      case '/':
        try{
          a=eval.top();eval.pop();
          b=eval.top();eval.pop();
          cout<<"Token: /"<<setw(15)<<"Pop: "<<a<<setw(15)<<"Pop: "<<b;
          if(a==0){
            throw(0);
          }
          cout<<setw(15)<<"Push: "<<b/a<<endl;
          eval.push(b/a); ind++;
        }
        catch(int n){
          cout<<endl<<"Division by 0 Exception, try again..."<<endl;
          exit(0);
        }
        break;
      case '%':
        a=eval.top();eval.pop();
        b=eval.top();eval.pop();
        cout<<"Token: %"<<setw(15)<<"Pop: "<<a<<setw(15)<<"Pop: "<<b;
        cout<<setw(15)<<"Push: "<<b%a<<endl;
        eval.push(b%a); ind++;
        break; 
      case ';':
        a=eval.top();eval.pop();
        cout<<"Token: ;"<<setw(15)<<"Pop: "<<a<<endl;
        ind++;
        break;
      default://assume curr val at index is a digit, account for multi-num digit, & renew val
        while(isdigit(input[ind])){
          val+=input[ind];
          ind++;
        }
        cout<<"Token: "<<val<<setw(15)<<"Push: "<<val<<endl;
        stringstream num(val);
        int x;
        num >> x;
        eval.push(x);
        val="";
        break;
    }
  }
  //get valid input on whether to repeat the program without interferring with incoming expressions
  try{
    cout<<"Go again? (Y/N)"<<endl;
    cin>>go;
    if(go!='Y' && go!='N'){
      throw(go);
    }
    cin.ignore();
  }
  catch(char g){
    cout<<"Must enter 'Y' or 'N'..."<<endl;
  }
 }
} 

//method to check that string contents are valid
bool isValid(string s)
{
  string val ="1234567890 _+-*/%;";
  for(int i=0;i<s.size();i++){
    if(val.find(s[i], 0)==string::npos){
    cout<<s[i]<<" is invalid"<<endl;
    return false;
    }
  }
  return true;
  
}

