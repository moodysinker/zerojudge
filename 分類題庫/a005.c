#include <stdio.h>

int main(void){
    int round;
    scanf("%d", &round);

    while(round != 0){
        int seq[5];
        int count = 0;

        while(1){
            scanf("%d", &seq[count]);
            count++;

            char next = getchar();

            if(next == '\n' || next == EOF){
                break;
            }
        }

        if(seq[1] - seq[0] == seq[2] - seq[1]){
            int d = seq[1] - seq[0];
            seq[4] = seq[3] + d;
        } else {
            int r = seq[1] / seq[0];
            seq[4] = seq[3] * r;
        }

        for(int i = 0; i < 5; i++){
            printf("%d", seq[i]);
            if(i < 4){
                printf(" ");
            }
        }
        printf("\n");

        round--;
    }

    return 0;
}
