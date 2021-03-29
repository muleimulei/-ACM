#define _USE_MATH_DEFINES
#include <stdio.h>
#include <algorithm> 
#include <vector>
#include <math.h>
using namespace std;

struct Point
{
	int x,y,r;
	Point(int a, int b, int c):x(a),y(b),r(c){
	}
	double angle;
	
	bool operator < (const Point p) const
	{
		return this->angle < p.angle;
	}
};

vector<Point> v; //���ڴ洢���еĵ� 


//���ֶ��򣬣�������ˣ��ж�b�Ƿ���a������ 
bool isleft(Point a, Point b)
{
	return a.x * b.y - b.x * a.y >= 0; 
}

int main()
{
#ifdef LOCAL
	freopen("1.txt", "r", stdin);
#endif
	int n;
	while(scanf("%d", &n)==1 && n)
	{
		v.clear();
		for(int i = 0; i < n; i++)
		{
			int x,y,r;
			scanf("%d%d%d", &x, &y, &r);
			v.push_back(Point(x,y,r));
		}
		
		int ans = 0;
		for(int i = 0; i < v.size(); i++) //�������л�׼�� 
		{
			vector<Point> v1; //���ڴ洢����׼��������������ڻ�׼��ĵ㣬��Ҫ���㼫�� 
			for(int j = 0; j < v.size(); j++)
			{
				if(i == j) continue; //���˵���׼��
				Point p(v[j].x - v[i].x, v[j].y - v[i].y, v[j].r);
				if(p.r == 0) //���� ��׼�� ���Գƣ�����ߺڵ� + �ұ߰ٵ� == ��ߺڵ� + �ԳƵ���ߵĵ㣩������ֻ��Ҫ����ÿ����׼�㣬����ÿ����׼��һ��ĵ������������ֵ�����Ǵ� 
				{
					p.x = -1 * p.x;
					p.y = -1 * p.y;
				}
				p.angle = atan2(p.y, p.x); //atan2 ��ȡֵ��Χ��-pi, pi��, 
				v1.push_back(p);
			}
			sort(v1.begin(), v1.end());
			
			int L = 0, R = 0, cnt = 2; // cnt == 2����׼���ϵ����� 
			
			int k = v1.size();
			//��ʱ����� 
			while(L < k)
			{
				if(L == R)
				{
					R = (R+1)%k;
				}
				while(L != R && isleft(v1[L], v1[R])) 
				{
					R = (R+1)%k;
					cnt++;
				}
				ans = max(ans, cnt);
				L++; 
				cnt--; //��L��һ����ô������һ���ٴθ����µ�������� 
			}
		}
		
		printf("%d\n", ans);
	}
}
/*
3
0 0 0
0 1 0
2 2 1
4
0 0 0
0 4 0
4 0 0
1 2 1
7
-1 0 0
1 2 1
2 3 0
2 1 1
0 3 1
1 4 0
-1 2 0
0
*/
