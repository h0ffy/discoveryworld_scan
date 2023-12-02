#include <bsd/bsd.h>
#include <bsd/stdio.h>
#include <curl/curl.h>
#include <tinyxml2.h>
#include <assert.h>
#include <openssl/ssl.h> 
#include <mbedtls/config.h>
#include <mbedtls/net.h>
#include <mbedtls/ssl.h>
#include <mbedtls/entropy.h>
#include <mbedtls/ctr_drbg.h>
#include <mbedtls/error.h>
#include <mbedtls/certs.h>
#include "input.h"
#include "config.h"
#include "threads.h"
#include "output.h"
#include "discovery.h"
#include "net_utils.h"
#include "modules/module_ssh.h"
#include "modules/module_agent.h"
#include "modules/protocol_whois.h"
#include "misc.h"

int main(int argc, char *argv[]) {
 config *conf = new config("/home/pumu/Repository/jennycorp/jennysec/jennysec/tools/discoveryworld/discoveryworld/daemon/etc/discoveryworld.conf");
 ssh *sh = new ssh();
 whois *lwhois = new whois();
 
 printf("FASFS");
 
 tinyxml2::XMLDocument xml_doc;
 tinyxml2::XMLError xml_error;
 tinyxml2::XMLNode *xml_root,*xml_body;
 /*
 assert(argc!=2);
 
 if((xml_error = xml_doc.LoadFile(argv[1]))!=tinyxml2::XML_SUCCESS) {
     printf("Error");
     return 0;
 }
   */
  
 char *host = "216.58.210.196";
 if(ssl::testport(host,443,0)==true)
   printf("SSL OK\n");
 else
   printf("SSL NO\n");
 

 lwhois->query("216.58.210.196");
 
 
 sh->finger("192.168.15.120",22);

 printf("##### SSH #######\n");
 printf("Reply: %s\nFinger: %s\n", sh->reply, sh->cert);
 printf("#################\n\n");

 printf("##### WHOIS #######\n");
 printf("Reply: %s\n", lwhois->reply);
 printf("#################\n\n");
 
 
 
 return(0); 
}
