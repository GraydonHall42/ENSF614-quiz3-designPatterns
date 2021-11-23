#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * The Target defines the domain-specific interface used by the client code.
 */

class Target {
    public:
    virtual string Request() const =0;
};

/**
 * The Adaptee contains some useful behavior, but its interface is incompatible
 * with the existing client code. The Adaptee needs some adaptation before the
 * client code can use it.
 */
class Adaptee {
 public:
  string SpecificRequest() const {
    return ".eetpadA eht fo roivaheb laicepS";
  }
};

/**
 * The Adapter makes the Adaptee's interface compatible with the Target's
 * interface.
 */
class Adapter : public Target {
 private:
  Adaptee *adaptee_;

 public:
  Adapter(Adaptee *adaptee) : adaptee_(adaptee) {} // constructor
  
  
  string Request() const override {
    string to_reverse = this->adaptee_->SpecificRequest();  // get the request from the adaptee    
    reverse(to_reverse.begin(), to_reverse.end());  // perform logic on it so it can be used
    return "Adapter: (TRANSLATED) " + to_reverse;  // return usable version
  }
};

/**
 * The client code supports all classes that follow the Target interface.
 */
void ClientCode(const Target *target) {
  cout << target->Request();
}

int main() {

  Adaptee *adaptee = new Adaptee;
  cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:\n";
  cout << "Adaptee: " << adaptee->SpecificRequest();
  cout << "\n\n";

  cout << "Client: But I can work with it via the Adapter:\n";
  Adapter *adapter = new Adapter(adaptee);
  ClientCode(adapter);
  cout << "\n";

  delete adaptee;
  delete adapter;

  return 0;
}