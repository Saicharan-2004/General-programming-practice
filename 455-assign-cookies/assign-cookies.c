#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int findContentChildren(int* greed, int greedSize, int* cookies, int cookiesSize) {
    insertionSort(greed, greedSize);
    insertionSort(cookies, cookiesSize);

    int contentChildren = 0;
    int greedIndex = 0;
    int cookieIndex = 0;

    while (greedIndex < greedSize && cookieIndex < cookiesSize) {
        if (cookies[cookieIndex] >= greed[greedIndex]) {
            // Assign the current cookie to the child
            contentChildren++;
            greedIndex++;
        }
        // Move to the next available cookie
        cookieIndex++;
    }

    return contentChildren;
}

