#include <string>
#include "nameserverinterface.h"
#include <map>

class MNS : public NameServerInterface
{

public:
    MNS();
    void insert(const HostName&, const IPAddress&) override;
    bool remove(const HostName&) override;
    IPAddress lookup(const HostName&) const override;
private:
    std::map<HostName, IPAddress> map;
};
