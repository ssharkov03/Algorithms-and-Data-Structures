#include <stdio.h>
#include <math.h>

int main()

{
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);

	// solution
	if (a == 0 && b == 0 && c == 0){
		printf("MANY");
		return 0;
	}
	else
		if (a == 0 && b == 0 && c != 0){
			printf("ERROR");
			return 0;
		}
		else
			if (a == 0 && b != 0){
				double x = -c/b;
				printf("1\n%0.5lf", x);
				return 0;
			}		
			else{
				double D = b * b - 4 * a * c;
				if (D < 0){
					printf("NO");
					return 0;
				}
				else{
					if (D == 0){
						double x = -b/(2 * a);
						printf("1\n%0.5lf", x);
						return 0;
					}
					else{
						double x1 = (-b - sqrt(D))/(2 * a);
						double x2 = (-b + sqrt(D))/(2 * a);

						if (x2 < x1){
							double temp = x1;
							x1 = x2;
							x2 = temp;
						}
						
						printf("2\n%0.5lf %0.5lf", x1, x2);
						return 0;
					}
				}
			}
}