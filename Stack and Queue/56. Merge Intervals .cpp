class Node
{
    public :
                int val;
                int min;
                Node *next;
    
                Node( int val, int min, Node *next)
                {
                    this->val = val;
                    this->min = min;
                    this->next = next;
                }
};

class MinStack {
public:
    
    Node *head;
    
    MinStack() 
    {
        head = NULL;
        
    }
    
    void push(int val) 
    {
        if(!head)
        {
            head = new Node( val ,val , NULL);
        }
        else
        {
            head = new Node( val , min(head->min , val), head);
        }
        
    }
    
    void pop() 
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        
    }
    
    int top() 
    {
        return head->val;
        
    }
    
    int getMin() 
    {
        return head->min;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
