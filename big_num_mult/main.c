#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str_length(char str[]) {
    // initializing count variable (stores the length of the string)
    int count;

    // incrementing the count till the end of the string
    for (count = 0; str[count] != '\0'; ++count);

    // returning the character count of the string
    return count;
}

int main() {
    //add user input char
    char num1[] = "1235421415454545454545454544";
    char num2[] = "1235421415454545454545454544";

    printf("Program obliczający duże liczby naturalne.\n");
    printf("Podane liczby: %s %s\n", num1, num2);

    //size of strings
    int len_num_1 = str_length(num1);
    int len_num_2 = str_length(num2);

    if (len_num_1 == 0 || len_num_2 == 0){
        printf("nie ma co mnożyć");
    }

    int i_n1 = 0;
    int i_n2 = 0;

    for (int i = len_num_1; i >= 0 ;i--){
        int carry = 0;
        int n1 = num1[i] - '0';

        i_n2 = 0;
        for (int j = len_num_2 - 1; j > 0; j--){
            int n2 = num2[j] - '0';
        }

    }

    return 0;
}

//int len_of_input(char input[]){
//    for(int i = 0; i < (sizeof(input) / (sizeof(input[0]))); i++){
//
//    }
//};