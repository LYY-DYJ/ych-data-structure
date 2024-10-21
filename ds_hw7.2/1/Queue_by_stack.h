#include <Stack.h>

template <class T>
class Queue_by_stack
{
private:
    Stack<T> front;
    Stack<T> rear;
    int max_size;

public:
    Queue_by_stack(int n);
    bool is_empty();
    bool enqueue(T &);
    bool dequeue(T &);
};

template<class T>
Queue_by_stack<T>::Queue_by_stack(int n):front(n),rear(n),max_size(n){};

template<class T>
bool Queue_by_stack<T>::is_empty()
{
    return (front.is_empty()&&rear.is_empty);
}

template<class T>
bool Queue_by_stack<T>::enqueue(T& item)
{
    T tmp;
    while(front.pop(tmp))
    {
        rear.push(tmp);
    }
    return rear.push(item);
}

template<class T>
bool Queue_by_stack<T>::dequeue(T &item)
{
    T tmp;
    while(rear.pop(tmp))
    {
        front.push(tmp);
    }
    return front.pop(item);
}