#include <stdio.h>
#include <math.h>

int main(void){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    int D = b*b - 4*a*c;
    if(D < 0){
        printf("No real root");
    } else {
        int x1 = (-b + sqrt(D)) / (2 * a);
        int x2 = (-b - sqrt(D)) / (2 * a);

        if(D == 0){
            printf("Two same roots x=%d", x1);
        }
        else if(D > 0){
            printf("Two different roots x1=%d , x2=%d", x1, x2);
        }
    }


    return 0;
}
