#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
const int maxn = 3005;

int dcmp(double x) {
    if (fabs(x) < EPS) return 0;
    return x < 0 ? -1 : 1;
}

struct Point {
    double x, y;
    Point () {}
    Point(double x, double y): x(x), y(y) {}
    Point operator + (Point p) {
        return Point(x + p.x, y + p.y);
    }
    Point operator - (Point p) {
        return Point(x - p.x, y - p.y);
    }
    Point operator * (double p) {
        return Point(x * p, y * p);
    }
    Point spin(double r) {
        return Point(x * cos(r) - y * sin(r), x * sin(r) + y * cos(r));
    }
    double operator * (Point p) {
        return x * p.x + y * p.y;
    }
    double operator ^ (Point p) {
        return x * p.y - y * p.x;
    }
    bool operator == (Point p) {
        return dcmp(fabs(x - p.x)) == 0 && dcmp(fabs(y - p.y)) == 0;
    }
    double mo() {
        return sqrt(x * x + y * y);
    }
    double angle() {
        return atan2(y, x);
    }
} ;

struct Line {
    Point s, e;
    double len;
    Line () {}
    Line(Point s, Point e) : s(s), e(e) {
        len = sqrt((s.x - e.x) * (s.x - e.x) + (s.y - e.y) * (s.y - e.y));
    }
    Point getp(double k) {
        cout << s.x  << ' ' <<  s.y  << ' ' << e.x << ' ' << e.y << ' ' << k << '\n';
        return Point(s.x + (e.x - s.x) * k, s.y + (e.y - s.y) * k);
    }
    pair <int, Point> operator & (Line l) {
        Point a = s, b = e, c = l.s, d = l.e;
        if (dcmp((b - a) ^ (d - c)) == 0) {
            if (dcmp((b - a) ^ (d - a)) == 0) return make_pair(0, a);
            else return make_pair(1, a);
        }
        return make_pair(2, getp(((d - c) ^ (c - a)) / ((d - c) ^ (b - a))));
    }
    bool operator | (Line l) {
        Point a = s, b = e, c = l.s, d = l.e;
        return max(a.x, b.x) >= min(c.x, d.x) && max(c.x, d.x) >= min(a.x, b.x) && max(a.y, b.y) >= min(c.y, d.y) && max(c.y, d.y) >= min(a.y, b.y) &&
               dcmp((b - a) ^ (c - a)) * dcmp((b - a) ^ (d - a)) <= 0 && dcmp((d - c) ^ (a - c)) * dcmp((d - c) ^ (b - c)) <= 0;
    }
} L[maxn];

struct Circle {
    Point o;
    double r;
    int inc(Point p, Circle c) {
        p = p - c.o;
        double len = p.mo();
        if (dcmp(len - c.r) == 0) return 1;
        else if (dcmp(len - c.r) < 0) return 0;
        else return 2;
    }
};

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            double x1, y1, x2, y2;
            scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
            L[i] = Line(Point(x1, y1), Point(x2, y2));
        }
        bool flag = 1;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((L[i] | L[j]) == 1) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0) break;
        }
        puts(flag ? "ok!" : "burned!");
    }
}