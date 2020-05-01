#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <cstddef>

template <typename T> struct Node {
  Node *previous;
  T data;
  Node *next;

  Node(const T &d, Node *p = nullptr, Node *n = nullptr)
      : data{d}, previous{p}, next{n} {}
};

template <typename T> class DoublyLinkedListIterator;

template <typename T> class DoublyLinkedList {
public:
  DoublyLinkedList() = default;
  DoublyLinkedList(const DoublyLinkedList &);
  DoublyLinkedList &operator=(const DoublyLinkedList &);
  ~DoublyLinkedList(); // O(n)

  /**
   * Appends the given element value to the end of the container.
   * O(1) time complexity
   */
  void push_back(const T &value);

  /**
   * Removes the last element of the container.
   * Calling pop_back on an empty container throws exception.
   * O(1) time complexity
   *
   * @throw std::runtime_error
   */
  void pop_back();

  /**
   * Appends the given element value at the beginning of the container.
   * O(1) time complexity
   *
   */
  void push_front(const T &value);

  /**
   * Removes the first element of the container.
   * Calling pop_front on an empty container throws exception.
   * O(1) time complexity
   *
   * @throw std::runtime_error
   */
  void pop_front();

  /**
   * @return an iterator to the beginning
   */
  DoublyLinkedListIterator<T> begin() noexcept;

  /**
   * @return an iterator to the end
   */
  DoublyLinkedListIterator<T> end() noexcept;

  /**
   * Inserts value before pos.
   *
   * @return Iterator pointing to the inserted value
   */
  DoublyLinkedListIterator<T> insert(DoublyLinkedListIterator<T> pos,
                                     const T &value);

  /**
   * Removes the element at pos.
   *
   * @return Iterator following the last removed element.
   * If pos refers to the last element, then the end() iterator is returned.
   */
  DoublyLinkedListIterator<T> erase(DoublyLinkedListIterator<T> pos);

  /**
   * Returns number of elements in the list
   * O(1) time complexity
   *
   */
  size_t size() const noexcept;

  /**
   * Returns whether the array is empty of elements or not
   * O(1) time complexity
   *
   */
  bool empty() const noexcept;

  /**
   * Clears the linked list's contents
   * Complexity: Linear in the size of the container, i.e., the number of
   * elements.
   */
  void clear();

private:
  Node<T> *head = nullptr;
  Node<T> *tail = nullptr;
  size_t currentSize = 0;
};

template <typename T> DoublyLinkedList<T>::~DoublyLinkedList() {
  while (head) {
    Node<T> *nextHead = head->next;
    delete head;
    head = nextHead;
  }
}

template <typename T> size_t DoublyLinkedList<T>::size() const noexcept {
  return currentSize;
}

template <typename T> bool DoublyLinkedList<T>::empty() const noexcept {
  return !head;
}

template <typename T> class DoublyLinkedListIterator {};

template <typename T>
bool operator==(const DoublyLinkedList<T> &lhs,
                const DoublyLinkedList<T> &rhs) {}

template <typename T>
bool operator!=(const DoublyLinkedList<T> &lhs,
                const DoublyLinkedList<T> &rhs) {}

#endif
