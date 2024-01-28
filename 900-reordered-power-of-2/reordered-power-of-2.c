#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

// Function to check if the input n can be reordered to form a power of 2
bool reorderedPowerOf2(int n) {
    // Convert n to a string
    char s[20];
    sprintf(s, "%d", n);

    // Sort the characters in the string
    int len = strlen(s);
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (s[j] > s[j + 1]) {
                // Swap characters
                char temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    // Generate and sort strings for powers of 2
    char power[31][20];
    for (int i = 0; i <= 30; i++) {
        int p = (int)pow(2, i);
        sprintf(power[i], "%d", p);

        // Sort the characters in the power string
        int powerLen = strlen(power[i]);
        for (int j = 0; j < powerLen - 1; j++) {
            for (int k = 0; k < powerLen - j - 1; k++) {
                if (power[i][k] > power[i][k + 1]) {
                    // Swap characters
                    char temp = power[i][k];
                    power[i][k] = power[i][k + 1];
                    power[i][k + 1] = temp;
                }
            }
        }
    }

    // Check if the sorted string matches any sorted power of 2 string
    for (int i = 0; i <= 30; i++) {
        if (strcmp(power[i], s) == 0) {
            return true;
        }
    }

    return false;
}
