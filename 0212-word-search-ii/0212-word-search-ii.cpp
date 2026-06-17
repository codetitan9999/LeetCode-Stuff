struct Node {
    Node* child[26];
    bool isEnded;
    Node() {
        isEnded = false;
        for(int i = 0 ; i < 26 ; i++) {
            child[i] = NULL;
        }
    }
    bool containsKey(char ch) {
        return (child[ch-'a'] != NULL);
    }

    Node* getKey(char ch) {
        return child[ch-'a'];
    }

    void insertKey(char ch, Node* node) {
        child[ch-'a'] = node;
    }
    void setEnd() {
        this->isEnded = true;
    }
    bool isEnd() {
        return isEnded;
    }
    void unSetEnd() {
        this->isEnded = false;
    }
};

class Trie {
    public:

    Node* root;
    Trie() {
        root = new Node();
    }
    Node* getRoot() {
        return root;
    }
    void insertWord(string s) {
        Node* node = root;
        int n = s.length();
        for(int i = 0 ; i < n ; i++) {
            if(!node->containsKey(s[i])) {
                node->insertKey(s[i], new Node());
            }
            node = node->getKey(s[i]);
        }
        node->setEnd();
    }
};

class Solution {

public:
    vector<int> delrow = {-1 , 0 , 1 , 0};
    vector<int> delcol = {0 , 1  , 0 , -1};
    void dfs(int row , int col , vector<vector<char>> & boards , vector<vector<int>> & vis , Node* node, string & ans, vector<string> & res) {
        int n = boards.size();
        int m = boards[0].size();
        vis[row][col] = 1;
        ans.push_back(boards[row][col]);
        if(node->isEnd()) {
            res.push_back(ans);
            node->unSetEnd();
        }
        for(int i = 0 ; i < 4 ; i++) {
            int drow = row + delrow[i];
            int dcol = col + delcol[i];
            if(drow >=0 && dcol >=0 && drow < n && dcol < m && !vis[drow][dcol] && (node->containsKey(boards[drow][dcol]))) {
                dfs(drow , dcol , boards, vis , node->getKey(boards[drow][dcol]) , ans, res);
            }
        }
        vis[row][col] = 0;
        ans.pop_back();
    } 
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        int n = board.size();
        int m = board[0].size();
        Trie t;
        for(auto it : words) {
            t.insertWord(it);
        }
        Node * root = t.getRoot();

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                string x = "";
                if(root->containsKey(board[i][j])) {
                    vector<vector<int>> vis(n , vector<int> (m , 0));
                    Node* node = root;
                    dfs(i , j , board, vis , node->getKey(board[i][j]) , x , ans); 
                }
            }
        }
        return ans;
    }
};