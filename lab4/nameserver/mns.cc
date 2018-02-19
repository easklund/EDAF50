#include <string>
#include "nameserverinterface.h"
#include "mns.h"
#include <iostream>
#include <algorithm>
#include <map>

MNS::MNS() {}

/*
 * Insert a name/address pair. Does not check if the name
 * or address already exists.
 */
void MNS::insert(const HostName& hn, const IPAddress& ip) {
  map[hn] = ip;
}

/*
 * Remove the pair with the specified host name. Returns true
 * if the host name existed and the pair was removed, false
 * otherwise.
 */
bool MNS::remove(const HostName& hn) {
  if(map.erase (hn) > 0){
    return true;
  }
  return false;
}

/*
 * Find the IP address for the specified host name. Returns
 * NON_EXISTING_ADDRESS if the host name wasn't in the name
 * server.
 */
IPAddress MNS::lookup(const HostName& hn) const {
  std::map<HostName, IPAddress>::iterator it;
  it = map.find(hn);
  if(it != map.end()){
    return it->second;
  }else{
    return NON_EXISTING_ADDRESS;
  }
}
