#include <iostream>

class IntVector
{
public:
    IntVector() : storeM(0), end_storeM(0) {} // no need for ;
    IntVector(const int *begin, const int *end);
    IntVector(const IntVector &src);            // so can pass by ref?
    IntVector &operator=(const IntVector &rhs); // truly what is this??
    ~IntVector();
    int size() const { return (int)(end_storeM - storeM); }
    const int &at(int i) const { return storeM[i]; } // so this is returning a reference?
    int &at(int i) { return storeM[i]; }
    void push_back(int el_val);
    void remove_all(int val);

private:
    int *storeM;
    int *end_storeM;
};

IntVector::IntVector(const int *begin, const int *end) : storeM(0), end_storeM(0)
{
    if (begin == end)
        return;
    size_t count = end - begin;
    storeM = new int[count];
    end_storeM = storeM + count;
    for (size_t i = 0; i < count; i++)
        storeM[i] = begin[i];
}

IntVector::~IntVector()
{
    delete[] storeM;
}

void IntVector::push_back(int el_val)
{
    int* temp;  // pointer to hold temporary array
    int new_size = size() + 1;

    temp = new int[size()+1];  // dynamically allocate array one elemeng bigger than old one
    
    // copy contents of storeM to temp
    for(int i=0; i<size(); i++){
        temp[i] = storeM[i];
    }

    temp[size()]=el_val;  // add el_val to end of temp
    delete [] storeM;  // get rid of old storeM
    storeM = temp;  // set storeM pointer to new array
    end_storeM = storeM + new_size;  //place end_storeM in correct place
}

void IntVector::remove_all(int val)
{
    int count = 0;

    // get count of values that != val
    for(int i=0; i<size(); i++){
        if (storeM[i] != val){
            count++;  
        }
    }

    // temp array to hold our numbers that != val
    int * temp;
    temp = new int[count];

    // add all values != val to temp
    int j =0;
    for(int i=0; i<size(); i++){
        if (storeM[i] != val){
            temp[j] = storeM[i];
            j++;
        }
    }

    delete [] storeM;
    storeM = temp;
    end_storeM = storeM + count;

}

int main()
{
    int a[] = {12, 25, 18, 25, 30, 2};
    IntVector v2(a, a + 6);
    for (int i = 0; i < v2.size(); i++)
        std::cout << v2.at(i) << std::endl;
    std::cout << "\n";

    v2.push_back(40);
    for (int i = 0; i < v2.size(); i++)
        std::cout << v2.at(i) << std::endl;
    std::cout << "\n";

    v2.remove_all(25);
    for (int i = 0; i < v2.size(); i++)
            std::cout << v2.at(i) << std::endl;

    return 0;
}