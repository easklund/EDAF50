#include <string>
#include "nameserverinterface.h"
#include "hns.h"
#include <vector>


HNS::HNS(size_t i): s(i), hns(i){}

/*
 * Insert a name/address pair. Does not check if the name
 * or address already exists.
 */
void HNS::insert(const HostName& hn, const IPAddress& ip) {
  std::pair<HostName, IPAddress> p (hn, ip);
  size_t i = std::hash<HostName>()(hn) % s; // hash = (hash + 1) % TABLE_SIZE;
  hns[i].push_back(p);
}

/*
 * Remove the pair with the specified host name. Returns true
 * if the host name existed and the pair was removed, false
 * otherwise.
 */
bool HNS::remove(const HostName& hn) {
  size_t size = std::hash<HostName>()(hn) % s;
  auto it = std::remove_if (hns[size].begin(), hns[size].end(),
    [&hn](const std::pair<HostName, IPAddress>& p){ // Ingen aning varför const ska vara med...
      return hn == p.first;
    }
  );
  if(it != hns[size].end()){
    hns[size].erase(it);
    return true;
  }
  return false;
}

/*
 * Find the IP address for the specified host name. Returns
 * NON_EXISTING_ADDRESS if the host name wasn't in the name
 * server.
 */
IPAddress HNS::lookup(const HostName& hn) const{
  size_t size = std::hash<HostName>()(hn) % s; // hash = (hash + 1) % TABLE_SIZE;
  auto it = std::find_if (hns[size].begin(), hns[size].end(),
    [&hn](const std::pair<HostName, IPAddress>& p){ // Ingen aning varför const ska vara med...
      return hn == p.first;
    }
  );
  if(it != hns[size].end()){
    return it->second;
  }else{
    return NON_EXISTING_ADDRESS;
  }
}
