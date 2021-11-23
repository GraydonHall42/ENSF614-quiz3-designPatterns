// Your First C++ Program
#include <string.h>
#include <stdio.h>

int compareMySTrings_ptrNotation(const char* arg1, const char* arg2);
int compareMySTrings_arrNotation(const char* arg1, const char* arg2);
int str_len_arr_notation(const char* s1);
int str_len_ptr_notation(const char* s1);
void my_strncat(char *dest, const char *source, int n);
int legal_vs_illega_example(); 

// ********* STRING PRACTICE **********
int main() {
    // ********** Different ways to declare strings **********

    // strings found on static area  
    const char * s1 = "AB";
    const char * s2 = "ABCD";
    char s10[10];  // initilaizes blank char array filled with garbage

    // declare char pointer, assign value after
    const char * s11;
    s11 = "abcd";

    // dynamically allocated string
    char * s3;
    s3 = new char[5]; 
    strcpy(s3,s2);

    // string found on stack
    char s4[] = "Hello";

    // 6 element char array, last 2 elements are '\0'
    char s5[6] = "Jack";

    // 10 element char array, all elements except first 3 filled with junk
    char s6[10];
    s6[0] = 'a';
    s6[1] = '\0';

    // ********** Working with Strings **********

    // working with strings (both array and pointer notation)
    int x1 = compareMySTrings_arrNotation(s1, s2);
    int x2 = compareMySTrings_ptrNotation(s1, s2);
    int x3 = str_len_arr_notation(s2);
    int x4 = str_len_ptr_notation(s2);
    int x5 = strlen(s2);  // use built in functions to find length of a string

    // string copying and concatenation
    char s7[8];
	strcpy(s7, "foo");
	strcat(s7, "bar");
    printf ("\n%s", s7); /* Array: 'f' 'o' 'o' 'b' 'a' 'r' '\0' ?? ... last element is junk*/


    // use my string concat function
    char s8[15] = "hello";
    char s9[] = " world";
    my_strncat(s8, s9, 6);
    printf("\n concatenated string: %s", s8);

    
    

    return 0;
}

int compareMySTrings_arrNotation(const char* arg1, const char* arg2){
    int i = 0;
    while(arg1[i] != '\0' || arg2[i] != '\0'){
        if(arg1[i] > arg2[i]){
            return 1;
        } else if (arg1[i] < arg2[i]){
            return -1;
        } else{
            i++;
        }
    }
    return 0;
}

int compareMySTrings_ptrNotation(const char* arg1, const char* arg2){
    
    while(*arg1 != '\0' || *arg2 != '\0'){
        if(*arg1 > *arg2){
            return 1;
        } else if (*arg1 < *arg2){
            return -1;
        } else{
            arg1++;
            arg2++;
        }
    }
    return 0;
}

int str_len_arr_notation(const char* s1){
    int i = 0;
    while(s1[i] != '\0'){
        i++;
    }
    return i;
}

int str_len_ptr_notation(const char* s1){
    int i=0;
    while(*s1 !='\0'){
        s1++;
        i++;
    }
    return i;
}

// append first n chars of source to dest
void my_strncat(char *dest, const char *source, int n){
    int i = 0;
    while(dest[i] != '\0'){
        i++;
    }
    int j = 0;
    while(source[j] != '\0' && j<=n){
        dest[i] = source[j];
        i++;
        j++;
    }
    dest[i] = '\0';

}

// key point: if we declare a string so it's held on the string constant area it's illegal to change it
int legal_vs_illega_example()
{
   char * s3 = "BCD";  // best to have const in front so instead i get compilation error 
//    s3[0]='A'; // this is illegal!

   char s4[] = "BCD";
   s4[0]='A'; // this is okay though!

   printf("%s", s3); // %s is format specifier

   return 0;
}



