using namespace std;
#include <iostream>

class Engine {
private:
    int size;
public:
    Engine (int size){this->size = size;}
};

// composition example 1: Use static object of Engine in class Car
class Car1{
private:
    Engine engine;
public:
    Car1(int size): engine(size){}
};

// Composition example 2: dynamic memory allocation
class Car2{
private:
    Engine* engine;
public:
    Car2(int size){
        engine = new Engine(size);
    }
};

// Composition example 2.2: dynamic memory allocation (alternate syntax)
class Car22{
private:
    Engine* engine;
public:
    Car22(int size):engine(new Engine(size)){}
};

//Aggregation Example: Engine is passed to the constructor
class Car3{
private:
    Engine * engine;
public:
    Car3(Engine* engine){this->engine = engine;}
};


int main(){
    // composition
    Car1 x = Car1(4);
    Car2 y = Car2(4);
    Car22 z = Car22(4);

    // aggregation
    Engine a = Engine(4);  // Or Engine a(4)
    Car3 b = Car3(&a);
    return 0;
}