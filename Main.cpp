#include "Main.h"
#include "SqLiteHelper.h"
namespace Customers
{
	Main::Main()
	{
        SqLite::SqLiteHelper* sql = SqLite::SqLiteHelper::getInstance();
        list<Models::Customer> ls = sql->Select();
        Customers::Main::printList(ls);
        /*Customer* c1 = new Customer();
        c1->setCustomerId(2);
        c1->setNationalCode(1361234567);
        c1->setCustomerName("mahdi moinifar");
        c1->setCustomerEmail("moein@outlook.com");
        sql->Insert(c1);*/
        ls = sql->Select();
        Customers::Main::printList(ls);
	}

	Main::~Main()
	{
	}
    void Main::printList(list<Customer> g)
    {
        list<Customer>::iterator it;
        for (it = g.begin(); it != g.end(); ++it)
            cout << *it << endl;
    }
}
int main()
{
    Customers::Main* m = new Customers::Main();
    
    return 0;
}