/*Abhijeet_D_R*/

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
class Graph{
    vector<pair<int, int>> adj[N];
    int n, m;
    // vector<int> h;
    // vector<int> f;
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

    void printPath(vector<int> predecessor, int src, int des){
        vector<int> path;
        int cur = des;
        while(cur != predecessor[cur]){
            path.push_back(cur);
            cur = predecessor[cur];
        }
        path.push_back(cur);
        reverse(path.begin(), path.end());
        cout << "Path from src to des: ";
        for(auto i: path){
            cout << i << " ";
        }
        cout << "\n";
    }

    int shortPathDijkstra(int src, int des){
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
        printPath(predecessor, src, des);
        return d[des];
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
    void inputHeuristics(vector<int>& h, int n){
        for(int i = 0; i < n; i++){
            cin >> h[i];
        }
    }



    int shortPathAstar(int src, int des){
        vector<int> f(n, 1e9);
        vector<int> h(n, 1e9);
        inputHeuristics(h, n);
        vector<int> predecessor(n,-1);
        for(int i = 0; i < n; i++){
            cout << "Enter heuristic value for " << i << "th node: ";
            cin >> h[i];
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,  greater<pair<int, int>>> pq;
        f[src] = 0;
        pq.push({f[src], src});

        while(!pq.empty()){
            pair<int,int> front = pq.top();
            int curnode = front.second;
            int fval = front.first;
            cout << "curnode: " << curnode << "\n";
            cout << "fval: " << fval << "\n";
            *963.
            pq.pop();
            if(curnode == des){
                printPath(predecessor, src, des);
                return f[des];
                /*TODO
                return path and min dis
                */
            }
            for(auto next: adj[curnode]){
                if(f[next.first] > h[next.first] + next.second){
                    cout << "\tchanging val of " << next.first << "\n";
                    f[next.first] = h[next.first] + next.second;
                    pq.push({f[next.first], next.first});
                    predecessor[next.first] = curnode;
                }
            }
        }

        printPath(predecessor, src, des);
        return f[des];
    }



};

int main(){
    Graph g;
    g.input();
    // g.print();
    int dis = g.shortPathDijkstra(0, 6);
    cout <<"using dis: " << dis << "\n";
    dis = g.shortPathAstar(0, 6);
    cout <<"using dis: " << dis << "\n";

    

    return 0;
}
