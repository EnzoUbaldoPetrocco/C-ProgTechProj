#ifndef NETWORKITEM_H
#define NETWORKITEM_H

#include "IP.h"
#include <string>
using namespace std;

/**
 * NetworkItem class is an abstract class needed for representing
 * general objects inside networks
*/
class NetworkItem
{
protected:
    /**
     * ItemName member is a string that describes the name of the item
    */
    string ItemName;
    /**
     * m_ip is a IP object
    */
    IP m_ip;

public:
    NetworkItem();
    NetworkItem(const char *name, IP ip);
    NetworkItem(const NetworkItem &);
    virtual ~NetworkItem();
    string getItemName();
    IP getIP();
    void setItemName(string &name);
    void setIP(IP &ip);
    virtual void Print() const;
    /**
     * Pure virtual method Size
     * @return the size of the network nested in network item
    */
    virtual int Size() const = 0;
    /**
     * Pure virtual clone method
    */
    virtual NetworkItem *clone() const = 0;


    NetworkItem &operator=(const NetworkItem &n);
    //..
};

#endif
