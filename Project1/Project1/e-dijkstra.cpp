#include "e-dijkstra.h"
#include <vector>
#include <fstream>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

struct Edge {
	int dest;
	int distance;

	bool operator<(const Edge& other) const {
		return distance < other.distance;
	}
};

struct Node {
	int now_dist = 0;
	int max_power = 0;

	vector<Edge> neighbor{};
};

struct State {
	int city_name;
	int power;
	int recharge;

	bool operator<(const State& other) const {
		if (recharge != other.recharge) return recharge < other.recharge; 
		return power < other.power;                                       
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
	void calc_lengths();
	pair<int, int> help_kstra(int source);
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
		//data[i].city_name = i;
		data[i].max_power = power;
	}

	int start, end, length;
	while (in >> start >> end >> length) {
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
	priority_queue<State> que;

	que.push({ source, maximum_power, maximum_recharge - 1 });

	while (!que.empty()) {
		State cur = que.top();
		que.pop();

		int u = cur.city_name;

		if (true_table[u]) { continue; }
		true_table[u] = true;

		for (const auto& nei : data[u].neighbor) {
			int v = nei.dest;
			int w = nei.distance;

			if (true_table[v]) { continue; }

			if (cur.power >= w) {
				que.push({ v, cur.power - w, cur.recharge });
			}
			else if (cur.recharge > 0 && maximum_power >= w) {
				que.push({ v, maximum_power - w, cur.recharge - 1 });
			}
		}
	}

	return std::all_of(true_table.begin(), true_table.end(),
		[](bool x) { return x; });
}




void vehiclestra::calc_lengths()
{
	int tmp_max = numeric_limits<int>::max();
	int tmp_min = 0;
	for (int i = 0; i < city_number; i++) {
		pair<int, int> test = help_kstra(i);
		if (tmp_max > test.first) {
			tmp_max = test.first;
		}
		if (tmp_min < test.second) {
			tmp_min = test.second;
		}
	}
	max_length = tmp_max;
	min_length = tmp_min - 1;
}

pair<int, int> vehiclestra::help_kstra(int source)
{
	vector<int> dist(city_number, numeric_limits<int>::max());
	vector<bool> eval(city_number, false);

	dist[source] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
	heap.push({dist[source], source});

	while (!heap.empty()) {
		pair<int, int> u = heap.top();
		heap.pop();

		if (eval[u.second]) { continue; }

		eval[u.second] = true;

		for (auto edge : data[u.second].neighbor) {
			if (eval[edge.dest]) { continue; }

			int alt = dist[u.second] + edge.distance;
			if (alt < dist[edge.dest]) {
				dist[edge.dest] = alt;
				heap.push({ dist[edge.dest], edge.dest });
			}
		}

	}
	std::nth_element(dist.begin(), dist.begin() + 1, dist.end());
	return { *max_element(dist.begin(), dist.end()), dist[1]};
}


int e_dijkstra_solver(char const* filename)
{
	vehiclestra go(filename);
	go.calc_lengths();

	while (go.max_length - go.min_length > 1) {
		go.reset();
		int trying = (go.min_length + go.max_length) / 2;
		go.set_power(trying);
		if (go.start()) {
			go.max_length = trying;
		}
		else {
			go.min_length = trying;
		}
	}


	return go.max_length;
}