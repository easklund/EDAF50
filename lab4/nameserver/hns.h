#include <string>
#include "nameserverinterface.h"

class HNS : public NameServerInterface
{

public:
    HNS();
    void insert(const HostName&, const IPAddress&) override;
    bool remove(const HostName&) override;
    IPAddress lookup(const HostName&) const override;
};
