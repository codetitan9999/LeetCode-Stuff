class Solution {
public:
    vector<int> delrow = {1 , -1 , 0 , 0};
    vector<int> delcol = {0 , 0 , 1 , -1};
    bool check(vector<vector<int>>& maze , int row , int col , int dr , int dc , int n , int m) {
        if(row + dr < 0 || row + dr >= n || col + dc >= m || col + dc < 0  || maze[row + dr][col + dc] == 1) return false;
        return true;
    }
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>> dist(n , vector<int> (m , 1e9));
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;


        dist[start[0]][start[1]] = 0;
        pq.push({0  , start[0] , start[1]});


        while(!pq.empty()) {
            int d = pq.top()[0];
            int row = pq.top()[1];
            int col = pq.top()[2];
            pq.pop();
            if(row == destination[0] && col == destination[1]) return dist[row][col];
            if(dist[row][col] != d) continue;
            for(int i = 0 ; i < 4 ; i++) {
                int newRow = row;
                int newCol = col;
                int steps = 0;
                while(check(maze , newRow, newCol , delrow[i] , delcol[i] , n , m)) {
                    newRow = newRow + delrow[i];
                    newCol = newCol + delcol[i];
                    steps++;
                }
                if(dist[newRow][newCol] > d+steps) {
                    dist[newRow][newCol] = d+steps;
                    pq.push({d+steps , newRow , newCol});
                }
            }
        }
        return -1;
    }
};