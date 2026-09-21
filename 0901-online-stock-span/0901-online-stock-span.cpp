class StockSpanner {
public:
    stack<pair<int,int>> st;
    int timer;
    StockSpanner() {
        st.push({INT_MAX, -1});
        timer = 0;
    }
    
    int next(int price) {
        while(st.top().first <= price) st.pop();
        int ans = timer - st.top().second ;
        st.push({price, timer});
        timer++;
        return ans;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */