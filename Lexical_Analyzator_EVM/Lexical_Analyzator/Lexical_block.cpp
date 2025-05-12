#include "Lexical_block.hpp"
int BSE = 0;
int Count_Line_TL = 0;
int Count_TL = 1;
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
	Table[0].pfunc = &Analyzator::B1d;
	Table[1].letter = 4;
	Table[1].pfunc = &Analyzator::A2q;
	Table[2].letter = 15;
	Table[2].pfunc = &Analyzator::B1d;
	Table[3].letter = 18;
	Table[3].pfunc = &Analyzator::F1b;
	Table[4].letter = 15;
	Table[4].pfunc = &Analyzator::B1d;
	Table[5].letter = 20;
	Table[5].pfunc = &Analyzator::B1d;
	Table[6].letter = 15;
	Table[6].pfunc = &Analyzator::E1a;
	Table[7].letter = 19;
	Table[7].pfunc = &Analyzator::B1d;
	Table[8].letter = 21;
	Table[8].pfunc = &Analyzator::B1d;
	Table[9].letter = 2;
	Table[9].pfunc = &Analyzator::E1b;
	Table[10].letter = 6;
	Table[10].pfunc = &Analyzator::A2r;
	Table[11].letter = 5;
	Table[11].pfunc = &Analyzator::B1d;
	Table[12].letter = 20;
	Table[12].pfunc = &Analyzator::F1a;
	Table[13].letter = 5;
	Table[13].pfunc = &Analyzator::B1d;
	Table[14].letter = 24;
	Table[14].pfunc = &Analyzator::B1d;
	Table[15].letter = 20;
	Table[15].pfunc = &Analyzator::C1a;
	Table[16].letter = 5;
	Table[16].pfunc = &Analyzator::B1d;
	Table[17].letter = 20;
	Table[17].pfunc = &Analyzator::B1d;
	Table[18].letter = 21;
	Table[18].pfunc = &Analyzator::B1d;
	Table[19].letter = 18;
	Table[19].pfunc = &Analyzator::B1d;
	Table[20].letter = 14;
	Table[20].pfunc = &Analyzator::A2s;
	Table[21].letter = 13;
	Table[21].pfunc = &Analyzator::G1a;
	Table[22].letter = 20;
	Table[22].pfunc = &Analyzator::B1d;
	Table[23].letter = 5;
	Table[23].pfunc = &Analyzator::B1d;
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
		cout << "Не удалось открыть файл";
		return;
	}
	while (!in.eof())
	{
		getline(in, str);
		str += '\n';
		Count_Line_TL++;
		Parse();

	}
	cout << '\n';
	cout << "TL" << endl;
	Print_TL();
	cout << '\n', '\n', '\n';
	cout << "TO:" << endl;
	Print_TO();
	cout << '\n', '\n', '\n';
	cout << "TS:";
	Print_TS();
	in.close();
}
void Analyzator::Print_TL()
{
	for (int i = 1; i < Count_TL; i++)
	{
		cout << TL[i].TokenClass << "||" << TL[i].TokenValue << "||" << String_View_TL(i) << endl;
	}
}
string Analyzator::String_View_TL(int i)
{
	string str = "";
	if (TL[i].TokenClass == 1)
		str = "Метка";
	if (TL[i].TokenClass == 2)
		str = "Операнд";
	if (TL[i].TokenClass == 3)
		str = "Арифметическая операция";
	if (TL[i].TokenClass == 4)
		str = "Операция отношения";
	if (TL[i].TokenClass == 5)
		str = "NEXT";
	if (TL[i].TokenClass == 6)
		str = "LET";
	if (TL[i].TokenClass == 7)
		str = "FOR";
	if (TL[i].TokenClass == 8)
		str = "GOTO";
	if (TL[i].TokenClass == 9)
		str = "GOSUB";
	if (TL[i].TokenClass == 10)
		str = "(";
	if (TL[i].TokenClass == 11)
		str = ")";
	if (TL[i].TokenClass == 12)
		str = "IF";
	if (TL[i].TokenClass == 13)
		str = "RETURN";
	if (TL[i].TokenClass == 14)
		str = "END";
	if (TL[i].TokenClass == 15)
		str = "TO";
	if (TL[i].TokenClass == 16)
		str = "STEP";
	if (TL[i].TokenClass == 17)
		str = "REM";
	if (TL[i].TokenClass == 18)
		str = "Ошибка";
	if (TL[i].TokenClass == 19)
		str = "Конец файла";
	return str;
}
void Analyzator::Print_TO()
{
	for (int i = 0; i < 1024; i++)
	{
		if (TO[i] != 0)
		{
			cout << i << "||" << TO[i] << endl;
		}
	}
}
void Analyzator::Print_TS()
{
	TS.print();
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
		if (ch == '=')
			RZN = 1;
		if (ch == '<')
			RZN = 2;
		if (ch == '>')
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
		for (int i = 0; i < 1; i++)// TS.Get_NTS();
		{
			if (TS.Find(RSTR))
			{
				t.TokenValue = i;
				fl = false;
				break;
			}
		}
		if (fl)
		{
			t.TokenValue = TS.el_add(RSTR, Count_Line_TL);
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
	Count_TL++;

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