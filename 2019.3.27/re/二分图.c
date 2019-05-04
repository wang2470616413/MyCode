#include<stdio.h>
#include<string.h>
 
const int INF = 505;
 
 
int dfs(int u);			//������u��Ϊ��������·����������ѵ�����1�����ܷ���0��
 
int edge[INF][INF];		//���ڽӾ������ʽ��������ͼ�� 
 
int n, k;
 
int vx[INF], vy[INF];	//vy�������y�������Ѿ�ƥ�����x�㣬����ƥ���i->j�ı�ʾ����Ϊvy[i]=j; 
					 
 
int vis[INF];		//�������������������ĳ���Ƿ��Ѿ�������·�У�����Ѿ��ھͲ�����������·����ˡ� 
 
 
/*
3 4
1 1
1 3
2 2
3 2
Sample Output
2
*/
int main()
{
	scanf("%d %d",&n, &k);
	
	memset(edge, -1, sizeof(edge));
	
	for(int i=1; i <= k; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		edge[x][y] = 1;
	}
	
	memset(vx, -1, sizeof(vx));
	memset(vy, -1, sizeof(vy));		//һ��ʼ������ͼ��û�е�ƥ�䡣 
	
	int result = 0;					//һ��ʼ����ͼƥ����Ϊ0��
	 
	for(int u = 1; u <= n; u++)		//�Զ���ͼ����ߵ�ÿ����Ѱ������·�� 
	{
		memset(vis, 0, sizeof(vis));
		result += dfs(u) ;			//���֪������·����ô ƥ����+1�� 
	}
	
	printf("%d\n", result) ;
	
	 
	
	
	
	return 0;
}
 
int dfs(int u)
{
	for(int v = 1; v <= n; v++)
	{
		if(edge[u][v] == 1 && vis[v] == 0)	//���u��v����֮���бߣ�Ҳ�����������ƥ�䣩��
											//����v��������·��
		{
			vis[v] = 1; 	//�� v���������·��
			if(vy[v] == -1 ||dfs(vy[v]) == 1)	//����õ�ΪΪ��ƥ���
												//�����ܸ��ݸõ�ƥ���x�е��ҵ�δƥ���
			{
				vx[u] = v;						//��ת��ϵ 
				vy[v] = u; 
				return 1;
			} 
		} 
	}
	return 0;
}
