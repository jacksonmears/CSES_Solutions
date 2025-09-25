#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* child[2];
    TrieNode() { child[0] = child[1] = nullptr; }
};

void insert(TrieNode* root, int num) {
    TrieNode* node = root;
    for (int i = 31; i >= 0; --i) {
        int bit = (num >> i) & 1;
        if (!node->child[bit]) node->child[bit] = new TrieNode();
        node = node->child[bit];
    }
}

// DFS to collect all numbers in trie
void dfs(TrieNode* node, int val, vector<int>& ans) {
    if (!node) return;
    if (!node->child[0] && !node->child[1]) {
        ans.push_back(val);
        return;
    }
    if (node->child[0]) dfs(node->child[0], val << 1, ans);
    if (node->child[1]) dfs(node->child[1], (val << 1) | 1, ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> prefix(n+1, 0);
    for (int i = 0; i < n; ++i) prefix[i+1] = prefix[i] ^ a[i];

    TrieNode* root = new TrieNode();
    insert(root, 0); // insert 0 prefix

    // Insert all prefix XORs into trie
    for (int i = 1; i <= n; ++i)
        insert(root, prefix[i]);

    // Collect all unique prefix XORs
    vector<int> unique_prefix_xors;
    dfs(root, 0, unique_prefix_xors);

    sort(unique_prefix_xors.begin(), unique_prefix_xors.end());

    cout << unique_prefix_xors.size() << "\n";
    for (auto x : unique_prefix_xors) cout << x << " ";
    cout << "\n";

    return 0;
}
