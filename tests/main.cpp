#include <iostream>
#include <cmath>
extern "C" {
    #include <bbio.h>
    #include <stdio.h>
}
using namespace std;
int main(int argc, char **argv) {
  cout << "started" << endl;
  exportGpio("P8_3");
  cout << "exported" << endl;
  digitalMode("P8_3", OUTPUT);
  cout << "mode = out" << endl;
  while(true){
    digitalWrite("P8_3", HIGH);
    cout << "high" << endl;
    sleep(1);
    digitalWrite("P8_3", LOW);
    cout << "low" << endl;    
    sleep(1);
  }
  
  unexportGpio("P8_3");
   cout << "unexported" << endl;
  
  
  
  return 0;
}
