#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include "Hash.hpp"
class Analyzator
{
protected:
	string str;
	typedef void(Analyzator::* pfuncType)();// указатель на функцию состояния
	pfuncType pfunc;
	int RCH, // регистр числа
		RZ, // регистр знака
		RP, // регистр порядка
		RS, // регистр счётчика                                                                      
		RKL, // регистр класса лексем
		ROT, // регистр значения отношения
		RZN, // регистр значения символа
		RSOS, // регистр состояния 
		ROB, // регистр обнаружения
		RK, // регистр значения класса символа 
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
	void Print_TL();
	string String_View_TL(int i);
	void Print_TO();
	void Print_TS();
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
		void(Analyzator::* pfunc)();
	};
	vector<node> Table; // таблица распознавания

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
		ROB++;
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