#include <stdio.h>

// Funcție pentru a găsi valoarea maximă dintre două numere
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Funcția principală de rezolvare a problemei Knapsack
int knapsack(int dimensiuni[], int valori[], int n, int capacitate) {
    int dp[n + 1][capacitate + 1];

    // Inițializarea matricei dp
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacitate; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (dimensiuni[i - 1] <= w) {
                dp[i][w] = max(valori[i - 1] + dp[i - 1][w - dimensiuni[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Valoarea maximă ce poate fi obținută
    return dp[n][capacitate];
}

int main() {
    FILE *fisier_intrare = fopen("date_intrare.txt", "r");
    if (fisier_intrare == NULL) {
        fprintf(stderr, "Nu am putut deschide fisierul de intrare.\n");
        return 1;
    }

    // Citirea capacitatii plasei
    int capacitate;
    fscanf(fisier_intrare, "%d", &capacitate);

    // Citirea numarului de homari
    int n;
    fscanf(fisier_intrare, "%d", &n);

    // Citirea dimensiunilor și valorilor homarilor
    int dimensiuni[n];
    int valori[n];

    for (int i = 0; i < n; i++) {
        fscanf(fisier_intrare, "%d %d", &dimensiuni[i], &valori[i]);
    }

    fclose(fisier_intrare);

    // Calculăm valoarea maximă
    int valoare_maxima = knapsack(dimensiuni, valori, n, capacitate);
    printf("Valoarea maximă ce poate fi obținută este: %d monede de aur\n", valoare_maxima);

    return 0;
}
