#pragma once
#include "Graph.h"
#include <algorithm>
#include <vector>
#define inf 1000000

void Dijkstra(const graph & g, const int a, vector<int> & d, vector<vector<int>> & p) {
	//prepare containers
	d.resize(g.getSize());	fill_n(d.begin(), g.getSize(), inf); int min, vmin;
	vector<bool> used;	used.resize(g.getSize()); int countOfNotUsed = g.getSize(); 
	fill_n(used.begin(), g.getSize(), false);  p.resize(g.getSize());
	//p will contain ways from a to all nodes
	//d will contain distances from a to all
	//min and vmin used to find a not used v with min distance
	d[a] = 0; p[a].push_back(a);
	//for all not used v
	while (countOfNotUsed > 0) {
		//find v with min d[v];
		min = inf;
		for (int v = 0; v < g.getSize(); v++) {
			if ((used[v] == false) && (d[v] < min)) {
					vmin = v;
					min = d[v];
			}
		}
		//set u[v] as true
		used[vmin] = true;
		countOfNotUsed--;
		//check all not checked nodes around current
		for (int u = 0; u < g.getSize(); u++) {
			if ((used[u] == 0) && (g.isEdge(vmin, u))) {
				//if distance in them more than distance in current + weight
				if (d[u] > d[vmin] + g.getWeight(vmin, u)) {
					//change it!
					d[u] = d[vmin] + g.getWeight(vmin, u);
					//change the way 
					p[u] = p[vmin]; 
					//and add checked
					p[u].push_back(u);
				}
			}
		}
	}
};