#include <string>
#include "nameserverinterface.h"
#include "vns.h"

using std::pair;


VNS::VNS() {}

VNS::~VNS() {}


/*
 * Insert a name/address pair. Does not check if the name
 * or address already exists.
 */
void VNS::insert(const HostName& hn, const IPAddress& ip){

}

/*
 * Remove the pair with the specified host name. Returns true
 * if the host name existed and the pair was removed, false
 * otherwise.
 */
bool VNS::remove(const HostName& hn) {

}

/*
 * Find the IP address for the specified host name. Returns
 * NON_EXISTING_ADDRESS if the host name wasn't in the name
 * server.
 */
IPAddress VNS::lookup(const HostName& hn) const{

}
