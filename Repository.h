#pragma once
#ifndef REPOSITORY_H
#define REPOSITORY_H
#include "Customer.h"
using namespace Models;
namespace Service
{
    class Repository
    {
    private:
        list<Customer>* customers = NULL;
    public:
        list<Customer> GetAll();
        Customer GetById(int id);
        void Add(const Customer customer);
        void Delete(const Customer customer);
        void Delete(const int id);
        Repository(list<Customer>* list);
        ~Repository();
    }; // namespace Customers
}
#endif // !REPOSITORY_H

