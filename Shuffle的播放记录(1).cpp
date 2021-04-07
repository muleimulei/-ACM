#include <stdio.h>
#include <string.h>
#define N 101000




int num[N], vis[N];
bool ok[N<<1];

int main()
{
	#ifdef LOCAL
	freopen("1.txt", "r", stdin);
	freopen("1.out", "w", stdout);
	#endif
	int kase;
	scanf("%d", &kase);
	while(kase--)
	{
		memset(num, 0, sizeof(num));
		memset(vis, 0, sizeof(num));
		memset(ok, 0, sizeof(ok));
		int s,n;
		scanf("%d%d", &s, &n);
		
		for(int i = 0; i < n; i++)
		{
			int a;
			scanf("%d", &a);
			num[i] = a;
		}
		
		//��ʼ��
		int cnt = 0; //�������м����ظ����� 
		vis[num[0]]++;
		for(int i = 0; i < n+s; i++)
		{
			ok[i] = (cnt == 0);
			if(i + 1 < n && ++ vis[num[i+1]] == 2) cnt++; //���ظ����ֽ��봰�� 
			if(i - s + 1  >=0 && --vis[num[i-s+1]] == 1) cnt--; // �������ظ����ּ���һ�� 
		}
		
		int ans = 0;
		for(int i = 0; i < s; i++)
		{
			bool f = 1;
			for(int j = i; j < n + s; j+= s)
			{
				if(!ok[j])
				{
					f = 0;
					break;
				}
			}
			if(f) ans++;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
