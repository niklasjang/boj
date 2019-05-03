/*
2019-03-21
��ȯ��

����
ö���� �丶�� ���忡���� �丶�並 �����ϴ� ū â���� ������ �ִ�. �丶��� �Ʒ��� �׸��� ���� ���� ��� ������ ĭ�� �ϳ��� �־ â���� �����Ѵ�.



â���� �����Ǵ� �丶��� �߿��� �� ���� �͵� ������, ���� ���� ���� �丶��鵵 ���� �� �ִ�. ���� �� �Ϸ簡 ������, ���� �丶����� ������ ���� �ִ� ���� ���� �丶����� ���� �丶���� ������ �޾� �Ͱ� �ȴ�. �ϳ��� �丶���� ������ ���� ����, ������, ��, �� �� ���⿡ �ִ� �丶�並 �ǹ��Ѵ�. �밢�� ���⿡ �ִ� �丶��鿡�Դ� ������ ���� ���ϸ�, �丶�䰡 ȥ�� ������ �ʹ� ���� ���ٰ� �����Ѵ�. ö���� â���� ������ �丶����� ��ĥ�� ������ �� �Ͱ� �Ǵ���, �� �ּ� �ϼ��� �˰� �;� �Ѵ�.

�丶�並 â���� �����ϴ� ���ڸ���� ���ڵ��� ũ��� ���� �丶���� ���� ���� �丶����� ������ �־����� ��, ��ĥ�� ������ �丶����� ��� �ʹ���, �� �ּ� �ϼ��� ���ϴ� ���α׷��� �ۼ��϶�. ��, ������ �Ϻ� ĭ���� �丶�䰡 ������� ���� ���� �ִ�.

�Է�
ù �ٿ��� ������ ũ�⸦ ��Ÿ���� �� ���� M,N�� �־�����. M�� ������ ���� ĭ�� ��, N �� ������ ���� ĭ�� ���� ��Ÿ����. ��, 2 �� M,N �� 1,000 �̴�. ��° �ٺ��ʹ� �ϳ��� ���ڿ� ����� �丶����� ������ �־�����. ��, ��° �ٺ��� N���� �ٿ��� ���ڿ� ��� �丶���� ������ �־�����. �ϳ��� �ٿ��� ���� �����ٿ� ����ִ� �丶���� ���°� M���� ������ �־�����. ���� 1�� ���� �丶��, ���� 0�� ���� ���� �丶��, ���� -1�� �丶�䰡 ������� ���� ĭ�� ��Ÿ����.

���
�������� �丶�䰡 ��� ���� �������� �ּ� ��¥�� ����ؾ� �Ѵ�. ����, ����� ������ ��� �丶�䰡 �;��ִ� �����̸� 0�� ����ؾ� �ϰ�, �丶�䰡 ��� ������ ���ϴ� ��Ȳ�̸� -1�� ����ؾ� �Ѵ�.
*/

#include <iostream>
#include <list>
using namespace std;

const int MAX = 1000;
int mat[MAX][MAX][2];  //x, y, day
int M, N;
int day= 1;
list<pair<int, int>> lst; //���� �丶�䰡 ����ִ� ��ġ�� list�� ������
list<pair<int, int>>::iterator it, frame;

void DayCount(int x, int y) {
	//��
	if (x - 1 >= 0) {
		if (mat[x - 1][y][0] == 0) { //����� ���;�����
			mat[x - 1][y][0] = 1;
			mat[x - 1][y][1] = day; //�� ��°�� �ʹ��� ����
			lst.push_back(pair<int, int>(x - 1, y ));
		}
	}
	//��
	if (x + 1 < N) {
		if (mat[x + 1][y][0] == 0) { //����� ���;�����
			mat[x + 1][y][0] = 1;
			mat[x + 1][y][1] = day; //�� ��°�� �ʹ��� ����
			lst.push_back(pair<int, int>(x + 1, y));
		}
	}

	//��
	if (y - 1 >= 0) {
		if (mat[x][y - 1][0] == 0) { //����� ���;�����
			mat[x][y - 1][0] = 1;
			mat[x][y - 1][1] = day; //�� ��°�� �ʹ��� ����
			lst.push_back(pair<int, int>(x, y - 1));
		}
	}
	//��
	if (y + 1 < M) {
		if (mat[x][y + 1][0] == 0) { //����� ���;�����
			mat[x][y + 1][0] = 1;
			mat[x][y + 1][1] = day; //�� ��°�� �ʹ��� ����
			lst.push_back(pair<int, int>(x, y + 1));
		}
	}
}

int main(void) {
	cin >> M >> N;
	
	//�丶�� ���� �Է�
	for (int i = 0; i < N;i++) {
		for (int j = 0; j < M; j++) {
			cin >> mat[i][j][0];     //�丶�� ���� �Է�
			if (mat[i][j][0] == 1) { //���� �丶�並 list�� �������ش�.
				lst.push_back(pair<int, int>(i, j));
			}
			else if (mat[i][j][0] == -1) { //���� ĭ�� day�� -1�� �д�.
				mat[i][j][1] = -1;
			}

		}
	}
	cout << "���� �Է� �Ϸ�" << "\n";

	for (int i = 0; i < N;i++) {
		for (int j = 0; j < M; j++) {
			cout << mat[i][j][0] << " ";
		}
		cout << "\n";
	}
	cout << "��� �Ϸ�" << "\n";

	int x = 0, y = 0;
	//��� ���� �丶�並 �ѹ��� ���鼭 call
	it = lst.begin();
	frame = lst.end();
	do{
		it = lst.begin();
		cout << "����" << "\n";
		for (it = lst.begin(); it != frame; it = lst.begin()) {
			x = (*it).first;
			y = (*it).second;
			DayCount(x, y); // N��° day���� �ֺ��� ������ �丶�並 �Ͱ� �����.
			lst.pop_front();
		}
		frame = lst.end();
	} while (lst.begin() != lst.end());
	cout << "���� �Ϸ�" << "\n";


	for (int i = 0; i < N;i++) {
		for (int j = 0; j < M; j++) {
			cout << mat[i][j][1] << " ";
		}
		cout << "\n";
	}
	cout << "��� �Ϸ�" << "\n";


	return 0;
}