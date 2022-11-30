#include <iostream>
#include "stack.cpp"
using namespace std;

main()
{
  stack<int> eval(10);
  cout<<"stack is empty"<<eval.isEmpty()<<endl;
  eval.push(3);
  cout<<"stack is empty"<<eval.isEmpty()<<endl;
  cout<<eval.top();
  eval.pop(); 
  cout<<"stack is empty"<<eval.isEmpty()<<endl;
}
