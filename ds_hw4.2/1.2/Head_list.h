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

class Head_list
{
private:
    Node *head;
    Node *tail;
    int length;
    Node *rcr_get(Node *head, int pos);

public:
    Head_list();                     // 构建函数
    ~Head_list();                    // 析构函数
    bool is_empty();                 // 判断是否为空，为空返回1
    int get_length();                // 返回链表长度，为空返回0
    void append(int value);          // 在链表末尾添加元素
    bool insert(int pos, int value); // 在链表中pos位置插入元素，如果插入位置不在链表范围中，返回0
    bool remove_pos(int pos);        // 在链表中pos位置删除元素,如果删除位置不在链表范围中或链表为空，返回0
    Node *itr_get_pos(int pos);      // 迭代方式返回位置为pos的节点指针
    Node *rcr_get_pos(int pos);      // 递归方式返回位置为pos的节点指针
    bool remove_value(int key);      // 删除值为key的节点
};
#ifndef HEAD_LIST_H
#define HEAD_LIST_H
Head_list::Head_list()
{
    head = make_node(-1);
    tail = head;
    length = 0;
}

Head_list::~Head_list()
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

bool Head_list::is_empty()
{
    return (length == 0);
}

int Head_list::get_length()
{
    return length;
}

void Head_list::append(int value)
{
    tail->next = make_node(value);
    tail = tail->next;
    length++;
}

bool Head_list::insert(int pos, int value)
{
    Node *ptr;
    Node *prev;
    int n;
    if (pos < 0 || pos > length)
    {
        return 0;
    }
    else
    {
        ptr = make_node(value);
        prev = head;
        n = 0;
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

Node *Head_list::itr_get_pos(int pos)
{
    Node *curr;
    int n;
    curr = head->next;
    n = 0;
    while (n != pos && curr != nullptr)
    {
        n++;
        curr = curr->next;
    }
    return curr;
}

Node *Head_list::rcr_get_pos(int pos)
{
    return rcr_get(head->next, pos);
}

Node *Head_list::rcr_get(Node *head, int pos)
{
    if (pos == 0)
        return head;
    else
        return rcr_get(head->next, pos - 1);
}

bool Head_list::remove_value(int key)
{
    Node *temp;
    Node *prev;
    prev = head;
    while (prev->next != nullptr && prev->next->value != key)
    {
        prev = prev->next;
    }
    if (prev->next == nullptr)
    {
        return 0;
    }
    else if (prev->next == tail)
    {
        temp = tail;
        prev->next = nullptr;
        delete temp;
        tail = prev;
        length--;
        return 1;
    }
    else
    {
        temp = prev->next;
        prev->next = prev->next->next;
        delete temp;
        length--;
        return 1;
    }
}
#endif

