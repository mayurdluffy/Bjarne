#include<iostream>
using namespace std;

template<typename T1=int, typename T2=double>
class Holdspair{
private:
	T1 value1;
	T2 value2;
public:
	Holdspair(T1 val1,T2 val2){
		value1 = val1;
		value2 = val2;
	}

	const T1& getvalue1() const{
		return value1;
	}

	const T2& getvalue2() const{
		return value2;
	}
};

//Specialization of Holdspair for type int , int
template<>
class Holdspair<int,int>{
private:
	int value1;
	int value2;
public:
	Holdspair(int val1,int val2){
		value1 = val1;
	    value2 = val2;
	}

	const int& getvalue1() const{
		return value1;
	}

	const int& getvalue2() const{
		return value2;
	}
};


int main(){
	Holdspair<> holdspair(2,3.14);
	cout<<"First value is: "<<holdspair.getvalue1()<<endl;
	cout<<"Second value is: "<<holdspair.getvalue2()<<endl;

	Holdspair<int,int> holdspair(2,3);
	cout<<"\n\nFirst value is: "<<holdspair.getvalue1()<<endl;
	cout<<"Second value is: "<<holdspair.getvalue2()<<endl;
	return 0;
}