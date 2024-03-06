#include <iostream>
#include "IP.h"
#include <string>
#include "NetworkItem.h"
using namespace std;

/**
 * Default constructor of class NetworkItem
*/
NetworkItem::NetworkItem()
{
}
/**
 * Constructor of class NetworkItem
 * @param name: is the name of the network item
 * @param ip: is the ip of the network item
*/
NetworkItem::NetworkItem(const char *name, IP ip)
{
    m_ip = ip;
    ItemName = *new string(name);
}
/**
 * Copy constructor of class Network Item
 * @param o is the Network object from which we copy the object
*/
NetworkItem::NetworkItem(const NetworkItem &o)
{
    m_ip = o.m_ip;
    ItemName = o.ItemName;
}

/**
 * Destructor of the class Network Item
*/
NetworkItem::~NetworkItem()
{
}

/**
 * Getter of ItemName member
 * @return ItenName
*/
string NetworkItem::getItemName()
{
    return ItemName;
}
/**
 * Getter of IP member
 * @return m_ip member (object of class IP)
*/
IP NetworkItem::getIP()
{
    return m_ip;
}
/**
 * Setter of member ItemName
 * @param name is the ItenName new value
*/
void NetworkItem::setItemName(string &name)
{
    ItemName = name;
}
/**
 * Setter of member m_ip
 * @param ip is the new m_ip object from class IP
*/
void NetworkItem::setIP(IP &ip)
{
    m_ip = ip;
}

/**
 * Implementation of assignment operator
 * @return a pointer to this object
*/
NetworkItem &NetworkItem::operator=(const NetworkItem &n)
{
    return *this;
}

/**
 * Implementation of Print function
*/
void NetworkItem::Print() const
{
    cout << "Item name: " << ItemName << " Ip: ";
    cout << m_ip << endl;
}
