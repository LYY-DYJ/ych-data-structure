struct Node
{
    int value;
    Node *next;
};
Node *make_node(int value)
{
    Node *ptr;
    ptr = new Node;
    ptr->value = value;
    ptr->next = nullptr;
    return ptr;
}

class List
{
private:
    Node *head;
    Node *tail;
    int length;
    Node *rcr_get(Node *head, int pos);
    bool rcr_remove(Node *&head, int value);

public:
    List();                          // 构建函数
    ~List();                         // 析构函数
    bool is_empty();                 // 判断是否为空，为空返回1
    int get_length();                // 返回链表长度，为空返回0
    void append(int value);          // 在链表末尾添加元素
    bool insert(int pos, int value); // 在链表中pos位置插入元素，如果插入位置不在链表范围中，返回0
    bool remove_pos(int pos);        // 在链表中pos位置删除元素,如果删除位置不在链表范围中或链表为空，返回0
    Node *itr_get_pos(int pos);      // 迭代方式返回位置为pos的节点指针
    Node *rcr_get_pos(int pos);      // 递归方式返回位置为pos的节点指针
    bool itr_remove_value(int key);      // 删除值为key的节点
    bool rcr_remove_value(int key);      // 删除值为key的节点
};
#ifndef LIST_H
#define LIST_H
List::List()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
};

List::~List()
{
    Node *curr;
    Node *next;
    curr = head;
    while (curr != nullptr)
    {
        next = curr->next;
        delete curr;
        curr = next;
    }
}

bool List::is_empty()
{
    if (head)
        return 0;
    else
        return 1;
}

int List::get_length()
{
    return length;
}

void List::append(int value)
{
    Node *ptr;
    ptr = make_node(value);
    if (is_empty())
    {
        head = ptr;
        tail = ptr;
    }
    else
    {
        tail->next = ptr;
        tail = ptr;
    }
    length++;
}

bool List::insert(int pos, int value)
{
    Node *ptr;
    Node *prev;
    int n;
    if (pos < 0 || pos > length - 1)
    {
        return 0;
    }
    else if (pos == 0)
    {
        ptr = make_node(value);
        ptr->next = head;
        head = ptr;
        length++;
        return 1;
    }
    else
    {
        ptr = make_node(value);
        prev = head;
        n = 1;
        while (n != pos && prev->next != nullptr)
        {
            n++;
            prev = prev->next;
        }
        ptr->next = prev->next;
        prev->next = ptr;
        length++;
        return 1;
    }
}

Node *List::itr_get_pos(int pos)
{
    Node *curr;
    int n;
    curr = head;
    n = 0;
    while (n != pos && curr != nullptr)
    {
        curr = curr->next;
        n++;
    }
    return curr;
}

Node *List::rcr_get_pos(int pos)
{
    return rcr_get(head, pos);
}

Node *List::rcr_get(Node *head, int pos)
{
    if (pos == 0 || head == nullptr)
        return head;
    else
        return rcr_get(head->next, pos - 1);
}

bool List::itr_remove_value(int key)
{
    Node *prev;
    Node *temp;
    bool done;
    if(length==0)
        done=0;
    else if (head->value == key)
    {
        temp = head;
        head = head->next;
        delete temp;
        length--;
        done=1;
    }
    else
    {
        prev = head;
        while (prev->next != nullptr && prev->next->value != key)
        {
            prev = prev->next;
        }
        if (prev->next == nullptr)
        {
            done=0;
        }
        else if (prev->next == tail)
        {
            temp = tail;
            prev->next = nullptr;
            delete temp;
            tail = prev;
            length--;
            done=1;
        }
        else
        {
            temp = prev->next;
            prev->next = prev->next->next;
            delete temp;
            length--;
            done=1;
        }
    }
    if(length==0)
    {
        head=nullptr;
        tail=nullptr;
    }
    return done;
}

bool List::rcr_remove_value(int key)
{
    bool done;
    if(length==0)
        return 0;
    done=rcr_remove(head,key);
    if(length==0)
    {
        head=nullptr;
        tail=nullptr;
    }
    return done;
}

bool List::rcr_remove(Node* &head, int key)
{
    bool done;
    if(head==nullptr)
    {
        done=0;
    }
    else if(head->value==key)
    {
        if(head==tail)
        {
            tail=nullptr;
        }
        head=head->next;
        length--;
        done=1;
    }
    else 
    {
        done=rcr_remove(head->next,key);
        if(tail==nullptr)
        {
            tail=head;
        }
    }
    return done;
}

#endif
