#ifndef MYSTACK_HPP
#define MYSTACK_HPP

template <typename type> class ListNode
{
  public:
    ListNode *prev;
    type val;

    inline ListNode() : prev(nullptr), val(0) {}
    inline ListNode(type value) : prev(nullptr), val(value) {}
};

template <typename type> class MyStack
{
  public:
    inline MyStack() : first(nullptr), count(0) {}
    
    inline void pop()
    {
      if (first != nullptr)
      {
        first = first->prev;
        count--;
      }
    }

    inline void push(type value)
    {
      ListNode<type> *next = new ListNode<type>(value);

      if (first == nullptr)
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

    inline type top() const
    {
      return first ? first->val : type();
    }

    inline int size() const
    {
      return count;
    }

  private:
    ListNode<type> *first;
    int count;
};

#endif // MYSTACK_HPP
