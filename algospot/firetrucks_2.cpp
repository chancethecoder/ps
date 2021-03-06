#include <cstdio>
#include <vector>
#include <queue>
#include <limits>
using namespace std;
const int INF = numeric_limits<int>::max();
const int MAX_V = 1001;
vector<pair<int, int> > adj[MAX_V];
int spot[MAX_V];
int station[MAX_V];
int V, E, n, m;

int dijkstra()
{
	vector<int> dist(V+1, INF);

	priority_queue<pair<int, int> > pq;

	for(int i = 0; i < m; ++i)
	{
		dist[station[i]] = 0;
		pq.push(make_pair(0, station[i]));
	}

	while(!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if(dist[here] < cost) continue;

		for(int i = 0; i < adj[here].size(); ++i)
		{
			int next_cost = adj[here][i].second + cost;
			int there = adj[here][i].first;

			if(dist[there] > next_cost)
			{
				dist[there] = next_cost;
				pq.push(make_pair(-next_cost, there));
			}
		}
	}

	int ret = 0;

	for(int i = 0; i < n; ++i)
		ret += dist[spot[i]];

	return ret;
}

void proc()
{
	int tc;
	for(scanf("%d", &tc); tc--; )
	{
		scanf("%d %d %d %d", &V, &E, &n, &m);

		for(int i = 1; i <= V; ++i) adj[i].clear();

		for(int i = 0; i < E; ++i)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			adj[a].push_back(make_pair(b, c));
			adj[b].push_back(make_pair(a, c));
		}

		for(int i = 0; i < n; ++i) scanf("%d", &spot[i]);
		for(int i = 0; i < m; ++i) scanf("%d", &station[i]);

		printf("%d\n", dijkstra());
	}
}

int main()
{
	proc();
	return 0;
}
