#include "Customer.h"
namespace Models
{
    std::ostream& operator<<(std::ostream& out, const Customer customer)
    {
        out << "Id: " << customer.getCustomerId() << ", Name: " << customer.getCustomerName() << ", Code: " << customer.getNationalCode() << ", Email: " << customer.getCustomerEmail();
        return out;
    }
    Customer::Customer()
    {
        customerId = 0;
        nationalCode = 0;
    }

    Customer::~Customer()
    {
    }
    bool Customer::operator==(const Customer customer) const
    {
        return customer.customerId == getCustomerId();
    }
    int Customer::getCustomerId() const
    {
        return customerId;
    }
    void Customer::setCustomerId(int id)
    {
        customerId = id;
    }
    string Customer::getCustomerName() const
    {
        return customerName;
    }
    void Customer::setCustomerName(string name)
    {
        customerName = name;
    }
    long Customer::getNationalCode() const
    {
        return nationalCode;
    }
    void Customer::setNationalCode(long code)
    {
        nationalCode = code;
    }
    string Customer::getCustomerEmail() const
    {
        return customerEmail;
    }
    void Customer::setCustomerEmail(string email)
    {
        customerEmail = email;
    }
}

