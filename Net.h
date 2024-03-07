#ifndef NET_H
#define NET_H

#include <list>
#include "NetworkItem.h"
#include <iostream>
#include <ostream>
#include <cstdlib>
using namespace std;

#include "IP.h"

class Net : public NetworkItem
{
    list<NetworkItem *> NetItemList;
    list<IP> IPList;

public:
    /**
     * Default constructor of Net class
    */
    Net()
    {
        this->init_IPs();
    }
    /**
     * Constructor of Net class
     * @param name to be passed to NetworkItem constructor
     * @param ip to be passed to NetworkItem constructor
     * @see NetworkItem(const char *name, IP ip)
    */
    Net(const char *name, IP ip) : NetworkItem(name, ip)
    {
        this->init_IPs();
    }
    /**
     * Copy constructor of Net object calls NetworkItem copy constructor
    */
    Net(const Net &o) : NetworkItem(o)
    {
    }
    /**
     * Destructor of Net object
    */
    ~Net() {}

    Net &operator=(const Net &r);

    void setNetItemList(list<NetworkItem *> o);
    void setIPList(list<IP> o);
    list<NetworkItem *> getNetItemList();
    list<IP> getIPList();

    bool AddCopy(const NetworkItem *item);
    bool Add(NetworkItem *item);
    bool remove(const IP ipremove);
    void init_IPs();

    virtual void Print() const;
    void Print(const char *s) const;
    virtual int Size() const;
    virtual Net *clone() const;
};

#endif