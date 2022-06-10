//amir abu shanab
//208586214
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void addBigNumbers(char first[], char second[], char result[]);
void sortBigNumbers(char *bigNumbers[], int n);
int checkIfNumbers(char first[]);
void bubbleSort(int arr[], int n);

int main() {

    char a[100], b[100], c[200];
    printf("Enter first number:\n");
    scanf("%s", a);
    printf("Enter second number:\n");
    scanf("%s", b);
    addBigNumbers(a, b, c);
    printf("The result is: %s\n", c);


    printf("sorting the array : ( agent,djin,ce-pasa,lucasvaz,dababy,burgerKing )\n");
    char* f[6]={"agent","djin","ce-pasa","lucasvaz","dababy","burgerKing"};
    sortBigNumbers(f,6);
    for(int i=0;i<6;i++){
        printf("%s ",f[i]);



    }

    return 0;
}
int checkIfNumbers(char first[]) {// this checks if the chars in both the arrays are only numbers.
    for (int i = 0; i < strlen(first); i++) {
        if (first[i] < 48 || first[i] > 58)
            return 0;
    }
    return 1;
}

void addBigNumbers(char first[], char second[], char result[]) {


    if (checkIfNumbers(first) == 0 || checkIfNumbers(second) == 0) {// if there is a char that is not a number it returns error
        strcpy(result, "error");
        return;
    }


    int resindex;
    if (strlen(first) > strlen(second))// checks which one of the arrays is bigger so it can make the new array the same size
        resindex = strlen(first);
    else
        resindex = strlen(second);

    int Fsize = strlen(first) - 1;// the size of the first array
    int Ssize = strlen(second) - 1;// the size of the secound array.
    int temp;
    int k;
    int carry = 0;

    for (k = 0; Fsize >= 0 || Ssize >= 0; k++) {// if both indexes of the arrays are bigger than 0 it will take from both
        if (Fsize >= 0 && Ssize >= 0) {
            int num1 = (first[Fsize] - 48);
            int num2 = (second[Ssize] - 48);
            temp = num1 + num2 + carry;
            carry = temp / 10;
            int ones = temp % 10;
            result[k] = (ones + 48);
            Fsize--;
            Ssize--;
        } else if (Fsize >= 0 && Ssize < 0) {// if one index is smaller that 0 it will take from the other array
            temp = first[Fsize] - 48 + carry;
            carry = temp / 10;
            int ones = temp % 10;
            result[k] = ones + 48;
            Fsize--;
        } else if (Ssize >= 0 && Fsize < 0) {// if one index is smaller that 0 it will take from the other array
            temp = second[Ssize] - 48 + carry;
            carry = temp / 10;
            int ones = temp % 10;
            result[k] = ones + 48;
            Ssize--;
        }
    }
    if (carry > 0) {// if the last one sum had a carry it will add it to the new array.
        result[k] = carry + 48;
        k++;
        result[k] = '\0';

    } else {
        result[k] = '\0';// else will end the array.
    }
    char rev[strlen(result)];// a new array to reverse the answer

    int j = strlen(result) - 1;
    int i;
    for (i = 0; j >= 0; i++) {
        rev[i] = result[j];
        j--;
    }
    rev[i] = '\0';
    result = strcpy(result, rev);


}



void sortBigNumbers(char *bigNumbers[], int n) {//a method to sort the array by the length.
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)// using bubble sort
            if (strlen(bigNumbers[j]) > strlen(bigNumbers[j + 1])) {
                char *temp = bigNumbers[j];
                bigNumbers[j] = bigNumbers[j + 1];
                bigNumbers[j + 1] = temp;
            }
            else
            if (strlen(bigNumbers[j]) == strlen(bigNumbers[j + 1])) {
                if((strcmp(bigNumbers[j] , bigNumbers[j+1])) >= 0) {
                    char *temp = bigNumbers[j];
                    bigNumbers[j] = bigNumbers[j + 1];
                    bigNumbers[j + 1] = temp;

                }
            }


}

