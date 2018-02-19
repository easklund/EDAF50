#include <string>
#include "nameserverinterface.h"

class UMNS : public NameServerInterface
{

public:
    UMNS();
    void insert(const HostName&, const IPAddress&) override;
    bool remove(const HostName&) override;
    IPAddress lookup(const HostName&) const override;
};