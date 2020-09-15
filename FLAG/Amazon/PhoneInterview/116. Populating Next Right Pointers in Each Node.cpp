// 116. Populating Next Right Pointers in Each Node

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int q_size = q.size();
            Node* prev = nullptr;
            for(int i = 0; i < q_size; i++)
            {
                Node* cur = q.front(); q.pop();
                if(prev) prev->next = cur;
                // cout << cur->val << endl;
                prev = cur;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        return root;
    }
};


class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        Node* ptr = root;
        Node* post = nullptr;
        Node* start = root->left;
        Node* head = root;
        while(ptr->left && ptr->right)
        {
            // cout << ptr->val << endl;
            if(!post){
                post = start;
                start = post->left;
                head = post;
                post->next = ptr->right;
                post = ptr->right;
            }
            else if(post != ptr->left)
            {
                post->next = ptr->left;
                post = ptr->left;
            }
            else
            {
                post->next = ptr->right;
                post = ptr->right;
            }
            
            if(post == ptr->right)
            {
                if(ptr->next)
                {
                    ptr = ptr->next;
                }
                else {
                    ptr = head;
                    post = nullptr;
                }
            }
        }
        return root;
    }
};