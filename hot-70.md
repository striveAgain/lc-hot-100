### 算法一：DP，时间复杂度：$O(n)$

经典的爬楼梯 DP 问题，`dp[i] = dp[i - 1] + dp[i - 2](n >= 3)` 即可；

### C++ 代码
```c++
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }

        if (n == 2) {
            return 2;
        }

        vector<int> dp(n + 1, 0);

        dp[1] = 1, dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};
```

---

### 矩阵快速幂，时间复杂度 $O(\log n)$

由于 `f(n) = f(n - 1) + f(n - 2)`，因此有：

$$
\begin{bmatrix}
  1 & 1 \\
  1 & 0 \\
\end{bmatrix}
\begin{bmatrix}
  f(n) \\
  f(n - 1) \\
\end{bmatrix}=
\begin{bmatrix}
  f(n + 1) \\
  f(n) \\
\end{bmatrix}
$$

因此有

$$
\begin{bmatrix}
  f(n) \\
  f(n - 1)
\end{bmatrix}=
\begin{bmatrix}
  1 & 1 \\
  1 & 0 \\
\end{bmatrix}^n
\begin{bmatrix}
  f(1) \\
  f(0) \\
\end{bmatrix}
$$

快速计算出 `M` 的 `n` 次幂，即可得到 `f(n)` 的值；

### C++ 代码
```c++
class Solution {
public:
    vector<vector<long long> > multiply(vector<vector<long long> >& a, vector<vector<long long> >& b) {
        vector<vector<long long> > ans(2, vector<long long>(2));
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                ans[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
            }
        }

        return ans;
    }

    vector<vector<long long> > quickPow(vector<vector<long long> > mat, int n) {
        vector<vector<long long> > ret = {{1, 0}, {0, 1}};
        while (n) {
            if (n & 1) {
                ret = multiply(ret, mat);
            }

            n >>= 1;
            mat = multiply(mat, mat);
        }

        return ret;
    }

    int climbStairs(int n) {
        vector<vector<long long> > mat = {{1, 1}, {1, 0}};
        vector<vector<long long> > ans = quickPow(mat, n);

        return ans[0][0];
    }
};
```
