#include<stdio.h>
#include<vector>
using namespace std;

struct edge
{
	vector<int> in; //����������±�
	vector<int> out; //��������±� 

	edge(vector<int> i, vector<int> o):in(i),out(o){
	}
};

struct NP
{
	int token; //�����е� tokens��Ŀ
//	vector<edge> NT; // �Ӹÿ��������ı�Ǩ���� 
	NP(int t):token(t){
	}
};


vector<NP> node; //��¼���п��� 
vector<edge> trans; //��Ǩ���� 
int main()
{
	#ifdef LOCAL
		freopen("1.txt", "r", stdin);
		freopen("1.out","w",stdout);
	#endif
	int n,kase=0;
	while(scanf("%d", &n) == 1 && n)
	{
//		if(kase) printf("\n");
		node.clear();
		trans.clear();
		for(int i = 0; i < n; i++)
		{
			int a;
			scanf("%d", &a);
			node.push_back(NP(a));
		}
		int t;
		scanf("%d", &t);
		
		for(int i = 0; i < t; i++)
		{
			int m;
			vector<int> in, out;
			while(scanf("%d", &m)==1 && m)
			{
				if(m < 0)
				{
					in.push_back(m * (-1) -1);
				}
				else
				{
					out.push_back(m -1);
				}
			}
			trans.push_back(edge(in, out));
		}
		
		int NF;
		scanf("%d", &NF);
		int run = 0, h = NF;
		while(NF--)
		{
			bool flag = 0;
			for(int i = 0; i < trans.size(); i++)
			{
				edge e = trans[i];
				vector<int> v = e.in;
				vector<NP> n = node;
				for(int j = 0; j < v.size(); j++)
				{
					n[v[j]].token--;
				}
				
				bool r = 1;
				for(int j  = 0; j < v.size(); j++)
				{
					if(n[v[j]].token < 0)
					{
						r = 0;
						break;
					}
				}
				
				
				if(r) //����ñ�Ǩ����ִ�� 
				{
					for(int j = 0; j < v.size(); j++)
					{
						node[v[j]].token--;
					}
					vector<int> y = e.out;
					for(int i = 0; i < y.size(); i++)
					{
						node[y[i]].token++;
					}
					flag = 1; 
					break; //����ѭ����������һ�� 
				}
			}
			
			if(flag)
			{
				run++;
			}else
			{
				break;
			}
		}
		
		printf("Case %d: ", ++kase);
		if(run == h)
		{
			printf("still live after %d transitions\n", run);
		}
		else
		{
			printf("dead after %d transitions\n", run);
		}
		printf("Places with tokens:");
		for(int i = 0; i < node.size(); i++)
		{
			if(node[i].token)printf(" %d (%d)", i+1, node[i].token);
		}
		printf("\n\n");
	}
	return 0; 
} 
