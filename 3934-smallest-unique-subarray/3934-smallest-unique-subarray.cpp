class Solution {
public:
    struct State {
        int len = 0, link = -1, occ = 0;
        unordered_map<int, int> next;
    };

    vector<State> st;
    int last;

    void extend(int x) {
        int cur = st.size();
        st.push_back({});
        st[cur].len = st[last].len + 1;
        st[cur].occ = 1;

        int p = last;
        while (p != -1 && !st[p].next.count(x)) {
            st[p].next[x] = cur;
            p = st[p].link;
        }

        if (p == -1) {
            st[cur].link = 0;
        } else {
            int q = st[p].next[x];

            if (st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            } else {
                int clone = st.size();
                st.push_back(st[q]);
                st[clone].len = st[p].len + 1;
                st[clone].occ = 0;

                while (p != -1 && st[p].next[x] == q) {
                    st[p].next[x] = clone;
                    p = st[p].link;
                }

                st[q].link = st[cur].link = clone;
            }
        }

        last = cur;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        st.reserve(2 * nums.size());
        st.push_back({});
        last = 0;

        for (int x : nums) {
            extend(x);
        }

        vector<int> order(st.size());
        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(), [&](int a, int b) {
            return st[a].len > st[b].len;
        });

        for (int v : order) {
            if (st[v].link != -1) {
                st[st[v].link].occ += st[v].occ;
            }
        }

        int ans = nums.size();

        for (int i = 1; i < st.size(); i++) {
            if (st[i].occ == 1) {
                int smallestLenInState = st[st[i].link].len + 1;
                ans = min(ans, smallestLenInState);
            }
        }

        return ans;
    }
};