using namespace std;
#include <iostream>
#include "NetworkItem.h"
#include "PC.h"

/**
 * Overloading of assignment operator
*/
PC &PC::operator=(const PC &r)
{
    if (&r != this)
    {
        this->NetworkItem::operator=(r);
    }
    return *this;
}

/**
 * Setter of memory and size
 * @param newmem is the new value of mem
 * @param newsize is the new value of size
*/
void PC::setMem(int *newmem, int newsize)
{
    mem = newmem;
    size = newsize;
}
/**
 * Getter of mem member
 * @return mem
*/
int *PC::getMem()
{
    return mem;
}
/**
 * Getter of size member
 * @return size
*/
int PC::getSize()
{
    return size;
}

/**
 * Overriding of Print function
*/
void PC::Print() const
{
    NetworkItem::Print();
}
/**
 * Overloading of Print() function
 * @param s string to be printed before calling Print()
*/
void PC::Print(const char *s) const
{
    cout << s;
    this->Print();
}

/**
 * Overriding of Size function
 * @return sum of mem in PC
*/
int PC::Size() const
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += mem[i];
    }
    return sum;
}

/**
 * Clone operator
*/
PC *PC::clone() const
{
    return new PC(*this);
}