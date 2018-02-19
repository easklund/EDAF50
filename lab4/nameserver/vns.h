#include <string>
#include "nameserverinterface.h"

class VNS : public NameServerInterface
{

public:
    VNS();
    ~VNS();
    void insert(const HostName&, const IPAddress&) override;
    bool remove(const HostName&) override;
    IPAddress lookup(const HostName&) const override;
};
