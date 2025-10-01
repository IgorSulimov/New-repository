#include "Lexical_Analyzator.hpp"
Vector new_vector;
void Lex_Analyze::See_number(int token_str, int number_lex, string Lex_, std::variant<int, Vector>* vec)
{
    cout << token_str << "|" << right << setw(2);
    if (number_lex == 1)
        cout << left << setw(10) << "if" << right << setw(3) << "|";
    if (number_lex == 2)
        cout << left << setw(10) << "then" << right << setw(3) << "|";
    if (number_lex == 3)
        cout << left << setw(10) << "else " << right << setw(3) << "|";
    if (number_lex == 4)
        cout << left << setw(10) << "while " << right << setw(3) << "|";
    if (number_lex == 5)
        cout << left << setw(10) << "each " << right << setw(3) << "|";
    if (number_lex == 6)
        cout << left << setw(10) << "end " << right << setw(3) << "|";
    if (number_lex == 7)
        cout << left << setw(10) << "in " << right << setw(3) << "|";
    if (number_lex == 8)
        cout << left << setw(10) << "cin " << right << setw(3) << "|";
    if (number_lex == 9)
        cout << left << setw(10) << "= " << right << setw(3) << "|";
    if (number_lex == 10)
        cout << left << setw(10) << "!= " << right << setw(3) << "|";
    if (number_lex == 11)
        cout << left << setw(10) << ">= " << right << setw(3) << "|";
    if (number_lex == 12)
        cout << left << setw(10) << "<= " << right << setw(3) << "|";
    if (number_lex == 13)
        cout << left << setw(10) << "+ " << right << setw(3) << "|";
    if (number_lex == 14)
        cout << left << setw(10) << "- " << right << setw(3) << "|";
    if (number_lex == 15)
        cout << left << setw(10) << "* " << right << setw(3) << "|";
    if (number_lex == 16)
        cout << left << setw(10) << "% " << right << setw(3) << "|";
    if (number_lex == 17)
        cout << left << setw(10) << "/ " << right << setw(3) << "|";
    if (number_lex == 18)
        cout << left << setw(10) << "> " << right << setw(3) << "|";
    if (number_lex == 19)
        cout << left << setw(10) << "< " << right << setw(3) << "|";
    if (number_lex == 20)
        cout << left << setw(10) << "shiftr " << right << setw(3) << "|";
    if (number_lex == 21)
        cout << left << setw(10) << "shiftl " << right << setw(3) << "|";
    if (number_lex == 22)
        cout << left << setw(10) << "concat " << right << setw(3) << "|";
    if (number_lex == 23)
        cout << left << setw(10) << "subvec " << right << setw(3) << "|";
    if (number_lex == 24)
        cout << left << setw(10) << "; " << right << setw(3) << "|";
    if (number_lex == 25)
        cout << left << setw(10) << "& " << right << setw(3) << "|";
    if (number_lex == 26)
        cout << left << setw(10) << "set " << right << setw(3) << "|";
    if (number_lex == 27)
        cout << left << setw(10) << "for " << right << setw(3) << "|";
    if (number_lex == 28)
        cout << left << setw(10) << ">> " << right << setw(3) << "|";
    if (number_lex == 29)
        cout << left << setw(10) << "<< " << right << setw(3) << "|";
    if (number_lex == 30)
        cout << left << setw(10) << "cout " << right << setw(3) << "|";
    if (number_lex == 31)
        cout << left << setw(10) << "C2 " << right << setw(3) << "|" << std::get<Vector>(*vec); // ??????
    if (number_lex == 32)
        cout << left << setw(10) << "jump " << right << setw(3) << "|";
    if (number_lex == 33)
        cout << left << setw(10) << "switch " << right << setw(3) << "|";
    if (number_lex == 34)
        cout << left << setw(10) << "when " << right << setw(3) << "|";
    if (number_lex == 35)
        cout << left << setw(10) << "throw " << right << setw(3) << "|";
    if (number_lex == 36)
        cout << left << setw(10) << "*COMMENT* " << right << setw(3) << "|";
    if (number_lex == 37)
        cout << left << setw(10) << "int " << right << setw(3) << "|";
    if (number_lex == 38)
        cout << left << setw(10) << "vector " << right << setw(3) << "|";
    if (number_lex == 39)
        cout << left << setw(10) << "L " << right << setw(3) << "|" << Lex_; //??????? ? ?????
    if (number_lex == 40)
        cout << left << setw(10) << "do " << right << setw(3) << "|";
    if (number_lex == 41)
        cout << left << setw(10) << "V " << right << setw(3) << "|" << Lex_;//??????????
    if (number_lex == 42)
        cout << left << setw(10) << "Warning " << right << setw(3) << "|";
    if (number_lex == 43)
        cout << left << setw(10) << "( " << right << setw(3) << "|";
    if (number_lex == 44)
        cout << left << setw(10) << ") " << right << setw(3) << "|";
    if (number_lex == 45)
    {
        cout << left << setw(10) << "C " << right << setw(3) << "|";
        if (std::holds_alternative<int>(*vec))
            std::cout << std::get<int>(*vec) << std::endl;
        else
            std::cout << std::get<Vector>(*vec) << std::endl;
    }
    if (number_lex == 46)
        cout << left << setw(10) << "L: " << right << setw(3) << "|" << Lex_; // ???? ?????
    if (number_lex == 47)
        cout << left << setw(10) << "otherwise " << right << setw(3) << "|";
    if (number_lex == 48)
        cout << left << setw(10) << "dim " << right << setw(3) << "|";
    if (number_lex == 49)
        cout << left << setw(10) << ", " << right << setw(3) << "|";
    if (number_lex == 50)
        cout << left << setw(10) << ": " << right << setw(3) << "|";
}

SymbolicToken Lex_Analyze::transliterator(int ch)
{
    SymbolicToken s;
    s.value = 0;

    if (isdigit(ch))
    {
        s.token_class = Digit;
        s.value = ch - '0';
    }
    else if (ch == '+' || ch == '-' || ch == '*' || ch == '%' || ch == '/' || ch == '&')
    {
        s.token_class = Arithmetic;
    }
    else if (ch == '=' || ch == '!' || ch == '<' || ch == '>' || ch == ';' || ch == '(' || ch == ')' || ch == ':' || ch == '[' || ch == ']' || ch == ',')
    {
        s.token_class = Comparison;
    }
    else if (ch == ' ' || ch == '\t')
    {
        s.token_class = Space;
    }
    else if (ch == '\n')
    {
        s.token_class = EndOfLine;
    }
    else if (ch == EOF)
    {
        s.token_class = EndOfFile;
    }
    else if (ch >= 'A' && ch <= 'z')
    {
        s.token_class = Symbol;
        s.value_c = ch;
    }
    else
    {
        s.token_class = Error;
    }
    return s;
}

Lexeme* Lex_Analyze::Inc_size(Lexeme* Table)
{
    Lexeme* New_Table = new Lexeme[size_ * 2];
    for (int i = 0; i < size_; i++)
    {
        New_Table[i].token_class = Table[i].token_class;
        New_Table[i].token_name = Table[i].token_name;
        New_Table[i].token_str = Table[i].token_str;
        New_Table[i].token_value = Table[i].token_value;
    }
    size_ *= 2;
    delete[] Table;
    Table = New_Table;
    return Table;

}

int* Lex_Analyze::Inc_arr(int* arr, int size_a)
{
    int* newArr = new int[size_array_ * 2];
    for (int i = 0; i < size_array_; i++) {
        newArr[i] = arr[i];
    }
    size_array_ *= 2;
    delete[] arr;
    arr = new int[size_array_ * 2];
    for (int i = 0; i < size_a; i++) {
        arr[i] = newArr[i];
    }
    return arr;
}

void Lex_Analyze::Print_Table_Lexem(Lexeme* Table)
{
    for (int i = 0; i < Value_Word_Lexems; i++)
    {
        cout << "|";
        See_number(Table[i].token_str, Table[i].token_class, Table[i].token_name, Table[i].token_value);
        if (Table[i].token_class != 31)
            cout << "\n";
    }
}
void Lex_Analyze::Initial_Vect(Initial_vector* vec_)
{
    vec_[1].symbol = 'w';
    vec_[1].detection = 17;
    vec_[2].symbol = 'r';
    vec_[2].detection = 58;
    vec_[3].symbol = 'e';
    vec_[3].detection = 4;
    vec_[4].symbol = 'j';
    vec_[4].detection = 1;
    vec_[5].symbol = 's';
    vec_[5].detection = 34;
    vec_[6].symbol = 'c';
    vec_[6].detection = 24;
    vec_[7].symbol = 'd';
    vec_[7].detection = 60;
    vec_[8].symbol = 'f';
    vec_[8].detection = 61;
    vec_[9].symbol = 't';
    vec_[9].detection = 52;
    vec_[10].symbol = 'i';
    vec_[10].detection = 12;
    vec_[11].symbol = 'v';
    vec_[11].detection = 63;
    vec_[12].symbol = 'o';
    vec_[12].detection = 68;
}

void Lex_Analyze::Detection_Tab(Detection_Table* table_)
{
    //Error
    table_[0].state = Error;

    //jump 
    table_[1].symbol = 'u';
    table_[2].symbol = 'm';
    table_[3].symbol = 'p';
    table_[3].state = Sy_J1;

    //end
    table_[4].symbol = 'n';
    table_[4].alternative = 6;
    table_[5].symbol = 'd';
    table_[5].state = Sy_E1;
    //else
    table_[6].symbol = 'l';
    table_[6].alternative = 9;
    table_[7].symbol = 's';
    table_[8].symbol = 'e';
    table_[8].state = Sy_E3;
    //each
    table_[9].symbol = 'a';
    table_[10].symbol = 'c';
    table_[11].symbol = 'h';
    table_[11].state = Sy_E2;

    //int
    table_[12].symbol = 'n';
    table_[12].alternative = 16;
    table_[13].symbol = 't';
    table_[13].alternative = 15;
    table_[13].state = Sy_I3;
    //in
    table_[14].symbol = 'n';
    table_[15].symbol = ' ';
    table_[15].state = Sy_I2;
    //if
    table_[16].symbol = 'f';
    table_[16].alternative = 13;
    table_[16].state = Sy_I1;

    //while
    table_[17].symbol = 'h';
    table_[18].symbol = 'i';
    table_[18].alternative = 22;
    table_[19].symbol = 'l';
    table_[20].symbol = 'e';
    table_[20].state = Sy_W1;
    //when
    table_[21].symbol = 'h';
    table_[22].symbol = 'e';
    table_[23].symbol = 'n';
    table_[23].state = Sy_W2;

    //concat
    table_[24].symbol = 'o';
    table_[24].alternative = 29;
    table_[25].symbol = 'n';
    table_[25].alternative = 32;
    table_[26].symbol = 'c';
    table_[27].symbol = 'a';
    table_[28].symbol = 't';
    table_[28].state = Sy_C1;
    //cin
    table_[29].symbol = 'i';
    table_[30].symbol = 'n';
    table_[30].state = Sy_C2;
    //cout
    table_[31].symbol = 'o';
    table_[32].symbol = 'u';
    table_[33].symbol = 't';
    table_[33].state = Sy_C3;


    //shiftl
    table_[34].symbol = 'h';
    table_[34].alternative = 40;
    table_[35].symbol = 'i';
    table_[36].symbol = 'f';
    table_[37].symbol = 't';
    table_[38].symbol = 'l';
    table_[38].state = Sy_S1;
    table_[38].alternative = 39;
    //shiftr
    table_[39].symbol = 'r';
    table_[39].state = Sy_S2;
    //subvec
    table_[40].symbol = 'u';
    table_[40].alternative = 45;
    table_[41].symbol = 'b';
    table_[42].symbol = 'v';
    table_[43].symbol = 'e';
    table_[44].symbol = 'c';
    table_[44].state = Sy_S3;
    //set
    table_[45].symbol = 'e';
    table_[45].alternative = 47;
    table_[46].symbol = 't';
    table_[46].state = Sy_S4;
    //switch
    table_[47].symbol = 'w';
    table_[48].symbol = 'i';
    table_[49].symbol = 't';
    table_[50].symbol = 'c';
    table_[51].symbol = 'h';
    table_[51].state = Sy_S5;

    //then
    table_[52].symbol = 'h';
    table_[53].symbol = 'e';
    table_[53].alternative = 55;
    table_[54].symbol = 'n';
    table_[54].state = Sy_T1;
    //throw
    table_[55].symbol = 'r';
    table_[56].symbol = 'o';
    table_[57].symbol = 'w';
    table_[57].state = Sy_T2;

    //rem
    table_[58].symbol = 'e';
    table_[59].symbol = 'm';
    table_[59].state = Sy_R1;

    //do
    table_[60].symbol = 'o';
    table_[60].alternative = 76;
    table_[60].state = Sy_D1;

    //for
    table_[61].symbol = 'o';
    table_[62].symbol = 'r';
    table_[62].state = Sy_F1;

    //vector
    table_[63].symbol = 'e';
    table_[64].symbol = 'c';
    table_[65].symbol = 't';
    table_[66].symbol = 'o';
    table_[67].symbol = 'r';
    table_[67].state = Sy_V1;

    //otherwise
    table_[68].symbol = 't';
    table_[69].symbol = 'h';
    table_[70].symbol = 'e';
    table_[71].symbol = 'r';
    table_[72].symbol = 'w';
    table_[73].symbol = 'i';
    table_[74].symbol = 's';
    table_[75].symbol = 'e';
    table_[75].state = Sy_O1;

    //dim
    table_[76].symbol = 'i';
    table_[77].symbol = 'm';
    table_[77].state = Sy_D2;
}

Lexeme* Lex_Analyze::Lexical_analyzer(const char* filename)
{
    ifstream in(filename);
    if (!in)
    {
        cout << "don't open file" << filename << endl;
    }
    int count_line = 1;
    Initial_vector vec_[13];
    Initial_Vect(vec_);
    int* arr_vect = new int[5];
    int size_arr_vect = 0;
    Detection_Table table_[78];
    Detection_Tab(table_);
    Lexeme* Table_Of_Lexemes = new Lexeme[size_];
    int ch;
    int zn = 0;
    string Lex;
    Vector a;
    SymbolicToken s;
    int detection = 0;
    int alternative = 0;
    int state = A1;
    bool stop = false;
    int date;
    while (!stop)
    {
        ch = in.get();
        s = transliterator(ch);
        switch (state)
        {
        case A1:
            Lex = "";
            if (Value_Word_Lexems >= size_ - 1)
            {
                Table_Of_Lexemes = Inc_size(Table_Of_Lexemes);
            }
            switch (s.token_class)
            {
            case Symbol:
                Lex += ch;
                for (int j = 0; j <= 12; j++)
                {
                    if (ch == vec_[j].symbol)
                    {
                        state = Sy_B1;
                        detection = vec_[j].detection;
                        break;
                    }
                }
                if (state != Sy_B1)
                {
                    if (Table_Of_Lexemes[Value_Word_Lexems - 1].token_class == 32)
                    {
                        state = Sy_L1;
                        zn = 39;
                    }
                    else
                    {
                        state = Sy_L1;
                        zn = 41;
                    }
                    break;
                }
                break;
            case Arithmetic:
                state = Ar_A1;
                Lex += ch;
                break;
            case Digit:
                state = Sy_Z60;
                date = ch - '0';
                break;
            case Space:
                break;

            case Comparison:
                if (ch == '=')
                {
                    Lex += ch;
                    state = Ar_A1;
                    break;
                }
                else if (ch == '[')
                {
                    Lex += ch;
                    state = Ar_B2;
                }
                else
                {
                    Lex += ch;
                    state = Co_B2;
                    break;
                }
                break;
            case EndOfLine:
                count_line++;
                break;
            case EndOfFile:
                stop = true;
                break;
            default:
                state = Stop;
                break;
            }
            break;
        case Sy_B1:
        {
            while (detection != 0)
            {
                if (ch == table_[detection].symbol)
                {
                    state = table_[detection].state;
                    detection++;
                    break;
                }
                else
                {
                    detection = table_[detection].alternative;
                }
            }
            if (detection == 0 && state == Sy_B1)
            {
                switch (s.token_class)
                {
                case Digit:
                    state = Sy_Z50;
                    Lex += ch;
                    break;
                case Symbol:
                    Lex += ch;
                    state = Sy_Z50;
                    break;
                case Space:
                    Table_Of_Lexemes[Value_Word_Lexems].token_class = 41;

                    Table_Of_Lexemes[Value_Word_Lexems].token_name = Lex;
                    Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                    Value_Word_Lexems++;
                    state = A1;
                    Lex = "";
                    break;
                case EndOfLine:
                    Table_Of_Lexemes[Value_Word_Lexems].token_class = 41;

                    Table_Of_Lexemes[Value_Word_Lexems].token_name = Lex;
                    Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                    count_line++;
                    Value_Word_Lexems++;
                    state = A1;
                    Lex = "";
                    break;
                case EndOfFile:
                    Table_Of_Lexemes[Value_Word_Lexems].token_class = 41;

                    Table_Of_Lexemes[Value_Word_Lexems].token_name = Lex;
                    Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                    stop = true;
                    Value_Word_Lexems++;
                    Lex = "";
                    break;

                default:
                    state = Stop;
                    break;
                }
                break;
            }
            if (state == Sy_I2)
            {
                Table_Of_Lexemes[Value_Word_Lexems].token_class = 7;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                state = A1;
                break;
            }
            Lex += ch;
        }
        break;
        case Ar_A1:

            if (Lex == "&")
                zn = 25;
            if (Lex == "+")
                zn = 13;
            if (Lex == "-")
                zn = 14;
            if (Lex == "*")
                zn = 15;
            if (Lex == "%")
                zn = 16;
            if (Lex == "/")
                zn = 17;
            if (Lex == "=")
                zn = 9;
            if (Lex == ">=")
                zn = 11;
            if (Lex == "<=")
                zn = 12;
            if (Lex == "!=")
                zn = 10;
            if (Lex == "<<")
                zn = 29;
            if (Lex == ">>")
                zn = 28;
            switch (s.token_class)
            {
            case Space:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                state = A1;

                break;
            case EndOfLine:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                count_line++;
                state = A1;
                break;
            case EndOfFile:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                stop = true;
                Value_Word_Lexems++;
                break;
            default:
                state = Stop;
                break;
            }
            break;
        case Co_B2: // >= <= !=
            if (Lex == ">")
                zn = 18;
            if (Lex == "<")
                zn = 19;
            if (Lex == ";")
                zn = 24;
            if (Lex == "(")
                zn = 43;
            if (Lex == ")")
                zn = 44;
            if (Lex == ",")
                zn = 49;
            if (Lex == ":")
                zn = 50;
            switch (s.token_class)
            {
            case Comparison:
                if (ch == '=' || ch == '<' || ch == '>' || ch == ';')
                {
                    Lex += ch;
                    state = Ar_A1;
                }
                break;
            case Space:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfLine:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                count_line++;
                state = A1;
                break;
            case EndOfFile:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                stop = true;
                break;
            default:
                state = Stop;
                break;
            }
            break;
        case Sy_L1:
        {
            switch (s.token_class)
            {
            case Comparison:
                if (ch == ':')
                {
                    Lex += ch;
                    zn = 46;
                    break;
                }
            case Symbol:
                Lex += ch;
                break;
            case Space:
                if (zn == 46 || zn == 39)
                {
                    Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                    Table_Of_Lexemes[Value_Word_Lexems].token_name = Lex;

                    Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                }
                else
                {
                    Table_Of_Lexemes[Value_Word_Lexems].token_class = 41;
                    Table_Of_Lexemes[Value_Word_Lexems].token_name = Lex;

                    Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                }
                Value_Word_Lexems++;
                Lex = "";
                state = A1;
                break;
            case EndOfLine:
                if (zn == 46 || zn == 39)
                {
                    Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                    Table_Of_Lexemes[Value_Word_Lexems].token_name = Lex;

                    Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                }
                else
                {
                    Table_Of_Lexemes[Value_Word_Lexems].token_class = 41;
                    Table_Of_Lexemes[Value_Word_Lexems].token_name = Lex;

                    Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                }
                count_line++;
                Value_Word_Lexems++;
                Lex = "";
                state = A1;
                break;
            case EndOfFile:
                if (zn == 46 || zn == 39)
                {
                    Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                    Table_Of_Lexemes[Value_Word_Lexems].token_name = Lex;

                    Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                }
                else
                {
                    Table_Of_Lexemes[Value_Word_Lexems].token_class = 41;
                    Table_Of_Lexemes[Value_Word_Lexems].token_name = Lex;

                    Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                }
                Lex = "";
                Value_Word_Lexems++;
                stop = true;
                break;
            case Digit:
                Lex += ch;
                break;
            default:
                state = Stop;
            }
        }
        break;
        case Sy_J1:
        {
            zn = 32;
            switch (s.token_class)
            {
            case Space:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfLine:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                count_line++;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfFile:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                stop = true;
                Value_Word_Lexems++;
                break;
            case Digit:
                Lex += ch;
                state = Sy_Z50;
                break;
            case Symbol:
                Lex += ch;
                state = Sy_Z50;
                break;
            default:
                state = Stop;
            }
        }
        break;
        case Sy_E1:
        {
            zn = 6;
            switch (s.token_class)
            {
            case Space:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfLine:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                count_line++;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfFile:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                stop = true;
                Value_Word_Lexems++;
                break;
            case Digit:
                Lex += ch;
                state = Sy_Z50;
                break;
            case Symbol:
                Lex += ch;
                state = Sy_Z50;
                break;
            default:
                state = Stop;
            }
        }
        break;
        case Sy_E3:
        {
            zn = 3;
            switch (s.token_class)
            {
            case Space:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfLine:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                count_line++;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfFile:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                stop = true;
                Value_Word_Lexems++;
                break;
            case Digit:
                Lex += ch;
                state = Sy_Z50;
                break;
            case Symbol:
                Lex += ch;
                state = Sy_Z50;
                break;
            default:
                state = Stop;
            }
        }
        break;
        case Sy_E2:
        {
            zn = 5;
            switch (s.token_class)
            {
            case Space:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfLine:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                count_line++;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfFile:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                stop = true;
                Value_Word_Lexems++;
                break;
            case Digit:
                Lex += ch;
                state = Sy_Z50;
                break;
            case Symbol:
                Lex += ch;
                state = Sy_Z50;
                break;
            default:
                state = Stop;
            }
        }
        break;
        case Sy_I1:
        {
            zn = 1;
            switch (s.token_class)
            {
            case Space:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfLine:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                count_line++;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfFile:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                stop = true;
                Value_Word_Lexems++;
                break;
            case Digit:
                Lex += ch;
                state = Sy_Z50;
                break;
            case Symbol:
                Lex += ch;
                state = Sy_Z50;
                break;
            default:
                state = Stop;
            }
        }
        break;
        case Sy_I3:
        {
            zn = 37;
            switch (s.token_class)
            {
            case Space:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfLine:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                count_line++;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfFile:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                stop = true;
                Value_Word_Lexems++;
                break;
            case Digit:
                Lex += ch;
                state = Sy_Z50;
                break;
            case Symbol:
                Lex += ch;
                state = Sy_Z50;
                break;
            default:
                state = Stop;
            }
        }
        break;
        case Sy_W1:
        {
            zn = 4;
            switch (s.token_class)
            {
            case Space:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfLine:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                count_line++;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfFile:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                stop = true;
                Value_Word_Lexems++;
                break;
            case Digit:
                Lex += ch;
                state = Sy_Z50;
                break;
            case Symbol:
                Lex += ch;
                state = Sy_Z50;
                break;
            default:
                state = Stop;
            }
        }
        break;
        case Sy_W2:
        {
            zn = 34;
            switch (s.token_class)
            {
            case Space:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfLine:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                count_line++;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfFile:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                stop = true;
                Value_Word_Lexems++;
                break;
            case Digit:
                Lex += ch;
                state = Sy_Z50;
                break;
            case Symbol:
                Lex += ch;
                state = Sy_Z50;
                break;
            default:
                state = Stop;
            }
        }
        break;
        case Sy_C1:
        {
            zn = 22;
            switch (s.token_class)
            {
            case Space:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfLine:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                count_line++;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfFile:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                stop = true;
                Value_Word_Lexems++;
                break;
            case Digit:
                Lex += ch;
                state = Sy_Z50;
                break;
            case Symbol:
                Lex += ch;
                state = Sy_Z50;
                break;
            default:
                state = Stop;
            }
        }
        break;
        case Sy_C2:
        {
            zn = 8;
            switch (s.token_class)
            {
            case Space:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfLine:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                count_line++;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfFile:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                stop = true;
                Value_Word_Lexems++;
                break;
            case Digit:
                Lex += ch;
                state = Sy_Z50;
                break;
            case Symbol:
                Lex += ch;
                state = Sy_Z50;
                break;
            default:
                state = Stop;
            }
        }
        break;
        case Sy_C3:
        {
            zn = 30;
            switch (s.token_class)
            {
            case Space:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfLine:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                count_line++;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfFile:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                stop = true;
                Value_Word_Lexems++;
                break;
            case Digit:
                Lex += ch;
                state = Sy_Z50;
                break;
            case Symbol:
                Lex += ch;
                state = Sy_Z50;
                break;
            default:
                state = Stop;
            }
        }
        break;
        case Sy_S1:
        {
            zn = 21;
            switch (s.token_class)
            {
            case Space:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfLine:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                count_line++;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfFile:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                stop = true;
                Value_Word_Lexems++;
                break;
            case Digit:
                Lex += ch;
                state = Sy_Z50;
                break;
            case Symbol:
                Lex += ch;
                state = Sy_Z50;
                break;
            default:
                state = Stop;
            }
        }
        break;
        case Sy_S2:
        {
            zn = 20;
            switch (s.token_class)
            {
            case Space:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfLine:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                count_line++;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfFile:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                stop = true;
                Value_Word_Lexems++;
                break;
            case Digit:
                Lex += ch;
                state = Sy_Z50;
                break;
            case Symbol:
                Lex += ch;
                state = Sy_Z50;
                break;
            default:
                state = Stop;
            }
        }
        break;
        case Sy_S3:
        {
            zn = 23;
            switch (s.token_class)
            {
            case Space:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfLine:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                count_line++;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfFile:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                stop = true;
                Value_Word_Lexems++;
                break;
            case Digit:
                Lex += ch;
                state = Sy_Z50;
                break;
            case Symbol:
                Lex += ch;
                state = Sy_Z50;
                break;
            default:
                state = Stop;
            }
        }
        break;
        case Sy_S4:
        {
            zn = 26;
            switch (s.token_class)
            {
            case Space:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfLine:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                count_line++;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfFile:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                stop = true;
                Value_Word_Lexems++;
                break;
            case Digit:
                Lex += ch;
                state = Sy_Z50;
                break;
            case Symbol:
                Lex += ch;
                state = Sy_Z50;
                break;
            default:
                state = Stop;
            }
        }
        break;
        case Sy_S5:
        {
            zn = 33;
            switch (s.token_class)
            {
            case Space:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfLine:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                count_line++;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfFile:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                stop = true;
                Value_Word_Lexems++;
                break;
            case Digit:
                Lex += ch;
                state = Sy_Z50;
                break;
            case Symbol:
                Lex += ch;
                state = Sy_Z50;
                break;
            default:
                state = Stop;
            }
        }
        break;
        case Sy_T1:
        {
            zn = 2;
            switch (s.token_class)
            {
            case Space:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfLine:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                count_line++;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfFile:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                stop = true;
                Value_Word_Lexems++;
                break;
            case Digit:
                Lex += ch;
                state = Sy_Z50;
                break;
            case Symbol:
                Lex += ch;
                state = Sy_Z50;
                break;
            default:
                state = Stop;
            }
        }
        break;
        case Sy_T2:
        {
            zn = 35;
            switch (s.token_class)
            {
            case Space:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfLine:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                count_line++;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfFile:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                stop = true;
                Value_Word_Lexems++;
                break;
            case Digit:
                Lex += ch;
                state = Sy_Z50;
                break;
            case Symbol:
                Lex += ch;
                state = Sy_Z50;
                break;
            default:
                state = Stop;
            }
        }
        break;
        case Sy_R1:
        {
            zn = 36;
            switch (s.token_class)
            {
            case Space:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                while (ch != '\n' && ch != EOF)
                    ch = in.get();
                if (ch == '\n')
                    count_line++;
                state = A1;
                break;
            case EndOfLine:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                count_line++;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfFile:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                stop = true;
                Value_Word_Lexems++;
                break;
            case Digit:
                Lex += ch;
                if (Table_Of_Lexemes[Value_Word_Lexems - 1].token_class == 32)
                {
                    zn = 39;
                }
                else
                {
                    zn = 49;
                }
                state = Sy_L1;
                break;
            case Symbol:
                Lex += ch;
                if (Table_Of_Lexemes[Value_Word_Lexems - 1].token_class == 32)
                {
                    zn = 39;
                }
                else
                {
                    zn = 49;
                }
                state = Sy_L1;
                break;
            default:
                state = Stop;
                break;
            }
        }
        break;
        case Sy_F1:
        {
            zn = 27;
            switch (s.token_class)
            {
            case Space:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfLine:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                count_line++;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfFile:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                stop = true;
                Value_Word_Lexems++;
                break;
            case Digit:
                Lex += ch;
                state = Sy_Z50;
                break;
            case Symbol:
                Lex += ch;
                state = Sy_Z50;
                break;
            default:
                state = Stop;
            }
        }
        break;
        case Sy_V1:
        {
            zn = 38;
            switch (s.token_class)
            {
            case Space:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfLine:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                count_line++;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfFile:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                stop = true;
                Value_Word_Lexems++;
                break;
            case Digit:
                Lex += ch;
                state = Sy_Z50;
                break;
            case Symbol:
                Lex += ch;
                state = Sy_Z50;
                break;
            default:
                state = Stop;
            }
        }
        break;
        case Sy_O1:
        {
            zn = 47;
            switch (s.token_class)
            {
            case Space:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfLine:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                count_line++;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfFile:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                stop = true;
                Value_Word_Lexems++;
                break;
            case Digit:
                Lex += ch;
                state = Sy_Z50;
                break;
            case Symbol:
                Lex += ch;
                state = Sy_Z50;
                break;
            default:
                state = Stop;
            }
        }
        break;
        case Sy_D1:
        {
            zn = 40;
            switch (s.token_class)
            {
            case Space:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfLine:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                count_line++;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfFile:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                stop = true;
                Value_Word_Lexems++;
                break;
            case Digit:
                Lex += ch;
                state = Sy_Z50;
                break;
            case Symbol:
                Lex += ch;
                state = Sy_Z50;
                break;
            default:
                state = Stop;
                break;
            }
        }
        break;
        case Sy_D2:
        {
            zn = 48;
            switch (s.token_class)
            {
            case Space:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfLine:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                count_line++;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfFile:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = zn;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                stop = true;
                Value_Word_Lexems++;
                break;
            case Digit:
                Lex += ch;
                state = Sy_Z50;
                break;
            case Symbol:
                Lex += ch;
                state = Sy_Z50;
                break;
            default:
                state = Stop;
                break;
            }

        }
        break;
        case Sy_Z50:
        {
            switch (s.token_class)
            {
            case Digit:
                Lex += ch;
                break;
            case Symbol:
                Lex += ch;
                break;
            case Space:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = 41;

                Table_Of_Lexemes[Value_Word_Lexems].token_name = Lex;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                state = A1;
                Lex = "";
                break;
            case EndOfLine:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = 41;

                Table_Of_Lexemes[Value_Word_Lexems].token_name = Lex;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                count_line++;
                Value_Word_Lexems++;
                state = A1;
                Lex = "";
                break;
            case EndOfFile:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = 41;

                Table_Of_Lexemes[Value_Word_Lexems].token_name = Lex;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                stop = true;
                Value_Word_Lexems++;
                Lex = "";
                break;

            default:
                state = Stop;
                break;
            }
        }
        break;
        case Sy_Z60:
            switch (s.token_class)
            {
            case Digit:
                date = date * 10 + (ch - '0');
                break;
            case Space:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = 45;
                Table_Of_Lexemes[Value_Word_Lexems].token_value = new std::variant<int, Vector>(date);

                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                state = A1;
                date = 0;
                break;
            case EndOfLine:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = 45;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Table_Of_Lexemes[Value_Word_Lexems].token_value = new std::variant<int, Vector>(date);

                count_line++;
                Value_Word_Lexems++;
                date = 0;
                state = A1;
                break;
            case EndOfFile:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = 45;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Table_Of_Lexemes[Value_Word_Lexems].token_value = new std::variant<int, Vector>(date);

                date = 0;
                stop = true;
                Value_Word_Lexems++;
                break;

            default:
                state = Stop;
                break;
            }
            break;
        case Ar_B2://????? ? ???????
            switch (s.token_class)
            {
            case Digit:
                arr_vect[size_arr_vect] = ch - '0';
                state = Ar_C2;
                break;
            default:
                state = Stop;
                delete[] arr_vect;
                arr_vect = new int[5];
                size_arr_vect = 0;
                size_array_ = 5;
                break;
            }
            break;
        case Ar_C2://?????????? ????? ? ???????
            switch (s.token_class)
            {
            case Digit:
                arr_vect[size_arr_vect] = 10 * arr_vect[size_arr_vect] + ch - '0';
                state = Ar_C2;
                break;
            case Space:
                state = Stop;
                delete[] arr_vect;
                arr_vect = new int[5];
                size_arr_vect = 0;
                size_array_ = 5;
                break;
            case Comparison:
                if (ch == ',')
                {
                    state = Ar_B2;
                    size_arr_vect++;
                    if (size_arr_vect >= size_array_)
                    {
                        arr_vect = Inc_arr(arr_vect, size_arr_vect);
                    }
                }
                else if (ch == ']')
                    state = Ar_D2;
                else
                {
                    state = Stop;
                    delete[] arr_vect;
                    arr_vect = new int[5];
                    size_arr_vect = 0;
                    size_array_ = 5;
                }
                break;
            case EndOfLine:
                delete[] arr_vect;
                arr_vect = new int[5];
                size_arr_vect = 0;
                size_array_ = 5;
                Table_Of_Lexemes[Value_Word_Lexems].token_class = 42;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfFile:
                delete[] arr_vect;
                arr_vect = new int[5];
                size_arr_vect = 0;
                size_array_ = 5;
                Table_Of_Lexemes[Value_Word_Lexems].token_class = 42;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                count_line++;
                state = A1;
                break;
            default:
                state = Stop;
                delete[] arr_vect;
                arr_vect = new int[5];
                size_arr_vect = 0;
                size_array_ = 5;
                break;
            }
            break;
        case Ar_D2:
            switch (s.token_class)
            {

            case Space:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = 31;
                new_vector.Vector_by_arr(arr_vect, size_arr_vect + 1);
                Table_Of_Lexemes[Value_Word_Lexems].token_value = new std::variant<int, Vector>(new_vector);
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                arr_vect = new int[5];
                size_arr_vect = 0;
                size_array_ = 5;
                state = A1;
                break;
            case EndOfLine:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = 31;
                new_vector.Vector_by_arr(arr_vect, size_arr_vect + 1);
                Table_Of_Lexemes[Value_Word_Lexems].token_value = new std::variant<int, Vector>(new_vector);
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;

                count_line++;
                Value_Word_Lexems++;
                arr_vect = new int[5];
                size_arr_vect = 0;
                size_array_ = 5;
                state = A1;
                break;
            case EndOfFile:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = 31;
                new_vector.Vector_by_arr(arr_vect, size_arr_vect + 1);
                Table_Of_Lexemes[Value_Word_Lexems].token_value = new std::variant<int, Vector>(new_vector);
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;

                stop = true;
                Value_Word_Lexems++;
                arr_vect = new int[5];
                size_arr_vect = 0;
                size_array_ = 5;
                break;

            default:
                state = Stop;
                delete[] arr_vect;
                arr_vect = new int[5];
                size_arr_vect = 0;
                size_array_ = 5;
                break;
            }
            break;
        case Stop:
            switch (s.token_class)
            {
            case Space:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = 42;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                state = A1;
                break;
            case EndOfLine:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = 42;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                Value_Word_Lexems++;
                count_line++;
                state = A1;
                break;
            case EndOfFile:
                Table_Of_Lexemes[Value_Word_Lexems].token_class = 42;
                Table_Of_Lexemes[Value_Word_Lexems].token_str = count_line;
                stop = true;
                Value_Word_Lexems++;
                break;
            default:
                state = Stop;
                break;
            }
        }
    }
    return Table_Of_Lexemes;
    in.close();
}