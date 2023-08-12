### 算法，时间复杂度 $O(mn)$

#### 状态表示

##### 集合

`dp[i][j]` -- 将 `word1` 的前 `i` 位变成 `word2` 的前 `j` 位的所有操作方案集合；

##### 属性

`Min`

#### 状态计算

##### 初始状态

`dp[0][i]` -- 将 `word1` 的前 `0` 个字符变成 `word2` 的前 `i` 个字符，只能通过插入 `i` 次来进行，故 `dp[0][i] = i`；

`dp[i][0]` -- 将 `word1` 的前 `i` 个字符变成 `word2` 的前 `0` 个字符，只能通过删除 `i` 次来进行，故 `dp[i][0] = i`；

##### 状态转移

**注意：这里的删除、插入、替换都是针对于尾字符而言的！！！**

`case 1: ` 通过删除字符的话，将 `word1` 的前 `i - 1` 位变成 `word2` 的前 `j` 位，然后删除 `word1[i]` 即可。即 `dp[i - 1][j] + 1`；

```
举个例子：
word1 = adt, word2 = adtaab
要通过删除 t 来使 word1 变成 word2。因此先将 ad 变为 adtaab，则 word1 变成 adtaabt，然后删除 t 即可；
```

`case 2: ` 通过插入字符的话，将 `word1` 的前 `i` 位变成 `word2` 的前 `j - 1` 位，然后在尾部加上 `word2[j]` 即可。即 `dp[i][j - 1] + 1`；

```
举个例子：
word1 = adt, word2 = adtaab
要通过插入 b 来使 word1 变成 word2。因此先将 adt 变为 adtaa，则 word1 变成 adtaa，然后插入 b 即可；
```

`case 3: ` 通过替换字符的话，`dp[i - 1][j - 1] + (word1[i] != word2[j])`即可；

```
举个例子：
word1 = adt, word2 = adtaab
要通过替换 t 为 b 来使 word1 变成 word2。因此先将 ad 变为 adtaa，则 word1 变成 adtaat，然后替换 t 为 b 即可；
```

### C++ 代码
```c++
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
	
        word1 = "#" + word1;
        word2 = "#" + word2;
        
        vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= m; ++i) {
            dp[0][i] = i;
        }
        
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = i;
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = min(dp[i][j - 1] + 1, dp[i - 1][j] + 1);
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (word1[i] != word2[j]));
            }
        }
        
        return dp[n][m];
    }
};
```
