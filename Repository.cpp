#include "Repository.h"

namespace Service
{
    Repository::Repository(list<Customer>* list)
    {
        customers = list;
    }

    Repository::~Repository()
    {
    }
    list<Customer> Repository::GetAll()
    {
        return *customers;
    }
    Customer Repository::GetById(int id)
    {
        if (id <= 0)
        {
            throw invalid_argument("Customer id must be positive and unzero!");
        }
        Customer searcher;
        searcher.setCustomerId(id);
        list<Customer>::iterator it = find(customers->begin(), customers->end(), searcher);
        if (it != customers->end())
        {
            return *it;
        }
        else
        {
            throw invalid_argument("Customer Not Found!");
        }
    }
    void Repository::Add(const Customer customer)
    {
        customers->push_back(customer);
    }
    void Repository::Delete(const Customer customer)
    {
        customers->remove(customer);
    }
    void Repository::Delete(const int id)
    {
        customers->remove(GetById(id));
    }
}