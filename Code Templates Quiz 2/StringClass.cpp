#include <string>
#include <iostream>
#include <limits>
using namespace std;

// example of using string as a function argument.
// recommended you pass by reference
void greeting(string& name){
    cout<< "Hello " << name << " hope you're having a great day :)" << endl;
}


int main(){
    //declaring a string
    string a1; // declare an empty string
    string a2("This is my string");
    string a3(4, 'G'); // create string containing 4 'G' chars

    // get size of string
    int s = a3.size();

    // using assignment operaotr with strings....
    // string on LHS is automatically resized
    string a4("First String");
    string a5("Second string"); 

    a4 = "Third String";
    a5 = 'b';
    a5 = a4;

    string a6 = "Graydon";
    greeting(a6);

    // appending
    string a7 = "fileName";
    a7.append(".cpp");
    cout << a7 << endl;

    // read two words from terminal... cout goes up until first whitespace
    string first_word, second_word;
    cout << "Enter two words:" <<endl;
    cin >> first_word >> second_word;
    cout << "Your first word was: " << first_word << endl;
    cout << "Your second word was: " << second_word << endl;

    //flush the new line out of the buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // must have #include <limiits>

    // read entire line of text
    string line_of_text;
    cout << "enter a line of text: ";
    getline( cin, line_of_text);
    cout << "Your line of text was: " << line_of_text;

    //removing and insertin characters
    string course = "ENCM 339 Class";
    course.erase(4,3);  // course is "ENCM Class"
    course.insert(4, "369");  // course is "ENCM Class"

}