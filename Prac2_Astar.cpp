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

    void printPath(vector<int> &predecessor, int src, int des){
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
            cout << "Enter heuristic value for " << i << "th node: ";
            cin >> h[i];
        }
    }

    void pqcurtime(priority_queue<pair<int, int>, vector<pair<int, int>>,  greater<pair<int, int>>>& pq){
        priority_queue<pair<int, int>, vector<pair<int, int>>,  greater<pair<int, int>>> tmp = pq;
        while(!tmp.empty()){
            cout << tmp.top().first << " " << tmp.top().second << "\n";
            tmp.pop();
        }

    }

    void shortPathAstar(int src, int des){
        vector<int> f(n, 1e9);
        vector<int> h(n, 1e9);
        inputHeuristics(h, n);
        h[des] = 0;
        vector<int> predecessor(n,-1);
        predecessor[src] = src;
        priority_queue<pair<int, int>, vector<pair<int, int>>,  greater<pair<int, int>>> pq;
        f[src] = 0;
        pq.push({f[src], src});
        int done = 0;
        while(!pq.empty() || done == 0){
            cout << "\n\n";
            pair<int,int> front = pq.top();
            int curnode = front.second;
            int fval = front.first;
            pq.pop();
            if(curnode == des){
                printPath(predecessor, src, des);
                done = 1;
                return;
            }

            for(auto next: adj[curnode]){
                if(next.first == predecessor[curnode]) continue;
                if(f[next.first] > h[next.first] + next.second){
                    f[next.first] = h[next.first] + next.second;
                    pq.push({f[next.first], next.first});
                    predecessor[next.first] = curnode;
                }
            }
        }
    }



};

int main(){
    Graph g;
    g.input();
    g.shortPathAstar(0, 6);

    return 0;
}

/*
0 1 1
0 2 4
1 5 6
1 3 3
2 3 2
2 4 5
3 5 2
3 4 4
5 6 7
4 6 6
5 4 2
*/
