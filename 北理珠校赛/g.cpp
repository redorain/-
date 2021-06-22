#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

double dcmp(double x) {
    if (fabs(x) < eps) return 0;
    return x > 0 ? 1 : -1;
}

struct Point {
    double x, y, z;
    Point (double x, double y, double z) : x(x), y(y), z(z) {}
    Point () {}
    Point operator - (Point p) {
        return Point(x - p.x, y - p.y, z - p.z);
    }
    Point operator + (Point p) {
        return Point(x + p.x, y + p.y, z + p.z);
    }
    Point operator ^ (Point p) {
        return Point(y * p.z - p.y * z, z * p.x - p.z * x, x * p.y - p.x * y);
    }
    Point operator * (double k) {
        return Point(x * k, y * k, z * k);
    }
    double operator * (Point p) {
        return x * p.x + y * p.y + z * p.z;
    }
    double mo() {
        double ret = sqrt(x * x + y * y + z * z);
        if (dcmp(ret) == 0) return 0;
        else return ret;
    }
};

Point p_to_plane(Point p, Point p0, Point p1) {
    double k = ((p - p0) * p1) / p1.mo();
    return p - (p1 * k);
}

struct Line {
    Point s, e;
    double len;
    Line (Point s, Point e) : s(s), e(e) {
        Point now = e - s;
        len = now.mo();
    }
    Line () {}
};

bool L_to_plane(Point p1, Point p2, Point p0, Point n, Point &s) {
    Point v = p2 - p1;
    // n = p0 ^ n;
    // p0.x = 0.0, p0.y = 0.0;
    if (dcmp((n * (p2 - p1))) == 0) return 0;
    double t = (n * (p0 - p1)) / (n * (p2 - p1));
    s = p1 + v * t;
    return 1;
}

int main () {
    int T, n, m, k, x, y;
    while (T--) {
        double x1, y1, z1, x2, y2, z2;
        scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &z1, &x2, &y2, &z2);
        Point p1 = Point(x1, y1, z1), p2 = Point(x2, y2, z2);
        scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &z1, &x2, &y2, &z2);
        Point p3 = Point(x1, y1, z1), p4 = Point(x2, y2, z2);
        Point l1 = (p2 - p1), l2 = (p4 - p3);
        Point pl = l1 ^ l2;
        Point s1, s2;
        double ans = 0.0;
        cout << pl.x << ' ' << pl.y << ' ' << pl.z << '\n';
        if (L_to_plane(p1, p2, pl, l2, s1) == 0) {
            printf("%.10lf\n", ans);
            continue;
        }
        cout << s1.x << ' ' << s1.y << ' ' << s1.z << '\n';
        if (L_to_plane(p3, p4, pl, l1, s2) == 0) {
            printf("%.10lf\n", ans);
            continue;
        }
        cout << s2.x << ' ' << s2.y << ' ' << s2.z << '\n';
        Line l = Line(s1, s2);
        ans = l.len;
        printf("%.10lf\n", ans);
    }
    return 0;
}
