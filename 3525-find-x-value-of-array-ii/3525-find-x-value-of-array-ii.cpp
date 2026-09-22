#include <vector>
using namespace std;

class Solution {
    struct Node {
        int remain[6] = {0};
        int prod = 1;
    };

    int K;
    vector<Node> tree;

    Node merge(const Node& left, const Node& right) {
        Node parent;
        parent.prod = (left.prod * right.prod) % K;

        for (int i = 0; i < K; ++i) {
            parent.remain[i] += left.remain[i];
        }
        for (int j = 0; j < K; ++j) {
            int new_rem = (left.prod * j) % K;
            parent.remain[new_rem] += right.remain[j];
        }

        return parent;
    }

    void build(const vector<int>& arr, int pos, int lo, int hi) {
        if (lo == hi) {
            int v = arr[lo] % K;
            tree[pos].prod = v;
            tree[pos].remain[v] = 1;
            return;
        }
        int mid = lo + (hi - lo) / 2;
        build(arr, 2 * pos, lo, mid);
        build(arr, 2 * pos + 1, mid + 1, hi);
        tree[pos] = merge(tree[2 * pos], tree[2 * pos + 1]);
    }

    void modify(int pos, int lo, int hi, int target, int newVal) {
        if (lo == hi) {
            for (int i = 0; i < K; ++i) tree[pos].remain[i] = 0;
            int v = newVal % K;
            tree[pos].prod = v;
            tree[pos].remain[v] = 1;
            return;
        }
        int mid = lo + (hi - lo) / 2;
        if (target <= mid) modify(2 * pos, lo, mid, target, newVal);
        else modify(2 * pos + 1, mid + 1, hi, target, newVal);
        tree[pos] = merge(tree[2 * pos], tree[2 * pos + 1]);
    }

    Node ask(int pos, int lo, int hi, int from, int to) {
        if (from <= lo && hi <= to) return tree[pos];
        int mid = lo + (hi - lo) / 2;
        if (to <= mid) return ask(2 * pos, lo, mid, from, to);
        if (from > mid) return ask(2 * pos + 1, mid + 1, hi, from, to);
        Node leftPart = ask(2 * pos, lo, mid, from, to);
        Node rightPart = ask(2 * pos + 1, mid + 1, hi, from, to);
        return merge(leftPart, rightPart);
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int sz = nums.size();
        K = k;
        tree.resize(4 * sz);

        build(nums, 1, 0, sz - 1);

        vector<int> out;
        out.reserve(queries.size());

        for (const auto& q : queries) {
            int index = q[0];
            int newVal = q[1];
            int from = q[2];
            int target = q[3];

            modify(1, 0, sz - 1, index, newVal);

            if (from >= sz) {
                out.push_back(0);
            } else {
                Node r = ask(1, 0, sz - 1, from, sz - 1);
                out.push_back(r.remain[target]);
            }
        }

        return out;
    }
};