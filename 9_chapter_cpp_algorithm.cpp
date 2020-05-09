//// 9_chapter_cpp_algorithm.cpp : Defines the entry point for the application.
////
//
#include "9_chapter_cpp_algorithm.h"
#include <iostream>
#include <time.h> 
#include <ppl.h>
#include <iomanip>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>

using namespace std;

//class base {
//public:
//	//string res() {
//	//	cout << "hi" << endl;
//	//	return "";
//	//}
//	string getName() const { return "A"; }
//};
//
//class derived : public base {
//public:
//	//virtual string res() {
//	//	cout << "hello" << endl;
//	//	return "";
//	//}
//	virtual std::string getName() const { return "B"; }
//};

//class A
//{
//public:
//	// note: no virtual keyword
//	virtual string getName() const { return "A"; }
//};
//
//class B : public A
//{
//public:
//	virtual std::string getName() const { return "B"; }
//};
//
//class C : public B
//{
//public:
//	virtual std::string getName() const { return "C"; }
//};
//
//class D : public C
//{
//public:
//	virtual std::string getName() const { return "D"; }
//};
//
//class base
//{
//public:
//	// note: no virtual keyword
//	string getName() const { return "A"; }
//};
//
//class dirived : public base
//{
//public:
//	virtual std::string getName() const { return "B"; }
//};
//
//int main(int argc, char** argv)
//{
//
//	dirived ceee;
//	base& rBaseeee{ ceee };
//
//
//	C c;
//	A& rBase{ c };
//	std::cout << rBase.getName() << '\n';
//
//	return 0;
//}

struct ooops : std::exception {
	const char* what() const noexcept { return "Ooops!\n"; }
};

class node {
public:
	int key;
	int value;
	node(int k, int v)
	{
		this->key = k;
		this->value = v;
	}
};

int main() {
	int8_t a = 200;
	uint8_t b = 100;
	cout << bool(a > b) << endl;
	node* n = new node(1, 2);
	//try {
		//if(1) throw ooops();
	//}
	//catch (std::exception& ex) {
	//	std::cout << ex.what();
	//}
	//int x = 5, y = 2;
	//cout << x & y << endl;
	cout << 1 << endl;

	return 0;
}








