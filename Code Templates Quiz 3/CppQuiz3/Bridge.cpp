#include <iostream>
#include <list>
#include <string>
using namespace std;


class Implementor {
 public:
  virtual string implementation() const = 0;
};

class ConcreteImplementor1 : public Implementor {
 public:
  string implementation() const override {
    return "ConcreteImplementor1: Here's the result on the platform A.\n";
  }
};

class ConcreteImplementator2 : public Implementor {
 public:
  string implementation() const override {
    return "ConcreteImplementator2: Here's the result on the platform B.\n";
  }
};

class Abstraction {
 protected:
  Implementor* implementation_;
 public:
  Abstraction(Implementor* implementation) : implementation_(implementation) {}

  virtual string Operation() const {
    return "Abstraction: Base operation with:\n" +
           this->implementation_->implementation();
  }
};

class RefinedAbstraction : public Abstraction {
 public:
  RefinedAbstraction(Implementor* implementation) : Abstraction(implementation) {}

  string Operation() const override {
    return "RefinedAbstraction: Extended operation with:\n" +
           this->implementation_->implementation();
  }
};


int main() {
  Implementor* implementation = new ConcreteImplementor1;
  Abstraction* abstraction = new Abstraction(implementation);
  cout << abstraction->Operation() <<endl;
  delete implementation;
  delete abstraction;

  implementation = new ConcreteImplementator2;
  abstraction = new RefinedAbstraction(implementation);
  cout << abstraction->Operation() <<endl;

  delete implementation;
  delete abstraction;

 return 0;
}