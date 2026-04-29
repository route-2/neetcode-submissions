class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};



class LRUCache {
private:
int cap;
unordered_map<int,Node*> cache;
Node* left;
Node * right;
public:

   void remove(Node * node){
   node->prev->next = node->next;
   node->next->prev = node->prev;
   }
   void insert(Node * node){
       
         right -> prev->next = node;
         node -> prev = right -> prev;
         node -> next = right;
         right -> prev = node;
   }


    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node(0,0);
        right = new Node(0,0);

        left->next = right;
        right->prev = left;
        
    }
    
    int get(int key) {

        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;

        }
        return -1;

        
    }
    
    void put(int key, int value) {
        if (cache.find(key)!= cache.end()){
            remove(cache[key]);
        }
        
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

         if (cache.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
         }

        
    }
};
