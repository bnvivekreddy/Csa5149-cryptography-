#include <stdio.h>
#include <stdint.h>

// Extended Euclidean Algorithm to find gcd(a, b) and coefficients x, y such that ax + by = gcd(a, b)
int extended_gcd(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = extended_gcd(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

// Function to find the modular inverse of a modulo m using extended Euclidean algorithm
int mod_inverse(int a, int m) {
    int x, y;
    int gcd = extended_gcd(a, m, &x, &y);

    if (gcd != 1) {
        printf("Inverse does not exist\n");
        return -1;
    } else {
        // Ensure the result is positive
        return (x % m + m) % m;
    }
}

int main() {
    int e = 31;
    int n = 3599;
    int phi_n = (59 - 1) * (61 - 1); // phi(n) = (p-1)(q-1) for p = 59, q = 61

    printf("Public key: (e, n) = (%d, %d)\n", e, n);
    printf("Calculating private key...\n");

    // Find the private key d
    int d = mod_inverse(e, phi_n);

    if (d != -1) {
        printf("Private key (d) = %d\n", d);
    }

return 0;
}

