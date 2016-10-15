#include "Graph.h"
#include "Dijkstra.h"
using namespace std;

int main() {
	graph g(6);
	g.setEdge(0, 1, 7);  g.setEdge(1, 0, 7);
	g.setEdge(1, 3, 15); g.setEdge(3, 1, 15);
	g.setEdge(3, 4, 6);  g.setEdge(4, 3, 6);
	g.setEdge(4, 5, 9);  g.setEdge(5, 4, 9);
	g.setEdge(5, 0, 14); g.setEdge(0, 5, 14);
	g.setEdge(0, 2, 9);  g.setEdge(2, 0, 9);
	g.setEdge(5, 2, 2);  g.setEdge(2, 5, 2);
	g.setEdge(3, 2, 11); g.setEdge(2, 3, 11);
	g.setEdge(1, 2, 10); g.setEdge(2, 1, 10);
	//g.randomUnDirectFill(1, 10);
	g.Print();
	vector<int> distances; 	vector<vector<int>> ways;
	Dijkstra(g, 0, distances, ways);
	for (int i = 0; i < g.getSize(); i++) {
		cout << i << ". " << distances[i] << endl;
	}
	return 0;
}