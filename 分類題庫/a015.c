/* 矩陣的翻轉(轉置) /*
#include <stdio.h>

int main(void){
    int row, col;
    while(scanf("%d%d", &row, &col) != EOF){
        int matrix[110][110];

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                scanf("%d", &matrix[i][j]);
            }
        }

        for(int j = 0; j < col; j++){
            for(int i = 0; i < row; i++){
                printf("%d", matrix[i][j]);
                if(j == col - 1 && i == row - 1){
                    break;
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
