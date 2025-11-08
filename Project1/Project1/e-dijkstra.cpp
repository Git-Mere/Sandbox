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
	bool dijkstra(int source);
	void reset();
	int Get_city() { return city_number; }
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

bool e_dijkstra(char const* filename, int power)
{
	vehiclestra go(filename, power);
	for (int i = 0; i < go.Get_city(); i++) {
		if (go.dijkstra(i) == false) {
			return false;
		}
		go.reset();
	}

    return true;
}

vehiclestra::vehiclestra(char const* filename, int power)
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

	int start, end, length;
	while (in >> start >> end >> length) {
		data[start].neighbor.push_back({ end, length });
		data[end].neighbor.push_back({ start, length });
	}

	maximum_power = power;
}

bool vehiclestra::dijkstra(int source)
{
	priority_queue<Node> que;
	data[source].recharge = maximum_recharge;
	que.push(data[source]);

	true_table[source] = true;

	while (!que.empty()) {
		Node cur = que.top();
		que.pop();

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
				true_table[nei.dest] = true;
			}
			else {
				if (cur.recharge != 0 && (maximum_power - nei.distance >= 0)) {
					next->power = maximum_power - nei.distance;
					next->recharge = cur.recharge - 1;
					next->now_dist = nei.distance;
					que.push(*next);
					true_table[nei.dest] = true;
				}
			}
		}

	}

	return std::all_of(true_table.begin(), true_table.end(), 
		[](bool x) { return x == true; });
}
