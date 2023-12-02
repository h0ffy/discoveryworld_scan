#include <bsd/bsd.h>
#include <bsd/stdio.h>
#include <bsd/string.h>
#include <bsd/stdlib.h>
#include "config.h"
#include "output.h"
#include "misc.h"
#include "services.h"

#define SERVICE_REFERRAL(id,s,ptr_func) { id,s,ptr_func }


static struct st_service srv[MAX_SERVICES] = { 
  SERVICE_REFERRAL(0, "HTTP", &services::chk_http),
  SERVICE_REFERRAL(1, "HTTPS", &services::chk_https),
  /*{2, "FTP", &services::chk_https},
  {3, "TELNET", &services::chk_https},*/
  SERVICE_REFERRAL(4, "SSH", &services::chk_https),
  //{5, "SMTP", &services::chk_https},
  {0, NULL, NULL},
};



bool services::srvcheck(const char *ip,st_output_node *node) {
  try {
    int serviceid = config::get_servicebyport(node->port);
    
    srv[serviceid].chk_func(ip,node);
    
    if(node->status==1)
      return(true);
    
    return(false);
    
    
  }
  catch(int iResult) {
    __logging("services::srvcheck: Unknow Error");
    return(false);
  }
}


const char *services::getServiceByID(int id) {
    if(id>MAX_SERVICES)
      return(NULL);
    
    return(srv[id].name);
}
