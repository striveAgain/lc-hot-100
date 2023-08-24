### 算法：双指针算法

**之前说过，这种区间字符串匹配问题都是采用哈希表记录区间内的字符数量，双指针用于维护当前 `check` 的区间；**

### C++ 代码
```c++
class Solution {
    unordered_map<char, int> us, ut;
public:
    bool check() {
        for (auto& i : ut) {
            if (us[i.first] < i.second) {
                return false;
            }
        }
        
        return true;
    }

    string minWindow(string s, string t) {
        for (auto& ch : t) {
            ++ut[ch];
        }
        
        int len = INT_MAX, idx = -1;
        for (int i = 0, j = 0; i < s.size(); ++i) {
            ++us[s[i]];
            while (j <= i && check()) {
                if (i - j + 1 < len) {
                    len = i - j + 1;
                    idx = j;
                }
                
                --us[s[j]];
                ++j;
            }
        }
        
        return idx == -1 ? "" : s.substr(idx, len);
    }
};
```
