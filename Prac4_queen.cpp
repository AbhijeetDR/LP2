#include<bits/stdc++.h>
using namespace std;

bool ok(vector<vector<int>> & v, int n, int i , int j){
    //hor
    int yes = 1;
    for(int jj = 0; jj < n; jj++){
        if(v[i][jj] ==1 && jj != j){
            return false;
        }
    }

    //ver
    for(int ii = 0; ii < n; ii++){
        if(v[ii][j] == 1 && ii != i){
            return false;
        }
    }

    //left-top diagonal
    int ii = i-1, jj = j-1;
    while(ii >= 0 && jj >= 0){
        if(v[ii][jj] == 1) return false;
        ii--;
        jj--;
    }

    //right top diagonal
    ii = i-1, jj = j+1;
    while(ii >= 0 && jj < n){
        if(v[ii][jj] == 1) return false;
        ii--;
        jj++;
    }

    //left-bottom diagonal
    ii = i+1, jj=j-1;
    while(ii < n && jj >= 0){
        if(v[ii][jj]==1) return false;
        ii++;
        jj--;
    }

    ii = i+1, jj = j+1;
    while(ii < n && jj < n){
        if(v[ii][jj] == 1) return false;
    }
    return true;

}

void printBoard(vector<vector<int>> & v, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n ;j ++){
            cout << v[i][j];
        }
        std::cout << "\n" << std::endl;
    }
}

int main(){
    int n;cin >> n;
    vector<vector<int>> v(n, vector<int>(n,0));
    int cnt = 0;
    stack<pair<int,int>> queenPlaced;
    
    
    queenPlaced.push({0,0});
    v[0][0] = 1;
    cnt++;

    while(cnt < n){
        pair<int,int> queenCoord = queenPlaced.top();
        int lastx = queenCoord.first;
        int lasty = queenCoord.second;
        cout << "last queen placed at: " << lastx << " " << lasty << "\n";
        int done = 0;

        for(int i = lastx+1; i < n; i++){
            for(int j = 0; j < n; j++){
                if(ok(v,n,i,j)){
                    v[i][j] = 1;
                    queenPlaced.push({i,j});
                    done = 1;
                    cnt++;
                    break;
                }
            }
            if(done){
                break;
            }
        }
        if(!done){
            if(queenPlaced.size()){
                pair<int, int> lastQueen = queenPlaced.top();
                queenPlaced.pop();
                cnt--;
                int x = lastQueen.first;
                int y = lastQueen.second;
                v[x][y] = 0;
            }
            else{
                cout << "NO queen can be Placed!!";
                break;
            }
        }
    }

    printBoard(v, n);

    

    return 0;
}
