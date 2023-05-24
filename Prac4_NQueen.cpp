#include<bits/stdc++.h>
using namespace std;

bool issafe(vector<vector<char>> &mat, int i, int j, int n){
	for(int k = 0; k < j; k++){
		if(mat[i][k] == 'Q'){
			return 0;
		}
	}
	
	for(int k = 0; k < i; k++){
		if(mat[k][j] == 'Q'){
			return 0;
		}
	}
	
	int i1 = i-1, j1 = j-1;
	while(i1 >= 0 && j1 >= 0){
		if(mat[i1][j1] == 'Q'){
			return 0;
		}
		i1--;
		j1--;
	}
	
	i1 = i+1, j1 = j-1;
	while(i1 < n  && j1 >= 0){
		if(mat[i1][j1] == 'Q'){
			return 0;
		}
		i1++;
		j1--;
	}
	
	
	return 1;
	
}

bool solve(vector<vector<char>>&mat, int col, int n){
	if(col == n){
		return 1;
	}
	int placed = 0;
	for(int i = 0; i < n; i++){
		if(issafe(mat, i, col, n)){
			mat[i][col] = 'Q';
			if(!solve(mat, col+1, n)){
				mat[i][col] = '.';
			}
			else{
				placed = 1;
			}
		}
	}
	if(placed == 0){
		return 0;
	}
	return 1;
}

int main(){
	int n;
	// cout << "Enter n: ";
	cin >> n;
	
	vector<vector<char>> mat(n, vector<char>(n, '.'));
	
	bool isNQueenPoss = solve(mat, 0, n);
	if(isNQueenPoss){
		for(int i =0 ; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << mat[i][j] << " ";
			}
			cout << "\n";
		}
	}
	
	else{
		cout  << n << " Queens can't be placed on " << n <<"x"<<n << "chessboard" ;
	}
	
	
	
	return 0;
}
