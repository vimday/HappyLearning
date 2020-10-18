/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :BBB.cpp
 * @Created Time:2020-10-10 19:25:48
 * @E-mail      :lwftx@outlook.com
 * @GitHub      :https://github.com/vimday
 */
#include <bits/stdc++.h>
using namespace std;
void debug() {
#ifdef LOCAL
    freopen("E:\\Cpp\\in.txt", "r", stdin);
    freopen("E:\\Cpp\\out.txt", "w", stdout);
#endif
}
struct DSU {
    std::vector<int> data;
    void init(int n) {
        data.assign(n, -1);
    }
    bool unionSet(int y, int x) {
        x = root(x);
        y = root(y);
        if (x != y) {
            if (data[y] < data[x]) std::swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 寻找朋友总数
     * @param M int整型二维数组 
     * @param MRowLen int M数组行数
     * @param MColLen int* M数组列数
     * @return int整型
     */
    int findFriendNum(int** M, int MRowLen, int* MColLen) {
        // write code here
        DSU dsu;
        dsu.init(MRowLen);
        for (int i = 0; i < MRowLen; i++)
            for (int j = i + 1; j < MRowLen; j++)
                if (M[i][j])
                    dsu.unionSet(i, j);
        int res = 0;
        for (int i = 0; i < MRowLen; i++) {
            cout << dsu.root(i) << endl;
            if (dsu.root(i) == 0 - i)
                res++;
        }

        return res;
    }
};

int main(int argc, char const* argv[]) {
    cout << "11111111111" << endl;
    int m[3][3];

    memset(m, 0, sizeof m);
    m[0][0] = m[0][1] = m[1][0] = m[1][1] = m[1][2] = m[2][1] = m[2][2] = 1;
    DSU dsu;
    dsu.init(3);
    for (int i = 0; i < 3; i++)
        for (int j = i + 1; j < 3; j++)
            if (m[i][j])
                dsu.unionSet(i, j);
    int res = 0;
    for (int i = 0; i < 3; i++) {
        cout << i << " " << dsu.root(i) << endl;
        if (dsu.root(i) == 0 - i)
            res++;
    }
    return 0;
}
