#include<string>
#include<iostream>

using namespace std;

//String initializations
int main(){

	string str1("Hello");
	str1 += " world.";

	string str2(str1);

	cout<<"First string is: "<<str1<<endl;
	cout<<"Second string is: "<<str2<<endl;

	string str3(5,'a'); //aaaaa
	cout<<"Third string is: "<<str3<<endl;

	return 0;

}