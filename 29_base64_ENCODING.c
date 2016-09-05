#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main() {
    char *input = (char *)malloc(1000 * sizeof(char));
    char *str = (char *)malloc(1000 * sizeof(char));
    fgets(str, 5000, stdin);
    char byte;
    int i, dup_index = 0;
    /*while(fread(&byte, 1, 1, stdin)) {
        if(byte != '\n')
            break;
        str[i++] = byte;
    }
    str[i] = '\0';*/

    int *duplicate = (int *)malloc(1000 * sizeof(int));
    int *result = (int *)malloc(1000 * sizeof(int));

    for(i = 0; i < 26; i++)
        input[i] = 65 + i;
    for(; i < 52; i++)
        input[i] = 97 + i - 26;
    for(; i < 62; i++)
        input[i] = 48 + i - 52;
    input[62] = '+';
    input[63] = '/';

    for(i = 0; str[i] != '\0'; i++)
        duplicate[i] = str[i];

    int len_result, flag = 0, length = (i - 1) * 8, num = i - 1;
    if(length % 24) {
        flag = 1;
        len_result = (length / 6) + 1;
    }
    else
        len_result = length / 6;
    printf("%d", len_result);

    for(i = 0; i < num; i++) {
        // start

        result[dup_index++] = (duplicate[i] & 252) >> 2;
        // 2,4
        if(dup_index < (len_result - 1))
            result[dup_index++] = ((duplicate[i] & 3) << 4) | ((duplicate[++i] & 240) >> 4);
        else {
            result[dup_index++] = ((duplicate[i] & 3) << 4);
            break;
        }
        // 4,2
        if(dup_index < (len_result - 1))
            result[dup_index++] = ((duplicate[i] & 15) << 2) | ((duplicate[++i] & 192) >> 6);
        else {
            result[dup_index++] = ((duplicate[i] & 15) << 2);
            break;
        }
        // end
        result[dup_index++] = duplicate[i] & 63;
    }
    if(length % 24 == 16)
        len_result = (length / 6) + 2;
    if(length % 24 == 8)
        len_result = (length / 6) + 3;
    if(flag == 1) {
        for(i = dup_index; i < len_result; i++) {
                result[i] = '=';
        }
    }
    printf("\nAfter encoding : \t");
    for(i = 0; i < dup_index; i++) {
        printf("%c", input[result[i]]);
    }
    if(flag == 1) {
    for(i = dup_index; i < len_result; i++)
        printf("%c", result[i]);
    }
}
