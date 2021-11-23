// Your First C++ Program

int non_decreasing2(int* arr, int n);
void push_back(int el_val);

int main() {
    // declare array on stack
    int y [] = {5, 5, 5, 10};
    // int x2 = y;  // this is ILLEGAL to copy an arrray

    // declare array dynamically on the heap. (initialized to garbage initially)
    int* x1;
    x1 = new int[5]; 
    x1[0] = 1;

    int z1 = non_decreasing(y, 4);
    int z2 = non_decreasing2(y, 4);

    return 0;
}


// using pointer notation
int non_decreasing(int* arr, int n){
    while(n){
        if(*arr > *(arr+1)){
            return 0;
        }
        arr++;
        n--;
    }
    return 1;
}

// using array notation
int non_decreasing2(int* arr, int n){
    for(int i =0; i<n; i++){
        if(arr[i] > arr[i+1]){
            return 0;
        }
    }
    return 1;
}


