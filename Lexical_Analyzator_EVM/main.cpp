#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include "Hash.hpp"
int BSE = 0;
class Analyzator
{
private:
	string str;
	typedef void(Analyzator::* pfuncType)();// указатель на функцию состо€ни€
	pfuncType pfunc;
	int RCH, // регистр числа
		RZ, // регистр знака
		RP, // регистр пор€дка
		RS, // регистр счЄтчика                                                                      
		RKL, // регистр класса лексем
		ROT, // регистр значени€ отношени€
		RZN, // регистр значени€ символа
		RSOS, // регистр состо€ни€ 
		ROB, // регистр обнаружени€
		RK, // регистр значени€ класса символа 
		RSTR, // регистр строка
		RI, // регистр номера буквы в имени переменной
		RSE; // регистр счетчика ошибок
	vector<int> InitialVector; // начальный вектор
	enum RK
	{
		Letter, Digit, Ar_Oper, Relationship, Left_Bracket, Right_Bracket, Point, Space, End_Line, End_File
	};
	enum RKL
	{
		ROWLABEL = 1, OPERAND, AR_OPER, RELATIONSHIP, NEXT, LET, FOR, GOTO, GOSUB, LEFT_BRACKET, RIGHT_BRACKET, IF, RETURN, END, TO_, STEP, REM, ERROR, END_FILE
	};
	void A1();
	void A2();
	void A3();
	void B1();
	void C1();
	void C2();
	void D1();
	void D2();
	void D3();
	void D4();
	void D5();
	void D6();
	void E1();
	void E2();
	void F1();
	void F2();
	void F3();
	void G1();
	void H1();
	void Transliterator(char);
	void Parse();
	void End();
	void CreatToken();
public:
	Analyzator();
	void Start(const char* filename);

	struct Str
	{
		int RowLabl;
	};

	Hash TS;

	struct Token
	{
		int TokenClass;
		int TokenValue;
	};
	
	vector<Token> TL;

	double TO[1024];

	int NTL;
	int NTO;

	struct node
	{
		int letter;
		int alternativa;
		void(Analyzator:: *pfunc)();
	};
	vector<node> Table; // таблица распознавани€

	void next()
	{
		ROB++;
	}
	void A1a()
	{
		CreatToken();
		pfunc = &Analyzator::A1;
	}
	void A1b()
	{
		RP = 0;
		CreatToken();
		pfunc = &Analyzator::A1;
	}
	void A1c()
	{
		CreatToken();
		pfunc = &Analyzator::A1;
		A1a();
	}
	void A1d()
	{
		CreatToken();
		pfunc = &Analyzator::A1;
	}
	void A1e()
	{
		A1a();
		pfunc = &Analyzator::A1;
	}
	void A1f()
	{
		RKL = ERROR;
		CreatToken();
		pfunc = &Analyzator::A1;
	}
	void A2a()
	{
		RKL = AR_OPER;
		CreatToken();
		pfunc = &Analyzator::A2;
	}
	void A2b()
	{
		CreatToken();
		pfunc = &Analyzator::A2;
	}
	void A2c()
	{
		CreatToken();
		RKL = AR_OPER;
		CreatToken();
		pfunc = &Analyzator::A2;
	}
	void A2h()
	{
		RKL = LEFT_BRACKET;
		CreatToken();
		pfunc = &Analyzator::A2;
	}
	void A2l()
	{
		CreatToken();
		RKL = LEFT_BRACKET;
		CreatToken();
		pfunc = &Analyzator::A2;
	}
	void A2g()
	{
		CreatToken();
		RKL = AR_OPER;
		CreatToken();
		pfunc = &Analyzator::A2;
	}
	void A2p()
	{
		if (ROT == 2 && RZN == 1)
			ROT = 4;
		if (ROT == 3 && RZN == 1)
			ROT = 5;
		if (ROT == 2 && RZN == 3)
			ROT = 6;
		CreatToken();
		pfunc = &Analyzator::A2;
	}
	void A2r()
	{
		RKL = IF;
		A2b();
		pfunc = &Analyzator::A2;
	}
	void A2k()
	{
		CreatToken();
		RKL = LEFT_BRACKET;
		CreatToken();
		pfunc = &Analyzator::A2;
	}
	void A2s()
	{
		RKL = RETURN;;
		A2b();
		pfunc = &Analyzator::A2;
	}
	void A2q()
	{
		RKL = END;
		A2b();
		pfunc = &Analyzator::A2;
	}
	void A2o()
	{
		if (RZN == 1)
			CreatToken();
		else
		{
			G1b();
			return;
		}
		pfunc = &Analyzator::A2;
	}
	void A2u()
	{
		RKL = TO_;
		A2b();
		pfunc = &Analyzator::A2;
	}
	void A2j()
	{
		CreatToken();
		RKL = LEFT_BRACKET;
		CreatToken();
		pfunc = &Analyzator::A2;
	}
	void A2f()
	{
		CreatToken();
		RKL = AR_OPER;
		CreatToken();
		pfunc = &Analyzator::A2;
	}
	void A2t()
	{
		RKL = STEP;
		A2b();
		pfunc = &Analyzator::A2;
	}
	void A3a()
	{
		CreatToken();
		pfunc = &Analyzator::A3;
	}
	void A3b()
	{
		RKL = RIGHT_BRACKET;
		CreatToken();
		pfunc = &Analyzator::A3;
	}
	void A3c()
	{
		CreatToken();
		RKL = RIGHT_BRACKET;
		CreatToken();
		pfunc = &Analyzator::A3;
	}
	void A3d()
	{
		CreatToken();
		RKL = RIGHT_BRACKET;
		CreatToken();
		pfunc = &Analyzator::A3;
	}
	void A3g()
	{
		CreatToken();
		RKL = RIGHT_BRACKET;
		CreatToken();
		pfunc = &Analyzator::A3;
	}
	void B1a()
	{
		ROB = InitialVector[RZN - 1];
		pfunc = &Analyzator::B1;
	}
	void B1b()
	{
		CreatToken();
		ROB = InitialVector[RZN - 1];
		pfunc = &Analyzator::B1;
	}
	void B1c()
	{
		CreatToken();
		ROB = InitialVector[RZN - 1];
		pfunc = &Analyzator::B1;
	}
	void B1d()
	{
		CreatToken();
		ROB = InitialVector[RZN - 1];
		pfunc = &Analyzator::B1;
	}
	void B1e()
	{
		CreatToken();
		ROB = InitialVector[RZN - 1];
		pfunc = &Analyzator::B1;
	}
	void C1a()
	{
		RKL = NEXT;
		pfunc = &Analyzator::C1;
	}
	void C2a()
	{
		RKL = OPERAND;
		RI = RZN;
		pfunc = &Analyzator::C2;
	}
	void C2b()
	{
		CreatToken();
		RKL = OPERAND;
		RI = RZN;
		pfunc = &Analyzator::C2;
	}
	void C2d()
	{
		RI = RZN;
		pfunc = &Analyzator::C2;
	}
	void D1a()
	{
		RKL = OPERAND;
		RCH = RZN;
		pfunc = &Analyzator::D1;
	}
	void D1b()
	{
		RCH *= 10;
		RCH += RZN;
		pfunc = &Analyzator::D1;
	}
	void D1c()
	{
		CreatToken();
		RKL = OPERAND;
		RCH = RZN;
		pfunc = &Analyzator::D1;
	}
	void D2a()
	{
		RS++;
		RCH *= 10;
		RCH += RZN;
		pfunc = &Analyzator::D2;
	}
	void D2b()
	{
		RS = 1;
		RCH = RZN;
		pfunc = &Analyzator::D2;
	}
	void D2c()
	{
		RS = 0;
		pfunc = &Analyzator::D2;
	}
	void D3a()
	{
		RS = 0;
		pfunc = &Analyzator::D3;
	}
	void D4a()
	{
		if (RZN == 1)
			RZ = 1;
		if (RZN == 2)
			RZ = -1;
		pfunc = &Analyzator::D4;
	}
	void D5a()
	{
		RZ = 1;
		RP = RZN;
		pfunc = &Analyzator::D5;
	}
	void D5b()
	{
		RP = RZN;
		pfunc = &Analyzator::D5;
	}
	void D5c()
	{
		RP *= 10;
		RP += RZN;
		pfunc = &Analyzator::D5;
	}
	void D6a()
	{
		CreatToken();
		RKL = OPERAND;
		pfunc = &Analyzator::D6;
	}
	void D6b()
	{
		RKL = OPERAND;
		pfunc = &Analyzator::D6;
	}
	void E1a()
	{
		RKL = GOTO;
		pfunc = &Analyzator::E1;
	}
	void E1b()
	{
		RKL = GOSUB;
		pfunc = &Analyzator::E1;
	}
	void E2a()
	{
		RKL = ROWLABEL;
		RSTR = RZN;
		pfunc = &Analyzator::E2;
	}
	void E2b()
	{
		RSTR = RZN;
		pfunc = &Analyzator::E2;
	}
	void E2c()
	{
		RSTR *= 10;
		RSTR += RZN;
		pfunc = &Analyzator::E2;
	}
	void F1a()
	{
		RKL = LET;
		pfunc = &Analyzator::F1;
	}
	void F1b()
	{
		RKL = FOR;
		pfunc = &Analyzator::F1;
	}
	void F2a()
	{
		RI = RZN;
		pfunc = &Analyzator::F2;
	}
	void F3a()
	{
		RI += (RZN) * 26;
		pfunc = &Analyzator::F3;
	}
	void G1a()
	{
		RKL = REM;
		CreatToken();
		pfunc = &Analyzator::G1;
	}
	void G1b()
	{
		RKL = ERROR;
		CreatToken();
		pfunc = &Analyzator::G1;
	}
	void H1a()
	{
		RKL = RELATIONSHIP;
		ROT = RZN;
		pfunc = &Analyzator::H1;
	}
	void H1b()
	{
		CreatToken();
		RKL = RELATIONSHIP;
		ROT = RZN;
		pfunc = &Analyzator::H1;
	}
	void H1c()
	{
		CreatToken();
		RKL = RELATIONSHIP;
		ROT = RZN;
		pfunc = &Analyzator::H1;
	}
	void H1f()
	{
		H1b();
		RKL = RELATIONSHIP;
		ROT = RZN;
		pfunc = &Analyzator::H1;
	}
	void M1()
	{
		if (ROB == 0)
		{
			G1b();
			return;
		}
		if (RZN == Table[ROB - 1].letter)
		{
			(this->*(Table[ROB - 1].pfunc))();
		}
		else
		{
			ROB = Table[ROB - 1].alternativa;
			if (ROB)
				(this->*(Table[ROB - 1].pfunc))();
			else
				G1b();
		}
	}
	void M2()
	{
		if (RZN == 5)
		{
			D3a();
			return;
		}
		else
		{
			CreatToken();
			ROB = InitialVector[RZN - 1];
			pfunc = &Analyzator::B1;
		}
	}
	void M3()
	{
		if (RZN == 5)
			pfunc = &Analyzator::D3;
	}
	//////////////////////////////
	void exit1()
	{
		RKL = END_FILE;
		CreatToken();
	}
	void exit2()
	{
		CreatToken();
		RKL = END_FILE;
		CreatToken();
	}
	void exit3()
	{
		CreatToken();
		RKL = END_FILE;
		CreatToken();
	}
	void exit4()
	{
		CreatToken();
		RKL = END_FILE;
		CreatToken();
	}
	void exit5()
	{
		CreatToken();
		RKL = END_FILE;
		CreatToken();
	}
};

Analyzator::Analyzator() : InitialVector(26), Table(26), TL(512), TS(512)
{
	for (int i = 0; i < 1024; i++)
	{
		TO[i] = 0;
	}
	pfunc = &Analyzator::A1;
	NTL = 1;
	RZ = 1;
	NTO = 287;
	RI = RCH = RP = RS = RSE = 0;

	InitialVector[0] = 0;
	InitialVector[1] = 0;
	InitialVector[2] = 0;
	InitialVector[3] = 0;
	InitialVector[4] = 1;
	InitialVector[5] = 3;
	InitialVector[6] = 5;
	InitialVector[7] = 0;
	InitialVector[8] = 11;
	InitialVector[9] = 0;
	InitialVector[10] = 0;
	InitialVector[11] = 12;
	InitialVector[12] = 0;
	InitialVector[13] = 14;
	InitialVector[14] = 0;
	InitialVector[15] = 0;
	InitialVector[16] = 0;
	InitialVector[17] = 17;
	InitialVector[18] = 23;
	InitialVector[19] = 26;
	InitialVector[20] = 0;
	InitialVector[21] = 0;
	InitialVector[22] = 0;
	InitialVector[23] = 0;
	InitialVector[24] = 0;
	InitialVector[25] = 0;

	for (int i = 0; i < 26; i++)
	{
		Table[i].alternativa = 0;
		Table[i].pfunc = &Analyzator::next;
	}
	Table[5].alternativa = 8;
	Table[17].alternativa = 22;
	Table[0].letter = 14;
	Table[1].letter = 4;
	Table[1].pfunc = &Analyzator::A2q;
	Table[2].letter = 15;
	Table[3].letter = 18;
	Table[3].pfunc = &Analyzator::F1b;
	Table[4].letter = 15;
	Table[5].letter = 20;
	Table[6].letter = 15;
	Table[6].pfunc = &Analyzator::E1a;
	Table[7].letter = 19;
	Table[8].letter = 21;
	Table[9].letter = 2;
	Table[9].pfunc = &Analyzator::E1b;
	Table[10].letter = 6;
	Table[10].pfunc = &Analyzator::A2r;
	Table[11].letter = 5;
	Table[12].letter = 20;
	Table[13].letter = 5;
	Table[14].letter = 24;
	Table[15].letter = 20;
	Table[15].pfunc = &Analyzator::C1a;
	Table[16].letter = 5;
	Table[17].letter = 20;
	Table[18].letter = 21;
	Table[19].letter = 18;
	Table[20].letter = 14;
	Table[20].pfunc = &Analyzator::A2s;
	Table[21].letter = 13;
	Table[21].pfunc = &Analyzator::G1a;
	Table[22].letter = 20;
	Table[23].letter = 5;
	Table[24].letter = 16;
	Table[24].pfunc = &Analyzator::A2t;
	Table[25].letter = 15;
	Table[25].pfunc = &Analyzator::A2u;
}
void Analyzator::Start(const char* filename)
{
	ifstream in(filename);
	if (!in)
	{
		cout << "Ќе удалось открыть файл";
		return;
	}
	while (!in.eof())
	{
		getline(in, str);
		str += '\n';
		Parse();

	}
	in.close();
}
void Analyzator::Parse()
{
	for (int i = 0; i < str.size(); i++)
	{
		Transliterator(str[i]);
		(this->*pfunc)();
	}
}
void Analyzator::Transliterator(char ch)
{
	if (ch >= 'a' && ch <= 'z')
	{
		RK = Letter;
		RZN = ch - 'a' + 1;
	}
	if (ch >= 'A' && ch <= 'Z')
	{
		RK = Letter;
		RZN = ch - 'A' + 1;
	}
	if (ch >= '0' && ch <= '9')
	{
		RK = Digit;
		RZN = ch - '0';
	}
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
	{
		RK = Ar_Oper;
		if (ch == '+')
			RZN = 1;
		if (ch == '-')
			RZN = 2;
		if (ch == '*')
			RZN = 3;
		if (ch == '/')
			RZN = 4;
		if (ch == '^')
			RZN = 5;
	}
	if (ch == ' ' || ch == '\t')
	{
		RK = Space;
	}
	if (ch == '.')
	{
		RK = Point;
	}
	if (ch == '\n')
	{
		RK = End_Line;
	}
	if (ch == '(')
	{
		RK = Left_Bracket;
	}
	if (ch == ')')
	{
		RK = Right_Bracket;
	}
	if (ch == '<' || ch == '>' || ch == '=')
	{
		RK = Relationship;
		if (ch == '>')
			RZN = 1;
		if (ch == '<')
			RZN = 2;
		if (ch == '=')
			RZN = 3;
	}
}
void Analyzator::CreatToken()
{
	Token t;
	t.TokenClass = RKL;
	t.TokenValue = -1;
	if (RKL == ROWLABEL || RKL == GOTO || RKL == GOSUB)
	{
		bool fl = true;
		for (int i = 0; i < TS.Get_NTS(); i++)
		{
			if (TS.find(RSTR))
			{
				t.TokenValue = i;
				fl = false;
				break;
			}
		}
		if (fl)
		{
			TS.add_el(RSTR);
			t.TokenValue = TS.Get_NTS();
		}
		RSTR = 0;
	}
	if (RKL == OPERAND || RKL == NEXT)
	{
		if (RI != 0)
		{
			int n;
			if (RK == Digit)
				n = RI + 26 * (RZN + 1);
			else
				n = RI;
			TO[n] = 1;
			t.TokenValue = n;
			RI = 0;
		}
		else
		{
			int n;
			if (RZ == 1)
				n = RCH * pow(10, RP - RS);
			else
				n = RCH / pow(10, RP + RS);
			RCH = RP = RS = 0;
			RZ = 1;
			for (int i = 287; i < NTO; i++)
			{
				if (TO[i] == n)
				{
					t.TokenValue = i;
					TL[NTL] = t;
					NTL++;
					return;
				}
			}
			TO[NTO] = n;
			t.TokenValue = NTO;
			NTO++;
		}
	}
	if (RKL == LET || RKL == FOR)
	{
		TO[RI] = 1;
		t.TokenValue = RI;
		RI = 0;
	}
	if (RKL == AR_OPER)
		t.TokenValue = RZN;
	if (RKL == RELATIONSHIP)
		t.TokenValue = ROT;
	TL[NTL] = t;
	NTL++;
}
void Analyzator::A1()
{
	switch (RK)
	{
	case Digit:
	{
		E2a();
		break;
	}
	case Space:
	{
		break;
	}
	case End_Line:
	{
		break;
	}
	default:
	{
		BSE++;
		G1b();
	}
	}
}
void Analyzator::A2()
{
	switch (RK)
	{
	case Letter:
	{
		C2a();
		break;
	}
	case Digit:
	{
		D1a();
		break;
	}
	case Ar_Oper:
	{
		A2a();
		break;
	}
	case Relationship:
	{
		H1a();
		break;
	}
	case Left_Bracket:
	{
		A2h();
		break;
	}
	case Right_Bracket:
	{
		A3b();
		break;
	}
	case Point:
	{
		D6b();
		break;
	}
	case Space:
	{
		break;
	}
	case End_Line:
	{
		pfunc = &Analyzator::A1;
		break;
	}
	}
}
void Analyzator::A3()
{
	switch (RK)
	{
	case Letter:
	{
		B1a();
		break;
	}
	case Digit:
	{
		D1a();
		break;
	}
	case Ar_Oper:
	{
		A2a();
		break;
	}
	case Relationship:
	{
		H1a();
		break;
	}
	case Left_Bracket:
	{
		A2h();
		break;
	}
	case Right_Bracket:
	{
		A3b();
		break;
	}
	case Point:
	{
		D6b();
		break;
	}
	case Space:
	{
		break;
	}
	case End_Line:
	{
		pfunc = &Analyzator::A1;
		break;
	}
	}
}
void Analyzator::B1()
{
	switch (RK)
	{
	case Letter:
	{
		M1();
		break;
	}
	case End_Line:
	{
		A1f();
		break;
	}
	default:
	{
		BSE++;
		G1b();
	}
	}
}
void Analyzator::C1()
{
	switch (RK)
	{
	case Letter:
	{
		C2d();
		break;
	}
	case Space:
	{
		break;
	}
	default:
	{
		G1b();
	}
	}
}
void Analyzator::C2()
{
	switch (RK)
	{
	case Letter:
	{
		B1b();
		break;
	}
	case Digit:
	{
		A3a();
		break;
	}
	case Ar_Oper:
	{
		A2g();
		break;
	}
	case Relationship:
	{
		H1b();
		break;
	}
	case Left_Bracket:
	{
		A2k();
		break;
	}
	case Right_Bracket:
	{
		A3c();
		break;
	}
	case Space:
	{
		break;
	}
	case End_Line:
	{
		A1a();
		break;
	}
	default:
	{
		G1b();
	}
	}
}
void Analyzator::D1()
{
	switch (RK)
	{
	case Letter:
	{
		M2();
		break;
	}
	case Digit:
	{
		D1b();
		break;
	}
	case Ar_Oper:
	{
		A2c();
		break;
	}
	case Relationship:
	{
		H1c();
		break;
	}
	case Left_Bracket:
	{
		A2l();
		break;
	}
	case Right_Bracket:
	{
		A3d();
		break;
	}
	case Point:
	{
		D2c();
		break;
	}
	case Space:
	{
		break;
	}
	case End_Line:
	{
		A1b();
		break;
	}
	default:
	{
		BSE++;
		G1b();
	}
	}
}
void Analyzator::D2()
{
	switch (RK)
	{
	case Letter:
	{
		M3();
		break;
	}
	case Digit:
	{
		D2a();
		break;
	}
	case Ar_Oper:
	{
		A2c();
		break;
	}
	case Relationship:
	{
		H1c();
		break;
	}
	case Left_Bracket:
	{
		A2l();
		break;
	}
	case Right_Bracket:
	{
		A3d();
		break;
	}
	case Space:
	{
		break;
	}
	case End_Line:
	{
		A1c();
		break;
	}
	default:
	{
		BSE++;
		G1b();
	}
	}
}
void Analyzator::D3()
{
	switch (RK)
	{
	case Digit:
	{
		D5a();
		break;
	}
	case Ar_Oper:
	{
		D4a();
		break;
	}
	case Space:
	{
		break;
	}
	default:
	{
		G1b();
	}
	}
}
void Analyzator::D4()
{
	switch (RK)
	{
	case Digit:
	{
		D5b();
		break;
	}
	case Space:
	{
		break;
	}
	default:
	{
		G1b();
	}
	}
}
void Analyzator::D5()
{
	switch (RK)
	{
	case Letter:
	{
		B1c();
		break;
	}
	case Digit:
	{
		D5c();
		break;
	}
	case Ar_Oper:
	{
		A2c();
		break;
	}
	case Relationship:
	{
		H1c();
		break;
	}
	case Left_Bracket:
	{
		A2l();
		break;
	}
	case Right_Bracket:
	{
		A3d();
		break;
	}
	case Space:
	{
		break;
	}
	case End_Line:
	{
		A1d();
		break;
	}
	default:
	{
		G1b();
	}
	}
}
void Analyzator::D6()
{
	switch (RK)
	{

	case Digit:
	{
		D2b();
		break;
	}

	case Space:
	{
		break;
	}
	default:
	{
		G1b();
	}
	}
}
void Analyzator::E1()
{
	switch (RK)
	{

	case Digit:
	{
		E2b();
		break;
	}

	case Space:
	{
		break;
	}
	default:
	{
		G1b();
	}
	}
}
void Analyzator::E2()
{
	switch (RK)
	{
	case Letter:
	{
		B1e();
		break;
	}
	case Digit:
	{
		E2c();
		break;
	}
	case Ar_Oper:
	{
		A2f();
		break;
	}
	case Relationship:
	{
		H1f();
		break;
	}
	case Left_Bracket:
	{
		A2j();
		break;
	}
	case Right_Bracket:
	{
		A3g();
		break;
	}
	case Space:
	{
		break;
	}
	case End_Line:
	{
		A1e();
		break;
	}
	default:
	{
		G1b();
	}
	}
}
void Analyzator::F1()
{
	switch (RK)
	{
	case Letter:
	{
		F2a();
		break;
	}
	case Space:
	{
		break;
	}
	default:
	{
		G1b();
	}
	}
}
void Analyzator::F2()
{
	switch (RK)
	{
	case Digit:
	{
		F3a();
		break;
	}
	case Relationship:
	{
		A2o();
		break;
	}
	case Space:
	{
		break;
	}
	default:
	{
		G1b();
	}
	}
}
void Analyzator::F3()
{
	switch (RK)
	{
	case Relationship:
	{
		A2o();
		break;
	}
	case Space:
	{
		break;
	}
	default:
	{
		G1b();
	}
	}
}
void Analyzator::G1()
{
	switch (RK)
	{
	case Letter:
	{
		break;
	}
	case Digit:
	{
		break;
	}
	case Ar_Oper:
	{
		break;
	}
	case Relationship:
	{
		break;
	}
	case Left_Bracket:
	{
		break;
	}
	case Right_Bracket:
	{
		break;
	}
	case Point:
	{
		break;
	}
	case Space:
	{
		break;
	}
	case End_Line:
	{
		A1();
		break;
	}
	case End_File:
	{
		exit1();
		break;
	}
	}
}
void Analyzator::H1()
{
	switch (RK)
	{
	case Letter:
	{
		C2b();
		break;
	}
	case Digit:
	{
		D1c();
		break;
	}
	case Ar_Oper:
	{
		A2g();
		break;
	}
	case Relationship:
	{
		A2p();
		break;
	}
	case Left_Bracket:
	{
		A2k();
		break;
	}
	case Right_Bracket:
	{
		A3c();
		break;
	}
	case Point:
	{
		D6a();
		break;
	}
	case Space:
	{
		H1();
		break;
	}
	case End_Line:
	{
		A1a();
		break;
	}
	case End_File:
	{
		exit2();
		break;
	}
	}
}
int main()
{
	Analyzator A;
	A.Start("i.txt");
}