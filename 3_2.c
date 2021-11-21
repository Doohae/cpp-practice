#include <stdio.h>

typedef struct point{
    int x;
    int y;
} point;

typedef struct {
    struct point ll;
    struct point ur;
} rectangle;

point make_point(int x, int y){
    point point_made={x,y};
    return point_made;
}

rectangle make_rectangle(point lower_left, point upper_right){
    rectangle rectangle_made={lower_left, upper_right};
    return rectangle_made;
}

int rectangle_area(rectangle r){
    int area;
    area=(r.ur.x-r.ll.x)*(r.ur.y-r.ll.y);
    return area;
}

int main()
{
    point a={1,2};
    struct point b={7,6};
    point p;
    rectangle r1= { {2,1}, {4,8} };
    rectangle r2;
    
    p = make_point(-1,-3) ;
    r2 = make_rectangle(a, b) ;
    printf("Rectangle 1: (%d,%d) to (%d,%d) . Area is %d\n",r1.ll.x,r1.ll.y,r1.ur.x,r1.ur.y,rectangle_area(r1));
    printf("Rectangle 2: (%d,%d) to (%d,%d) . Area is %d\n",r2.ll.x,r2.ll.y,r2.ur.x,r2.ur.y,rectangle_area(r2));
    
    return (0);
}





