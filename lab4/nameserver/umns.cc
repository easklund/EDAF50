#include <string>
#include "nameserverinterface.h"
#include "umns.h"
#include <unordered_map>

UMNS::UMNS() {}

/*
 * Insert a name/address pair. Does not check if the name
 * or address already exists.
 */
void UMNS::insert(const HostName& hn, const IPAddress& ip) {
  umap.insert ( {{hn, ip}} );
}

/*
 * Remove the pair with the specified host name. Returns true
 * if the host name existed and the pair was removed, false
 * otherwise.
 */
bool UMNS::remove(const HostName& hn) {
  if(umap.erase(hn) > 0){
    return true;
  }
  return false;
}

/*
 * Find the IP address for the specified host name. Returns
 * NON_EXISTING_ADDRESS if the host name wasn't in the name
 * server.
 */
IPAddress UMNS::lookup(const HostName& hn) const {
  auto it = umap.find(hn);
  if(it != umap.end()){
    return it->second;
  }else{
    return NON_EXISTING_ADDRESS;
  }
}
