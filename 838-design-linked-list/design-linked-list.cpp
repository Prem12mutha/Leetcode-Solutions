class MyLinkedList {
public:
    ListNode* head;
    ListNode* tail;
    int size;

    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int get(int index) {
        if(index < 0 || index >= size) return -1;
        ListNode* temp = head;
        for(int i = 0; i < index; i++) temp = temp->next;
        return temp->val;
    }

    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
        if(size == 0) tail = newNode;
        size++;
    }

    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        if(size == 0) head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void addAtIndex(int index, int val) {
        if(index < 0 || index > size) return;
        if(index == 0) { addAtHead(val); return; }
        if(index == size) { addAtTail(val); return; }
        ListNode* temp = head;
        for(int i = 0; i < index - 1; i++) temp = temp->next;
        ListNode* newNode = new ListNode(val);
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }

    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) return;
        if(index == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            if(size == 1) tail = nullptr;
        } else {
            ListNode* temp = head;
            for(int i = 0; i < index - 1; i++) temp = temp->next;
            ListNode* delNode = temp->next;
            temp->next = delNode->next;
            if(index == size - 1) tail = temp;
            delete delNode;
        }
        size--;
    }
};
