#include <iostream>
#include <list>
#include <string>
using namespace std;


// ProductA: create 2 versions of it (A1 and A2)
class AbstractProductA {
 public:
  virtual ~AbstractProductA(){};
  virtual string UsefulFunctionA() const = 0;
};

class ConcreteProductA1 : public AbstractProductA {
 public:
  string UsefulFunctionA() const override {
    return "The result of the product A1.";
  }
};

class ConcreteProductA2 : public AbstractProductA {
  string UsefulFunctionA() const override {
    return "The result of the product A2.";
  }
};

// ProductB: create 2 versions of it (B1 and B2)
class AbstractProductB {
 public:
  virtual ~AbstractProductB(){};
  virtual string UsefulFunctionB() const = 0;
  virtual string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const = 0;
};


class ConcreteProductB1 : public AbstractProductB {
 public:
  string UsefulFunctionB() const override {
    return "The result of the product B1.";
  }

  string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const override {
    const string result = collaborator.UsefulFunctionA();
    return "The result of the B1 collaborating with ( " + result + " )";
  }
};

class ConcreteProductB2 : public AbstractProductB {
 public:
  string UsefulFunctionB() const override {
    return "The result of the product B2.";
  }

  string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const override {
    const string result = collaborator.UsefulFunctionA();
    return "The result of the B2 collaborating with ( " + result + " )";
  }
};

// create 2 factories. Each one creates a product A and B
class AbstractFactory {
 public:
  virtual AbstractProductA *CreateProductA() const = 0;
  virtual AbstractProductB *CreateProductB() const = 0;
};

// factory using A1 and B1
class ConcreteFactory1 : public AbstractFactory {
 public:
  AbstractProductA *CreateProductA() const override {
    return new ConcreteProductA1();
  }
  AbstractProductB *CreateProductB() const override {
    return new ConcreteProductB1();
  }
};

// factory using A2 and B2
class ConcreteFactory2 : public AbstractFactory {
 public:
  AbstractProductA *CreateProductA() const override {
    return new ConcreteProductA2();
  }
  AbstractProductB *CreateProductB() const override {
    return new ConcreteProductB2();
  }
};

// code to test out an Abstract Factory
void ClientCode(const AbstractFactory &factory) {
  const AbstractProductA *product_a = factory.CreateProductA();
  const AbstractProductB *product_b = factory.CreateProductB();
  cout << product_b->UsefulFunctionB() << "\n";
  cout << product_b->AnotherUsefulFunctionB(*product_a) << "\n";
  delete product_a;
  delete product_b;
}

int main() {
  cout << "Client: Testing client code with the first factory type:\n";
  ConcreteFactory1 *f1 = new ConcreteFactory1();
  ClientCode(*f1);
  delete f1;
  cout << endl;

  cout << "Client: Testing the same client code with the second factory type:\n";
  ConcreteFactory2 *f2 = new ConcreteFactory2();
  ClientCode(*f2);
  delete f2;
  return 0;
}