#include<string>
#include<iostream>

using namespace std;

int main(){

	string str1("Hello ");
	string str2 = str1 + "C";
	string str3(str2); 
	str3.append("++");

	cout<<"First string is: "<<str1.c_str()<<endl;
	cout<<"Second string is: "<<str2.c_str()<<endl;
	cout<<"Third string is: "<<str3.c_str()<<endl;

	return 0;
}