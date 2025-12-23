#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long M;
    cin >> N >> M;

    vector<int> trees(N);
    int max_height = 0;
    for (int i = 0; i < N; i++) {
        cin >> trees[i];
        if (trees[i] > max_height) max_height = trees[i];
    }

    int low = 0;
    int high = max_height;
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long sum = 0;

        for (int i = 0; i < N; i++) {
            if (trees[i] > mid) {
                sum += (trees[i] - mid);
            }
        }

        if (sum >= M) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << result << "\n";

    return 0;
}