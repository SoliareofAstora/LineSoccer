#include <string>
#include <iostream>
#include "stack.h"

static void out(std::string message)
{
	std::cerr << message;
}

static void out(int number)
{
	std::cerr << std::to_string(number);
}
static void outln()
{
	std::cerr << std::endl;
}
static void outln(std::string message)
{
	std::cerr << message << std::endl;
}
static void outtab(std::string message)
{
	std::cerr <<"\t"<< message << std::endl;
}
static void out(stack<uint8_t> *t)
{
	while (t->empty())
	{
		std::cerr << t->pop() << " ";
	}
	std::cerr << std::endl;
}
static void out(stack<int> &t)
{
	while (t.empty())
	{
		std::cerr << t.pop() << " ";
	}
	std::cerr << std::endl;
}