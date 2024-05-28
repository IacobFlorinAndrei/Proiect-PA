def max(a, b):
    return a if a > b else b

def knapsack(dimensiuni, valori, n, capacitate):
    dp = [[0 for _ in range(capacitate + 1)] for _ in range(n + 1)]

    for i in range(1, n + 1):
        for w in range(1, capacitate + 1):
            if dimensiuni[i - 1] <= w:
                dp[i][w] = max(valori[i - 1] + dp[i - 1][w - dimensiuni[i - 1]], dp[i - 1][w])
            else:
                dp[i][w] = dp[i - 1][w]

    return dp[n][capacitate]

def main():
    try:
        with open("date_intrare.txt", "r") as fisier_intrare:
            capacitate = int(fisier_intrare.readline().strip())
            n = int(fisier_intrare.readline().strip())

            dimensiuni = []
            valori = []
            for i in range(n):
                line = fisier_intrare.readline().strip().split()
                dimensiuni.append(int(line[0]))
                valori.append(int(line[1]))

    except FileNotFoundError:
        print("Nu am putut deschide fisierul de intrare.")
        return

    valoare_maxima = knapsack(dimensiuni, valori, n, capacitate)
    print(f"Valoarea maximă ce poate fi obținută este: {valoare_maxima} monede de aur")

if __name__ == "__main__":
    main()
