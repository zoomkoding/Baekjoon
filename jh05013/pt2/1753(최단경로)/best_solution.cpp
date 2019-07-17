#include <cstdio>
#include <vector>
#include <queue>
#define INF 0x7000000

using namespace std;
typedef pair<int, int> Pair;

vector<Pair> graph[20000];
vector<int>  minCost;
struct priority {
	bool operator()(Pair &x, Pair &y) {
		return x.second > y.second;
	}
};
char buf[0x40000];
int  idx, bytes, vertex, edge, start;

inline static int read() {
	if (!(idx - bytes)) {
		bytes = fread(buf, sizeof(char), sizeof(buf), stdin);
		idx = 0;
	}
	return buf[idx++];
}
inline static int parse() {
	int ret = 0,
		num = read();

	while (num - 0x0A && num - 0x20) {
		ret = ret*10 + (num & 0x0F);
		num = read();
	}
	return ret;
}
vector<int> dijkstra(int root) {
	priority_queue<Pair, vector<Pair>, priority> visited;
	vector<int> dist(vertex, INF);

	dist[root] = 0;
	visited.push({ root, 0 });

	while (!visited.empty()) {
		int pos = visited.top().first,
			weight = visited.top().second;
		visited.pop();

		if (weight != dist[pos])
			continue;
		for (auto x : graph[pos]) {
			int newWeight = dist[pos] + x.second;

			if (dist[x.first] > newWeight) {
				dist[x.first] = newWeight;
				visited.push({ x.first, newWeight });
			}
		}
	}
	return dist;
}

int main() {
	scanf("%d %d %d", &vertex, &edge, &start), read();

	while (edge--) {
		int x = parse(),
			y = parse(),
			v = parse();
		graph[x - 1].push_back({ y - 1, v });
	}
	minCost = dijkstra(--start);

	for (int sorted : minCost)
		if (!(sorted - INF))
			puts("INF");
		else
			printf("%d\n", sorted);
}