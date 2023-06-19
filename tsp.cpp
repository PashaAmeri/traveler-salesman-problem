#include <iostream>
using namespace std;

const int INF = 1e9;

int calculateMinCost(int n, int citiesMatrix[20][20]) {

    int dp[1 << n][n];

    for (int i = 0; i < (1 << n); ++i) {

        for (int j = 0; j < n; ++j) {

            dp[i][j] = INF;
        }
    }

    dp[1][0] = 0;

    for (int mask = 1; mask < (1 << n); ++mask) {

        for (int lastCity = 0; lastCity < n; ++lastCity) {

            if ((mask & (1 << lastCity)) != 0) {

                for (int currentCity = 0; currentCity < n; ++currentCity) {

                    if ((mask & (1 << currentCity)) == 0) {
                        
                        int newMask = mask | (1 << currentCity);
                        dp[newMask][currentCity] = min(dp[newMask][currentCity], dp[mask][lastCity] + citiesMatrix[lastCity][currentCity]);
                    }
                }
            }
        }
    }

    int minCost = INF;

    for (int lastCity = 0; lastCity < n; ++lastCity) {

        minCost = min(minCost, dp[(1 << n) - 1][lastCity] + citiesMatrix[lastCity][0]);
    }

    return minCost;
}

int main() {

    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    int citiesMatrix[20][20];

    cout << "Enter the cost matrix:\n";

    for (int i = 0; i < n; ++i) {

        for (int j = 0; j < n; ++j) {
            
            cin >> citiesMatrix[i][j];
        }
    }

    int minCost = calculateMinCost(n, citiesMatrix);

    cout << "Minimum cost: " << minCost << endl;

    return 0;
}
