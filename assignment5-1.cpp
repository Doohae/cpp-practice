#include <iostream>
#include "assingment5-1.h"

int main() {
	IntArray powersOf2;
	IntArray* ppow = &powersOf2;
	powersOf2.init();
	cout << "IsEmpty = " << powersOf2.IsEmpty() << endl;
	cout << "Length = " << powersOf2.Length() << endl;
	ppow->setSize(8);
	ppow->setElem(0, 1);
	ppow->setElem(1, 2 * ppow->getElem(0));
	ppow->setElem(2, 2 * ppow->getElem(1));
	ppow->setElem(3, 2 * ppow->getElem(2));
	ppow->setElem(4, 2 * ppow->getElem(3));
	ppow->setElem(5, 2 * ppow->getElem(4));
	ppow->setElem(6, 2 * ppow->getElem(5));
	ppow->setElem(7, 2 * ppow->getElem(6));
	cout << "IntArray is = " << 
		ppow->getElem(0) << ppow->getElem(1) <<
		ppow->getElem(2) << ppow->getElem(3) <<
		ppow->getElem(4) << ppow->getElem(5) <<
		ppow->getElem(6) << ppow->getElem(7) << endl;
	cout << "IsEmpty = " << powersOf2.IsEmpty() << endl;
	cout << "Length = " << powersOf2.Length() << endl; 
	int z;
	if (powersOf2.Find(0, &z))
		cout << "First element is " << z << endl;
	if (powersOf2.Find(powersOf2.Length() - 1, &z))
		cout << "Last element is " << z << endl;
		
	powersOf2.cleanup(); 
	return(0);
}