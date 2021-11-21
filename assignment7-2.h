#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
using namespace std;

class my_string {
public:
    my_string();
    my_string(const char* s);
    my_string(const my_string& copy);
    ~my_string();
    my_string& operator=(const my_string& cs);
    my_string& operator+(const my_string& cs);
    char* getString();
    void print(ostream* os);
    
    friend ostream& operator<<(ostream& os, my_string& str);
    
private:
    char* cstring;
    int clength;
};

my_string::my_string() {
    cstring = NULL;
    clength = 0;
}

my_string::my_string(const char* s) {
    clength = (int)strlen(s) + 1;
    cstring = new char[clength];
    strcpy(cstring, s);
}

my_string::my_string(const my_string& copy) {
    clength = copy.clength;
    cstring = new char[clength];
    strcpy(cstring, copy.cstring);
}

my_string::~my_string() {
    if (cstring) delete []cstring;
}

my_string& my_string::operator=(const my_string& cs) {
    if (cstring==NULL) return *this;
    if (cstring) delete[]cstring;
    clength = cs.clength;
    cstring = new char[clength];
    strcpy(cstring, cs.cstring);
    return *this;
}

my_string& my_string::operator+(const my_string& cs){
    char* temp = new char[clength+cs.clength-1];
    if (cstring) strcpy(temp, cstring);
    if (cs.cstring) strcat(temp, cs.cstring);
    my_string addString(temp);
    delete []temp;
    return addString;
}

char* my_string::getString() {
    return cstring;
}

void my_string::print(ostream* os) {
    *os << cstring;
}

ostream& operator<<(ostream& os, my_string& str) {
    os << str.getString();
    return os;
}
