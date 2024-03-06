using namespace std;
#include <iostream>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>

#include "IP.h"
#include "NetworkItem.h"
#include "PC.h"

#include "Net.h"
#include <random>

/**
 * Setter of NetItemList
 * @param o is the list of NetworkItem to be assigned to NetItemList
*/
void Net::setNetItemList(list<NetworkItem *> o)
{
    this->NetItemList = o;
}
/**
 * Setter of IPList
 * @param o is the list of IP to be assigned to IPList
*/
void Net::setIPList(list<IP> o)
{
    this->IPList = o;
}
/**
 * Getter of NetItemList
 * @return NetItemList
*/
list<NetworkItem *> Net::getNetItemList()
{
    return this->NetItemList;
}
/**
 * Getter of IPList
 * @return IPList
*/
list<IP> Net::getIPList()
{
    return this->IPList;
}

/**
 * Overloading of assignment operator
 * @param r Net object
 * @return a pointer to this parent object if r is not the same of this, else returns a pointer to this object
*/
Net &Net::operator=(const Net &r)
{
    if (&r != this)
    {
        this->NetworkItem::operator=(r);
    }
    return *this;
}

/**
 * Function that Adds to NetItemList a copy of the item passed.
 * From the IPList of the Network one Ip is assigned to the copy of the item
 * @param item: NetworkItem to be copied in NetItemList
 * @return true if the operation goes well, else otherwise
*/
bool Net::AddCopy(const NetworkItem *item)
{
    if (IPList.size() == 0)
        return false;
    auto tempit = IPList.end();
    IP tempip = *tempit;
    IPList.pop_back();

    NetItemList.push_back(item->clone());
    return true;
}
/**
 * Function that Adds to NetItemList the item passed.
 * From the IPList of the Network one Ip is assigned to the item
 * @param item: NetworkItem to be put in NetItemList
 * @return true if the operation goes well, else otherwise
*/
bool Net::Add(NetworkItem *item)
{
    if (IPList.size() == 0)
        return false;
    auto tempit = IPList.end();
    IP tempip = *tempit;
    IPList.pop_back();

    NetItemList.push_back(item);
    return true;
}

/**
 * Removes an item from NetItemList using IP as comparison
 * @param ipremove: IP used for searching the object
 * @return true if the operation goes well, else othewise
*/
bool Net::remove(const IP ipremove)
{
    bool found = false;
    if (NetItemList.size() == 0)
        return false;
    for (auto itr = NetItemList.begin(); itr != NetItemList.end(); /*nothing*/)
    {
        if ((*itr)->getIP() == ipremove)
        {
            itr = NetItemList.erase(itr);
            found = true;
        }
        else
        {
            ++itr;
        }
    }
    if (found)
    {
        IPList.push_back(ipremove);
    }
    return found;
}
/**
 * initialize initial IPList
 * IPs inside a Net are randomically assigned starting from the a set of possible Ips.
 * In fact, the last part of the Ip is randomically assigned to the IPs connected to the net, while the first part are fixed
 * The Net Ip has as host (last element of IP) a 0.
 * For testing purposes, I limited the possible IPs to 30 addresses
*/
void Net::init_IPs()
{
    
    // Limiting number of IPs for testing purposes
    const int n_ips = 30;
    int newip[4];
    this->m_ip.getip()[3] = 0;
    for(int i = 0; i < 3; i++){
        newip[i] = this->m_ip.getip()[i]; 
    }
    int host[n_ips];
    std::default_random_engine generator(10);
    for (int i = 0; i < n_ips; i++)
    {
        host[i] = i;
    }
    
    std::shuffle(host, host + n_ips, generator);
    for (int i = 0; i < n_ips; i++)
    {
        newip[3] = host[i];
        IPList.push_back(IP(newip));
    }
}

/**
 * Overriding of Print() function
*/
void Net::Print() const
{
    NetworkItem::Print();
    cout << "Available IPs: ";
    for (const auto &tempIP : this->IPList)
    {
        tempIP.Print();
        cout << " - ";
    }
    cout << "Items Connected: ";
    for (const auto &tempNet : this->NetItemList)
    {
        tempNet->Print();
        cout << " - ";
    }
}

/**
 * Overload of Print() function, adding a string before the classical Print implementation
*/
void Net::Print(const char *s) const
{
    cout << s;
    this->Print();
}

/**
 * Overriding of Size function
 * @return size of the Net memory occupation
*/
int Net::Size() const
{
    int sum = 0;
    for (const auto &tempNet : this->NetItemList)
    {
        int sz = tempNet->Size();
        sum += sz;
    }
    return sum;
}

/**
 * Implementation of clone operator
*/
Net *Net::clone() const
{
    return new Net(*this);
}