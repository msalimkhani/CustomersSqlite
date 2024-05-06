#pragma once
#ifndef CUSTOMERS_H
#define CUSTOMERS_H
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

namespace Models
{
    class Customer
    {
    private:
        int customerId;
        long nationalCode;
        string customerName;
        string customerEmail;
        /* data */
    public:
        //Getters
        int getCustomerId() const;
        long getNationalCode() const;
        string getCustomerName() const;
        string getCustomerEmail() const;
        //Setters
        void setCustomerId(int id);
        void setNationalCode(long code);
        void setCustomerName(string name);
        void setCustomerEmail(string email);
        bool operator==(const Customer customer) const;
        Customer(/* args */);
        ~Customer();
    };
    std::ostream& operator<<(std::ostream& out, const Customer customer);
}
#endif // !CUSTOMERS_H
