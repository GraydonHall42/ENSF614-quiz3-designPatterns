#include <iostream>
using namespace std;


// abstract class since we make display a virtual function
class Animal{
protected:
    char name[20];
public:
    virtual void display()=0;  // pure virtual function. Must be defined in every child class
};

class Fish: public Animal{
protected:
    char color[20];
public:
    void display(){cout<<"This is a fish"<<endl;}
};

class Cat: public Animal{
protected:
    char color[20];
public:
    void display(){cout<<"This is a cat"<<endl;}
};


// ----------------- Virtual Destructor example --------------
// done to avoid memory leaks
class A{
protected:
    char*s1;
public:
    A(int n){s1 = new char[n];}
    virtual ~A(){delete[] s1;}
};

class B: public A{
protected:
    char*s2;
public:
    B(int n, int m):A(n){s2 = new char[m];}
    virtual ~B(){delete[] s1;}
};

int main(){
    A*p=new B(5,6);
    delete p;
}