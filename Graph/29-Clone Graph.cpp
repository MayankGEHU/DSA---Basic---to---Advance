class Solution {
public:
    unordered_map<Node*, Node*> mp;

    void dfs(Node* node, Node* clone_Node) {
        for (Node* n : node->neighbors) {
            if (mp.find(n) == mp.end()) { 
                Node* clone = new Node(n->val);
                mp[n] = clone;
                clone_Node->neighbors.push_back(clone);
                dfs(n, clone);
            } else { 
                clone_Node->neighbors.push_back(mp[n]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }

        Node* clone_Node = new Node(node->val);
        mp[node] = clone_Node;
        dfs(node, clone_Node);
        return clone_Node;
    }
};