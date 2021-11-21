#include <stdio.h>
typedef struct {
    int i;
    char c;
} some;

//int main() {
//    char *p, *q;
//    int i, j;
//
//    typedef struct {
//        char *r;
//        float *f;
//    } sp;
//
//    sp *sp_ptr;
//    sp_ptr = func1(*p, q);
//    p = func2(&i, sp_ptr->f);
//    j = func3(sp_ptr->r, i);
//
//    return 0;
//}
//
//struct sp func1(char *p, char q) {
//
//}


int main() {
    some u = {3, 'a'};
    some v = {7, 'b'};
    some *s1, *s2;
    
    printf("BEFORE: u is (%d, %c), v is (%d, %c)\n", u.i, u.c, v.i, v.c);
    
    s1 = &u;
    s2 = &v;
    *s2.i = *s1.i;
    
    s1 = &v;
    *s1.c = u.c;
    ++(*s2.i);
    
    s2 = &u;
    *s2.i = *s1.i;
    ++(*s2.i);
    
    
    printf("AFTER: u is (%d, %c), v is (%d, %c)\n", u.i, u.c, v.i, v.c);
    
    return 0;
}
