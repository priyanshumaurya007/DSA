class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        if( head == NULL )
            return NULL;
        
        Node *ptr = head;
        Node *qtr = NULL;
        
        // inserting copy of node 
        
        while( ptr )
        {
            qtr = ptr->next;
            Node *newNode = new Node(ptr->val);
            newNode->next = qtr;
            ptr->next = newNode;
            ptr = qtr;
        }
        
        ptr = head;
        qtr = NULL;
        
        // connecting random pointers of new 
        
        while( ptr && ptr->next )
        {
            qtr = ptr->next;
            if( ptr->random)
            {
                qtr->random = ptr->random->next;
            }
            else
            {
                qtr->random = NULL;
            }
            
            ptr = qtr->next;
        }
        
        // segreate the two list we have made 
        
        ptr = head;
        Node *newhead = ptr->next;
        qtr = ptr->next;
        
        while( ptr && ptr->next)
        {
            qtr = ptr->next;
            ptr->next = qtr->next;
            ptr = qtr;
            
        }
        
        // returning head of second list 
        
        return newhead;
    }
};
