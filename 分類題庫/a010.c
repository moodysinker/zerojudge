#include <stdio.h>
#include <math.h>

int main(void){

    int n;
    scanf("%d", &n);

    int is_first = 1;
    int limit = (int)sqrt(n);

    if(n == 1){
        printf("1");
        return 0;
    }

    for(int i = 2; i <= limit; i++){
        if(n % i == 0){
            int count = 0;

            while(n % i == 0){
                n /= i;
                count++;
            }

            limit = (int)sqrt(n);

            if(!is_first){
                printf(" * ");
            }
            is_first = 0;

            if(count > 1){
                printf("%d^%d", i, count);
            } else {
                printf("%d", i);
            }
        }
    }

    if(n > 1){
        if(!is_first){
            printf(" * ");
        }
        printf("%d", n);
    }

    return 0;
}
