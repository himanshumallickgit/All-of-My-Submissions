#include <bits/stdc++.h>
using namespace std;
pair<int, int> findCenter(int n, int m, const vector<vector<char>>& grid) {
	vector<int> x;
	vector<int> y;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j] == '#'){
				x.push_back(i);
				y.push_back(j);
			}
		}
	}	
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	int minix = x[0];
	int miniy = y[0];
	int maxix = x[x.size() - 1];
	int maxiy = y[y.size() - 1];
	int p1 = minix + (maxix - minix)/2;
	int p2 = miniy + (maxiy - miniy)/2;
	return {p1, p2};
}

void rec(){
		int n, m;
    	cin >> n >> m;
    	vector<vector<char>> grid(n, vector<char>(m));
    	for (int i = 0; i < n; i++) {
        	for (int j = 0; j < m; j++) {
            	cin >> grid[i][j];
        	}
    	}
    pair<int, int> c = findCenter(n, m, grid);
    cout << c.first + 1 << " " << c.second + 1 << endl;
}
int main() {
	int t;
	cin >> t;
	while(t--){
		rec();
	}
    return 0;
}
