#include <stdio.h>
#define NMAX 30

int input(int *a, int *len);
void output(int *a, int len);
void quickSort(int *a, int left, int right);
void insertionSort(int *a, int len);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);

int main() {
    int is_error = 0;
    int array[NMAX], len;
    is_error = input(array, &len);
    if (is_error == 0) {
        int array_2[NMAX];
        for (int i = 0; i < len; i++) array_2[i] = array[i];
        quickSort(array, 0, len - 1);
        output(array, len);
        printf("\n");
        insertionSort(array_2, len);
        output(array_2, len);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int *len) {
    int is_error = 0;
    if (scanf("%d", len) != 1 || *len <= 0) {
        is_error = 1;
    }
    if (is_error == 0) {
        for (int *p = a; p - a < *len; p++) {
            if (scanf("%d", p) != 1) {
                is_error = 1;
                break;
            }
        }
        char c = ' ';
        if ((scanf("%c", &c) != 0) && (c != '\n')) {
            is_error = 1;
        }
    }
    return is_error;
}

void output(int *a, int len) {
    for (int *p = a; p - a < len; p++) {
        printf("%d", *p);
        if (p - a != len - 1) {
            printf(" ");
        }
    }
}

void quickSort(int *a, int left, int right) {
    if (right - left == 0) {
        return;
    }
    if (right - left == 1) {
        if (a[left] > a[right]) {
            int tmp = a[left];
            a[left] = a[right];
            a[right] = tmp;
        }
        return;
    }
    int l_hold = left, r_hold = right;
    int sr_ar = 0;
    for (int i = l_hold; i <= r_hold; i++) {
        sr_ar += a[i];
    }
    sr_ar /= (right - left + 1);
    while (left < right) {
        while ((a[right] > sr_ar) && (left < right)) {
            right--;
        }
        while ((a[left] <= sr_ar) && (left < right)) {
            left++;
        }
        if (left < right) {
            int tmp = a[left];
            a[left] = a[right];
            a[right] = tmp;
        }
    }
    if (l_hold < left) {
        quickSort(a, l_hold, left);
    }
    if (right < r_hold) {
        quickSort(a, right + 1, r_hold);
    }
}

void merge(int arr[], int l, int m, int r) {
    // Function to merge two subarrays of arr[].
    // First subarray is arr[l..m]
    // Second subarray is arr[m+1..r]

    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
