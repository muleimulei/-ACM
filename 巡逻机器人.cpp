#include<stdio.h>
#include<queue>
#include <string.h>
using namespace std;
#define N 30

int maze[N][N];
int m,n,k;
int mark[N][N][N]; //�����ĳ���㣬�����˼����ϰ�����ڼ����ظ����ң�����ᳬʱ 


int dir[][2] = 
{
	{-1, 0},
	{0, 1},
	{1, 0},
	{0, -1}
};

struct Point
{
	int x,y,o; //��¼ 
	int d; //���� 
	Point(int a, int b, int c, int d):x(a),y(b),o(c),d(d){
	}	
};

int BFS()
{
	queue<Point> q;
	q.push(Point(0, 0, 0, 0));
	mark[0][0][0] = 1;
	while(!q.empty())
	{
		Point s = q.front(); q.pop();
		if(s.x == m-1 && s.y == n-1)
		{
			return s.d;
		}
		
		for(int i = 0; i < 4; i++)
		{
			int nx = s.x + dir[i][0], ny = s.y + dir[i][1];
			
			if(nx <0 || nx >=m || ny < 0 || ny >=n) continue; //�����Խ�� 
			
			if(maze[nx][ny] == 1) //���Ϊ�ϰ��� 
			{
				if(s.o + 1 > k) continue; //������������ϰ����� 
				if(mark[nx][ny][s.o + 1] == 1) continue; //����ڸõ㴦��ͨ���������ϰ����� ״̬֮ǰ�Ѿ� ������У����֦��״̬�������ظ����� 
				else {
					q.push(Point(nx, ny, s.o+1, s.d+1));
					mark[nx][ny][s.o+1] = 1;
				}
			}
			else
			{
				if(mark[nx][ny][0] == 1) continue; //ͬ�� 
				q.push(Point(nx, ny, 0, s.d+1));
				mark[nx][ny][0] = 1;
			}
		}
	}
	return -1;
}

int main()
{
	#ifdef LOCAL
	freopen("1.txt", "r", stdin);
	#endif
	int kase;
	scanf("%d", &kase);
	while(kase--)
	{
		scanf("%d%d%d", &m, &n, &k);
		memset(mark, 0, sizeof(mark));
		for(int i = 0;i < m; i++)
		{
			for(int j = 0; j < n;j ++)
			{
				scanf("%d", &maze[i][j]);
			}
		}
		
		printf("%d\n", BFS());
	}
	return 0;
}
