#include <assert.h>
#include <string.h>
using namespace std;

class MyString
{
public:
    MyString();
    MyString(const char *s);
    MyString(const MyString &s);
    ~MyString();
    MyString &operator=(MyString &s);

private:
    char *storageM;
    int lengthM;
};

// constructor
MyString::MyString(const char *s) : lengthM((int)strlen(s))
{
    storageM = new char[lengthM + 1];
    strcpy(storageM, s);
}

// default constructor
MyString::MyString() : lengthM(0), storageM(new char[1])
{
    storageM[0] = '/0';
}

// destructor
MyString::~MyString()
{
    delete[] storageM;
}

//copy constructor
MyString::MyString(const MyString &s) : lengthM(s.lengthM)
{
    storageM = new char[lengthM + 1];
    assert(storageM != 0);
    strcpy(storageM, s.storageM);
}

//overload assignment operator
MyString &MyString::operator=(MyString &s)
{
    if (this != &s)
    {
        delete[] storageM;
        lengthM = s.lengthM;
        storageM = new char[lengthM + 1];
        assert(storageM != NULL);
        strcpy(storageM, s.storageM);
    }
    return *this;
};

MyString *fun()
{
    MyString s1;
    MyString s2("XY");
    MyString *s3 = NULL;
    MyString *s4 = NULL;

    s3 = new MyString("AD");
    s4 = new MyString("TD");

    return s3;
}

MyString &fun2()
{
    MyString *s3 = NULL;
    s3 = new MyString("AD");
    return *s3;
}

int main()
{
    MyString *p = NULL;
    p = fun();

    {
        MyString q = fun2();
        MyString &r = fun2();
        int y = 0;
    } // q dtor is called but no r dtor - what happens to r's pointer?
    int i = 0;

    delete p;

    return 0;
}