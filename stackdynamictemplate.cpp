//Stack using dynamic Arrays and template
//Template is used to create any type of array
//g++  7.4.0

#include <iostream>
//#include <climits>
using namespace std;
template <typename T>
class Stack
{
    T *data;
    int nextIndex;
    int capacity;

public:
    Stack()
    {
        data = new T[4];
        nextIndex = 0;
        capacity = 4;
    }
    int size()
    {
        return nextIndex;
    }
    bool isempty()
    {
        return nextIndex == 0;
    }
    void push(T element)
    {
        if (nextIndex == capacity)
        {
            T *newdata = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newdata[i] = data[i];
            }
            capacity *= 2;
            delete[] data;
            data = newdata;
        }
        data[nextIndex] = element;
        nextIndex++;
    }
    T pop()
    {
        if (isempty())
        {
            cout << "stack is empty" << endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }
    T top()
    {
        if (isempty())
        {
            cout << "stack is empty" << endl;
            return 0;
        }
        return data[nextIndex - 1];
    }
};
int main()
{
    Stack<int> s;
    //Stack s(4);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << s.top() << endl;
    cout << s.size() << endl;
    cout << s.isempty() << endl;
    s.pop();
    s.pop();
    s.pop();
    cout << s.top();
}