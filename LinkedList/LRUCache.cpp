/* Approach:

Make a doubly linked list, storing key and val. Also make a HashMap to point to the node in O(1) having the given 'key'
For insertion (put):
Check if a given node exists for given key. If it does then delete that node from it's current position and insert it at the head of the doubly linked list
If it doesn't, create a new node and add it to the head. Increase the counter of number of nodes by 1. If the total number of nodes exceed the given capacity, evict the node at tail

For querying (get):
Get the node pointing to the given key in the doubly linked list and delete the node from it's current position and insert it at the head of it.

*/

// Code:


class node
{
    public:
    node* prev;
    node* next;
    int key;
    int val;
    node(int x, int y)
    {
        key = x;
        val = y;
        prev = NULL;
        next = NULL;
    }
};
class LRUCache {
public:
    map<int, node*> look;
    node* head;
    node* tail;
    int curr;
    int cap;
    LRUCache(int capacity) {
        curr = 0;
        cap = capacity;
        head = NULL;
        tail = NULL;
        map<int, node*> empt;
        look = empt;
    }
    
    int get(int x) {
        if(look[x]!=NULL)
     {
         auto nd = look[x];
         if(nd->prev)
         {
             auto temp = nd->prev;
             auto ntemp = nd->next;
             temp->next = ntemp;
             if(ntemp) ntemp->prev = temp;
             nd->prev = NULL;
             nd->next = NULL;
             if(temp->next == NULL) tail = temp;
             if(head)
             {
                 nd->next = head;
                 head->prev = nd;
                 head = nd;
                 head->prev = NULL;
             }
         }
         return nd->val;
     }
     return -1;
    }
    
    void put(int x, int y) {
        if(look[x]!=NULL)
         {
             auto nd = look[x];
             if(nd->prev)
             {
                 auto temp = nd->prev;
                 auto ntemp = nd->next;
                 temp->next = ntemp;
                 if(ntemp) ntemp->prev = temp;
                 nd->prev = NULL;
                 nd->next = NULL;
                 if(temp->next == NULL) tail = temp;
                 if(head)
                 {
                     nd->next = head;
                     head->prev = nd;
                     head = nd;
                     head->prev = NULL;
                 }
             }
             nd->val = y;
             return;
         }
         node* nd = new node(x,y);
         look[x] = nd;
         if(head==NULL)
         {
             head = nd;
             tail = nd;
             ++curr;
             return;
         }
         nd->next = head;
         head->prev = nd;
         head = nd;
         head->prev = NULL;
         ++curr;
         if(curr > cap)
         {
             --curr;
             if(tail)
             {
                 auto temp = tail;
                 tail = tail->prev;
                 tail->next = NULL;
                 temp->prev = NULL;
                 look[temp->key] = NULL;
             }
         }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */