#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTMLClasses.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace cgicc;

int main() {
  Cgicc formData;

  cout << "Content-type:text/html\r\n\r\n"
       << "<html>\n"
       << "<head>\n"
       << "<title>Using GET and POST Methods</title>\n"
       << "</head>\n"
       << "<body>\n";

  form_iterator fi = formData.getElement("first_name");
  if (!fi->isEmpty() && fi != (*formData).end()) {
    cout << "First name: " << **fi << endl;
  } else {
    cout << "No text entered for first name" << endl;
  }

  cout << "<br/>\n";
  fi = formData.getElement("last_name");
  if (!fi->isEmpty() && fi != (*formData).end()) {
    cout << "Last name: " << **fi << endl;
  } else {
    cout << "No text entered for last name" << endl;
  }

  cout << "<br/>\n"
       << "</body>\n"
       << "</html>\n";
}
