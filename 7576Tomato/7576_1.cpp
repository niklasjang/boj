/*
2019-03-21
장환석

문제
철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다. 토마토는 아래의 그림과 같이 격자 모양 상자의 칸에 하나씩 넣어서 창고에 보관한다.



창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다. 보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를 의미한다. 대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수를 알고 싶어 한다.

토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.

입력
첫 줄에는 상자의 크기를 나타내는 두 정수 M,N이 주어진다. M은 상자의 가로 칸의 수, N 은 상자의 세로 칸의 수를 나타낸다. 단, 2 ≤ M,N ≤ 1,000 이다. 둘째 줄부터는 하나의 상자에 저장된 토마토들의 정보가 주어진다. 즉, 둘째 줄부터 N개의 줄에는 상자에 담긴 토마토의 정보가 주어진다. 하나의 줄에는 상자 가로줄에 들어있는 토마토의 상태가 M개의 정수로 주어진다. 정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다.

출력
여러분은 토마토가 모두 익을 때까지의 최소 날짜를 출력해야 한다. 만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.
*/

#include <iostream>
#include <list>
using namespace std;

const int MAX = 1000;
int mat[MAX][MAX];
bool exist[MAX][MAX]; //False : 익어야할 토마토가 없음, True : 익어야할 토마토가 있음
bool ripe[MAX][MAX]; //False : 토마토가 익지 않음, True : 토마토가 익음
int M, N;
int check_count;
bool check(const int &x, const int &y){
	check_count++;
	int x, y; //익은 토마토의 위치
	//모든 lst에 들어있는 익은 토마토의 위치에서 시작해서
	//사방으로 퍼지면서 exist가 false면 가만히 있고, true면 다음 진행
	//ripe을 체크해서 false면 true로 바꾸고 이미 true이면 종료

	//상
	if (y - 1 >= 0) {
		if (exist[x][y - 1]) {
			ripe[x][y - 1] = true;

		}
		cout << "(" << x << "," << y << ")" << " called (" << x << "," << y - 1 << ")" << "\n";
		return check(x, y - 1);
	}
	//하
	if (y + 1 < N) {
		if (exist[x][y + 1]) {
			ripe[x][y + 1] = true;
		}
		cout << "(" << x << "," << y << ")" << " called (" << x << "," << y + 1 << ")" << "\n";
		check(x, y - 1);
	}

	//좌
	if (x - 1 >= 0) {
		if (exist[x-1][y ]) {
			ripe[x-1][y ] = true;
		}
		cout << "(" << x << "," << y << ")" << " called (" << x-1 << "," << y  << ")" << "\n";
		check(x, y - 1);
	}
	//우
	if (x + 1 < M) {
		if (exist[x+1][y]) {
			ripe[x+1][y] = true;
		}
		cout << "(" << x << "," << y << ")" << " called (" << x +1<< "," << y << ")" << "\n";
		check(x, y - 1);
	}
	
}
int main(void) {
	list<pair<int,int>> lst; //익은 토마토가 들어있는 위치를 list로 저장함
	list<pair<int,int>>::iterator it;
	cin >> M >> N;

	//토마토 현재 상태 입력
	for (int i = 0; i < M;i++) {
		for (int j = 0; j < N; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 1) { //익음
				ripe[i][j] == true;
				lst.push_back(pair<int, int>(i, j));
			}
			else if (mat[i][j] == 0) { //안익음
				exist[i][j] = true;
				//ripe[i][j] = false;
			}
			else if (mat[i][j] == -1){ //없음
				//exist[i][j] = false;
			}
			else {
				cout << "Wrong input." << "\n";
			}
		}
	}
	for (it = lst.begin(); it != lst.end(); it++) {
		check((*it).first, (*it).second);
	}
	cout << "iterator end" << "\n";

	for (int i = 0; i < M;i++) {
		for (int j = 0; j < N; j++) {
			if (exist[i][j] && ripe[i][j] == false) {
				cout << -1 << "\n";
				return 0;
			}
		}
	}
	cout << check_count << endl;

	return 0;
}