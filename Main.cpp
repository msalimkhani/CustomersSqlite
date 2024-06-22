#include "Main.h"
//static int callback(void* NotUsed, int argc, char** argv, char** azColName)
//{
//	return 0;
//}
namespace Customers
{
	Main::Main()
	{
		Sqlite::SqliteConnection* conn = new Sqlite::SqliteConnection("customers.db");
		CustomerRepository* repo = new CustomerRepository(conn);
		cout << conn->GetDbName() << endl;
		list<Models::Customer*>* ls = repo->GetAll();
		Customers::Main::printList(ls);
		/*conn->open();
		conn->execute("CREATE TABLE Customer(\
            CustomerId		int				NOT NULL,\
            FullName		nvarchar(350)	NOT NULL,\
            NationalCode	bigint			NOT NULL,\
            Email			nvarchar(450)	NULL\
        )", "Table Create Successfully", callback);
		conn->close();*/
		
		/*Customer* c1 = new Customer();
		c1->setCustomerId(2);
		c1->setNationalCode(125356458);
		c1->setCustomerName("edited");
		c1->setCustomerEmail("lihiuluih");
		repo->Edit(c1);*/
		/*list<Models::Customer*>* ls = repo->GetAll();
		Customers::Main::printList(ls);
		repo->Delete(5);
		ls = repo->GetAll();
		Customers::Main::printList(ls);*/
		/*Customer* c = repo->GetById(5);
		cout << *c << endl;*/
	}

	Main::~Main()
	{
	}
	void Main::printList(list<Customer*>* g)
	{
		list<Customer*>::iterator it;
		for (it = g->begin(); it != g->end(); ++it)
			cout << **it << endl;
	}
}
int main()
{
	Customers::Main* m = new Customers::Main();

	return 0;
}