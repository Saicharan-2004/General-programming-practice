#include <stdio.h>
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int findContentChildren(int *greed, int greedSize, int *cookies, int cookiesSize)
{
    insertionSort(greed, greedSize);
    insertionSort(cookies, cookiesSize);

    int contentChildren = 0;
    int cookieIndex = 0;

    for (int i = 0; i < greedSize; i++)
    {
        while (cookieIndex < cookiesSize && cookies[cookieIndex] < greed[i])
        {
            cookieIndex++;
        }

        if (cookieIndex < cookiesSize)
        {
            contentChildren++;
            cookieIndex++;
        }
        else
        {
            break;
        }
    }

    return contentChildren;
}
