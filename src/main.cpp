#include "mbed.h"
#include "bamocar-can.h"

using namespace std;
 
Ticker ticker;
 
void send() {
    printf("send()\r\n");
    
}
 
int main() {
    ticker.attach(&send, 2);

    while(1) {
        printf("loop wait()\r\n");
        
        wait(0.5);
    }
}