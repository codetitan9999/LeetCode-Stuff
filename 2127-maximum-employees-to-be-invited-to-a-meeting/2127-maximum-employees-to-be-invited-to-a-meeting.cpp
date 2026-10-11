class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        /*
            definitely there will be a cycle , because the conditions are in that way 

            there can be two types of cycles
            1) cycleLength >=3
            2) cycle length == 2


            -> For cycle length greater than 3 , a->b->c ->a , now each of the two slots of each node are filled, so here there is no option to add any new node to cycle, so maxCycle length will be the answer

            ->For CycleLength ==2 , a->b->a , we can place them this way    a, b , now we can attach as many series of nodes to a and b , so we take depths of both nodes


        */



        int n = favorite.size();
        vector<int> indegree(n , 0);

        for(int i = 0 ; i < n ; i++) {
            indegree[favorite[i]]++;
        }

        queue<int> q;

        for(int i = 0 ; i < n ; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> depth(n , 1);


        while(!q.empty()) {
            int u = q.front();
            q.pop();
            int v = favorite[u];
            depth[v] = max(depth[v] , depth[u] + 1);
            indegree[v]--;
            if(indegree[v] == 0) q.push(v);
        }

        int cycleLengths = 0;
        int twoCycleLengths = 0;

        vector<int> visited(n , 0);

        for(int i = 0 ; i < n ; i++) {
            if(visited[i] || indegree[i] == 0) continue;

            int u = i ;
            int cnt = 0;
            while(!visited[u]) {
                visited[u] = 1; 
                u = favorite[u];
                cnt++;
            }

            if(cnt == 2) {
                twoCycleLengths += (depth[i] + depth[favorite[i]]);
            } else {
                cycleLengths = max(cycleLengths , cnt);
            }


        }
        return max(cycleLengths , twoCycleLengths);


        
    }
};