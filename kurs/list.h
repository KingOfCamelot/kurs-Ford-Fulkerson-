#ifndef ADD_H
#define ADD_H
#include <iostream>

template<typename T>
struct node_list { T info; struct node_list* next; };

template<typename T>
class ListOfNum
{
private: size_t size;
public:
    node_list* CurrentItem;
    node_list* head = NULL;
    node_list* LastItem;
    ListOfNum()
    {
        size = 0;
        int Value = 1;
        if (head == NULL)
        {
            head = new node_list;
            head->info = Value++;
            head->next = NULL;
            LastItem = head;
        }
    }
    T& operator[](size_t index);
    void push_back(T Num);
    void push_front(T Num);
    void pop_back();
    void pop_front();
    void insert(T value, size_t index);
    bool contains(T num);
    int at(T index);
    int search(T value);
    T get_elem(int index);
    void remove(T index);
    int get_size();
    void clear();
    void set(size_t index, T value);
    void swap();
    bool isEmpty();
    long index(T& value);
};
#endif