#include <iostream>

using namespace std;

int main () {
  const char *p[3];		
  p[0] = "XYZ";			
  p[1] = "KLM";
  p[2] = "ABC";

  // without *, the result is the address
  cout << p << endl;		          // p without * - prints: address of XYZ
  
  // *p is the exact same as p[0]
  // parentheses influence how the pointer moves - either to the next element
  // within the same string, or to the next element in the array of p
  cout << *p << endl;		          // *p is a pointer to "XYZ" - prints: XYZ
  cout << *(p+1) << endl;         // move the pointer to "KLM" - prints: KLM
  cout << *(p+2) << endl;         // move the pointer to "ABC" - prints: ABC
  cout << p[0] << endl;		        // p[0] is a pointer to "XYZ" - prints: XYZ
  cout << p[1] << endl;           // p[1] is a pointer to "KLM" - prints: KLM
  cout << p[2] << endl;           // p[2] is a pointer to "ABC" - prints: ABC
  
  cout << p+1 << endl;            // move the pointer to "KLM" - prints: address of KLM
  cout << *p+1 << endl;           // move the pointer to "Y" - prints: YZ
  cout << p[0]+1 << endl;         // move the pointer to "Y" - prints: YZ
  cout << *(p+1)+1 << endl;       // move the pointer to "L" - prints: LM
  cout << p[1]+1 << endl;         // move the pointer to "L" - prints: LM
  
  cout << **p << endl;            // **p is a char – prints: X
  cout << *(*(p+1)) << endl;      // **p is a char – prints: K
  cout << *(*(p+2)) << endl;      // **p is a char – prints: A
  cout << *p[0] << endl;          // *p[0] is a char – prints: X
  cout << *p[1] << endl;          // *p[1] is a char – prints: K
  cout << *p[2] << endl;          // *p[2] is a char – prints: A

  cout << *p[0]+1 << endl;        // prints: 89 (ASCII of X + 1 = ASCII of Y, which is 89), NOT pointing at Y
  cout << *(p[0]+1) << endl;      // prints: Y
  cout << *(p[0]+1)+1 << endl;    // prints: 90 (ASCII of Y + 1 = ASCII of Z, which is 90), NOT pointing at Z
  cout << *(p[0]+2) << endl;      // prints: Z
  cout << *(p[1])+1 << endl;      // prints: 76 (ASCII of K + 1 = ASCII of L, which is 76), NOT pointing at L
  cout << *(p[1]+1) << endl;      // prints: L
  

  cout << **p+1 << endl;          // prints: 89 (ASCII of X + 1 = ASCII of Y, which is 89), NOT pointing at Y
  cout << *(*p+1) << endl;        // prints: Y
  cout << *(*p+1)+1 << endl;      // prints: 90 (ASCII of Y + 1 = ASCII of Z, which is 90), NOT pointing at Z
  cout << *(*p+2) << endl;        // prints: Z
  cout << *(*(p+1))+1 << endl;    // prints: 76 (ASCII of K + 1 = ASCII of L, which is 76), NOT pointing at L
  cout << *(*(p+1)+1) << endl;    // prints: L
  

  // if we want to access "C", there are multiple ways
  cout << *(p+2)+2 << endl;       // prints the string from "C" onwards
  cout << p[2]+2 << endl;         // prints the string from "C" onwards
  cout << *(*(p+2)+2) << endl;    // prints the char "C"
  cout << *(p[2]+2) << endl;      // prints the char "C"
  
}
