class Solution {
public:
    void bfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        queue<int> q;
        q.push(node);
        vis[node] = 1;

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            for(auto it : adj[curr]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }

    int numProvinces(vector<vector<int>> adj) {
        int V = adj.size();

        // Convert matrix to adjacency list
        vector<vector<int>> adjList(V);

        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(adj[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                }
            }
        }

        vector<int> vis(V, 0);
        int count = 0;

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                count++;
                bfs(i, adjList, vis);
            }
        }

        return count;
    }
};

//TC = O(N) + O(N + 2E) ...for loop + we call bfs multiple time through for loop but in total by while & for loop of bfs we travel all vertices & all neighbour of each vertices.
//SC = O(N) + O(N) = O(2N) = O(N)  ..vis + queue