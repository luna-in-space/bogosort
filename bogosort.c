#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int list[5] = {5, 1, 2, 3, 4,};

void print_array(int arr[], int n) {
    for(int i=0;i<n;i++) {
        printf("%d,", arr[i]);
        }
}
int array_sorted_or_not(int arr[], int n) {
    if (n == 1 || n == 0)
        return 1;
    if (arr[n - 1] < arr[n - 2])
        return 0;
    return array_sorted_or_not(arr, n - 1);
}
void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void shuffle(int *array, size_t length) {
    for(int i = 0; i<length-2; i++) { 
        int j = rand() % length + 0;
        swap(&array[j], &array[i]);
    }
}
int main() {
    size_t length = sizeof(list) / sizeof(int);
    srand(time(NULL));
    print_array(list, length);
    printf("\n");
    while(array_sorted_or_not(list, length) == 0) {
        shuffle(list, length);
        print_array(list, length);
        printf("\n");
        }
    printf("\n");
    print_array(list, length);
    return 0;
}

