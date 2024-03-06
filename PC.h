#ifndef PC_H
#define PC_H
using namespace std;
#include <iostream>
#include "NetworkItem.h"
#include <cstdlib>
#include <ostream>

class PC : public NetworkItem
{
    int *mem;
    int size;

public:
    /**
     * Default Constructor of PC object
     * for testing purpose we call insided this function test_initialization
     * for initializing the memory to a known value
    */
    PC()
    {
        test_initialization();
    }
        /**
     * Constructor of PC object
     * for testing purpose we call insided this function test_initialization
     * for initializing the memory to a known value
    */
    PC(const char *name, IP ip) : NetworkItem(name, ip)
    {
        test_initialization();
    }
        /**
     * Copy Constructor of PC object
     * for testing purpose we call insided this function test_initialization
     * for initializing the memory to a known value
    */
    PC(const PC &o) : NetworkItem(o)
    {
        test_initialization();
    }

    /**
     * This function initialize mem to a known set of 
     * integers for testing purposes
    */
    void test_initialization(){
        size = 2;
        mem = new int[size];
        mem[0] = 2;
        mem[1] = 3;
    }

    /**
     * Destructor of PC object
    */
    ~PC() {}

    PC &operator=(const PC &r);

    void setMem(int *newmem, int newsize);
    int *getMem();
    int getSize();

    virtual void Print() const;
    void Print(const char *s) const;
    virtual int Size() const;
    virtual PC *clone() const;
};

#endif
