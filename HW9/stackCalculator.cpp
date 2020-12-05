/* 
    Program Name: Stack Calculator (stackCalculator.cpp)
    Compile: c++ stackCalculator.cpp -o stackCalculator
    Author: Malachi Payne
    Course: COMP B12
    Date: 11.7.2020
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;
template <class T>
struct node
{
    T data;
    node<T> *nxt;
};

template <class T>
struct calcStack
{
    node<T> *head;
    calcStack()
    {
        head = NULL;
    }
    void push(T x)
    {
        node<T> *n = new node<T>();
        n->data = x;
        n->nxt = head;
        head = n;
    }

    T pop(int *empty)
    {
        if (head == NULL)
        {
            *empty = 1;
            return 0;
        }
        *empty = 0;
        node<T> *tmp = head;
        head = head->nxt;
        T x = tmp->data;
        delete (tmp);
        return x;
    }

    char top()
    {
        if (head == NULL)
        {
            return 0;
        }
        return head->data;
    }
};

bool isOperator(char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isDigit(char x)
{
    if (x >= '0' && x <= '9')
    {
        return true;
    }
    else
    {
        return false;
    }
}
int precedence(char operation)
{
    switch (operation)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

// CONVERTING FROM AN INFIX EXPRESSION TO A POSTFIX EXPRESSION
string InfixToPostfix(string infix)
{
    string postfix = "";
    calcStack<char> opsStack;
    int opsStackEmpty = 0;

    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == ' ')
            ;

        else if (isdigit(infix[i]) || infix[i] == '.')
        {
            postfix += infix[i];
        }

        else if (isOperator(infix[i]))
        {
            postfix += ' ';

            if (precedence(infix[i]) > precedence(opsStack.top()))
                opsStack.push(infix[i]);
            else
            {
                while (!opsStackEmpty && precedence(opsStack.top()) >= precedence(infix[i]))
                {
                    postfix += opsStack.pop(&opsStackEmpty);
                    postfix += ' ';
                }

                opsStack.push(infix[i]);
            }
        }
        else if (infix[i] == '(')
        {
            if (infix[i + 1] == '-')
            {
                opsStack.push(infix[i]);
                postfix += '0';
            }
            else
                opsStack.push(infix[i]);
        }

        else if (infix[i] == ')')
        {
            while (opsStack.top() != '(')
            {
                postfix += ' ';
                postfix += opsStack.pop(&opsStackEmpty);
            }

            opsStack.pop(&opsStackEmpty);
        }
    }

    while (!opsStackEmpty)
    {
        postfix += ' ';
        postfix += opsStack.pop(&opsStackEmpty);
    }

    return postfix;
}

// EVAULATE THE POSTFIX EXPRESSION
double postfixEvaluation(string postfix)
{
    calcStack<double> output;
    int empty = 0;
    double final, num = 0.0;
    string Temp = "";

    for (int i = 0; i < postfix.length(); i++)
    {
        if (isdigit(postfix[i]) || postfix[i] == '.')
        {
            Temp += postfix[i];
        }

        else if (postfix[i] == ' ')
        {
            if (Temp.length() >= 1)
            {
                num = stod(Temp);
                output.push(num);
                Temp = "";
            }
        }

        else if (isOperator(postfix[i]))
        {
            double valueOne, valueTwo, compute;

            valueTwo = output.pop(&empty);

            valueOne = output.pop(&empty);

            switch (postfix[i])
            {
            case '+':
                compute = (valueOne + valueTwo);
                break;

            case '-':
                compute = (valueOne - valueTwo);
                break;

            case '*':
                compute = (valueOne * valueTwo);
                break;

            case '/':
                compute = (valueOne / valueTwo);
                break;
            case '^':
                compute = pow(valueOne, valueTwo);
                break;
            default:
                break;
            }
            output.push(compute);
        }
    }

    final = output.pop(&empty);

    return final;
}

int main()
{

    string input = "";
    cout << "Welcome!" << endl
         << "Enter the expression you'd like calculated" << endl
         << "Enter Q to quit the program" << endl
         << endl;
    while (input != "q" || input != "Q")
    {
        cout << "Enter: ";
        cin >> input;
        if (input == "q" || input == "Q")
        {
            cout << endl
                 << "Goodbye!" << endl;
            break;
        }
        string postfix = InfixToPostfix(input);
        cout << "Result:    " << postfixEvaluation(postfix) << endl
             << endl;
    }
    return 0;
}