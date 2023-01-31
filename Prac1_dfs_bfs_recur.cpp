#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    vector<vector<int>> adj;
    int n, m;

    void input(){
        cout << "Enter no of vertices: ";
        cin >> n;
        cout << "Enter no of edges: ";
        cin >> m;

        for(int i =0;i< n;i ++){
            vector<int> v;
            adj.push_back(v);
        }

        for(int i = 0; i < m; i++){
            cout << "Enter src and des: ";
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
    }
    
    void dfsHelper(int cur, vector<int>& vis){
        vis[cur] = 1;
        cout << cur << " ";
        for(auto next: adj[cur]){
            if(vis[next])continue;
            dfsHelper(next, vis);
        }
    }

    void dfs(){
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++){
            if(vis[i])continue;
            dfsHelper(i, vis);
        }
    }

    void bfsHelper(int cur, vector<int> &vis){
        queue<int> nodes;
        nodes.push(cur);
        vis[cur] = 1;
        while(!nodes.empty()){
            int front = nodes.front();
            nodes.pop();

            cout << front << " ";

            for(auto next: adj[front]){
                if(vis[next])continue;
                vis[next] = 1;
                nodes.push(next);
            }
        }
        
    }

    void bfs(){
        vector<int> vis(n, 0);
        for(int i = 0;i < n; i++){
            if(vis[i])continue;
            bfsHelper(i, vis);
        }
    }

    void print(){
        for(int i =0; i < n; i++){
            cout << i << ": ";
            for(auto j: adj[i]){
                cout << j << " ";
            }
            cout << "\n";
        }
    }

    void bfsRHelper(queue<int> nodes, vector<int>& vis){
        if(nodes.empty()) return;
        int front = nodes.front();
        cout << front << " ";
        vis[front] = 1;
        nodes.pop();
        for(auto next: adj[front]){
            if(vis[next])continue;
            vis[next] = 1;
            nodes.push(next);
        }
        bfsRHelper(nodes, vis);
    }

    void bfsR(){
        vector<int> vis(n ,0);
        queue<int> nodes;
        for(int i = 0; i < n; i++){
            if(vis[i])continue;
            nodes.push(i);
            bfsRHelper(nodes, vis);
        }
    }
};


int main(){
    Graph g;
    g.input();
    cout << "DFS: ";
    g.dfs();
    cout << "\nBFS: ";
    g.bfs();
    cout << "\nBFSREcur: ";
    g.bfsR();
    // cout << "\n print: ";
    // g.print();
    return 0;
}
