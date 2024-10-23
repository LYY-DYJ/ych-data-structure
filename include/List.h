#include<iostream>
template <class T>
class List
{
private:
    T *listp;
    int maxsize;
    int curlen;
    void upscaling();

public:
    List();
    List(const List& l);
    List& operator=(const List& l);
    ~List();
    // 判断数列是否为空
    bool is_empty();
    // 返回数列的长度
    int length();
    // 在数列末尾添加元素
    void append(const T &value);
    // 在数列中位置p插入元素
    void insert(int p,const T &value);
    // 移除数列中位置p的元素
    bool remove(int p);
    // 设置数列中位置p的元素
    void set_value(int p,const T &value);
    // 查询数列中位置p的元素
    bool get_value(int p,T &value);
    // 查找数列中的元素，如果有，返回1并通过参数返回位置，否则返回0
    bool find_value(int &p,const T &value);
    void print(std::ostream& os=std::cout);
    template<typename TT>
    friend std::ostream& operator<<(std::ostream& os, List<TT> &list);
};

#define INITIAL_LIST_MAXSIZE 8
template <class T>
List<T>::List()
{
    maxsize = INITIAL_LIST_MAXSIZE;
    listp = new T[maxsize];
    curlen = 0;
}
#undef INITIAL_LIST_MAXSIZE

template <class T>
List<T>::List(const List& l)
{
    maxsize=l.maxsize;
    listp = new T[maxsize];
    curlen = l.curlen;
    for(int i=0;i<curlen;i++)
    {
        listp[i]=l.listp[i];
    }
}

template <class T>
List<T>& List<T>::operator=(const List& l)
{
    maxsize=l.maxsize;
    listp = new T[maxsize];
    curlen = l.curlen;
    for(int i=0;i<curlen;i++)
    {
        listp[i]=l.listp[i];
    }
    return *this;
}

template <class T>
List<T>::~List()
{
    delete[] listp;
}

template <class T>
void List<T>::upscaling()
{
    T *new_listp;
    new_listp = new T[maxsize * 2];
    for (int i = 0; i < curlen; i++)
    {
        new_listp[i] = listp[i];
    }
    delete[] listp;
    listp = new_listp;
    maxsize = 2 * maxsize;
}

template <class T>
bool List<T>::is_empty()
{
    return (curlen == 0);
}

template <class T>
int List<T>::length()
{
    return curlen;
}

template <class T>
void List<T>::append(const T &value)
{
    if (curlen == maxsize)
    {
        upscaling();
    }
    listp[curlen] = value;
    curlen++;
}

template <class T>
void List<T>::insert(int p,const T &value)
{
    while (p >= maxsize || curlen == maxsize)
    {
        upscaling();
    }
    if (p < curlen)
    {
        for (int i = curlen; i > p; i--)
        {
            listp[i] = listp[i - 1];
        }
        listp[p] = value;
        curlen++;
    }
    else
    {
        for (int i = curlen; i < p; i++)
        {
            listp[i] = 0;
        }
        listp[p] = value;
        curlen = p + 1;
    }
}

template <class T>
void List<T>::set_value(int p,const T &value)
{
    while (p >= maxsize || curlen == maxsize)
    {
        upscaling();
    }
    if (p < curlen)
    {
        listp[p] = value;
    }
    else
    {
        for (int i = curlen; i < p; i++)
        {
            listp[i] = 0;
        }
        listp[p] = value;
        curlen = p + 1;
    }
}

template <class T>
bool List<T>::get_value(int p, T &value)
{
    if (p < curlen)
    {
        value = listp[p];
        return 1;
    }
    else
    {
        return 0;
    }
}

template <class T>
bool List<T>::find_value(int &p,const T &value)
{
    int i;
    for (i = 0; i < curlen && listp[i] != value; i++)
        ;
    if (i == curlen)
        return 0;
    else
    {
        p = i;
        return 1;
    }
}

template <class T>
void List<T>::print(std::ostream& os)
{
    os<<"[";
    for(int i=0;i<length();i++)
    {
        if(i>0)
        {
            os<<",";
        }
        T tmp;
        get_value(i,tmp);
        os<<tmp;
    }
    os<<"]\n";
}

template <typename T>
std::ostream& operator<<(std::ostream& os,List<T>& list)
{
    list.print(os);
    return os;
}
