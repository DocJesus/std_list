#include <iostream>
#include <iterator>
#include <cstddef>

template<typename T>
class my_list
{
    private:
        struct node
        {
            T elem;
            node *next;
            node *prev;
        };

        int size;
        node *base;

    public:
        struct Iterator
        {
            using difference_type = std::ptrdiff_t;
            using value_type = node;
            using pointer = node*;
            using reference = node&;
            using iterator_category = std::bidirectional_iterator_tag;

            private:
                pointer ptr;

            public:
                Iterator(pointer _ptr) : ptr(_ptr) 
                {}
                ~Iterator()
                {}

                T &operator*() const 
                {
                    return ptr->elem;
                }
                pointer operator->() 
                { 
                    return ptr;
                }
                Iterator& operator++() 
                { 
                    ptr = ptr->next;
                    return *this;
                }
                Iterator& operator--() 
                { 
                    ptr = ptr->prev;
                    return *this; 
                }
                friend bool operator==(const Iterator& a, const Iterator& b)
                { 
                    return a.ptr == b.ptr; 
                };
                friend bool operator!=(const Iterator& a, const Iterator& b)
                { 
                    return a.ptr != b.ptr;
                };  
 
        };

    public:
        my_list()
        {
            this->base = new node;
            this->size = 0;
            this->base->next = this->base;
            this->base->prev = this->base;
        }
        my_list(std::initializer_list<T> l)
        {
            this->base = new node;
            this->size = 0;
            this->base->next = this->base;
            this->base->prev = this->base;
            for (auto n : l)
            {
                this->push_front(n);
            }
        }
        ~my_list()
        {
            int i = 0;
            node *next;

            while (i <= this->get_size())
            {
                next = this->base->next;
                free(this->base);
                this->base = next;
                i++;
            }
        }

        void push_front(const T &elem)
        {
            node *new_node = new node;
            new_node->elem = elem;

            new_node->next = this->base;
            new_node->prev = this->base->prev;
            new_node->prev->next = new_node;
            this->base->prev = new_node;

            this->base = new_node;
            this->size += 1; 
        }

        void push_back(const T &_elem)
        {
            if (this->get_size() == 0)
                this->push_front(_elem);
            else
            {
                node *new_node = new node;
                new_node->elem = _elem;

                new_node->next = this->base->prev;
                new_node->prev = this->base->prev->prev;
                this->base->prev->prev = new_node;
                new_node->prev->next = new_node;

                this->size += 1; 
            }
        }

        void insert(Iterator &it, const T &_elem)
        {
            node *new_node = new node;
            new_node->elem = _elem;

            new_node->next = it->prev->next;
            new_node->prev = it->prev;
            it->prev->next = new_node;
            it->prev = new_node;
            this->size += 1;

            if (it == this->begin())
                this->base = new_node;
        }

        constexpr Iterator begin()
        {
            return Iterator(this->base);
        }

        constexpr Iterator end()
        {
            return Iterator(this->base->prev);
        }

        constexpr T& operator[](int _pos)
        {
            std::cout << _pos << std::endl;
            return "toto";
        }

        constexpr int get_size()
        {
            return this->size;
        }
};