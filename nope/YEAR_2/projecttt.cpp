#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct Edge {
    char node;
    int type; // 0: normal, 1: black, 2: red
};

int minPathToTarget(const unordered_map<char, vector<Edge>>& graph, char start, char target) {
    unordered_set<char> visited;
    queue<pair<char, int>> q; // Node, distance
    q.push({start, 0});

    while (!q.empty()) {
        char currNode = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (currNode == target) {
            return dist;
        }

        if (visited.find(currNode) != visited.end()) {
            continue;
        }

        visited.insert(currNode);

        for (const auto& edge : graph.at(currNode)) {
            int nextDist = dist;
            if (edge.type != 0) {
                nextDist++;
            }
            q.push({edge.node, nextDist});
        }
    }

    // Target node not reachable
    return -1;
}

int main() {
    int n,m,s,t ; 
    cin >> n >> m >> s >>t ; 
    unordered_map<int, vector<Edge>> graph ;

    for(int i = 0 ; i <m ; i++){
        int x,y,z;  
        cin >> x >>y >> z  ;
        graph[x].push_back({y,z}) ;
        graph[y].push_back({x,z}) ; 
    }

    char startNode = 'A';
    char targetNode = 'F';

    int minPath = minPathToTarget(graph, startNode, targetNode);
    if (minPath != -1) {
        cout << "Minimum path from " << startNode << " to " << targetNode << " : " << minPath << endl;
    } else {
        cout << "Target node not reachable from the start node." << endl;
    }

    return 0;
}
