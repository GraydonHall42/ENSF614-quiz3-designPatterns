#include<iostream>
#include<fstream>
#include <vector>
using namespace std;

// define student struct
struct Student {
    int roll_no;
    string name;
};
int main() {

    // create output file stream
    ofstream wf("student.dat", ios::out | ios::binary);

    // check for failure
    if(!wf) {
        cout << "Cannot open file!" << endl;
        return 1;
    }

    // create array of 3 students and populate it
    Student wstu[3];
    wstu[0].roll_no = 1;
    wstu[0].name = "Ram";
    wstu[1].roll_no = 2;
    wstu[1].name = "Shyam";
    wstu[2].roll_no = 3;
    wstu[2].name = "Madhu";

    // write each student to the binary file
    for(int i = 0; i < 3; i++)
        wf.write((char *) &wstu[i], sizeof(Student));

    // close connection
    wf.close();

    // check if any errors while writing
    if(!wf.good()) {
        cout << "Error occurred at writing time!" << endl;
        return 1;
    }

    // create input stream
    ifstream rf("student.dat", ios::binary);
    if(!rf) {
        cout << "Cannot open file!" << endl;
        return 1;
    }
 
    // alternative: use while loop and vector
    vector<Student> studentVec;
    Student tempStudent;
    while(rf.read((char *)(&tempStudent), sizeof(Student))){
        studentVec.push_back(tempStudent);
    }
    rf.close();

    if(!rf.good()) {
        cout << "Error occurred at reading time!" << endl;
    }

    cout<<"Student's Details:"<<endl;
    for(int i=0; i < studentVec.size(); i++) {
        cout << "Roll No: " << studentVec.at(i).roll_no << endl;
        cout << "Name: " << studentVec.at(i).name << endl;
        cout << endl;
    }

    return 0;
}