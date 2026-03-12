#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

int main(){

    int roll = 9060;
	string roll_number("1011"s);
	// note: 'std::string_view' is only available from C++17 onwards
	//cout<<string_view(num)<<endl;
    cout<<roll_number.c_str()<<endl;

	return 0;
}
