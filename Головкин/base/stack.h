#ifndef __STACK_H__
#define __STACK_H__

const int MaxStackSize = 100;

// Класс стек, работающий по принципу FILO (first in last out)
template <class T>
class TStack
{
  T *pMem;
  int size;
  int top;
public:
  TStack(int _size = 20) : size(_size), top(-1)
  {
    if ((size < 1) || (size > MaxStackSize))
      throw size;
    pMem = new T[size];
  }
  TStack(const TStack& st) : size(st.size), top(st.top)
  {
      pMem = new T[size];
      for (int i = 0; i <= top; ++i)
          pMem[i] = st.pMem[i];
  }
  ~TStack()
  {
    delete [] pMem;
  }
  bool empty() // Пуст ли стек?
  {
      return top == -1;
  }
  bool full() // Полон?
  {
      return top == size - 1;
  }
  void push(const T& val) // Добавить элемент в конец
  {
      if (full()) throw "Overflow";
      pMem[++top] = val;
  }
  T pop() // Получить последний элемент (удаляется из конца)
  {
      if (empty()) throw "Underflow";
      return pMem[top--];
  }
  T peek() // Получить последний элемент (без удаления)
  {
      if (empty()) throw "Underflow";
      return pMem[top];
  }
  TStack& operator=(const TStack& st) // Оператор писваивания
  {
      if (this != &st)
      {
          size = st.size;
          top = st.top;
          delete[] pMem;
          pMem = new T[size];
          for (int i = 0; i <= top; ++i)
              pMem[i] = st.pMem[i];
      }
      return *this;
  }
};

#endif
