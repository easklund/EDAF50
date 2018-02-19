#include <string>
#include "nameserverinterface.h"
#include "mns.h"


MNS::MNS() {}

/*
 * Insert a name/address pair. Does not check if the name
 * or address already exists.
 */
void MNS::insert(const HostName& hn, const IPAddress& ip) {

}

/*
 * Remove the pair with the specified host name. Returns true
 * if the host name existed and the pair was removed, false
 * otherwise.
 */
bool MNS::remove(const HostName& hn) {

}

/*
 * Find the IP address for the specified host name. Returns
 * NON_EXISTING_ADDRESS if the host name wasn't in the name
 * server.
 */
IPAddress MNS::lookup(const HostName& hn) const {

}
