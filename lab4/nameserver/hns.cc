#include <string>
#include "nameserverinterface.h"
#include "hns.h"


HNS::HNS() {}

/*
 * Insert a name/address pair. Does not check if the name
 * or address already exists.
 */
void HNS::insert(const HostName& hn, const IPAddress& ip) {

}

/*
 * Remove the pair with the specified host name. Returns true
 * if the host name existed and the pair was removed, false
 * otherwise.
 */
bool HNS::remove(const HostName& hn) {

}

/*
 * Find the IP address for the specified host name. Returns
 * NON_EXISTING_ADDRESS if the host name wasn't in the name
 * server.
 */
IPAddress HNS::lookup(const HostName& hn) const{

}
