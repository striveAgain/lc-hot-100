### 算法一：组合数，时间复杂度 $O(m)$

经典的组合数求解问题；

### C++ 代码
```c++
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        for (int x = n, y = 1; y <= m - 1; ++x, ++y) {
            ans = ans * x / y;
        }

        return ans;
    }
};
```

---

### 算法二：DP，时间复杂度 $O(mn)$

#### 状态表示

`dp[i][j]` -- 从 `(0, 0)` 到 `(i, j)` 的方案数

#### 状态计算

`dp[i][j] += (dp[i - 1][j] + dp[i][j - 1])`

### C++ 代码
```c++
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m, vector<int>(n, 0));

        dp[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i >= 1) {
                    dp[i][j] += dp[i - 1][j];
                }

                if (j >= 1) {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
```
