#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>
#include <iomanip>
#include <stack>
using namespace std;

class parent
{
protected:
	string str;

public:
	virtual void start(string file_name) = 0;

	virtual ~parent() {};
};

class Avto1 : public parent
{
	void (Avto1::* q)(char ch);
public:
	Avto1() { q = &Avto1::q0; }
	int er_fl = 0;
	void start(string file_name)
	{
		ifstream in(file_name);
		if (!in)
		{
			cout << "Íå óäàëîñü îòêðûòü ôàéë " << file_name << endl;
		}
		char ch = in.get();
		while (ch != EOF)
		{
			while (ch != '\n' && ch != EOF)
			{
				(this->*q)(ch);
				cout << ch << endl;
				ch = in.get();
			}
			ch = in.get();
			if (er_fl == 1)
			{
				cout << "Bad" << endl;
				er_fl = 0;
			}
			else
			{
				if (q == &Avto1::q1 || q == &Avto1::q0)
					cout << "GOOD" << endl;
				else
					cout << "Bad" << endl;
				
			}
			q = &Avto1::q0;
		}
	}
	void q0(char ch)
	{
		cout << "Work q0" << endl;
		switch (ch)
		{
		case '0': q = &Avto1::q2; break;
		case '1': q = &Avto1::q1; break;
		default:Error();
		}
	}

	void q1(char ch)
	{
		cout << "Work q1" << endl;
		switch (ch)
		{
		case '0':Error(); break;
		case '1':q = &Avto1::q0; break;
		}
	}
	void q2(char ch)
	{
		cout << "Work q2" << endl;
		switch (ch)
		{
		case '0': q = &Avto1::q3; break;
		case '1': Error(); break;
		default:Error();
		}
	}
	void q3(char ch)
	{
		cout << "Work q3" << endl;
		switch (ch)
		{
		case '0': q = &Avto1::q2; break;
		case '1': Error(); break;
		default:Error();
		}
	}
	void Error()
	{
		er_fl = 1;
		cout << "Error simbol" << endl;
	}
};
class Avto2 : public parent
{
	void (Avto2::* q)(char ch);
public:
	Avto2() { q = &Avto2::q0; }
	int er_fl = 0;
	void start(string file_name)
	{
		ifstream in(file_name);
		if (!in)
		{
			cout << "Íå óäàëîñü îòêðûòü ôàéë " << file_name << endl;
		}
		char ch = in.get();
		while (ch != EOF)
		{
			while (ch != '\n' && ch != EOF)
			{
				(this->*q)(ch);
				cout << ch << endl;
				ch = in.get();
			}
			ch = in.get();
			if (er_fl == 1)
			{
				cout << "Bad" << endl;
				er_fl = 0;
			}
			else
			{
				if (q == &Avto2::q1 || q == &Avto2::q0)
					cout << "GOOD" << endl;
				else
					cout << "Bad" << endl;
				
			}
			q = &Avto2::q0;
		}
	}
	void q0(char ch)
	{
		cout << "Work q0" << endl;
		switch (ch)
		{
		case '0': q = &Avto2::q0; break;
		case '1': q = &Avto2::q1; break;
		default:Error();
		}
	}

	void q1(char ch)
	{
		cout << "Work q0" << endl;
		switch (ch)
		{
		case '0': q = &Avto2::q2; break;
		case '1': q = &Avto2::q3; break;
		default:Error();
		}
	}
	void q2(char ch)
	{
		cout << "Work q0" << endl;
		switch (ch)
		{
		case '0': q = &Avto2::q1; break;
		case '1': Error(); break;
		default:Error();
		}
	}
	void q3(char ch)
	{
		cout << "Work q0" << endl;
		switch (ch)
		{
		case '0': q = &Avto2::q4; break;
		case '1': Error(); break;
		default:Error();
		}
	}
	void q4(char ch)
	{
		cout << "Work q0" << endl;
		switch (ch)
		{
		case '0': q = &Avto2::q5; break;
		case '1': Error(); break;
		default:Error();
		}
	}
	void q5(char ch)
	{
		cout << "Work q0" << endl;
		switch (ch)
		{
		case '0': q = &Avto2::q4; break;
		case '1': q = &Avto2::q3; break;
		default:Error();
		}
	}
	void Error()
	{
		er_fl = 1;
		cout << "Error simbol" << endl;
	}
};
class Avto3 : public parent
{
	void (Avto3::* q)(char ch);
public:
	Avto3() { q = &Avto3::q0; }
	int er_fl = 0;
	void start(string file_name)
	{
		ifstream in(file_name);
		if (!in)
		{
			cout << "Íå óäàëîñü îòêðûòü ôàéë " << file_name << endl;
		}
		char ch = in.get();
		while (ch != EOF)
		{
			while (ch != '\n' && ch != EOF)
			{
				(this->*q)(ch);
				cout << ch << endl;
				ch = in.get();
			}
			ch = in.get();
			if (er_fl == 1)
			{
				cout << "Bad" << endl;
				er_fl = 0;
			}
			else
			{
				if (q == &Avto3::q1 || q == &Avto3::q0)
					cout << "GOOD" << endl;
				else
					cout << "Bad" << endl;
				
			}
			q = &Avto3::q0;
		}
	}
	void q0(char ch)
	{
		cout << "Work q0" << endl;
		switch (ch)
		{
		case '0': q = &Avto3::q0; break;
		case '1': q = &Avto3::q1; break;
		default:Error();
		}
	}

	void q1(char ch)
	{
		cout << "Work q0" << endl;
		switch (ch)
		{
		case '0': q = &Avto3::q0; break;
		case '1': q = &Avto3::q2; break;
		default:Error();
		}
	}
	void q2(char ch)
	{
		cout << "Work q0" << endl;
		switch (ch)
		{
		case '0': q = &Avto3::q0; break;
		case '1': Error(); break;
		default:Error();
		}
	}
	void Error()
	{
		er_fl = 1;
		cout << "Error simbol" << endl;
	}
};
class Avto4 : public parent
{
	void (Avto4::* q)(char ch);
public:
	Avto4() { q = &Avto4::q0; }
	int er_fl = 0;
	void start(string file_name)
	{
		ifstream in(file_name);
		if (!in)
		{
			cout << "Íå óäàëîñü îòêðûòü ôàéë " << file_name << endl;
		}
		char ch = in.get();
		while (ch != EOF)
		{
			while (ch != '\n' && ch != EOF)
			{
				(this->*q)(ch);
				cout << ch << endl;
				ch = in.get();
			}
			ch = in.get();
			if (er_fl == 1)
			{
				cout << "Bad" << endl;
				er_fl = 0;
			}
			else
			{
				cout << "GOOD" << endl;
			}
			q = &Avto4::q0;
		}
	}
	void q0(char ch)
	{
		cout << "Work q0" << endl;
		switch (ch)
		{
		case '0': q = &Avto4::q1; break;
		case '1': q = &Avto4::q1; break;
		default:Error();
		}
	}

	void q1(char ch)
	{
		cout << "Work q0" << endl;
		switch (ch)
		{
		case '0': q = &Avto4::q2; break;
		case '1': q = &Avto4::q2; break;
		default:Error();
		}
	}
	void q2(char ch)
	{
		cout << "Work q0" << endl;
		switch (ch)
		{
		case '0':Error(); break;
		case '1': q = &Avto4::q0; break;
		default:Error();
		}
	}
	void Error()
	{
		er_fl = 1;
		cout << "Error simbol" << endl;
	}
};
int main()
{
	Avto1 obj;
	Avto2 obj2;
	obj2.start("i.txt");
	return 0;
}

