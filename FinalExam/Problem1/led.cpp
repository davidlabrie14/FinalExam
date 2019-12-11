#include <iostream>         // for the input/output
#include <stdlib.h>         // for the getenv call
#include <sys/sysinfo.h>    // for the system uptime call
#include <cgicc/Cgicc.h>    // the cgicc headers
#include <cgicc/CgiDefs.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#include <unistd.h>
#include <string.h>
#include "GPIO.h"
#define LED_GPIO "/sys/class/gpio/gpio60/"
using namespace std;

using namespace cgicc;

void readGPIO(string filename, string value){
   fstream fs;
   string path(LED_GPIO);
   fs.open((path + filename).c_str(), fstream::in);
   fs >> value;
  
   fs.close();
}

int main(){
   Cgicc form;                      // the CGI form object
   string cmd;                      // the Set LED command
   string NumBlinks;
 
  
   readGPIO("direction", "in");
   // get the state of the form that was submitted - script calls itself
   bool isStatus = form.queryCheckbox("status");
   form_iterator it = form.getElement("cmd");  // the radio command
   if (it == form.getElements().end() || it->getValue()==""){
      cmd = "off";                     // if it is invalid use "off"
   }
   else { cmd = it->getValue(); }      // otherwise use submitted value
    
   form_iterator it2 = form.getElement("NumBlinks"); 
   if (it2 == form.getElements().end() || it2->getValue()==""){
      NumBlinks="0";                     // if it is invalid use "off"
   }
   else { NumBlinks = it2->getValue(); }
   char *value = getenv("REMOTE_ADDR");    // The remote IP address
 
   // generate the form but use states that are set in the submitted form
   cout << HTTPHTMLHeader() << endl;       // Generate the HTML form
   cout << html() << head() << title("CPE 422 Final Exam: Reading Digital Input") << head() << endl;
   cout << body() << h1("Reading a GPIO Pin via a Web Browser") << endl;;
   cout << "<form action=\"/cgi-bin/led.cgi\" method=\"POST\">\n";

   cout << "<input type=\"submit\" value=\"Read Switch\" </div>"<<endl;
    
   cout << "</div></form>"<<endl;
 
   // process the form data to status
   if ( == "1") cout << body() << h1("ON");              // turn on
   else if ( == "0") cout << body() << h1("OFF") ;        // turn off}             // blink LED
   else if ( != "1" |  != "0") cout << body() << h1();        // not possible
   cout << "<div> The CGI REMOTE_ADDR value is " << value << "</div>";
   cout << body() << html();
   return 0;
}

