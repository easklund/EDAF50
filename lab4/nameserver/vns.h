#include <string>
#include <iostream>
#include <vector>
#include "nameserverinterface.h"

class VNS : public NameServerInterface
{

public:
    VNS();
    void insert(const HostName&, const IPAddress&) override;
    bool remove(const HostName&) override;
    IPAddress lookup(const HostName&) const override;
private:
    std::vector<std::pair<HostName , IPAddress>> v;
};
