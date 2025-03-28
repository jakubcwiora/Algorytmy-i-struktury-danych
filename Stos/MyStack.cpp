#ifndef MYSTACK_CPP
#define MYSTACK_CPP
#include "MyStack.h"

template <typename type> ListNode<type>::ListNode()
{
  prev = NULL;
  val = 0;
}

template <typename type> ListNode<type>::ListNode(type value)
{
  this->val = value;
  this->prev = NULL;
}

template <typename type> MyStack<type>::MyStack()
{
  first = NULL;
  count = 0;
}

template <typename type> void MyStack<type>::pop()
{
  if (first != NULL)
  {
    first = first->prev;
    count--;
  }
}

template <typename type> void MyStack<type>::push(type value)
{
  ListNode<type> *next = new ListNode<type>(value);

  if (first == NULL)
  {
    first = next;
  }
  else
  {
    next->prev = first;
    std::swap(first, next);
  }
  count++;
}

template <typename type> type MyStack<type>::top()
{
  if (first != NULL)
  {
    return first->val;
  }
  return 0;
}

template <typename type> int MyStack<type>::size()
{
  return count;
}

#endif // MYSTACK_CPP
