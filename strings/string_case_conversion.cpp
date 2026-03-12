#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

int main(){

	string str1("Focus on the process, not on the path.");
	cout<<"String is: "<<str1.c_str()<<endl;

	string str2(str1);
	transform(str2.begin(),str2.end(),str2.begin(),::toupper);
	cout<<"String after convsersion to upper casse is: "<<str2.c_str()<<endl;

	transform(str1.begin(),str1.end(),str1.begin(),::tolower);
	cout<<"String after conversion to lower case is: "<<str1.c_str()<<endl;

	// Iterate through each character by reference
    for (char& c : str2) {
        c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
    }
    std::cout << str2 << std::endl;

	return 0;
}
