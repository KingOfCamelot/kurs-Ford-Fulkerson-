#include <iostream>
#include "list.h"

using namespace std;

template<typename T>
void ListOfNum<T>::push_back(T Num)
{
    node_list_list* elem = new node_list_list;
    elem->info = Num;
    if (head == nullptr)
    {
        head = elem;
        LastItem = elem;
        elem->next = nullptr;
    }
    else
    {
        LastItem->next = elem;
        LastItem = elem;
    }
    size++;
}
template<typename T>
void ListOfNum<T>::push_front(T Num)
{
    node_list_list* elem = new node_list_list;
    elem->info = Num;
    if (head == nullptr)
    {
        head = elem;
        LastItem = elem;
        elem->next = nullptr;
    }
    else
    {
        elem->next = head;
        head = elem;
    }
    size++;
}

template<typename T>
void ListOfNum<T>::swap()
{
    if (count < 2) return;
    size_t i = 0;
    size_t j = count - 1;
    while (i < j)
    {
        Swap(i, j);
        i++;
        j--;
    }
}

template<typename T>
void ListOfNum<T>::pop_back()
{
    if (head == nullptr) throw invalid_argument("List empty");
    node_list* temp = head;
    node_list* prev = NULL;
    while (temp->next)
    {
        prev = temp;
        temp = temp->next;
    }
    if (prev) prev->next = NULL;
    else head = NULL;
    if (temp) delete temp;
    size--;
}

template<typename T>
inline int ListOfNum<T>::search(T value)
{
    Node* current = head;
    for (int i = 0; i < size; i++) {
        if (current->value == value)
            return i;
        current = current->next;
    }
    return -1;
}

template<typename T>
T ListOfNum<T>::get_elem(int index)
{
    if (size >= index + 1)
    {
        Node* current = head;
        for (int i = 0; i < index; i++, current = current->next);
        return current->value;
    }
}

template<typename T>
void ListOfNum<T>::pop_front()
{
    if (head == nullptr) throw invalid_argument("List empty");
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        LastItem = nullptr;
    }
    else
    {
        node_list* first = head->next;
        delete head;
        head = first;
    }
    size--;
}
template<typename T>
void ListOfNum<T>::remove(T index)
{
    if (index > get_size()) throw invalid_argument("Your index > size of list");
    if (index <= 0) throw invalid_argument("Your index <= 0");
    CurrentItem = head;
    node_list* previositem = 0;
    for (int i = 0; i < index; ++i)
    {
        previositem = CurrentItem;
        CurrentItem = CurrentItem->next;
    }
    previositem->next = CurrentItem->next;
    size--;
    delete CurrentItem;
}
template<typename T>
int ListOfNum<T>::at(T index)
{
    if (index > get_size()) throw invalid_argument("Your index > size of list");
    if (index <= 0) throw invalid_argument("Your index <= 0");
    int i = 0;
    node_list* tmp_ptr = head;
    while (i < index)
    {
        tmp_ptr = tmp_ptr->next;
        i++;
    }
    CurrentItem->info = tmp_ptr->info;
    return tmp_ptr->info;
}
template<typename T>
bool ListOfNum<T>::contains(T Num)
{
    node_list* current = head;
    while (current)
    {
        if (current->info == Num) return true;
        current = current->next;
    }
    return false;
}
template<typename T>
int ListOfNum<T>::get_size()
{
    if (isEmpty())
    {
        CurrentItem->info = 0;
        return 0;
    }
    node_list* tmp_ptr = head;
    while (tmp_ptr->next != nullptr)
    {
        tmp_ptr = tmp_ptr->next;
        size++;
    }
    CurrentItem->info = size;
    return size;
}
template<typename T>
void ListOfNum<T>::set(size_t index, T value)
{
    if (index > get_size()) throw invalid_argument("Your index > size of list");
    if (index <= 0) throw invalid_argument("Your index <= 0");
    CurrentItem = head;
    for (int i = 1; i <= index; ++i)
    {
        if (i == index) CurrentItem->info = value;
        CurrentItem = CurrentItem->next;
    }
}

template<typename T>
T ListOfNum<T>::operator[](size_t index)
{
    return at(index);
}

template<typename T>
bool ListOfNum<T>::isEmpty()
{
    return head == nullptr;
}
template<typename T>
void ListOfNum<T>::clear()
{
    if (head != nullptr)
    {
        while (head != nullptr)
        {
            pop_back();
        }
    }
}
template<typename T>
void ListOfNum<T>::insert(T value, size_t index)
{
    if (index > get_size()) throw invalid_argument("Your index > size of list");
    if (index <= 0) throw invalid_argument("Your index <= 0");
    node_list* newel = new node_list;
    newel->info = value;
    if (index == 1)
    {
        newel->next = head;
        head = newel;
    }
    else
    {
        node_list* before = head;
        for (int i = 0; i < index - 1; i++)
            before = before->next;

        newel->next = before->next;
        before->next = newel;
    }
    size++;
}
template<typename T>
long ListOfNum<T>::index(T& value)
{
    for (size_t i = 0; i < count; i++)
        if (value == At(i))
            return i;

    return -1;
}