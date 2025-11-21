#include "e-dijkstra.h"
#include <vector>
#include <fstream>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
	int dest;
	int distance;
};

struct Node {
	int city_name = 0;
	int power = 0;
	int recharge = 0;
	int now_dist = 0;

	vector<Edge> neighbor{};
	bool operator<(const Node& other) const {
		return now_dist > other.now_dist;
	}
};

class vehiclestra {
public:
	vehiclestra(char const* filename, int power);
	vehiclestra(char const* filename);
	void read_data(char const* filename, int power = 0);
	bool dijkstra(int source);
	void reset();
	int Get_city() { return city_number; }
	void set_power(int power) { maximum_power = power; }
	bool start();
	int min_length = 0;
	int max_length = 0;
private:
	int city_number = 0;
	int maximum_recharge = 0;

	int maximum_power = 0;
	std::vector<Node> data{};
	std::vector<bool> true_table{};

};

void vehiclestra::reset() {
	for (auto& a : data) {
		a.now_dist = 0;
		a.power = 0;
		a.recharge = 0;
	}
	std::fill(true_table.begin(), true_table.end(), false);
}

bool vehiclestra::start()
{
	for (int i = 0; i < city_number; i++) {
		if (dijkstra(i) == false) {
			return false;
		}
		reset();
	}
	return true;
}

bool e_dijkstra(char const* filename, int power)
{
	vehiclestra go(filename, power);
	return go.start();
}



vehiclestra::vehiclestra(char const* filename, int power)
{
	read_data(filename, power);
}

vehiclestra::vehiclestra(char const* filename)
{
	read_data(filename);
}

void vehiclestra::read_data(char const* filename, int power)
{
	std::ifstream in(filename, std::ifstream::in);

	int help;
	in >> help;
	city_number = help;
	in >> help;
	maximum_recharge = help;
	in >> help;

	true_table.resize(city_number, false);
	data.resize(city_number);
	for (size_t i = 0; i < data.size(); i++) {
		data[i].city_name = i;
	}

	min_length = numeric_limits<int>::max();
	int start, end, length;
	while (in >> start >> end >> length) {
		max_length += length;
		if (min_length > length) {
			min_length = length;
		}
		if (power != 0) {
			if (length <= power) {
				data[start].neighbor.push_back({ end, length });
				data[end].neighbor.push_back({ start, length });
			}
		}
		else {
			data[start].neighbor.push_back({ end, length });
			data[end].neighbor.push_back({ start, length });
		}

	}

	maximum_power = power;
}

bool vehiclestra::dijkstra(int source)
{
	priority_queue<Node> que;
	data[source].recharge = maximum_recharge;
	que.push(data[source]);

	while (!que.empty()) {
		Node cur = que.top();
		que.pop();

		if (true_table[cur.city_name]) {
			continue;
		}
		true_table[cur.city_name] = true;

		int current_power = cur.power;

		for (auto nei : cur.neighbor) {
			if (true_table[nei.dest]) {
				continue;
			}
			Node* next = &data[nei.dest];
			if (current_power - nei.distance >= 0) {
				next->power = cur.power - nei.distance;
				next->recharge = cur.recharge;
				next->now_dist = nei.distance;
				que.push(*next);
			}
			else {
				if (cur.recharge != 0 && maximum_power - nei.distance >= 0) {
					next->power = maximum_power - nei.distance;
					next->recharge = cur.recharge - 1;
					next->now_dist = nei.distance;
					que.push(*next);
				}
			}
		}

	}

	return std::all_of(true_table.begin(), true_table.end(),
		[](bool x) { return x == true; });
}


int e_dijkstra_solver(char const* filename)
{
	vehiclestra go(filename);
	int trying = (go.min_length + go.max_length) / 2;
	go.set_power(trying);
	while (go.max_length - go.min_length != 2) {
		if (go.start()) {
			go.max_length = trying;
		}
		else {
			go.min_length = trying;
		}
		go.reset();
		trying = (go.min_length + go.max_length) / 2;
		go.set_power(trying);
	}


	return go.max_length - 1;
}


//Dijkstra(G, source)
//{
//	for each vertex v in G                  // Initialization of helper data structures
//	{
//		dist[v] = INFINITY                  // Unknown distance from source to v
//		prev[v] = UNDEFINED                 // Previous node in optimal path from source
//	}
//
//		dist[source] = 0                        // Distance from source to source
//
//		binary_heap BH                          // 
//		BH.push(source, dist[source])         // only source added
//
//		while BH is not empty                   // can be optimized for connected by counting evaluated nodes
//		{
//			u = BH.top()                        // Node with the least estimated distance - GREEDY
//			BH.pop()
//
//			if (u.evaluated) continue         // skip duplicates
//
//			u.evaluated = true
//
//			for each neighbor v of u
//			   if (v.evaluated) continue      // skip - tiny optimization, may be 
//
//			   alt = dist[u] + length(u, v)     // relaxation
//			   if alt < dist[v]:                // a shorter path to v has been found
//				   dist[v] = alt
//				   prev[v] = u
//				   BH.push(v, dist[v])        // will insert a duplicate vertex
//		}
//
//			return dist[], prev[]
//}