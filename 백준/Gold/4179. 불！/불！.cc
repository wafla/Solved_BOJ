#include <iostream>
#include <cstdbool>
#include <queue>
#include <string>
using namespace std;

char map[1000][1000];
bool visitedJ[1000][1000]; //지훈이의 방문여부
bool visitedF[1000][1000]; //불 위치 방문여부
queue<pair<int, int>> qJ; //지훈이 위치 저장하는 큐
queue<pair<int, int>> qF; //불 위치 저장하는 큐
int r, c;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

// 기훈이의 상하좌우 이동
int bfs_J() {
	if (qJ.empty()) return -1; //지훈이가 없다면(ex.불로인해) -1반환
	int size = qJ.size();
	int moved = 0;

	while (size--) {
		int y = qJ.front().first;
		int x = qJ.front().second;
		visitedJ[y][x] = true;
		qJ.pop();

		if (map[y][x] == 'J') { //지훈이라면,
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				//map 내의 위치이며, 이동가능하고, 방문한적 없다면 이동
				if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
				if (map[ny][nx] == '.' && !visitedJ[ny][nx]) {
					map[y][x] = '.';
					map[ny][nx] = 'J';
					qJ.push({ ny,nx });
					visitedJ[ny][nx] = true; //지훈이의 움직임 체크
					moved = 1;
				}
			}
		}
	}
	if (moved) return 1; //한 번이상 이동했다면 1반환
	return -1; //그렇지 않다면 -1반환
}

// 불의 상하좌우 이동
void bfs_F() {
	if (qF.empty()) return; //불이 없다면 return
	int size = qF.size();

	while (size--) {
		int y = qF.front().first;
		int x = qF.front().second;
		visitedF[y][x] = true;
		qF.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			//map 내의 위치이며, 이동가능하고, 방문한 적 없다면 이동
			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if (map[ny][nx] != '#' && !visitedF[ny][nx]) {
				map[ny][nx] = 'F';
				qF.push({ ny,nx });
				visitedF[ny][nx] = true;
			}
		}
	}
}

//지훈이가 미로 가장자리에 있는지 확인
bool J_inBorder() {
	for (int j = 0; j < c; j++) {
		if (map[0][j] == 'J') return true;
		if (map[r - 1][j] == 'J') return true;
	}
	for (int i = 0; i < r; i++) {
		if (map[i][0] == 'J') return true;
		if (map[i][c - 1] == 'J') return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    string s;
	// 미로 입력
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> s;
		for (int j = 0; j < c; j++) {
			map[i][j] = s[j];
			if (map[i][j] == 'J') qJ.push({ i,j }); //지훈 위치 qJ에 넣기
			else if (map[i][j] == 'F') qF.push({ i,j }); //불 위치 qF에 넣기
		}
	}

	int t = 0;
	while (1) {
		t++;

		//지훈이가 미로 가장자리에 있는지 확인
		if (J_inBorder()) {
			cout << t;
			break;
		}

		//지훈이가 전혀 움직이지 못했거나(ex.갇힌 공간)
		//지훈이가 없다면(ex.불로 인해) => impossible
		if (bfs_J() == -1) {
			cout << "IMPOSSIBLE";
			break;
		}
		bfs_F(); //불 이동 진행
	}
	return 0;
}
//https://www.acmicpc.net/board/view/101674