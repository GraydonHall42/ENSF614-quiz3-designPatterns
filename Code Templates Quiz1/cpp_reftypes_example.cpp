void modify(int &x);
int max(const int& x, const int & y);
int & modify2(int &x);

int main()
{
    int a, b;  // 2 integer variables
    a = 5;
    b = 6; 

    int & ref_b = b;  // ref b is a reference to b

    int * ptr_a = &a; // pointer to a
    int * & ref_ptr_a = ptr_a;  // reference to ptr_a

    int z = 45;
    modify(z);  // z now 45 after this

    int c = max(a, b-2);  // a=5, b=6, so c=5. 

    // exapmle of returning a reference type
    // this function modifies z and d is now a reference to z as well
    int & d = modify2(z);  // z was 46, now is 47. 
    d++; // z now 48

}

// variable is passed to funciton by reference
void modify(int &x){
    x++;
}

// example of returning a reference type
int & modify2(int &x){
    x++;
    return x;
}

// key: if we want to pass an expression to a fucntion, the reference type must be const
// temporary anonymous memory space will be created
int max(const int& x, const int & y){
    return (x>y)? x: y;
    // return x if statement is true, else return y
}