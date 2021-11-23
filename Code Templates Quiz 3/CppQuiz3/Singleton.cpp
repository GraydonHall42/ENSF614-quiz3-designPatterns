#include <iostream>
#include <list>
#include <string>
#include <thread>

using namespace std;

class Singleton{
protected:
    Singleton(const string value): value_(value){}
    static Singleton* singleton_;
    string value_;

public:
    Singleton(Singleton &other) = delete;
    void operator=(const Singleton &) = delete;
    static Singleton *GetInstance(const string& value);
    void SomeBusinessLogic(){}
    string value() const{return value_;} 
};

// initialize static varialbe
Singleton* Singleton::singleton_= nullptr;;

Singleton *Singleton::GetInstance(const string& value)
{
    if(singleton_==nullptr){
        singleton_ = new Singleton(value);
    }
    return singleton_;
}


int main()
{
    cout <<"If you see the same value, then singleton was reused (yay!\n" <<
                "If you see different values, then 2 singletons were created (booo!!)\n\n" <<
                "RESULT:\n";   

    Singleton* singleton1 = Singleton::GetInstance("FOO");
    cout << singleton1->value() << "\n";
    Singleton* singleton2 = Singleton::GetInstance("BAR");
    cout << singleton2->value() << "\n";

    return 0;
}