#include "IP.h"
#include "Net.h"
#include "NetworkItem.h"
#include "PC.h"
#include <iostream>
using namespace std;

int main()
{
    Net root("root", IP(10, 1, 3, 1));
    PC *pc = new PC("pc", IP());
    root.Add(pc);
    Net *nodo1 = new Net("node1", IP());

    for (int i = 0; i < 5; i++)
    {
        PC *pc = new PC("pc1", IP());
        nodo1->Add(pc);
    }
    Net *nodo2 = new Net("node2", IP());
    for (int i = 0; i < 5; i++)
    {
        PC *pc = new PC("pc2", IP());
        nodo2->Add(pc);
    }
    nodo1->AddCopy(nodo2);
    root.Add(nodo1);
    root.AddCopy(nodo2);
    root.Add(nodo2);
    root.Print("");
    cout << "Net size before removing object = " << root.Size() << endl;
    root.remove(pc->getIP());
    root.Print("");
    cout << "Net size after removing object= " << root.Size() << endl;
}