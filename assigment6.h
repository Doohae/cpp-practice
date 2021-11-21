Polynomial::Polynomial(int d) {
    this->d = d;
    this->a = new double[d];
    for (int i=0; i<d; i++) {
        if (i==0) { 
	this->a[i]=1;
        }
        else {
	this->a[i] = 0;
        }
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
    return this->a[i];
}

int Polynomial::degree() const {
    return this->d;
}

double Polynomial::evaluate(double x) const {
    double eval = 0;
    for (int i=0; i<d; i++) {
        eval += (this->a[i]) * pow(x, i);
    }
    return eval;
}