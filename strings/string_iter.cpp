#include<string>
#include<iostream>;

using namespace std;

int main(){

	string str("Hello world");
    cout<<"Displaying string content using iterator: ";
    
	//displaying string chars using iterator
	for(auto char_iter = str.cbegin(); char_iter != str.cend(); char_iter++)
		cout<<*char_iter;
	cout<<endl<<endl;

	cout<<"Displaying string content using C type string: "<<str.c_str()<<endl;

	return 0;
}