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
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
using namespace std;
char map_arr[102][102] = { 0 };
int n, m, sx, sy, bx, by;
int dx[4] = { 0,0,-1,1 }, dy[4] = { 1,-1,0,0 };
string move_s;

struct player {
	int lv; // 레벨
	int hp; // 체력
	int att; // 공격력
	int def; // 방어력
	int exp; // 경험치
};
struct monster {
	int x;
	int y;
	string name;
	int W; // 공격
	int A; // 방어
	int H; // 최대 체력
	int E; // 얻는 경험치
};
struct weapon {
	int x;
	int y;
	int num;
};
struct armor {
	int x;
	int y;
	int num;
};
struct accessory {
	int x;
	int y;
	string name;
};

int now_x, now_y; // 현재 위치
int CUR = 20; // 최대 체력
int MAX_E = 5; // 최대 경험치
int p_att = 0; // 무기
int p_def = 0; // 방어구
int turns = 0; // 진행중인 턴
set<string> S; // 장신구 개수
map<string, int> SM; // 장신구

vector<monster> mon; // 몬스터
vector<weapon> W; // 공격
vector<armor> A; // 방어
vector<accessory> O; // 장신구
player p = { 1,20,2,2,0 }; // 레벨, 체력, 공격, 방어, 경험치

pair<int, int> check(int idx)
{
	int nx = now_x + dx[idx];
	int ny = now_y + dy[idx];
	if (map_arr[nx][ny] == '#')
		return { now_x,now_y };
	else if (nx <= 0 || ny <= 0 || nx > n || ny > m)
		return { now_x,now_y };
	return { nx,ny };
}

void Gameover(char x, string s)
{
	if (x == '^' || x == '&')
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				cout << map_arr[i][j];
			cout << '\n';
		}
	}
	else if (x == 'M' || x == 'S')
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (now_x == i && now_y == j)
					cout << "@";
				else
					cout << map_arr[i][j];
			}
			cout << '\n';
		}
	}
	cout << "Passed Turns : " << turns << '\n';
	cout << "LV : " << p.lv << '\n';
	cout << "HP : " << p.hp << "/" << CUR << '\n';
	cout << "ATT : " << p.att << "+" << p_att << '\n';
	cout << "DEF : " << p.def << "+" << p_def << '\n';
	cout << "EXP : " << p.exp << "/" << MAX_E << '\n';
	if (x == '^')
		cout << "YOU HAVE BEEN KILLED BY SPIKE TRAP..\n";
	else if (x == '&')
		cout << "YOU HAVE BEEN KILLED BY " << s << "..\n";
	else if (x == 'M')
		cout << "YOU WIN!\n";
	else if (x == 'S')
		cout << "Press any key to continue.\n";
	exit(0);
}

void Fight(int idx, char x)
{
	bool m_first = false;
	int p_first = p.att + p_att;
	int tmp = mon[idx].H;
	if (SM["CO"])
	{
		if (SM["DX"])
			p_first *= 3;
		else
			p_first *= 2;
	}
	if (SM["HU"] && x == 'M')
	{
		p.hp = CUR;
		m_first = true;
	}
	mon[idx].H -= max(1, p_first - mon[idx].A);
	if (mon[idx].H > 0)
	{
		if (!m_first)
		{
			p.hp -= max(1, mon[idx].W - (p.def + p_def));
			if (p.hp <= 0)
			{
				if (SM["RE"])
				{
					p.hp = CUR;
					now_x = sx;
					now_y = sy;
					mon[idx].H = tmp;
					S.erase("RE");
					SM["RE"] = 0;
					return;
				}
				else
				{
					p.hp = 0;
					Gameover('&', mon[idx].name);
				}
			}
		}
	}
	while (mon[idx].H > 0)
	{
		mon[idx].H -= max(1, p.att + p_att - mon[idx].A);
		if (mon[idx].H <= 0)
			break;
		p.hp -= max(1, mon[idx].W - (p.def + p_def));
		if (p.hp <= 0)
		{
			if (SM["RE"])
			{
				p.hp = CUR;
				now_x = sx;
				now_y = sy;
				mon[idx].H = tmp;
				S.erase("RE");
				SM["RE"] = 0;
				return;
			}
			else
			{
				p.hp = 0;
				Gameover('&', mon[idx].name);
			}
		}
	}
	map_arr[now_x][now_y] = '.';
	if (SM["HR"])
		p.hp = min(p.hp + 3, CUR);
	if (SM["EX"])
		p.exp += mon[idx].E * 1.2;
	else
		p.exp += mon[idx].E;
	if (p.exp >= MAX_E)
	{
		CUR += 5;
		MAX_E += 5;
		p.hp = CUR;
		p.att += 2;
		p.def += 2;
		p.lv++;
		p.exp = 0;
	}
	if (x == 'M')
		Gameover('M', "");
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	int mon_cnt = 0, box_cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map_arr[i][j];
			if (map_arr[i][j] == '@')
			{
				map_arr[i][j] = '.';
				sx = i;
				sy = j;
				now_x = i;
				now_y = j;
			}
			else if (map_arr[i][j] == 'M')
			{
				bx = i;
				by = j;
				mon_cnt++;
			}
			else if (map_arr[i][j] == '&')
				mon_cnt++;
			else if (map_arr[i][j] == 'B')
				box_cnt++;
		}
	}
	cin >> move_s;
	for (int i = 0; i < mon_cnt; i++)
	{
		int x, y;
		cin >> x >> y;
		string str;
		cin >> str;
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		mon.push_back({ x,y,str,a,b,c,d });
	}
	for (int i = 0; i < box_cnt; i++)
	{
		int x, y;
		string str;
		cin >> x >> y >> str;
		if (str == "W")
		{
			int a;
			cin >> a;
			W.push_back({ x,y,a });
		}
		else if (str == "A")
		{
			int a;
			cin >> a;
			A.push_back({ x,y,a });
		}
		else if (str == "O")
		{
			string s;
			cin >> s;
			O.push_back({ x,y,s });
		}
	}

	for (int i = 0; i < move_s.size(); i++)
	{
		turns++;
		char x = move_s[i];
		if (x == 'R')
		{
			pair<int, int> N = check(0);
			now_x = N.X;
			now_y = N.Y;
		}
		else if (x == 'L')
		{
			pair<int, int> N = check(1);
			now_x = N.X;
			now_y = N.Y;
		}
		else if (x == 'U')
		{
			pair<int, int> N = check(2);
			now_x = N.X;
			now_y = N.Y;
		}
		else if (x == 'D')
		{
			pair<int, int> N = check(3);
			now_x = N.X;
			now_y = N.Y;
		}
		if (map_arr[now_x][now_y] == 'B')
		{
			map_arr[now_x][now_y] = '.';
			for (int j = 0; j < W.size(); j++)
			{
				if (W[j].x == now_x && W[j].y == now_y)
				{
					p_att = W[j].num;
					break;
				}
			}
			for (int j = 0; j < A.size(); j++)
			{
				if (A[j].x == now_x && A[j].y == now_y)
				{
					p_def = A[j].num;
					break;
				}
			}
			for (int j = 0; j < O.size(); j++)
			{
				if (S.size() >= 4)
					break;
				if (O[j].x == now_x && O[j].y == now_y)
				{
					S.insert(O[j].name);
					SM[O[j].name] = 1;
					break;
				}
			}
		}
		else if (map_arr[now_x][now_y] == '^')
		{
			if (SM["DX"])
				p.hp -= 1;
			else
				p.hp -= 5;
			if (p.hp <= 0)
			{
				if (SM["RE"])
				{
					p.hp = CUR;
					now_x = sx;
					now_y = sy;
					S.erase("RE");
					SM["RE"] = 0;
				}
				else
				{
					p.hp = 0;
					Gameover('^', "");
				}
			}
		}
		else if (map_arr[now_x][now_y] == '&' || map_arr[now_x][now_y] == 'M')
		{
			for (int j = 0; j < mon.size(); j++)
			{
				if (mon[j].x == now_x && mon[j].y == now_y)
				{
					if (now_x == bx && now_y == by)
						Fight(j, 'M');
					else
						Fight(j, 'm');
					break;
				}
			}
		}
	}
	Gameover('S', "");
}