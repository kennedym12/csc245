#include <iostream>
using namespace std;

double convert(double celsius);

int main(){
    double celsius, fahrenheit;
    cout<<"Please enter a celsius value:"<<endl;
    cin>>celsius;
    fahrenheit=convert(celsius);
    cout<<celsius<<" degrees celsius is "<<fahrenheit<<" degrees in fahrenheit."<<endl; 
    return 0;
}

double convert(double celsius){
    return 1.8 * celsius + 32.0;
}