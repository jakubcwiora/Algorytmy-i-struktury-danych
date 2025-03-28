template <typename type>
class ListNode
{
  public:
    ListNode *prev;
    type val;

    inline ListNode() : prev(NULL), val(0) {}

    inline ListNode(type value) : val(value), prev(NULL) {}
};

template <typename type>
class MyQueue
{
  public:

    inline MyQueue() : first(NULL), last(NULL), count(0) {}

    inline void pop()
    {
      if (first != NULL) {
        first = first->prev;
        count--;
      }
    }

    inline void push(type value)
    {
      ListNode<type> *next = new ListNode<type>(value);

      if (first == NULL) {
        first = next;
      } else if (last == NULL) {
        last = next;
        first->prev = last;
      } else {
        last->prev = next;
        last = next;
      }
      count++;
    }

    inline type top() const
    {
      if (first != NULL) {
        return first->val;
      }
      return type(); // Zwraca domyślną wartość typu
    }

    inline int size() const
    {
      return count;
    }

  private:
    ListNode<type> *first;
    ListNode<type> *last;
    int count;
};
