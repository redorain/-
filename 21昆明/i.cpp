#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
double 	X[maxn], Y[maxn];

struct node {
	double tx, ty, tlen;
	bool operator < (const node gg) const {
		return gg.tlen > tlen;
	}
} T[maxn];

map <double , int> mp;

double cal(double x, double y, double xx, double yy) {
	return sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
}

int main(void) {
	int n, m;
	double x1, x2, y1, y2;
	scanf("%d %d", &n, &m);
	scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
	for(int i = 1; i <= n; i++) {
		double xx, yy;
		scanf("%lf %lf", &xx, &yy);
		X[i] = xx, Y[i] = yy;
	}
	double mxx = cal(x1, y1, x2, y2);
	for(int i = 1; i <= m; i++) {
		int x, t;
		scanf("%d %d", &x, &t);
		double a = X[x], b = Y[x];
		int cnt = 0;
		mp.clear();
		for(int i = 1; i <= n; i++) {
			double xx = 0.0, yy = 0.0;
			double c = X[i], d = Y[i];
			if(i == x) continue;
			if(y1 == y2 && b == d) continue;
			if(x1 == x2 && a == c) continue;
//			cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
			if(a == c) {
				xx = a;
				yy = ((y1 - y2) * xx + (x1 - x2) * y1 + (y2 - y1) * x1) / (x1 - x2);
			} else
				xx = (b * (x2 - x1) * (c - a) + (b - d) * (x2 - x1) * a + (x1 - x2) * y1 * (c - a) + (y2 - y1) * x1 * (c - a)) / ((y1 - y2) * (a - c) + (b - d) * (x2 - x1));
			if(b == d) {
				yy = d;
				xx = ((x2 - x1) * yy + (x1 - x2) * y1 + (y2 - y1) * x1) / (y2 - y1);
			}
			if(x1 != x2)
				yy = ((y1 - y2) * xx + (x1 - x2) * y1 + (y2 - y1) * x1) / (x1 - x2);
			else {
				xx = x1;
				yy = ((b - d) * xx + (a - c) * b + (d - b) * a) / (a - c);
			}
			if(y1 == y2) {
				yy = y1;
				xx = ((c - a) * yy + (a - c) * b + (d - b) * a) / (d - b);
			}
			double len = cal(x1, y1, xx, yy);
			map <double, int> :: iterator it = mp.find(len);
			if(xx == -0) xx = 0.0;
			if(yy == -0) yy = 0.0;
			if(len > mxx || cal(xx, yy, x2, y2) > mxx) continue;
			if(it == mp.end()) mp[len] = 1;
			else continue;
			T[cnt].tx = xx, T[cnt].ty = yy;
			T[cnt++].tlen = len;
		}
		sort(T, T + cnt);
//		for(int i  = 0; i < cnt ; i++) {
////			cout << T[i].tlen << '\n';s
//			cout << T[i].tx << ' ' << T[i].ty << '\n';
//		}
		if(t - 1 >= cnt) printf("-1\n");
		else printf("%.10lf %.10lf\n", T[t - 1].tx, T[t - 1].ty);
	}
}
