#pragma once
#include "Customer.h"
#include "SqliteConnection.h"
#include <list>
using namespace Sqlite;
using namespace Models;
namespace Repositories
{
	class CustomerRepository
	{
	private:
		SqliteConnection* conn;
	public:
		CustomerRepository(SqliteConnection* conn);
		~CustomerRepository();
		void Add(Customer *c);
		void Edit(Customer* c);
		void Delete(int id);
		list<Customer*>* GetAll();
		Customer* GetById(int id);
	};
}

