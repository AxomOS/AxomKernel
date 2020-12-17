template<typename T>
struct Node
{
    T* node;
    T* next;
};

template<typename T>
struct LinkedList
{
    Node<T>* head;
    Node<T>* tail;

    void AddNode(T* n)
    {
        Node<T> *tmp = new Node<T>;
        tmp->node = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    Node<T>* operator[](int i)
    {
        Node<T>* tmp;
        tmp = head;
        for (int j=0;j<=i;j++)
        {
            if(tmp->next == nullptr)
            {
                return nullptr;
            }
            elseif (i==j)
            {
                return tmp;
            }
            else
            {
                tmp = tmp->next;
            }
        }
    }

    size_t length()
    {
        size_t i = 0;
        for(i = 0;this[i]!=nullptr;i++);
        return i;
    }
};