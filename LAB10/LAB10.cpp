#include <iostream>

using namespace std;

template <class T>
class Ring
{
private:
    class Node
    {
    public:
        T value;
        Node* next;
        Node* prev;
        Node(T newVal) :value(newVal) { next = 0; prev = 0; }
        Node() { next = 0; prev = 0; value = 0; }
        ~Node() {}
        void print()
        {
            cout << value << " ";
        }
    };
public:
    class iterator
    {
    private:
        friend class Ring<T>;
        Node* node;
    public:
        iterator(Node* n) :node(n) {}
        iterator() :node(0) {}
        iterator(const iterator& iterator) :node(iterator.node) {}
        iterator& operator=(const iterator& it)
        {
            node = it.node;
            return *this;
        }
        bool operator==(const iterator& it) const
        {
            return (node == it.node);
        }
        bool operator!=(const iterator& it) const
        {
            return !(it == *this);
        }
        iterator& operator++()
        {
            if (node == 0)  throw "Error! Incrementation of empty iterator!\n";
            if (node->next == 0)    throw "Error!!! 'Next' is NULL!\n";
            node = node->next;
            return *this;
        }
        iterator& operator--()
        {
            if (node == 0)  throw "Error! Decrementation of empty iterator!\n";
            if (node->prev == 0)    throw "Error!!! 'Prev' is NULL!\n";
            node = node->prev;
            return *this;
        }
        T& operator*() const
        {
            if (node == 0)  throw "Error! Dereference of empty iterator!";
            return node->value;
        }
    };
private:
    Node* head;
    Node* tail;
    Ring& operator=(const Ring&);
    Ring(const Ring&);
    iterator headIterator;
    iterator tailIterator;
public:
    Ring()
    {
        head = tail = new Node;
        tail->next = 0;
        tail->prev = 0;
        headIterator = iterator(head);
        tailIterator = iterator(tail);
    }
    Ring(T newVal)
    {
        head = tail = new Node;
        tail->next = 0;
        tail->prev = 0;
        headIterator = iterator(head);
        tailIterator = iterator(tail);
        add(newVal);
    }
    ~Ring()
    {
        Node* delNode = head;
        for (Node* sn = head; sn != tail; sn = sn->next)
        {
            //delete delNode;
            delNode = sn;
        }
        delete delNode;
    }
    bool isEmpty() { return head == tail; }
    iterator front() { return headIterator; }
    iterator rear() { return tailIterator; }
    void add(T newVal)
    {
        Node* addNode = new Node(newVal);
        addNode->next = head;
        addNode->prev = tail;
        head->prev = addNode;
        tail->next = addNode;
        head = addNode;
        headIterator = iterator(head);
    }
    bool remove_it(iterator key)
    {
        for (Node* dn = head; dn != tail; dn = dn->next)
            if (dn == key.node)    
            {
                dn->prev->next = dn->next;
                dn->next->prev = dn->prev;
                delete dn;                           
                key.node = 0;
                return true;
            }
        return false;
    }
    iterator find(T val) const
    {
        for (Node* dn = head; dn != tail; dn = dn->next)
            if (dn->value == val) return iterator(dn);
        return tailIterator;
    }
    int size() const
    {
        int count = 0;
        for (Node* dn = head; dn != tail; dn = dn->next) ++count;
        return count;
    }
    void print() const
    {
        for (Node* dn = head; dn != tail; dn = dn->next)
            dn->print();
        cout << endl;
    }
};


typedef int tip;

Ring<tip> ring;

int main()
{
    int ret = 0;
    Ring<tip>::iterator ringIterator;
    for (int j = 0; j < 5; ++j)
        ring.add(j);
    ring.print();
    for (ringIterator = ring.front(); ringIterator != ring.rear(); ++ringIterator)
        cout << *ringIterator << " ";
    cout << endl;
    for (ringIterator = ring.rear(); ringIterator != ring.front(); )
    {
        --ringIterator; 
        cout << *ringIterator << " ";
    }
    cout << endl;
    ring.remove_it(ring.find(3));
    ring.print();
    return 0;
}


