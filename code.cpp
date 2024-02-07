class Solution {
    void DFS(unordered_map<int, vector<int>>& adj, int curr, vector<bool>& visited) {
        visited[curr] = true; 
        for(auto i: adj[curr]) {
            if(visited[i] == false) {
                DFS(adj,i,visited);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<bool> visited(n,false);
        unordered_map<int,vector<int>> adj;

        //STEP1: Make adjacency list
        int edges = 0;
        for(int i = 0; i < connections.size(); ++i) {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
            edges++;
        }

        //STEP2: Find number of components
        int components = 0;
        for(int i = 0; i < n; ++i) {
            if(visited[i] == false) {
                components++;
                DFS(adj,i,visited);
            }
        }

        //STEP3: Count number of edges
        if(edges < n-1) {
            return -1; 
        }
        int redundant = edges - ((n-1) - (components-1));
        if(redundant >= (components-1)){
            return (components-1);
        }
        return -1;
    }
};
