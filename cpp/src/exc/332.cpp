#include <iostream>
#include <cstdlib>
using namespace std;
class myException {
	string message;
	public:
	myException(string msg)
  {message = msg;}
	string what(void)
  {return message;}
};
class doubleArrayCls{
	double* data = nullptr;
	int size = 0;
  void copy(double*a , int sz){
		data = new double[size=sz] ;
		for(int i=0 ; i<size; i++)
      data[i] = a[i];
  }
	public:
	doubleArrayCls() = default;
	doubleArrayCls(double* a, int sz)
  {copy(a, sz);}
  doubleArrayCls(const doubleArrayCls& a)
  {copy(a.data, a.size);}
  doubleArrayCls(const int n1){data = new double[size = n1];}
	~doubleArrayCls()
  {delete[] data;data=nullptr;size=0;}
	doubleArrayCls operator+(
      doubleArrayCls& a){
		if(size != a.size)
      throw myException("Length of two arrays are not equal");
		doubleArrayCls retVal(size);
		for(int i=0; i < size ; i++)
			retVal.data[i]=data[i]+a.data[i];
		return retVal;
	}
	doubleArrayCls operator-(
      doubleArrayCls& a){
		if(size != a.size) 
      throw myException("Length of two arrays are not equal");
		doubleArrayCls retVal(size);
		for(int i=0; i < size ; i++)
      retVal.data[i]=data[i]-a.data[i];
		return retVal;
	}
	doubleArrayCls operator=(
      const doubleArrayCls& a){
		delete[] data;
    copy(a.data, a.size);
		return *this;
	}
	double& operator[](int index){
		if(index >= size || index < 0) 
      throw myException("Index is out of range");
		return data[index];
	}
};
int main(){
	double t1[]={1,2,3,4,5,6}, 
    t2[]={11,12,13,14,15,16};
	double t3[]={21,22,23,24,25,26}, 
    t4[] = {1,2}, t5[]={3,4} ;
	doubleArrayCls a(t1,6), b(t2,6), 
    c(t3,6), d(t4,2), e(t5,2), f, g;
	try{
		f = a + b - c ;
		g = e + f;
		f = a - e;
		f = b - d;
	}catch(myException &ex1)
  {cout<<ex1.what()<<endl;}
	catch(...)
  {cout << "unknown exception" << endl;}
	try{
		a[5] = 12 ;
		cout << a[5]<<endl;
		a[9] = 8;
		cout << a[-1]<<endl;
	}
	catch(myException& ex1)
  {cout << ex1.what() << endl;}
	catch(...)
  {cout << "unknown exception" << endl;}
	int am[20];
  for(int& imm : am) 
    imm=2;
}
