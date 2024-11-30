class Solution {
public:
    vector<int> parent;
    int component = 0;

    int find(int x) {
        if(parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }
    bool Union(int P, int C) {
        if(find(C) != C) return false;

        if(find(P) == C) return false;

        parent[C] = P;
        component -= 1;

        return true;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        component = n;
        parent.resize(n);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for(int i = 0; i < n; i++) {
            int node = i;
            int lc = leftChild[i];
            int rc = rightChild[i];

            if(lc != -1 && Union(node, lc) == false) return false;

            if(rc != -1 && Union(node, rc) == false) return false;
        }
        return component == 1;
    }
};