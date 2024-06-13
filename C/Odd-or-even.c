#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n) {
    int i=1, j=i-1;
    for (int i = 1; i < n; i++) {     
        int temp = arr[i];
        j=i-1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int main() {
    int i, n;
    scanf("%d", &n);
    int arr[n+1];
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\n\n");
    
    insertionSort(arr, n);
    printf("Angka Genap:\n");
    for (i = 0; i < n; i++) {
        if(arr[i]%2==0){
            printf("%d ", arr[i]);
        }
    }
    getchar();
    printf("\n");
    printf("Angka Ganjil:\n");
    for (i = n-1; i>=0; i--) {
        if(arr[i]%2!=0){
            printf("%d ", arr[i]);
        }
    }
    getchar();
    printf("\n");

    return 0;
}
