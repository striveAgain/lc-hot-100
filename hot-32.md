### 算法一：DP，时间复杂度 $O(n)$

#### 状态表示

##### 集合

`dp[i]` -- 以 `s[i]` 结尾的有效括号子串

##### 属性

`Max`

#### 状态计算

##### 初始状态

有效的括号长度只能以 `)` 结尾，因此当 `s[i] == '('` 时，对应的 `dp[i]` 均为 0；

##### 状态转移

从第 `1` 个字符开始，枚举第 `i - 1` 个字符的情况：

`case 1: ` 如果 `s[i] == ')' && s[i - 1] == '('`，此时 `dp[i] = dp[i - 2] + 2`；

`case 2: ` 如果 `s[i] == ')' && s[i - 1] == ')'`，此时 `dp[i]` 分为两部分：

`case 2.1: ` `dp[i - 1]`

`case 2.2: ` 如果 `dp[i - dp[i - 1] - 1] == '('` （即找到与该 `)` 匹配的 `(`），则该部分为 `dp[i - dp[i - 1] - 2] + 2`

**注意特判 `- 2` 是否合法！！！**

### C++ 代码
```c++
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
	
        vector<int> dp(n, 0);
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = ((i >= 2) ? dp[i - 2] : 0) + 2;
                } else {
                    if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                        dp[i] = dp[i - 1] + ((i - dp[i - 1] >= 2) ? dp[i - dp[i - 1] - 2] : 0) + 2;
                    }
                }

                ans = max(ans, dp[i]);
            }
        }
        
        return ans;
    }
};
```

---

### 算法二：栈，时间复杂度 $O(n)$

采用栈，栈底保存了最后一个没有被匹配的右括号的下标，初始时压入 `-1`；

`case 1: ` 如果 `s[i] == '('`，将下标压栈；

`case 2: ` 如果 `s[i] == ')'`，先弹栈，

`case 2.1：` 如果弹栈后栈为空了，说明当前右括号没有能够匹配，将下标入栈；

`case 2.2: ` 如果弹栈后栈不为空，说明当前右括号被匹配了，那么当前右括号的下标 `-` 栈顶下标即为**以该右括号结尾的最长有效括号子窜长度；**

### C++ 代码
```c++
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
	
        stack<int> st;
        st.push(-1);
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    ans = max(ans, i - st.top());
                }
            }
        }
        
        return ans;
    }
};
```

---

### 算法三：两次遍历，时间复杂度 $O(2n) = O(n)$

记录遍历过程中 `(` 和 `)` 的值，记为 `l` 和 `r`

第一次从左向右遍历：

`case 1: ` 如果 `l == r`，更新答案 `ans = max(ans, 2 * l)`；

`case 2: ` 如果 `l < r`，无法得到匹配，重置 `l = r = 0`；

**但是从左往右遍历无法处理 '(()' 这样的情况，因此添加一次从右往左遍历**

第二次从左向右遍历：

`case 1: ` 如果 `l == r`，更新答案 `ans = max(ans, 2 * l)`；

`case 2: ` 如果 `l > r`，无法得到匹配，重置 `l = r = 0`；

### C++ 代码
```c++
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
	
        int l = 0, r = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                ++l;
            } else {
                ++r;
            }
            
            if (l == r) {
                ans = max(ans, 2 * l);
            } else if (l < r) {
                l = r = 0;
            }
        }
        
        l = r = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '(') {
                ++l;
            } else {
                ++r;
            }
            
            if (l == r) {
                ans = max(ans, 2 * l);
            } else if (l > r) {
                l = r = 0;
            }
        }
        
        return ans;
    }
};
```
