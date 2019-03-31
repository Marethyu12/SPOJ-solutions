#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int INF = 999999;
	
	int N;
	int E;
	int T;
	int M;
	
	cin >> N;
	
	int dist[N][N];
	
	memset(dist, INF, sizeof(dist));
	
	cin >> E;
	cin >> T;
	cin >> M;
	
	int u;
	int v;
	int weight;
	
	for (int i = 0; i < M; ++i)
	{
		cin >> u >> v >> weight;
		
		dist[--u][--v] = weight;
	}
	
	for (int i = 0; i < N; ++i)
		dist[i][i] = 0;
	
	for (int k = 0; k < N; ++k)
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	
	int c = 0;
	
	for (int i = 0; i < N; ++i)
		if (dist[i][E - 1] <= T)
			c++;
	
	cout << c << "\n";
	
	return 0;
}