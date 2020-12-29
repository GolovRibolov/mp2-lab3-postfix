#include <iostream>
#include <string>
#include "postfix.h"

using namespace std;

int main()
{
  string expression;
  TPostfix postfix;
  double res;

  setlocale(LC_ALL, "Russian");
  cout << "Введите арифметическое выражение: ";
  getline(cin, expression);
  cout << expression << endl;
  try
  {
      postfix.ToPostfix(expression);
      cout << "Арифметическое выражение: " << postfix.GetInfix() << endl;
      cout << "Постфиксная форма: " << postfix.GetPostfix() << endl;
      res = postfix.Calculate();
      cout << res << endl;
  }
  catch (char* ex_cstr)
  {
      cerr << ex_cstr;
  }
  return 0;
}
