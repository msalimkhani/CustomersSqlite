#define _CRT_SECURE_NO_WARNINGS
#include "SqLiteHelper.h"
#include <stdio.h>
using namespace std;
list<Models::Customer> *ls;
namespace SqLite
{
	int SqLiteHelper::callback(void* NotUsed, int argc, char** argv, char** azColName)
	{
		Models::Customer* temp;
		temp = new Models::Customer();
		temp->setCustomerId(atoi(argv[0]));
		temp->setCustomerName(argv[1]);
		temp->setNationalCode(atol(argv[2]));
		temp->setCustomerEmail(argv[3]);
		ls->push_back(*temp);
		return 0;
	}
	SqLiteHelper::SqLiteHelper()
	{
		
	}
	SqLiteHelper* SqLiteHelper::getInstance()
	{
		static SqLiteHelper ins;
		return &ins;
	}
	list<Models::Customer> SqLiteHelper::Select()
	{
		ls = new list<Models::Customer>();
		ls->erase(ls->begin(), ls->end());
		sqlite3* db;
		char* zErrMsg = 0;
		int rc;
		list <Models::Customer> res;
		rc = sqlite3_open("customers.db", &db);
		if (rc)
		{
			cerr << "Cant Open database: " << sqlite3_errmsg(db) << endl;
		}
		else
		{
			cout << "Opened database sucessfully." << endl;
		}
		const char* sql = "SELECT * FROM CUSTOMER";
		rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
		if (rc != SQLITE_OK)
		{
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
		}
		else
		{
			printf("SQl exec successfully\n");
		}
		res = *ls;
		return res;
	}
	int SqLiteHelper::Insert(Models::Customer *input)
	{
		sqlite3* db;
		char* zErrMsg = 0;
		int rc;
		list <Models::Customer> res;
		rc = sqlite3_open("customers.db", &db);
		if (rc)
		{
			cerr << "Cant Open database: " << sqlite3_errmsg(db) << endl;
		}
		else
		{
			cout << "Opened database sucessfully." << endl;
		}
		char* sql = (char *) malloc(sizeof(char) * 300);
		sprintf(sql, "INSERT INTO CUSTOMER (CustomerId, CustomerName, NationalCode, CustomerEmail)"\
			"VALUES (%d, '%s', %d, '%s');", input->getCustomerId(), input->getCustomerName().c_str(), input->getNationalCode(), input->getCustomerEmail().c_str());
		rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
		if (rc != SQLITE_OK)
		{
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			return -1;
		}
		else
		{
			printf("SQl exec successfully\n");
			return 0;
		}
	}
	SqLiteHelper::~SqLiteHelper()
	{
	}
}
