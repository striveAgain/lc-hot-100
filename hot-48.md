### 算法，时间复杂度 $O(n^2)$

顺时针旋转 $90^\circle$，采用翻转代替旋转的方式，先将 `(i, j)` 和 `(j, i)` 互换，然后以矩阵的中垂线为对称轴，翻转矩阵；

逆时针旋转 $90^\circle$ 的话，以反对角线为对称轴进行翻转，即 `(i, j)` 变为 `(n - 1 - i, n - 1 - j)`，然后作同样的水平翻转即可；

旋转 $180^\circle$，相当于中心对称，变换过程 `(i, j) -> (j, i) -> (n - 1 - j, n - 1 - i)`；

顺时针 $270^\circle$ 相当于逆时针 $90^\circle$；同理，逆时针 $270^\circle$ 相当于顺时针 $90^\circle$；

### C++ 代码
```c++
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n / 2; ++i) {
            int l = i, r = n - 1 - i;
            for (int j = 0; j < n; ++j) {
                swap(matrix[j][l], matrix[j][r]);
            }
        }
    }
};
```
