#include "Lexical_block.hpp"
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct Atom 
{
	int cl;
	int a1;
	int a2;
	int a3;
	int a4;
};

class Syntax_block : public Analyzator
{
private:
	vector<Atom> TA;
	typedef void(Syntax_block::* pfunc)();// указатель на функцию перехода
	pfunc Table[33][23];
	int NTA = 0;//Первое свободное место атомов


	 
public:
	void add_Atom(int cl, int a1, int a2, int a3, int a4);
	void F1();
	void F2();
	void F3();
	void F4();
	void F5();
	void F6();
	void F7();
	void F8();
	void F9();
	void F10();
	void F11();
	void F12();
	void F13();
	void F14();
	void F15();
	void F16();
	void F17();
	void F18();
	void F19();
	void F20();
	void F21();
	void F22();
	void F23();
	void F24();
	void F25();
	void F26();
	void F27();
	void F28();

	void a();
	void b();
	void c();
	void d();
	void e();
	void f();
	void g();
	void h();
	void j();
	void k();
	void i();
	void l();
	void m();

	void n();
	void o();

	void p();
	void q();
	void r();

};