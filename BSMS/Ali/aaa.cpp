/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :aaa.cpp
 * @Created Time:2020-08-16 09:58:23
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

// class MyPoint {
// public:
//     double x;
//     double y;
//     MyPoint(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}
//     friend const MyPoint operator+(const MyPoint& p1, const MyPoint& p2) {
//         return MyPoint(p1.x + p2.x, p1.y + p2.y);
//     };
//     friend const MyPoint operator-(const MyPoint& p1, const MyPoint& p2) {
//         return MyPoint(p1.x - p2.x, p1.y - p2.y);
//     };
//     friend const MyPoint operator*(const MyPoint& p, const double& m) {
//         return MyPoint(p.x * m, p.y * m);
//     };
//     friend const MyPoint operator*(const double& m, const MyPoint& p) {
//         return MyPoint(p.x * m, p.y * m);
//     };
//     friend const MyPoint operator/(const MyPoint& p, const double& m) {
//         return MyPoint(p.x / m, p.y / m);
//     };
//     friend ostream& operator<<(ostream& out, MyPoint& a) {
//         printf("(%lf,%lf)", a.x, a.y);
//         return out;
//     };
// };
// typedef MyPoint vect2;  //重命名，向量也是用坐标表示

// class line {
// public:
//     MyPoint start;
//     MyPoint end;
//     line(MyPoint s = MyPoint(0, 0), MyPoint e = MyPoint(0, 0)) : start(s), end(e) {}
// };

// double dot(MyPoint O, MyPoint A, MyPoint B) {  //点乘
//     double oa_x = A.x - O.x;
//     double oa_y = A.y - O.y;
//     double ob_x = B.x - O.x;
//     double ob_y = B.y - O.y;
//     return oa_x * ob_x + oa_y * ob_y;
// }
// double dis(const MyPoint& p1, const MyPoint& p2) {  //求两点之间距离
//     double ans = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
//     return sqrt(ans);
// }
// double dis2(const MyPoint& p1, const MyPoint& p2) {  //求两点之间距离的平方
//     return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
// }
// //点到直线的距离
// double disOfMyPointToLine(MyPoint O, line l) {
//     double cos0 = dot(l.start, O, l.end) / (dis(O, l.start) * dis(l.start, l.end));
//     return dis(O, l.start) * sin(acos(cos0));
// }
// //点在直线上的投影
// MyPoint shadowMyPointOfMyPointToLine(MyPoint A, line l) {  //投影点出了问题
//     MyPoint B = l.start;
//     MyPoint C = l.end;
//     MyPoint D;
//     MyPoint BC = C - B;
//     MyPoint BA = B - A;
//     MyPoint BD = BC * ((BA / dis2(B, C)) * BC);
//     D = B + BD;
//     return D;
// }
struct MyPoint {
    double x, y;
    MyPoint(double xx = 0, double yy = 0) {
        x = xx;
        y = yy;
    }
};
MyPoint GetFootOfPerpendicular(
    const MyPoint& pt,     // 直线外一点
    const MyPoint& begin,  // 直线开始点
    const MyPoint& end)    // 直线结束点
{
    MyPoint retVal;

    double dx = begin.x - end.x;
    double dy = begin.y - end.y;
    if (abs(dx) < 0.00000001 && abs(dy) < 0.00000001) {
        retVal = begin;
        return retVal;
    }

    double u = (pt.x - begin.x) * (begin.x - end.x) +
               (pt.y - begin.y) * (begin.y - end.y);
    u = u / ((dx * dx) + (dy * dy));

    retVal.x = begin.x + u * dx;
    retVal.y = begin.y + u * dy;

    return retVal;
}
class Solution {
public:
    /**
     * @param position: the position of circle A,B and MyPoint P.
     * @return: if two circle intersect return 1, otherwise -1.
     */
    bool xiangjiao(double x1, double y1, double r1, double x2, double y2, double r2) {
        double s;
        s = sqrt(double((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1)));
        if (s <= r2 + r1 && s >= abs(r2 - r1))
            return true;
        else
            return false;
    }
    int IfIntersect(vector<double>& position) {
        // write your code here
        double ax = position[0], ay = position[1], ar = position[2], bx = position[3], by = position[4], br = position[5], px = position[6], py = position[7];
        double dx = px, dy = py;
        MyPoint MyPointa = MyPoint(ax, ay), MyPointb = MyPoint(bx, by), MyPointp = MyPoint(px, py);
        MyPoint d = GetFootOfPerpendicular(MyPointb, MyPointa, MyPointp);
        bool f = false;
        if ((d.x <= px && d.x >= ax) || (d.x >= px && d.x <= ax)) {
            f |= xiangjiao(d.x, d.y, ar, bx, by, br);
        }
        f |= xiangjiao(ax, ay, ar, bx, by, br);
        f |= xiangjiao(px, py, ar, bx, by, br);
        if (f)
            return 1;
        return -1;
    }
};

class Solution {
public:
    /**
     * @param cost: the cost
     * @param val: the value
     * @return: the all cost
     */
    long long mybs(vector<long long>& ps, long long t) {
        int l = 0, h = ps.size();
        while (l < h) {
            int mi = l + (h - l >> 1);
            ps[mi] <= t ? l = mi + 1 : h = mi;
        }
        return l == 0 ? 0 : ps[--l];
    }
    long long doingHomework(vector<int>& cost, vector<int>& val) {
        // Write your code here.
        long long res = 0;
        int n = cost.size();
        if (n == 0)
            return 0;
        vector<long long> ps(n);
        ps[0] = cost[0];
        for (int i = 1; i < n; i++)
            ps[i] = ps[i - 1] + cost[i];
        for (int i : val) {
            res += mybs(ps, i);
        }
        return res;
    }
};

class Solution {
public:
    /**
     * @param n: the length of the string.
     * @param k: the kth Lexicographically smallest that result should be.
     * @return: return the kth Lexicographically smallest string.
     */
    string kthString(int n, long long k) {
        // write your code here.
        long long dp[n + 1];
        memset(dp, 0, sizeof dp);
        dp[1] = 3;
        for (int i = 2; i <= n; i++) {
            dp[i] = 2 * dp[i - 1];
            if (dp[i] >= k) {
            }
        }
    }
};