#include<string>
#include<iostream>
using namespace std;

int main(){
    
    string str("Good day string. Today is beautiful");

    cout << "Locating all instances of substring \"day\"" << endl;
    size_t subStrPos = str.find ("day", 0);

    while (subStrPos != string::npos){
    cout << "\"day\" found at position " << subStrPos+1 << endl;

    // Make find() search forward from the next character onwards
    size_t searchOffset = subStrPos + 1;
    subStrPos = str.find ("day", searchOffset);
}

    //find_first_of()
    //find_first_not_of()
    //find_last_of()
    //find_last_not_of()

	return 0;
}