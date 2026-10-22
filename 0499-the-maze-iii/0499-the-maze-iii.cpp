class Solution {
public:
    vector<int> delrow = {1 , -1 , 0 , 0};
    vector<int> delcol = {0 , 0 , 1 , -1};
    string dir = "durl";
    bool check(vector<vector<int>>& maze , int row , int col , int dr , int dc , int n , int m) {
        if(row + dr < 0 || row + dr >= n || col + dc >= m || col + dc < 0  || maze[row + dr][col + dc] == 1) return false;
        return true;
    }
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {

        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>> dist(n , vector<int> (m , 1e9));
        vector<vector<string>> path(n , vector<string> (m , ""));
        using State = tuple<int , string , int , int>;

        priority_queue< State , vector<State> , greater<State>> pq;
        dist[ball[0]][ball[1]] = 0;
        pq.push({0 , "" , ball[0] , ball[1]});

        while(!pq.empty()) {
            auto [d , p , r , c] = pq.top();
            pq.pop();
            if(d != dist[r][c] || p != path[r][c]) continue;
            if(r  == hole[0] && c == hole[1]) return p;

            for(int i = 0 ; i < 4 ; i++) {


                int newR = r , newC = c;
                int steps = 0;
                while(check(maze , newR , newC , delrow[i] , delcol[i] , n , m)) {
                    newR += delrow[i];
                    newC += delcol[i];
                    steps++;
                    if(newR == hole[0] && newC == hole[1]) {
                        break;
                    }
                }

                if((dist[newR][newC] > dist[r][c] + steps) || ((dist[newR][newC] == dist[r][c] + steps) && ((p+dir[i]) < path[newR][newC]))) {
                    dist[newR][newC] = dist[r][c] + steps;
                    path[newR][newC] = p + dir[i];
                    pq.push({dist[newR][newC] , path[newR][newC] , newR , newC});
                }


            }

        }
        return "impossible";


        
    }
};

