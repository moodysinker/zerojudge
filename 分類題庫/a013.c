#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int charToValue(char c){
    switch(c){
    case 'M':
        return 1000;
    case 'D':
        return 500;
    case 'C':
        return 100;
    case 'L':
        return 50;
    case 'X':
        return 10;
    case 'V':
        return 5;
    case 'I':
        return 1;
    default:
        return 0;
    }
}

int RomToValue(char roman[]){
    int length = strlen(roman);
    int value = 0;

    for(int i = 0; i < length; i++){
        int now = charToValue(roman[i]);
        int next = charToValue(roman[i + 1]);

        if(now >= next){
            value += now;
        } else {
            value -= now;
        }
    }

    return value;
}


void ValueToRomAndPrint(int diff){
    int values[]    = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    for (int i = 0; i < 13; i++) {
        while (diff >= values[i]) {
            printf("%s", symbols[i]);
            diff -= values[i];
        }
    }

    printf("\n");
}
    


int main(void){

    while(1){
        char roman1[500];
        scanf("%s", roman1);
        if(roman1[0] == '#'){
            break;
        }

        char roman2[500];
        scanf("%s", roman2);

        int value1 = RomToValue(roman1);
        int value2 = RomToValue(roman2);

        int diff = abs(value1 - value2);

        if(diff == 0){
            printf("ZERO\n");
            continue;
        }

        ValueToRomAndPrint(diff);
    }

    return 0;
}
