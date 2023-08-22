#include <stdio.h>
#include <math.h>

int main(){
    float r, area, r2;
    scanf("%f", &r);
    area = r*r*3.141592;
    r2 = sqrt(area / (2 * 3.141592));
    printf("%.2f %.2f", area, r2);
    return 0;
}