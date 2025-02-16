#include <iostream>
#include <fstream>
using namespace std;

enum SymbolicTokenClass { Zero,One, Error, EndOfFile };

enum States { A1, B1, C1, D1,E1,F1, Stop };

struct SymbolicToken
{
    SymbolicTokenClass token_class; 
};
SymbolicToken transliterator(int ch)
{
    SymbolicToken s;
    if (ch == '1')
    {
        s.token_class = One;
    }
    else if (ch == '0')
    {
        s.token_class = Zero;
    }
    else if (ch == EOF || ch == ' ' || ch == '\t' || ch == '\0')
    {
        s.token_class = EndOfFile;
    }
    else
    {
        s.token_class = Error;
    }
    return s;
}

// Основная функция анализа. Функция запускает конечный автомат на тексте из файла filename.
int exercise_1(string str)
{
    int ch;          
    SymbolicToken s;   
    int state = A1;     
    bool stop = false;
    int i = -1;
    while (!stop)
    {
        i++;
        ch = str[i];
        s = transliterator(ch);
        switch (state)
        {
        case A1:
            switch (s.token_class)
            {
            case One:
                state = B1;
                break;
            case Zero:
                state = C1;
                break;
            case EndOfFile:
                return 0;
            default:
                state = Stop;
                break;
            }
            break;
        case B1:
            switch (s.token_class)
            {
            case One:
                state = A1;
                break;
            case EndOfFile:
                return 0;
            default:
                state = Stop;
                break;
            }
            break;
        case C1:
            switch (s.token_class)
            {
            case Zero:
                state = D1;
                break;
            case EndOfFile:
                return 1;
            default:
                state = Stop;
                break;
            }
            break;
        case D1:
            switch (s.token_class)
            {
            case Zero:
                state = C1;
                break;
            case EndOfFile:
                return 0;
            default:
                return 0;
            }
            break;
        }
    }
}
int exercise_2(string str)
{

    int ch;
    SymbolicToken s;
    int state = A1;
    bool stop = false;
    int i = -1;
    while (!stop)
    {
        i++;
        ch = str[i];
        s = transliterator(ch);
        switch (state)
        {
        case A1:
            switch (s.token_class)
            {
            case One:
                state = B1;
                break;
            case Zero:
                state = A1;
                break;
            case EndOfFile:
                return 1;
            default:
                return 0;
            }
            break;
        case B1:
            switch (s.token_class)
            {
            case One:
                state = D1;
                break;
            case Zero:
                state = C1;
                break;
            case EndOfFile:
                return 1;
            default:
                return 0;
            }
            break;
        case C1:
            switch (s.token_class)
            {
            case Zero:
                state = B1;
                break;
            case EndOfFile:
                return 0;
            default:
                return 0;
            }
            break;
        case D1:
            switch (s.token_class)
            {
            case One:
                state = B1;
                break;
            case Zero:
                state = E1;
                break;
            case EndOfFile:
                return 1;
            default:
                return 0;
            }
            break;
        case E1:
            switch (s.token_class)
            {
            case Zero:
                state = F1;
                break;
            case EndOfFile:
                return 1;
            default:
                return 0;
            }
            break;
        case F1:
            switch (s.token_class)
            {
            case One:
                state = D1;
                break;
            case Zero:
                state = E1;
                break;
            case EndOfFile:
                return 1;
            default:
                return 0;
            }
            break;
        }
    }
}
int exercise_3(string str)
{
    int ch;
    SymbolicToken s;
    int state = A1;
    bool stop = false;
    int i = -1;
    while (!stop)
    {
        i++;
        ch = str[i];
        s = transliterator(ch);
        switch (state)
        {
        case A1:
            switch (s.token_class)
            {
            case One:
                state = B1;
                break;
            case Zero:
                state = A1;
                break;
            case EndOfFile:
                return 1;
            default:
                state = Stop;
                break;
            }
            break;
        case B1:
            switch (s.token_class)
            {
            case One:
                state = C1;
                break;
            case Zero:
                state = A1;
                break;
            case EndOfFile:
                return 1;
            default:
                state = Stop;
                break;
            }
            break;
        case C1:
            switch (s.token_class)
            {
            case Zero:
                state = A1;
                break;
            case EndOfFile:
                return 0;
            default:
                return 0;
            }
            break;
        }
    }
}
int exercise_4(string str)
{
    int ch;
    SymbolicToken s;
    int state = A1;
    bool stop = false;
    int i = -1;
    while (!stop)
    {
        i++;
        ch = str[i];
        s = transliterator(ch);
        switch (state)
        {
        case A1:
            switch (s.token_class)
            {
            case One:
                state = B1;
                break;
            case Zero:
                state = B1;
                break;
            case EndOfFile:
                return 1;
            default:
                state = Stop;
                break;
            }
            break;
        case B1:
            switch (s.token_class)
            {
            case One:
                state = C1;
                break;
            case Zero:
                state = C1;
                break;
            case EndOfFile:
                return 1;
            default:
                state = Stop;
                break;
            }
            break;
        case C1:
            switch (s.token_class)
            {
            case One:
                state = A1;
                break;
            case EndOfFile:
                return 1;
            default:
                return 0;
            }
            break;
        }
    }
}
int main()
{
    string srt = "11";
    cout << exercise_4(srt);
    return 0;
}