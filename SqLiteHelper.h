#pragma once
#include "sqlite3.h"
#include "Customer.h"
#include <iostream>
#include <list>
namespace SqLite
{
	class SqLiteHelper
	{
	private:
		static int callback(void* NotUsed, int argc, char** argv, char** azColName);
		SqLiteHelper();
	public:
		SqLiteHelper(const SqLiteHelper& obj) = delete;
		static SqLiteHelper* getInstance();
		list<Models::Customer> Select();
		int Insert(Models::Customer *input);
		~SqLiteHelper();
	};
}

