// struct.c 
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
    add code for struct here.
*/
static const int max_name_length = 51;

typedef struct Student {
    
    int age;
    char first_name[max_name_length];
    char last_name[max_name_length];
    int standard;
} Student;

int main() {
    Student st;
    
    cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;
    
    return 0;
}
