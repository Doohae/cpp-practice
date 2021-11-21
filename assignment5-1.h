#include <iostream>
using namespace std;

class IntArray {
public:
	void init();
	void cleanup();
	void setSize(int value);
	int getSize();
	void setElem(int index, int value);
	int getElem(int index);
	bool IsEmpty() const; 
	int Length() const; 
	bool Find(int k, int* x) const;
private:
	int* elems;
	int numElems;
};

void IntArray::init() {
	this->elems = 0;
	this->numElems = 0;
}

void IntArray::cleanup() {
	if (this->elems != 0) free(this->elems);
}

void IntArray::setSize(int value) {
	if (this->elems != 0)
		free(this->elems);
	this->numElems = value;
	this->elems = (int*)malloc(value * sizeof(int));
}

int IntArray::getSize() {
	return this->numElems;
}

void IntArray::setElem(int index, int value) {
	elems[index] = value;
}

int IntArray::getElem(int index) {
	if (index >= this->numElems) cout << "bad index" << endl;
	return this->elems[index];
}

bool IntArray::IsEmpty() const {
	if (this->numElems == 0) return true;
	return false;
}

int IntArray::Length() const {
	return this->numElems;
}

bool IntArray::Find(int k, int* x) const {
	*x = elems[k];
	if ((k == 0) || (0 < k < this->numElems)) return true;
	return false;
}