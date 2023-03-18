class BrowserHistory {
public:
    struct Node
    {
        Node* next;
        Node* prev;
        string data;
        Node(string s)
        {
            data=s;
            next=NULL;
            prev=NULL;
        }
    };
    Node* reff;
    Node* temp;
    BrowserHistory(string homepage) {
        reff=new Node(homepage);
        temp=reff;
    }
    
    void visit(string url) {
        Node* v=new Node(url);
        v->prev=temp;
        temp->next=v;
        temp=temp->next;
    }
    
    string back(int steps) {
        while(steps--&&temp->prev)
        {
            temp=temp->prev;
        }
        return temp->data;
    }
    
    string forward(int steps) {
        while(steps--&&temp->next)
        {
            temp=temp->next;
        }
        return temp->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */