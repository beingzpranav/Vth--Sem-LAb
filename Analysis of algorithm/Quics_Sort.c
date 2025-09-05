#include <stdio.h>

void swap(int *a, int *b);  
void qsort(int arr[], int length);
void qsort_rec(int arr[], int l, int h);
int partition(int arr[], int l, int h);
int main(){
    printf("Quick Sort Implementation\n");
    printf("Enter the Array Size:\n");
    int size;
    scanf("%d", &size);
    int arr[size];
    printf("Enter the array to be sorted:\n");
    for(int i=0; i<size; i++){
        int num;
        scanf("%d", &num);
       arr[i] = num;
    }
    int n = sizeof(arr)/sizeof(arr[0]);
    qsort(arr, n);
    printf("Sorted array: \n");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    return 0;
}
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
void qsort(int arr[], int length){
    qsort_rec(arr, 0, length-1);
}
void qsort_rec(int arr[], int l, int h){
    if(l < h){
        int pivoti = partition(arr, l, h);
        qsort_rec(arr, l, pivoti-1);
        qsort_rec(arr, pivoti+1, h);
    }
    
}
int partition(int arr[], int l, int h){
    int pivot = arr[h];
    int i = (l - 1);
    for(int j = l; j <= h - 1; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[h]);
    return i;
}