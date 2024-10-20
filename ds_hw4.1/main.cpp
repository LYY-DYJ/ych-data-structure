#include<stdio.h>

template <class T>
class Arr_List
{
private:
    T *listp;
    int maxsize;
    int curlen;
    void upscaling();

public:
    long int op_num=0;
    Arr_List(int size);
    ~Arr_List();
    // 判断数列是否为空
    bool is_empty();
    // 返回数列的长度
    int length();
    // 在数列末尾添加元素
    void append(T &value);
    // 在数列中位置p插入元素
    void insert(int p, T &value);
    // 移除数列中位置p的元素
    bool remove(int p);
    // 设置数列中位置p的元素
    void set_value(int p, T &value);
    // 查询数列中位置p的元素
    bool get_value(int p, T &value);
    // 查找数列中的元素，如果有，返回1并通过参数返回位置，否则返回0
    bool find_value(int &p, T &value);
};

template <class T>
Arr_List<T>::Arr_List(int size)
{
    maxsize = size;
    listp = new T[maxsize];
    curlen = 0;
}

template <class T>
Arr_List<T>::~Arr_List()
{
    delete[] listp;
}

#define UPSCALING_SIZE 100

template <class T>
void Arr_List<T>::upscaling()
{
    T *new_listp;
    new_listp = new T[maxsize*2];
    for (int i = 0; i < curlen; i++)
    {
        new_listp[i] = listp[i];
        op_num++;
    }
    delete[] listp;
    listp = new_listp;
    maxsize = maxsize*2;
}

template <class T>
bool Arr_List<T>::is_empty()
{
    return (curlen == 0);
}

template <class T>
int Arr_List<T>::length()
{
    return curlen;
}

template <class T>
void Arr_List<T>::append(T &value)
{
    if (curlen == maxsize)
    {
        upscaling();
    }
    listp[curlen] = value;
    curlen++;
}

template <class T>
void Arr_List<T>::insert(int p, T &value)
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
void Arr_List<T>::set_value(int p, T &value)
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
bool Arr_List<T>::get_value(int p, T &value)
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
bool Arr_List<T>::find_value(int &p, T &value)
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

#define SIZE (20*1024)

int main()
{
    int tmp;
    double avg_op_num;
    Arr_List<int> a(1);
    for(int i=0;i<SIZE;i++)
    {
        a.append(i);
        a.get_value(i,tmp);
        // printf("%d ",tmp);
    }
    avg_op_num=(float)a.op_num/SIZE;
    printf("Operation number of one appending is %ld\n",a.op_num);
    printf("Average operation number of one appending is %f\n",avg_op_num);
}