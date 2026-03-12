#include<iostream>
using namespace std;

template<typename T1=int, typename T2=double>
class Holdspair{
private:
	T1 val1;
	T2 val2;
public:
	Holdspair(T1 t1,T2 t2){
		val1 = t1;
		val2 = t2;
	}

	const T1& getval1() const{
		return val1;
	}

	const T2& getval2() const{
		return val2;
	}
};

int main(){
	Holdspair<> holdspair(2,3.14);
	cout<<"First value is: "<<holdspair.getval1()<<endl;
	cout<<"Second value is: "<<holdspair.getval2()<<endl;

	Holdspair<double, const char*> holdspair(3.14,"PI");
	cout<<"\n\nFirst value is: "<<holdspair.getval1()<<endl;
	cout<<"Second value is: "<<holdspair.getval2()<<endl;
	return 0;
}