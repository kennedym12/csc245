#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;

int maxElemLength(const vector<int>& v);
int getDigit(int num, int k, int max);
vector <queue<int> > itemsToQueues(const vector<int>& L, int k);
vector<int> queuesToArray(vector<queue<int> >& qa);
void radixSort(vector<int>& L);
void printVector(const vector<int>& L);
main(){
	vector<int> L;
	L.push_back(380);
	L.push_back(95);
	L.push_back(345);
	L.push_back(382);
	L.push_back(260);
	L.push_back(100);
	L.push_back(492);
  cout<<"initial array..."<<endl;
  printVector(L);
  radixSort(L);
  cout<<"sorted array..."<<endl;
  printVector(L);
}

int maxElemLength(const vector<int>& v){
	int max=0;
	int begin=0;
	int end=v.size();
	while(begin<end){
		if(v[begin]>max){
			max=v[begin];
		}
		if(v[end]>max){
			max=v[end];
		}
		begin++;
		end--;
	}	
	stringstream ss;
	string temp;
	ss<<max;ss>>temp;
	return temp.length();
}

int getDigit(int num, int k, int max){
	stringstream ss,s;
	string temp;
	int digit;
  k=max-k-1;
  //pad element smaller than the max
	ss<<num;ss>>temp;
	while(temp.length()<max){
   temp="0"+temp;
 }
	//cout<<"digit at "<<k<<": "<<temp[k]<<endl;
	s<<temp[k];s>>digit;
	return digit;
} 

vector<queue<int> > itemsToQueues(const vector<int>& L, int k){
	vector<queue<int> > output;
	for(int i=0;i<10;i++){
		queue<int> bucket;
		output.push_back(bucket);
	}
	//cout<<"num buckets in vector: "<<output.size()<<endl;
   int maxDigit=maxElemLength(L);
	for(int i=0;i<L.size();i++){
		//insert every elem into queue based on digit
		int digit=getDigit(L[i],k,maxDigit);
		output[digit].push(L[i]);
		//cout<<"inserting "<<L[i]<<" into bucket "<<digit<<endl;
	}
	return output;
}

vector<int> queuesToArray(vector<queue<int> >& qa){
  vector<int> output;
  int bucket=0;
  while(bucket<qa.size()){
    if(!qa[bucket].empty()){
      int val=qa[bucket].front();
      output.push_back(val);
      qa[bucket].pop();
    }
    else{
      bucket++;
    }
  }
  return output;
}

void radixSort(vector<int>& L){
  vector<queue<int> > qa(10);
  int numDigits=maxElemLength(L);
  for(int i=1;i<numDigits;i++){
    qa=itemsToQueues(L,i);
    L=queuesToArray(qa);
  }
}

void printVector(const vector<int>& L){
  for(int i=0;i<L.size();i++){
    cout<<L[i]<<endl;
  }
}