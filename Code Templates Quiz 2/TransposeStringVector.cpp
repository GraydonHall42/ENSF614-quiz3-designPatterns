#include<vector>
#include<string>
#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;

typedef vector<string> String_Vector;

String_Vector transpose(const String_Vector& sv);

int main() {
    
    const int ROWS = 5;
    const int COLS = 4;
    
    char c = 'A';
    String_Vector sv;
    sv.resize(ROWS);
    
    // populate string vector
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++) {
            sv.at(i).push_back(c);
            c++;
            if(c == 'Z' + 1)
                c = 'a';
            else if (c == 'z' + 1)
                c = 'A';
        }
    }
    
    for(int i = 0; i < ROWS; i++) {
        cout<< sv.at(i);
        cout << endl;
    }

    cout << "\nTransposed vector: \n";
    
    String_Vector vs = transpose(sv);
    for(int i = 0; i < (int)vs.size(); i++)
        cout << vs.at(i) << endl;
    
    return 0;
}


// Function to transpose String Vector
String_Vector transpose (const String_Vector& sv) {

    int sv_rows = sv.size();
    int sv_cols = sv.at(0).size();

    int vs_rows = sv_cols;
    int vs_cols = sv_rows;
    
    String_Vector vs;
    vs.resize(vs_rows);

    for(int i=0; i<vs_rows; i++){
        for(int j=0; j<vs_cols; j++){
            vs.at(i).push_back(sv.at(j).at(i));
        }
    }
    
    return vs;
    
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