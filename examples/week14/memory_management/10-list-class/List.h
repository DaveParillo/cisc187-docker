#pragma once

#include <cassert>

namespace mesa {

  // An alternative to the Link from the textbook sect 17.9 and 17.10
  // Key features:
  // 1. Pointer ownership is unabiguously assigned to this class
  //    - only private members have direct access to pointers
  //    - The list value, and next/previous pointers are encapulated in a Node
  // 2. No null pointers
  //    - An empty list is not == nullptr
  //    - An empty list has a single Node, the tail which points to itself
  //    - As new elements are added, the last element in the list points to tail
  //      and the tail points to the first element in the list
  template<class T>
    class List {
      public:
        List();
        virtual ~List();
        // return the number of elements in the list
        int size()   { return size_; }

        // check if the container is empty
        bool empty() { return size_ == 0; }

        // return the value at list position pos
        virtual    T at (int pos);

        // replace the value at list position pos with a new value
        virtual    T set(int pos, T value);

        // insert a new value before list position pos 
        virtual void insert(int pos, T value);

        // append a new value to the end of the list
        virtual void push_back(T value) { 
          insert(size_, value); 
        }

        // remove the list element at position pos
        virtual    T remove(int pos);

        // remove all list elements
        virtual void clear ();
      private:
        struct Node {
          T value;
          Node *prev, *next;
        };
        Node tail;
        int size_;
        void remove(Node *element);

        // insert a new value before the provided element
        Node* insert(Node *element, T value);
        // get the node at position pos
        Node* get_node(int pos);
    };


  template<class T>
    List<T>::List() {
      tail.next = &tail;
      tail.prev = &tail;
      size_ = 0;
    }

  template<class T>
    List<T>::~List() {
      clear();
    }


  template<class T>
    T List<T>::at(int pos) {
      return get_node(pos)->value;
    }

  template<class T>
    T List<T>::set(int pos, T value) {
      Node* it = get_node(pos);
      T y = it->value;
      it->value = value;
      return y;
    }

  template<class T>
    void List<T>::clear() {
      Node *x = tail.next;
      while (x != &tail) {
        Node *y = x->next;
        delete x;
        --size_;
        x = y;
      }
      assert (size_ == 0);
    }

  template<class T>
    void List<T>::remove(Node *element) {
      element->prev->next = element->next;
      element->next->prev = element->prev;
      delete element;
      --size_;
    }

  template<class T>
    void List<T>::insert(int pos, T value) {
      insert(get_node(pos), value);
    }

  template<class T>
    T List<T>::remove(int pos) {
      Node *it = get_node(pos);
      T value = it->value;
      remove(it);
      return value;
    }






  //
  //  private helper functions
  //
  template<class T>
    typename List<T>::Node* List<T>::insert(Node *element, T value) {
      Node *it = new Node;
      it->value = value;
      it->prev = element->prev;
      it->next = element;
      it->next->prev = it;
      it->prev->next = it;
      ++size_;
      return it;
    }

  template<class T>
    typename List<T>::Node* List<T>::get_node(int pos) {
      Node* it;
      if (pos < size_ / 2) {
        it = tail.next;
        for (int j = 0; j < pos; ++j)
          it = it->next;
      } else {
        it = &tail;
        for (int j = size_; j > pos; --j)
          it = it->prev;
      }
      return it;
    }
} 


