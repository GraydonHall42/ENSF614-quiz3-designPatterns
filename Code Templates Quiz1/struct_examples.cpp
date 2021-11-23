# include  <stdio.h>

struct Point{
    double x; // points x coord
    double y; // points y coord
    char label;
};

// declare while utilizing typedef
typedef struct Point2{
    double x; // points x coord
    double y; // points y coord
    char label;
} Point2;

int main()
{   
    // declaring struct type
    struct Point centre;  // Point object
    struct Point *pst;  // pointer to struct Point
    pst = &centre;  // pst pointing to centre

    // accessing structures data members 
    (*pst).x = 57.66;  // de-reference pointer
    pst -> y = 99.00;  // arrow notation
    centre.label = 'C';  

    // copying a structure
    struct Point centre_copy;
    centre_copy = centre;    

    //using a structre that utilizes typedef
    Point2 p1 = {100.00, 200.00, 'C'};
    
    // only initialize X value
    Point2 p2 = {100};  // y and label are set to 0 and 

    Point p3 = {.x=200};  // this is fine (is same as p2)
    // Point p3 = {.y=200};  // this is illegal!

    // Arrays of structures
    Point2 p4_arr[5]; // declare array with 5 elemetns fo struct variable. values initialized to garbage

    Point2 p5_arr[2] = {
        {100.00, 200.00, 'C'},
        {100.00, 200.00, 'C'}
    };


    return 0;
}