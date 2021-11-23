#include <iostream>
using namespace std;

void swapPointers(int **x, int**y){
    int *temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int a=23, b=40;
    int* p1 = &a;
    int* p2 = &b;

    swapPointers(&p1, &p2);
    cout << "a = " << *p1 << endl;
    cout << "b = " << *p2 << endl;
    // a and b are unchaged, it's just that the pointers are swapped
    
    return 0;
}