#include <stdio.h>
int map[101][101] = { 0 }, visit[101][101] = { 0 }, dx[] = { 1,0,0,-1 }, dy[] = { 0,1,-1,0 }, n, m, t = 1, b = 0;
typedef struct q {
	int x;
	int y;
}q;
q queue[10001];
q deque()
{
	q temp = queue[b++];
	return temp;
}
void enque(int x, int y)
{
	q temp;
	temp.x = x;
	temp.y = y;
	queue[t++] = temp;
}
void bfs()
{
	int nx, ny, i;
	while (t != b)
	{
		q pop = deque();
		for (i = 0; i < 4; i++)
		{
			nx = pop.x + dx[i];
			ny = pop.y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
				if (map[nx][ny] == 1)
					if (visit[nx][ny] == 0) 
					{
						visit[nx][ny] = visit[pop.x][pop.y] + 1;
						enque(nx, ny);
					}
		}
	}
}
int main()
{
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%1d", &map[i][j]);
	visit[0][0] = 1;
	bfs();
	printf("%d", visit[n-1][m-1]);
}
//참고 https://m.blog.naver.com/sukwoo0711/220902510038