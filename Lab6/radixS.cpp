#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;

int maxElemLength(const vector<string>& v);
char getChar(string s, int k, int max);
vector <queue<string> > itemsToQueues(const vector<string>& L, int k);
vector<string> queuesToArray(vector<queue<string> >& qa);
void radixSort(vector<string>& L);
void printVector(const vector<string>& L); 

main(){
	vector<string> L;
	L.push_back("kennedy");
	L.push_back("mercer");
	L.push_back("alpha");
	L.push_back("lion");
  L.push_back("omega");
  cout<<"initial array..."<<endl;
  printVector(L);
  radixSort(L);
  cout<<"sorted array..."<<endl;
  printVector(L);
}

int maxElemLength(const vector<string>& v){
	int max=0;
	int begin=0;
	int end=v.size()-1;
	while(begin<end){
		if(v[begin].length()>max){
     cout<<v[begin]<< ":"<<v[begin].length()<<endl;
			max=v[begin].length();
		}
		if(v[end].length()>max){
   cout<<v[end]<< ":"<<v[end].length()<<endl;
			max=v[end].length();
		}
		begin++;
		end--;
	}	
	return max;
}

char getChar(string s, int k, int max){
  k=max-k-1;
  //pad element smaller than the max
	while(s.length()<max){
   s+=" ";
 }
	//cout<<"digit at "<<k<<": "<<temp[k]<<endl;
	return s[k];
} 

vector<queue<string> > itemsToQueues(const vector<string>& L, int k){
	vector<queue<string> > output;
	for(int i=0;i<128;i++){
		queue<string> bucket;
		output.push_back(bucket);
	}
	//cout<<"num buckets in vector: "<<output.size()<<endl;
   int length=maxElemLength(L);
	for(int i=0;i<L.size();i++){
		//insert every elem into queue based on digit
		char ch=getChar(L[i],k,length);
		output[ch].push(L[i]);
	 cout<<"inserting "<<L[i]<<" into bucket "<<ch<<endl;
	}
	return output;
} 

vector<string> queuesToArray(vector<queue<string> >& qa){
  vector<string> output;
  int bucket=0;
  while(bucket<qa.size()){
    if(!qa[bucket].empty()){
      string temp=qa[bucket].front();
      output.push_back(temp);
      qa[bucket].pop();
    }
    else{
      bucket++;
    }
  }
  return output;
}

void radixSort(vector<string>& L){
  vector<queue<string> > qa;
  int length=maxElemLength(L);
  for(int i=1;i<length;i++){
    qa=itemsToQueues(L,i);
    L=queuesToArray(qa);
  }
} 

void printVector(const vector<string>& L){
  for(int i=0;i<L.size();i++){
    cout<<L[i]<<endl;
  }
} 
