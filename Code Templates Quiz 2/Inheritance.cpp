#include <iostream>
using namespace std;

class Person{
public:
    Person();
    Person(const char*n, int a):name(n), age(a){}
    virtual void display(){cout<<"I'm a person"<<endl;}
protected:
    int age;
    const char *name;

};

class Student: public Person{
public:
    Student();
    Student(const char*n, int a, const char* i):Person(n,a),id(i){}
    void display(){cout<<"I'm a student"<<endl;}  // if we comment out, just uses Person::display()
protected:
    const char *id;

};

class Monitor: public Student{
public:
    Monitor();
    Monitor(const char*n, int a, const char* i):Student(n,a, i){}
    void display(){cout<<"I'm a monitor"<<endl;}  // if we comment out, just uses Person::display()
protected:

};

int main(){
    Person a("Alex", 12);
    a.display();

    Student b("Matt", 13, "014");
    b.display();

    Monitor c("Gary", 14, "015");
    c.display();
}