/* Abhijeet_D_R */

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+1;

class Graph{
    vector<pair<int, int>> adj[N];
    int n, m;
    public:
    Graph(){
        n = 0;m=0;
    }

    void input(){
        cout << "enter n: ";
        cin >> n;
        cout<<"enter no of edges: ";
        cin >>m;
        for(int i =0;i<m;i++){
            int x, y,w;
            cin>>x>>y>>w;
            adj[x].push_back({y,w});
            adj[y].push_back({x,w});
        }
    }

    void printMST(vector<pair<int, int>> MST[]){
        for(int i = 0;i < n; i++){
            for(auto next: MST[i]){
                cout << next.first << " " << next.second << "\n";
            }
        }
    }

    void PrimsMST(int src){
        vector<pair<int,int>> MST[n];
        vector<int> vis(n);
        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int,int>, int>>, greater<pair<pair<int, int>,int>>> q;
        for(auto next: adj[src]){
            q.push({{next.second, next.first}, src}); //wt  to_go  came_from
        }
        vis[src] = 1;
        while(!q.empty()){
            int wt = q.top().first.first;
            int toGo = q.top().first.second;
            int cameFrom = q.top().second;

            q.pop();

            if(!vis[toGo]){
                MST[toGo].push_back({cameFrom, wt});
                MST[cameFrom].push_back({toGo, wt});
                for(auto next: adj[toGo]){
                    if(!vis[next.first]){
                        q.push({{next.second, next.first}, src});
                    }
                }
            }
        }

        printMST(MST);

    }

};


int main(){
    Graph g;
    g.input();
    g.PrimsMST(0);

    return 0;
}
