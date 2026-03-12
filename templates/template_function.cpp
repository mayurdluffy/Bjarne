#include<iostream>
using namespace std;

template<typename T>
const T& getmax(const T& num1, const T& num2){
	if(num1>num2) return num1;
	else return num2;
}

int main(){

	cout<<"getmax(3,4): "<<getmax(3,4)<<endl;
	cout<<"getmax(3.45,4.56): "<<getmax(3.45,4.56)<<endl;
	return 0;
}