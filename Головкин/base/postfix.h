#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include "stack.h"

using namespace std;

// Вспомогательная структура, хранящая в себе количество операндов и приоритет для оператора
struct OperatorsData
{
    int operands;
    int priority;
};

// Класс хранящий две формы представляющие уравнения
// Для корректного преобразования инфиксной формы в постфиксную необходимо, чтобы
// каждый элемент инфиксной формы отделялся от другого с помощью одного пробела
class TPostfix 
{
  string infix; // инфиксное представление уравнения
  string postfix; // постфиксное представление

  // Таблица операторов, хранящая в себе строку, как ключ, и вспомогательную структуру OperatorsData, как значение
  map<string, OperatorsData> table = {
      {"(",{0,0}},
      {")",{0,0}},
      {"+",{2,1}},
      {"-",{2,1}},
      {"*",{2,2}},
      {"/",{2,2}},
      {"^",{2,2}}
  };

  //Вспомогательный метод, позволяющий разделить строку по второму параметру (по умолчанию - пробел)
  vector<string> split(const string& infix, char splitter = ' ');

  // Метод, с помощью которого находится пара открывающей скобке (ищется закрывающая)
  // Возвращается индекс закрывающей скобки
  int findPair(const vector<string>& elements, int first, int last);

  // Сушествует ли в словаре элемент с таким ключом?
  // Результат работы: существует - true, иначе - false
  template<class T>
  bool included(const map<string, T>& map, const string& key); 

  // Вспомогательный рекурсивный метод имеющий приватный доступ
  // Преобразование разделенных элементов инфиксной формы в строку в постфиксной в [first;last]
  string transform(const vector<string>& elements, int first, int last);
public:
  TPostfix()
  {
      infix = "a + b";
      postfix = "a b +";
  }
  string GetInfix() { return infix; }
  string GetPostfix() { return postfix; }

  // Преобразование инфиксной формы в постфиксную
  void ToPostfix(const string& infix);

  // Ввод переменных, вычисление по постфиксной форме
  double Calculate();
};
#endif
