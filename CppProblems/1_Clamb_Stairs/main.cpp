#include <stdint.h>
#include <vector>
#include <iostream>

using namespace std;

// method1: recursive
int ClambStairs(int n);

long long ClambStairs1(int n);

// method2: dynamic programing
long long ClambStairs2(int n);

int main(int argi, char** argc) {
    int stairs = 0;
    cout << "Please input the number of stairs:" << endl;
    cin >> stairs;
    cout << "" << ClambStairs(stairs) << endl;
    cout << "" << ClambStairs1(stairs) << endl;
    cout << "" << ClambStairs2(stairs) % 100003 << endl;
}

// The idea is:
// Teacher Yuan has 3 ways to reach stair n, by climbing 1, 2 or 3 stairs.
// if he reaches n by climbing 1 stair, he starts the last move from n-1;
// if he reaches n by climbing 2 stairs, he starts the last move from n - 2;
// if he reaches n by climbing 3 stairs, he starts the last move from n - 3;
// Therefore, the total number of ways he can reach n is way(n-1) + way(n-2) + way(n-3)

// Recursive
int ClambStairs(int n) {
    if (n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 2;
    }
    else if (n == 3) {
        return 4;
    }

    vector<long long> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[n] % 100003;
}

long long ClambStairs1(int n) {
    if (n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 2;
    }
    else if (n == 3) {
        return 4;
    }

    return ClambStairs1(n - 1) + ClambStairs1(n - 2) + ClambStairs1(n - 3);
}

// Dynamic programming
long long ClambStairs2(int n) {
    if (n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 2;
    }
    else if (n == 3) {
        return 4;
    }

    vector<long long> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[n];
}