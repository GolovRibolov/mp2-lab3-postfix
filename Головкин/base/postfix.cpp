#include "postfix.h"
#include "stack.h"

template <class T>
bool TPostfix::included(const map<string, T>& map, const string& key)
{
    for (pair<const string, T> pair : map)
        if (pair.first == key) return true;
    return false;
}

vector<string> TPostfix::split(const string& infix, char splitter)
{
    vector<string> elements;
    string temp = "";
    for (char c : infix)
    {
        if (c != splitter)
            temp += c;
        else
        {
            if (temp != "")
                elements.push_back(temp);
            temp = "";
        }
    }
    if (temp != "")
        elements.push_back(temp);
    return elements;
}

int TPostfix::findPair(const vector<string>& elements, int first, int last)
{
    TStack<string> brackets;
    for (int i = first; i < last; ++i)
    {
        if (elements[i] == "(")
            brackets.push("(");
        else if (elements[i] == ")")
        {
            if (brackets.empty())
                return i;
            else
                brackets.pop();
        }
    }
    throw "Incorrect expression";
}

string TPostfix::transform(const vector<string>& elements, int first, int last)
{
    string postfix = "";
    bool lastIsOperand = false;
    TStack<string> operators;
    for (int i = first; i < last; ++i)
    {
        if (!included(table, elements[i]))
        {
            if (lastIsOperand)
                throw "Incorrect expression";
            postfix += elements[i] + " ";
            lastIsOperand = true;
        }
        else if (elements[i] == "(")
        {
            if (lastIsOperand)
                throw "Incorrect expression";
            int closingBracket = findPair(elements, i + 1, last);
            postfix += transform(elements, i + 1, closingBracket) + " ";
            i = closingBracket;
            lastIsOperand = true;
        }
        else
        {
            if (!lastIsOperand)
                throw "Incorrect expression";
            while (!operators.empty() && table[operators.peek()].priority >= table[elements[i]].priority)
                postfix += operators.pop() + " ";
            operators.push(elements[i]);
            lastIsOperand = false;
        }
    }
    while (!operators.empty())
        postfix += operators.pop() + " ";
    postfix.erase(postfix.size() - 1);
    return postfix;
}

void TPostfix::ToPostfix(const string& infix)
{
    this->infix = infix;
    vector<string> elements = split(infix);
    postfix = transform(elements, 0, elements.size());
}

double TPostfix::Calculate()
{
    TStack<double> values;
    map<string, double> operands;
    vector<string> elements = split(postfix);
    for (string element : elements)
    {
        if (!included(table, element))
        {
            if (included(operands, element))
                values.push(operands[element]);
            else
            {
                double value;
                cout << "Enter " << element << ": ";
                cin >> value;
                operands.emplace(element, value);
                values.push(value);
            }
        }
        else
        {
            double second = values.pop();
            double first = values.pop();
            if (element == "+") values.push(first + second);
            if (element == "-") values.push(first - second);
            if (element == "*") values.push(first * second);
            if (element == "/") values.push(first / second);
            if (element == "^") values.push(pow(first, second));
        }
    }

    return values.pop();
}
