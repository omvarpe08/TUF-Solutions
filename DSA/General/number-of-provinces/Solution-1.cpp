class Solution {
public:
    void bfs(int node, vector<vector<int>>& adj, vector<int>& vis, int V) {
        queue<int> q;
        q.push(node);
        vis[node] = 1;

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            for(int j = 0; j < V; j++) {
                if(adj[curr][j] == 1 && !vis[j]) {
                    vis[j] = 1;
                    q.push(j);
                }
            }
        }
    }

    int numProvinces(vector<vector<int>> adj) {
        int V = adj.size();

        vector<int> vis(V, 0);
        int count = 0;

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                count++;
                bfs(i, adj, vis, V);
            }
        }

        return count;
    }
};

//TC = O(N + N^2) = o(N^2)  ...for loop + we call bfs multiple time through for loop but in total by while & for loop of bfs we take O(N^2) of TC.
//SC = O(N) + O(N) = O(2N) = O(N)  ..vis + queue

//one more wayy in tab-2