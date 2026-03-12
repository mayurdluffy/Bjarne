#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

int main(){

	string str("Hello C++");
	cout<<str.c_str()<<endl;

	reverse(str.begin(),str.end());
	cout<<str.c_str()<<endl;

}