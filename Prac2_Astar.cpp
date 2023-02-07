#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
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

    pair<int, vector<int>> shortPathDijktra(int src, int des){
        vector<int> predecessor(n+3, 1e9);
        vector<int> d(n+3, 1e9);
        d[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minDis;
        minDis.push({d[src], src});
        predecessor[src] = src;
        while(!minDis.empty()){
            pair<int, int> dis_node = minDis.top();
            minDis.pop();
            int dis =dis_node.first;
            int curnode = dis_node.second;
            for(auto next: adj[curnode]){
                if(dis+next.second < d[next.first]){
                    d[next.first] = dis+next.second;
                    minDis.push({d[next.first], next.first});
                    predecessor[next.first] = curnode;
                }
            }
        }
        vector<int> path;
        int cur = des;
        while(cur != predecessor[cur]){
            path.push_back(cur);
            cur = predecessor[cur];
        }
        path.push_back(cur);
        reverse(path.begin(), path.end());
        return {d[des], path};
    }

    void print(){
        for(int i = 0; i < n+1; i++){
            cout << i << ": ";
            for(auto j: adj[i]){
                cout << "(" << j.first << " " << j.second << "), ";
            }
            cout << "\n";
        }
    }

};

int main(){
    Graph g;
    g.input();
    // g.print();
    pair<int,vector<int>> path = g.shortPathDijktra(0, 7);
    cout << "Shortest Path from 0, 7: ";
    for(auto i : path.second){
        cout << i << " ";
    }
    cout << "\nShortest distance from 0, 7: " << path.first << "\n";

    

    return 0;
}
