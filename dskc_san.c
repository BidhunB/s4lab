#include <stdio.h>
#include <math.h>

int main() {
    int n, a[100], hd, temp, f[100], p = 0, tot = 0, k;
    float avg;

    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    printf("Enter the head position: ");
    scanf("%d", &hd);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Add boundary elements
    a[n] = hd;
    a[n+1] = 0;
    a[n+2] = 199;
    n = n + 3;

    // Bubble sort the array a
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // Find index k where hd is located in sorted array a
    for (int i = 0; i < n; i++) {
        if (a[i] == hd) {
            k = i;
            break;
        }
    }

    // C-SCAN algorithm
    // Move in one direction until the end and wrap around
    for (int i = k; i < n; i++, p++) {
        f[p] = a[i];
    }
    for (int i = 0; i < k; i++, p++) {
        f[p] = a[i];
    }

    printf("The order of disk requests is:\n");
    for (int i = 0; i < p; i++) {
        printf("--> %d", f[i]);
        tot += abs(hd - f[i]);
        hd = f[i]; // Update head position
    }
    avg = (float)tot / n;

    printf("\nTotal seek time: %d\n", tot);
    printf("Average seek time: %f\n", avg);

    return 0;
}
