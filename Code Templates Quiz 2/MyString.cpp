#include <assert.h>
#include <string.h>
using namespace std;

class MyString{
public:
    MyString();
    MyString(const char *s);
    MyString(const MyString& s);
    ~MyString();
    MyString& operator=(MyString&s);
private:
    char *storageM;
    int lengthM;
};

// constructor
MyString::MyString(const char *s): lengthM((int)strlen(s)){
    storageM = new char[lengthM+1];
    strcpy(storageM, s);
}

// default constructor
MyString::MyString():lengthM(0), storageM(new char[1]){
    storageM[0] = '/0';
}

// destructor
MyString::~MyString(){
    delete[] storageM;
}

//copy constructor
MyString::MyString(const MyString& s):lengthM(s.lengthM){
    storageM = new char[lengthM+1];
    assert(storageM !=0);
    strcpy(storageM, s.storageM);
}

//overload assignment operator
MyString& MyString::operator=(MyString&s){
    if(this!=&s){
        delete[] storageM;
        lengthM = s.lengthM;
        storageM = new char [lengthM+1];
        assert(storageM != NULL);
        strcpy(storageM, s.storageM);
    }
    return *this;
};