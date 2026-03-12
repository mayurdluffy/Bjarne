#include<iostream>
using namespace std;

template<typename T>
class Teststatic{
public:
	static int staticVal;
};
//Static member initialization 
template<typename T> int Teststatic<T>::staticVal;

int main(){
    Teststatic<int> intInstance;
    intInstance.staticVal = 2021;
    cout<<"Value of static attribute is: "<<intInstance.staticVal<<endl;
	return 0;
}