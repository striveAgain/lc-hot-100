### 算法，时间复杂度 $O(n k \log k)$

**`n` 为字符串个数，`k` 为每个字符串的最大长度；**

先对每个字符串进行排序，得到变形后的字典序最小的相同字母组成的字符串，将它作为哈希表的键值；

然后通过键值将原字符串加入到对应的哈希表值域中去即可；

最后遍历哈希表得到答案；

### C++ 代码
```c++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        if (!n) {
            return {};
        }

        unordered_map<string, vector<string> > ump;

        vector<vector<string> > ans;
        for (int i = 0; i < n; ++i) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());

            ump[tmp].push_back(strs[i]);
        }

        for (auto& it : ump) {
            ans.push_back(it.second);
        }

        return ans;
    }
};
```
