#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
#include "stack.cpp"
using namespace std;
//construct BET
struct BetNode
{
  char info;
  BetNode* left;
  BetNode* right;
};

string getPostfix(string s);
int prec(char s);
BetNode* getTree(string s);
bool isOperator(char c);
void preorder(BetNode* h);

main()
{
  fstream newfile;
  newfile.open("infix.dat",ios::in); 
   if (newfile.is_open()){   
      string exp;
      while(getline(newfile, exp)){ 
         cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
         cout << "Infix Expression: "<<exp<<endl;//print orig expression
         string fr=getPostfix(exp);
         cout << "Postfix Expression: "<<fr << endl;//convert to postfix
         stack<BetNode*> temp(20);          
         BetNode* head=getTree(fr);
         cout << "Binary Expression Tree Head: "<<head->info<<endl;//convert to BET
         cout <<"Preorder Tree Traversal: ";
         preorder(head);//print traversal
         cout<<endl;
         cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
         
      }
      newfile.close(); 
   }
}

string getPostfix(string s){//check each char then operate as usual
  stack<char> temp(20);
  string postfix="";
  for(int i=0;i<s.size();i++){
    if(s[i]=='*' || s[i]=='/' || s[i]=='+' || s[i]=='-'){
      if(temp.isEmpty()){
        temp.push(s[i]);
        //cout<<"Push: "<<s[i]<<endl;
      }
      else{
        while(prec(temp.top())>=prec(s[i]) && !temp.isEmpty()){
          postfix = postfix+temp.top();
          //cout<<"Pop: "<<temp.top()<<endl;
          temp.pop();
        }
        temp.push(s[i]);
      }
    }
    
    if(s[i]=='('){
      temp.push(s[i]);
    }
    
    if(s[i]==')'){
      while(temp.top()!='('){
        postfix=postfix+temp.top();
        temp.pop();
      }
      temp.pop();
    }
    
    if(isdigit(s[i])){
      postfix=postfix+s[i];
    } 
  }  
  
  while(!temp.isEmpty()){
    postfix=postfix+temp.top();
    temp.pop();
  } 
  return postfix;
} 

int prec(char s){
  if(s=='*' || s=='/'){return 2;}
  if(s=='+' || s=='-'){return 1;}
  else{return 0;}
} 

BetNode* getTree(string s){
  stack<BetNode*> temp(20);
  
  for(int i=0;i<s.size();i++){
    BetNode* t=new BetNode;
    t->info=s[i];
    //cout<<t->info<<endl;
    if(isOperator(s[i])){
      t->right=temp.top();temp.pop();
      t->left=temp.top();temp.pop();
    }
    else{
      t->right=NULL;
      t->left=NULL;
    }
    temp.push(t);
  }
  return temp.top();
} 

bool isOperator(char c){
  string val ="+-*/";
  
  if(val.find(c, 0)==string::npos){
    return false;
  }
  return true;
}

void preorder(BetNode* h){
  if(h!=NULL){
    cout<<h->info;
    preorder(h->left);
    preorder(h->right);
  }
  return;
} 