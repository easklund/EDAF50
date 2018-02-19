#include <string>
#include "nameserverinterface.h"
#include "vns.h"

#include <iostream>     // std::cout
#include <algorithm>    // std::find_if
#include <vector>       // std::vector


VNS::VNS() {}


/*
 * Insert a name/address pair. Does not check if the name
 * or address already exists.
 */
void VNS::insert(const HostName& hn, const IPAddress& ip){
  v.push_back(std::make_pair(hn, ip));
}

/*
 * Remove the pair with the specified host name. Returns true
 * if the host name existed and the pair was removed, false
 * otherwise.
 */
bool VNS::remove(const HostName& hn) {
  auto it = remove_if (v.begin(), v.end(),
    [&hn](const std::pair<HostName, IPAddress>& p){
      return p.first == hn;
    }
  );
  if(it != v.end()){
    v.erase(it);
  }
}

/*
 * Find the IP address for the specified host name. Returns
 * NON_EXISTING_ADDRESS if the host name wasn't in the name
 * server.
 */
IPAddress VNS::lookup(const HostName& hn) const{
  auto it = std::find_if (v.begin(), v.end(),
    [hn](std::pair<HostName, IPAddress> p){
      return hn == p.first;
    }
  );
}
