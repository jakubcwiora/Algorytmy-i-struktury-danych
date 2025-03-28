template <typename type> class ListNode
{
  public:
    ListNode *prev;
    type val;

    ListNode()
    {
      prev = NULL;
      val = 0;
    }

    ListNode(type value)
    {
      this->val = value;
      this->prev = NULL;
    }
};

template <typename type> class MyQueue
{
  public:

    MyQueue()
    {
      first = NULL;
      last = NULL;
    }

    void pop()
    {
      first = first->prev;
      count--;
    }

    void push(type value)
    {
      ListNode<type> *next = new ListNode<type>(value);

      if(first == NULL)
      {
        first = next;
      }
      else if(last == NULL)
      {
        last = next;
        first->prev = last;
      }
      else
      {
        last->prev = next;
        std::swap(last, next);
      }
      count++;
     
    }

    type top()
    {
      if(first != NULL)
      {
        return first->val;
      }
      return 0;
    }

    int size()
    {
      return count;
    }

  private:
  ListNode<type> *first;
  ListNode<type> *last;
  int count = 0;
};
