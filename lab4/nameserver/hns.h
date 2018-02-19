#include <string>
#include "nameserverinterface.h"
#include <vector>

class HNS : public NameServerInterface
{

public:
    HNS(size_t);
    void insert(const HostName&, const IPAddress&) override;
    bool remove(const HostName&) override;
    IPAddress lookup(const HostName&) const override;
private:
    size_t s;
    std::vector<std::vector<std::pair<HostName, IPAddress>>> hns;
};
