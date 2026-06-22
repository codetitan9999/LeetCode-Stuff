class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (parent[node] == node) {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) {
            return;
        }

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();

        DSU dsu(n);

        for (auto& pair : pairs) {
            dsu.unionBySize(pair[0], pair[1]);
        }

        unordered_map<int, vector<int>> components;

        for (int i = 0; i < n; i++) {
            int root = dsu.findParent(i);
            components[root].push_back(i);
        }

        for (auto& component : components) {
            vector<int> indices = component.second;
            vector<char> chars;

            for (int index : indices) {
                chars.push_back(s[index]);
            }

            sort(indices.begin(), indices.end());
            sort(chars.begin(), chars.end());

            for (int j = 0; j < indices.size(); j++) {
                s[indices[j]] = chars[j];
            }
        }

        return s;
    }
};