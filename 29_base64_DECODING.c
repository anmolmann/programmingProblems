#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main() {
    char *input = (char *)malloc(1000 * sizeof(char));
    int i, index = 0, count = 0, num;
    for(i = 0; i < 26; i++)
        input[i] = 65 + i;
    for(; i < 52; i++)
        input[i] = 97 + i - 26;
    for(; i < 62; i++)
        input[i] = 48 + i - 52;
    input[62] = '+';
    input[63] = '/';
    char *str = (char *)malloc(1000 * sizeof(char));
    fgets(str, 5000, stdin);
    int *duplicate = (int *)malloc(1000 * sizeof(int));
    for(i = 0; str[i] != '\0'; i++) {
        if((str[i] != '\0') && (str[i] > 64) && (str[i] < 91))
            duplicate[i] = str[i] - 65;
        if((str[i] != '\0') && (str[i] > 96) && (str[i] < 123))
            duplicate[i] = str[i] - 97 + 26;
        if((str[i] != '\0') && (str[i] > 47) && (str[i] < 58))
            duplicate[i] = str[i] - 48 + 52;
        if(str[i] == '=')
            count++;
    }
    num = i - 1;
    char *result = (int *)malloc(1000 * sizeof(int));
    for(i = 0; i < num; i++) {
        if(str[i] != '=')
            result[index++] = (duplicate[i] << 2) | (duplicate[++i] >> 4);
        if(i != (num - count - 1))
            result[index++] = (duplicate[i] << 4) | (duplicate[++i] >> 2);
        else {
            result[index++] = '\0';
            break;
        }
        if(i != (num - count - 1))
            result[index++] = (duplicate[i] << 6) | duplicate[++i];
        else {
            result[index++] = '\0';
            break;
        }
    }
    if(count == 0)
        result[index] = '\0';
    printf("\n%s\n", result);
}

