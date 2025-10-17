#include "tsp.h"
#include <fstream>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    float promising;
    int index;
    int cost;

    bool operator<(const Node& other) const {
        return promising > other.promising;
    }
};

static float Bound(MAP map, std::vector<int> route, int total_city, int target) {
    int previous_city = route.back();
    float bowl = 0;

    route.push_back(target);
    for (int i = 0; i < total_city; i++) {
        if (find(route.begin(), route.end(), i) == route.end()) {
            std::vector<int> tmp = map[i];
            std::sort(tmp.begin(), tmp.end());
            bowl += tmp[0] + tmp[1];
        }
        else {
            if (i == route.front()) {
                std::vector<int> tmp = map[i];
                std::sort(tmp.begin(), tmp.end());
                if (tmp[0] == map[i][route[1]]) {
                    bowl += tmp[1];
                }
                else {
                    bowl += tmp[0];
                }
            }
            else if (i == route.back()) {
                std::vector<int> tmp = map[i];
                std::sort(tmp.begin(), tmp.end());
                if (tmp[0] == map[*(route.end() - 2)][i]) {
                    bowl += tmp[1];
                }
                else {
                    bowl += tmp[0];
                }
            }
        }
    }



    return bowl / 2;

}

static void backtracking(MAP map, std::vector<int>& route, std::vector<int>& best_route, int total_city, int index, int cost, int& best_cost) {
    if (index == total_city) {
        int final_cost = cost + map[route.back()][0];
        if (final_cost < best_cost) {
            best_cost = final_cost;
            best_route = route;
        }
        route.pop_back();
        return;
    }

    priority_queue<Node> que;


    for (int i = 0; i < total_city; i++) {
        if (find(route.begin(), route.end(), i) == route.end()) {
            int this_cost = map[route.back()][i];
            float lower_bound = Bound(map, route, total_city, i) + this_cost + cost;
            Node next;
            next.cost = this_cost;
            next.promising = lower_bound;
            next.index = i;
            que.push(next);
        }
    }

    int size = que.size();
    for (int i = 0; i < size; i++) {
        Node next = que.top();
        que.pop();
        if (next.promising < best_cost) {
            route.push_back(next.index);
            backtracking(map, route, best_route, total_city, index + 1, cost + next.cost, best_cost);
        }
    }
    route.pop_back();


}

std::vector<int> SolveTSP(char const* filename) {
    std::vector<int> result;
    int TotalCity = 0;
    MAP map;
    std::ifstream in(filename, std::ifstream::in);
    if (!in.is_open()) {
        return {};
    }
    in >> TotalCity;
    for (int i = 0; i < TotalCity; ++i) {
        std::vector<int> row;
        for (int j = 0; j < TotalCity; ++j) {
            row.push_back(std::numeric_limits<int>::max());
        }
        map.push_back(row);
    }
    for (int i = 0; i < TotalCity; ++i) {
        for (int j = i + 1; j < TotalCity; ++j) {
            if (!in.good()) {
                return {};
            }
            in >> map[i][j];
            map[j][i] = map[i][j];
        }
    }
    std::vector<int> tmp{0};
    int best = std::numeric_limits<int>::max();
    backtracking(map, tmp, result, TotalCity, 1, 0, best);

    result.push_back(0);
    return result;
}

