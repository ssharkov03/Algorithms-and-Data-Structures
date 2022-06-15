#include <stdio.h>
#include <math.h>
double distance(double x1, double y1, double x2, double y2){
    return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}


int main()

{
    double x1, y1, x2, y2, x3, y3;
    
    scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
    double a = distance(x1, y1, x2, y2);
    double b = distance(x2, y2, x3, y3);
    double c = distance(x3, y3, x1, y1);
    
    double perimeter = a + b + c;
    double p = perimeter / 2;
    double s = sqrt(p*(p - a)*(p - b)*(p - c));
    
    printf("%0.3lf \n", perimeter);
    printf("%0.3lf", s);
    
    return 0;
}