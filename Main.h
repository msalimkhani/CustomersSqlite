#pragma once
#ifndef MAIN_H
#define MAIN_H
#include "includes.h"
using namespace Repositories;
namespace Customers
{
	class Main
	{
	public:
		Main();
		static void printList(list<Customer*> *g);
		~Main();

	private:

	};
}
#endif // !MAIN_H
