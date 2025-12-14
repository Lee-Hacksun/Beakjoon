#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int itemCount, maxWeight;
    cin >> itemCount >> maxWeight;

    vector<int> weights(itemCount + 1);
    vector<int> values(itemCount + 1);
    vector<vector<int>> dp(itemCount + 1, vector<int>(maxWeight + 1, 0));

    for (int i = 1; i <= itemCount; i++) {
        cin >> weights[i] >> values[i];
    }

    for (int i = 1; i <= itemCount; i++) {
        for (int j = 1; j <= maxWeight; j++) {
            if (weights[i] <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i]] + values[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[itemCount][maxWeight] << "\n";

    return 0;
}