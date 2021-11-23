#include <vector>
#include <iostream>
using namespace std;

// example pass vector to a function
double average(const vector<int>& data){
    double sum=0;
    for(int i=0; i<data.size(); ++i){
        sum += data[i];
    }
    return sum / data.size();
}

int main(){
    // declaring a vector
    vector<double> a1;  // creates an empty vector
    vector<double> a2(0);  // also is an empty vector
    vector<double> a3(5); // has 5 elements all with 0

    vector<double> a4(3, 300);  // has 3 elements each containing 300.o

    // accessing values of vector.
    vector<double> a5(4);
    a5[0] = 0;  // accessing via square brackets (no boundary checking)
    a5[1] = 1;
    a5.at(2) = 2;  // accessing using .at() (performs boundary checking)
    a5.at(3) = 3;

    //copying vectors
    vector<double> a6(a5); //copy elements of a5 to a6

    // example: read 4 numbers and print them in reverse order
    vector<int> numbers(4);
    for(int i=0; i<numbers.size(); ++i){
        cout << "Please enter an integer number: " << endl;
        cin >> numbers[i];
    }

    cout << "\nNumbers you entered in reverse: " << endl;
    for(int i=numbers.size()-1; i>=0; --i){
        cout << numbers[i] <<endl;
    }


    // other vector functions
    vector <double> v (3, 1);
    v.empty();  // returns true if vector is empty
    v.push_back(4);  // inserts value 4 at the end of the vector
    v.pop_back(); 
    v.assign(3,2);  // assigns value of 2 to first 2 elements
    v.clear();  // deletes all elements

    // alternate vector initialization
    vector<int> a7{ 10, 20, 30 };
    // cout << "average of vector a7 is : " << average(a7) << endl;
    
    // vector of vectors (matrix)
    vector<vector<int>> v;  // define v, a vector of vectors

    typedef vector<vector<int>> matrix;
    matrix m;

    //setting rows and columns for your matrix:
    const int numRows = 3;
    const int numCols = 5;
    m.resize(numRows);
    for(int j=0; j<numRows;j++){
        m.at(j).resize(numCols);
    }

    //accessing vector elments
    cout<< "Element at row 3 column 5: "<< m.at(2).at(4) <<endl;

    return 0;
}


double average(const vector < vector<int>>& m){
    int rows = m.size();
    int cols = m.at(0).size();
    double sum = 0;
    double count = 0;

    for(int i =0; i<rows; i++){
        for(int j=0; j<rows; j++){
            sum += m.at(i).at(j);
            count ++;
        }
    }

    return sum/count;

}

