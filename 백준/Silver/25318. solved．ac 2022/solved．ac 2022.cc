#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <deque>
#include <math.h>
#include <memory.h>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#define X first
#define Y second
#define INF 987654321
using namespace std;
vector<string> v;
int n;
string last_y, last_m, last_d;
string last_h, last_min, last_s;
int to_day(int y, int m, int d)
{
	int mon[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int day = 0;
	for (int i = 0; i < y; i++)
		day += (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) ? 366 : 365;
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) mon[2]++;
	for (int i = 1; i < m; i++)
		day += mon[i];
	return day + d;
}
int diff(int y1, int m1, int d1, int y2, int m2, int d2)
{
	int a = to_day(y1, m1, d1);
	int b = to_day(y2, m2, d2);
	return a - b;
}
void lastday()
{
	for (int i = 0; i < 4; i++)
		last_y += v[n - 1][i];
	for (int i = 5; i < 7; i++)
		last_m += v[n - 1][i];
	for (int i = 8; i < 10; i++)
		last_d += v[n - 1][i];
}
void lastclock()
{
	for (int i = 11; i < 13; i++)
		last_h += v[n - 1][i];
	for (int i = 14; i < 16; i++)
		last_min += v[n - 1][i];
	for (int i = 17; i < 19; i++)
		last_s += v[n - 1][i];
}
double cal(int idx)
{
	int l_y = stoi(last_y);
	int l_m = stoi(last_m);
	int l_d = stoi(last_d);
	int l_h = stoi(last_h);
	int l_min = stoi(last_min);
	int l_s = stoi(last_s);
	
	string i_y, i_m, i_d, i_h, i_min, i_s;
	for (int i = 0; i < 4; i++)
		i_y += v[idx][i];
	for (int i = 5; i < 7; i++)
		i_m += v[idx][i];
	for (int i = 8; i < 10; i++)
		i_d += v[idx][i];
	
	for (int i = 11; i < 13; i++)
		i_h += v[idx][i];
	for (int i = 14; i < 16; i++)
		i_min += v[idx][i];
	for (int i = 17; i < 19; i++)
		i_s += v[idx][i];

	int n_y = stoi(i_y);
	int n_m = stoi(i_m);
	int n_d = stoi(i_d);
	int n_h = stoi(i_h);
	int n_min = stoi(i_min);
	int n_s = stoi(i_s);

	int second = l_s - n_s;
	int minute = l_min - n_min;
	int hour = l_h - n_h;
	int day = diff(l_y, l_m, l_d, n_y, n_m, n_d);
	if (second < 0)
	{
		minute--;
		second += 60;
	}
	if (minute < 0)
	{
		hour--;
		minute += 60;
	}
	if (hour < 0)
	{
		day--;
		hour += 24;
	}
	double ans = day + double(hour)/24 + double(minute)/60/24 + double(second)/60/60/24;
	return ans/365;
}
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	if (n == 0)
	{
		cout << 0;
		return 0;
	}
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string s;
		getline(cin, s);
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	lastday();
	lastclock();
	double num = 0, den = 0;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		string z;
		z += v[i][20];
		z += v[i][21];
		int zz = stoi(z);
		double x = cal(i);
		num += max(pow(0.5, x), pow(0.9, n - 1 - i)) * zz;
		den += max(pow(0.5, x), pow(0.9, n - 1 - i));
	}
	cout << round(num / den);
}