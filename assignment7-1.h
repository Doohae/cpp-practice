//assignment6 과제에 이어서 assignment7 code 작성 (밑부분에 표시)
//20171357 정두해
//printing operator, copy constructor, assignment operator 순

#include <iostream>
#include <cmath>
using namespace std;

class Polynomial {
public:
    Polynomial(int d=0);
    ~Polynomial();
    void set(int i, double v);
    double get(int i) const;
    int degree() const;
    double evaluate(double x) const;
    
//    new function declarations
//    for assignment7
    void print(ostream* os);
    Polynomial(Polynomial& source);
    Polynomial& operator=(Polynomial& source);
    friend ostream& operator<<(ostream& os, Polynomial& poly);
//    new function declarations end here
    
private:
    double *a;
    int d;
};

Polynomial::Polynomial(int d) {
    this->d = d;
    this->a = new double[d];
    for (int index=0; index<d; index++) {
        if (index==0) this->a[index]=1;
        else this->a[index] = 0;
    }
}

Polynomial::~Polynomial() {
    if (a != 0) {
        delete [] a;
    }
}

void Polynomial::set(int i, double v) {
    this->a[i] = v;
}

double Polynomial::get(int i) const {
    if (i>d) cout << "put smaller integer" << endl;
    return (double)this->a[i];
}

int Polynomial::degree() const {
    return (int)this->d;
}

double Polynomial::evaluate(double x) const {
    double eval = 0;
    for (int j=0; j<d; j++) {
        eval += (this->a[j]) * pow(x, j);
    }
    return eval;
}

//^^ previous assignment code ^^
//Here Starts three new functions for assignment7-1

void Polynomial::print(ostream* os) {
    *os << "Current Polynomial Degree and Constant: " << degree << ", " << a[0];
}

ostream& operator<<(ostream& os, Polynomial& poly) {
    poly.print(&os);
    return os;
}

Polynomial::Polynomial(Polynomial& source) {
    Polynomial::operator=(source);
    d = source.d;
    delete [] a;
    a = new double[d+1];
    for (int index=0; index<=d; index++) {
        a[index] = source.a[index];
    }
}

Polynomial& Polynomial::operator=(Polynomial& source) {
    if (this==&source) return;
    Polynomial::operator=(source);
    d = source.d;
    a = new double[d+1];
    for (int index=d; index>=0; index--) {
        a[index] = source.a[index];
    }
    return *this;
}
