/* 解碼器 /*
#include <stdio.h>
#include <string.h>

int main(void){
    char code[1000];
    scanf("%s", code);

    int length = strlen(code);

    for(int i = 0; i < length; i++){
        printf("%c", code[i] - 7);
    }


    return 0;
}
