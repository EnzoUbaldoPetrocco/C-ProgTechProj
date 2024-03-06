#ifndef IP_H
#define IP_H
#include <ostream>

/**
 * IP class that represent an ip address
*/
class IP
{
    /**
     * member ip: ip are usually represented as "x.x.x.x" where x are integers
     * from 0 to 255.
    */
    int ip[4];

public:
    IP();
    IP(int *newip);
    IP(const IP &);
    IP(int a, int b, int c, int d);
    ~IP();
    void setip(int *newip);
    int *getip();
    void Print() const;
    friend bool operator==(const IP &o, const IP &ob);
    friend std::ostream &operator<<(std::ostream &os, const IP &r);
};

#endif
