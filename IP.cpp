#include "IP.h"
#include <iostream>
#include <ostream>
#include <cstdlib>
using namespace std;


/**
 * Default IP constructor
 * ip member must be initialized randomically with values 0 <= int <= 255
 */
IP::IP()
{
    for (int i = 0; i < 4; i++)
    {
        ip[i] = rand() % 256;
    }
}
/**
 * IP constructor
 * @param newip is the new array of values of ip member
*/
IP::IP(int *newip)
{
    IP::setip(newip);
}
/**
 * IP constructor
 * @param a, b, c, d are the value with which initialize ip member
*/
IP::IP(int a, int b, int c, int d)
{
    int newip[4] = {a, b, c, d};
    IP::setip(newip);
}
/**
 * Copy constructor of class IP
 * @param o is the object with which initialize the object of class IP
*/
IP::IP(const IP &o)
{
    for (int i = 0; i < 4; i++)
    {
        ip[i] = o.ip[i];
    }
}

/**
 * Destructor of class IP
*/
IP::~IP()
{
}

/**
 * Setter of ip member of class IP
 * @param newip is an integer pointer which values can be assigned to ip if they are between 0 and 255
*/
void IP::setip(int *newip)
{
    try
    {
        for (int i = 0; i < 4; i++)
        {
            if (newip[i] >= 0 && newip[i] <= 256)
            {
                ip[i] = newip[i];
            }
            else
            {
                throw(i);
            }
        }
    }
    catch (int i)
    {
        cout << "Index " << i << "of new IP is not valid" << endl;
        ;
    }
}

/**
 * Getter of ip member from class IP
 * @return the member ip
*/
int *IP::getip()
{
    return ip;
}

/**
 * Print function of class IP
*/
void IP::Print() const
{
    for (int i = 0; i < 4; i++)
    {
        cout << ip[i];
        if (i < 3)
        {
            cout << ".";
        }
    }
}

/**
 * Implementation of operator == for comparing two IP objects
 * @param o first member of ==
 * @param ob second member of ==
 * @return true if the member ips are equal element by element, false otherwise
*/
bool operator==(const IP &o, const IP &ob)
{
    bool equal = true;
    for (int i = 0; i < 4; i++)
    {
        equal = equal && ob.ip[i] == o.ip[i];
    }
    return equal;
}

/**
 * Implementation of operator << for printing an IP objects easily
 * @param os output stream object
 * @param r IP object to print
*/
ostream &operator<<(ostream &os, const IP &r)
{
    for (int i = 0; i < 4; i++)
    {
        os << r.ip[i];
        if (i < 3)
        {
            os << '.';
        }
    }
    return os;
}