#include "CustomerRepository.h"
#include <string>
list<Customer*>* customers;
static int callback(void* NotUsed, int argc, char** argv, char** azColName)
{
	Models::Customer* temp;
	temp = new Models::Customer();
	temp->setCustomerId(atoi(argv[0]));
	temp->setCustomerName(argv[1]);
	temp->setNationalCode(atol(argv[2]));
	temp->setCustomerEmail(argv[3]);
	customers->push_back(temp);
	return 0;
}
Repositories::CustomerRepository::CustomerRepository(SqliteConnection* conn)
{
	this->conn = conn;

}

Repositories::CustomerRepository::~CustomerRepository()
{
	delete customers;
	delete conn;
}

void Repositories::CustomerRepository::Add(Customer* c)
{
	string sql = "INSERT INTO Customer (CustomerId, FullName, NationalCode, Email)"\
		"VALUES (" + to_string(c->getCustomerId()) + ", '" + c->getCustomerName() + "', " + to_string(c->getNationalCode()) + ", '" + c->getCustomerEmail() + "');";
	conn->open();
	conn->execute(sql, "Data Insert Success.", callback);
	conn->close();
}

void Repositories::CustomerRepository::Edit(Customer* c)
{
	string sql =
		"UPDATE Customer "\
		"SET CustomerId = " + to_string(c->getCustomerId()) + \
		", FullName = '" + c->getCustomerName() + \
		"', NationalCode = " + to_string(c->getNationalCode()) + \
		", Email = '" + c->getCustomerEmail() + \
		"' WHERE CustomerId = " + to_string(c->getCustomerId()) + ";";
	conn->open();
	conn->execute(sql, "Data Update Success.", callback);
	conn->close();
}

void Repositories::CustomerRepository::Delete(int id)
{
	string sql = "DELETE FROM Customer WHERE CustomerId = " + to_string(id);
	conn->open();
	conn->execute(sql, "Data Remove Success.", callback);
	conn->close();
}

list<Customer*>* Repositories::CustomerRepository::GetAll()
{
	delete customers;
	customers = new list<Customer*>();
	customers->erase(customers->begin(), customers->end());
	conn->open();
	conn->execute("SELECT * from Customer", "Data Recived.", callback);
	conn->close();
	return customers;
}

Customer* Repositories::CustomerRepository::GetById(int id)
{
	delete customers;
	customers = new list <Customer*>();
	string sql = "SELECT * FROM Customer WHERE CustomerId = " + to_string(id);
	conn->open();
	conn->execute(sql, "Data Recive Success.", callback);
	conn->close();
	return customers->front();
}
