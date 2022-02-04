class Solution {
public:
    Node* connect(Node* root) 
    {
        // if tree doesn't exist 
        if(!root)
            return NULL;
        
        // track head of tree
        Node *head = root;
        
        // to store level nodes and its children 
        queue<Node*> q;
        
        q.push(root);
        
        // loop runs untill queue gets empty
        while(!q.empty())
        {
            // to track previous node 
            Node *prev = NULL;
            int size = q.size();
            
            // loop for each level
            for(int i=0; i<size ;i++)
            {
                // take first node from the queue
                Node *curr = q.front();
                q.pop();
                
                // if it is first node of any level
                if(i==0)
                {
                    prev = curr;
                }
                // otherwise
                else
                {
                    prev->next = curr;
                    prev = curr;
                }
                
                // push its children if its exist
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            
            // last node points to NULL of each level
            prev->next = NULL;
              
        }
        
        // return head of a tree
        return head;
        
    }
};
