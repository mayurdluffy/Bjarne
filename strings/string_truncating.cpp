#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

int main(){

	string str("Hello string. Wake up to a beautiful day.");
	cout<<"String is: "<<str.c_str()<<endl;

	str.erase(13,28);
	cout<<"String after truncation is: "<<str.c_str()<<endl;

	/*string::iterator iter = str.find(str.begin(), str.end(),'d');
	while(iter != str.end()){
		str.erase(iter);
		iter++;
	}
	cout<<"String after truncation using iterator is: "<<str.c_str()<<endl;*/

    str.erase(str.cbegin(),str.cend());
	cout<<"String after again truncation: "<<str.c_str()<<endl;

	return 0;
}