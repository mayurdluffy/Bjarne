#include<iostream>
using namespace std;

// template function which can accept anonymous number of arguments
template<typename Result, typename First, typename ... Rest>
auto Sum(Result& result, First var1,Rest...varN){
	result += var1;
	return Sum(result,varN...);
}

int main(){
   
    int result = 0;
    Sum(result,3,5,7,10);
    cout<<"Sum(3,5,7,10) is: "<<result<<endl;
	return 0;
}