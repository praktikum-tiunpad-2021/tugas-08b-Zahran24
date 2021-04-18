#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  // Implementasikan di sini.
  T data;
  int priority;
  Element* next;
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
  // Implementasikan di sini.
  ElementPtr<T> head;
  ElementPtr<T> tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  // Implementasikan di sini.
  Queue<T> brandnew;
  brandnew.head = nullptr;
  brandnew.tail = nullptr;
  return brandnew;
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  // Implementasikan di sini.
  ElementPtr<T> baru = new Element<T>;
  baru -> data = value;
  baru -> priority = priority;
  baru -> next = nullptr;
  if(q.head == nullptr && q.tail == nullptr){
    q.tail = baru;
    q.head = baru;
  }else{
    ElementPtr<T> help1 = q.head;
    ElementPtr<T> help2 = nullptr;
    while(help1 -> priority >= priority && help1 -> next != nullptr){
      help2 = help1;
      help1 = help1 -> next;
    }
    if(help1 == q.head && help1 -> priority < priority){
      baru -> next = help1;
      q.head = baru;
    }else if(help1 == q.tail && help1 -> priority > priority){
      help1 -> next = baru;
      q.tail = baru;
    }else{
      help2 -> next = baru;
      baru -> next = help1;
    }
  }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  // Implementasikan di sini.
  return q.head -> data;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  // Implementasikan di sini.
  ElementPtr<T> deleteelm;
  if(q.head == nullptr && q.tail == nullptr){
    deleteelm = nullptr;
  }else if(q.head -> next == nullptr){
    deleteelm = q.head;
    q.head = nullptr;
    q.tail = nullptr;
  }else{
    deleteelm = q.head;
    q.head = q.head -> next;
    deleteelm -> next = nullptr;
  }
}

}  // namespace priority_queue

}  // namespace strukdat
