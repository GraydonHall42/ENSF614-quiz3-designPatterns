class DynString {
public:
    DynString();  // default constructor
    DynString(const char *s);      // overloaded constructor
    ~DynString();  // destructor
    int length() const;  // return length
    char get_element(int pos)const;  //getter
    void set_element(int pos, char val); //setter
    const char * c_str() const;  // Return value points to first char in built-in string
    void append(const DynString& tail);  // chars are copied from tail to the end of the string
    void truncate(int new_length);  // REQUIRES: new_length >= 0 && new_length <= length(). Length is reduced to new length
private:
    int lengthM;
    char *storageM;
};

#include <iostream>
using namespace std;

#include <assert.h>
#include <string.h>


int main()
{
    DynString x("foot");
    DynString y;
    DynString z("ball");
    
    x.truncate(3); // "foo"
    x.truncate(0);  // ""
    x.append("foot"); // "foot"
    x.append(y); // "foot"
    x.append(z); // football
    
  return 0;
}

// default constructor
DynString::DynString()
: lengthM(0), storageM(new char[1])
{
    storageM[0] = '\0';
}

// constructor that takes as tring
DynString::DynString(const char *s)
: lengthM ((int)strlen(s))
{
    storageM = new char[lengthM + 1];
    strcpy(storageM, s);
}

// destructor
DynString::~DynString()
{
    delete [] storageM;
}

// getter for length
int DynString::length() const
{
    return lengthM;
}

// getter for a single element
char DynString::get_element(int pos)const
{
    assert(pos >= 0 && pos < length());
    return storageM[pos];;
}

// setter for setting a specific element
void DynString::set_element(int pos, char value)
{
    assert(pos >= 0 && pos < length());
    storageM[pos] = value;
}

// return constant pointer to storageM which holds the string
const char * DynString::c_str() const
{
    return storageM;
}

// truncate the string down to new_length
void DynString::truncate(int new_length)
{
    assert(new_length <= length());
    char *smaller_storage = new char[new_length + 1];  // new storage array on heap
    assert(smaller_storage != NULL);  
    
    // read contents of storageM into smaller_storage
    for (int i = 0; i < new_length; i++)
        smaller_storage[i] = storageM[i];
    
    smaller_storage[new_length] = '\0';  // add '\0' to terminate string
    delete [] storageM;  // delete old storage on heap
    storageM = smaller_storage;
    lengthM = new_length;
    
}

void DynString::append(const DynString& tail){
  int new_length = lengthM + tail.lengthM;  // find new length
  char * holder;  // char array to hold our new string
  holder = new char[new_length+1]; 
  strcpy(holder, storageM);  // copy starageM contents into holder first

  // copy contents of tail into holder
  for (int i = 0; i < tail.lengthM; i++) {
    holder[i+lengthM] = tail.storageM[i];
  }

  holder[new_length] = '\0';
  storageM = holder;
  lengthM = new_length;
}
