class MyLinkedList {
private:
    struct Node{
        int val;
        Node* next;
        Node(int v) : val(v) , next(nullptr) {}
    };
    Node* head;
    int size;

public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= size){
            return -1;
        }
        Node* curr = head;
        for(int i = 0 ; i < index ; i++){
            curr = curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
         Node* n_head = new Node(val);
         n_head->next = head;
         head = n_head;
         size++;
    }
    
    void addAtTail(int val) {
        if (head == nullptr){
            addAtHead(val);
            return;
        }
        Node* curr = head;
        while (curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = new Node(val);
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size) {return;}
        if(index <=0){addAtHead(val); return;}
        if(index == size){addAtTail(val); return;}
        else{
            Node* prev = head;
            for(int i = 0 ; i < index - 1 ; i++){
                prev = prev->next;
            }
            Node* addn = new Node(val);
            addn->next = prev->next;
            prev->next = addn;
            size++;
        }
        
    }
    
    void deleteAtIndex(int index) {
        if(index >= size || index <0){return ;}
        if(index == 0 ){
            Node *toDel = head;
            head = head->next;
            delete toDel;
            size--;
        }
        else{
            Node* prev = head;
            for(int i = 0 ; i < index - 1 ; i++){
                prev = prev->next;
            }
            Node* toDel = prev->next;
            prev->next = toDel->next;
            delete toDel;
            size--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */