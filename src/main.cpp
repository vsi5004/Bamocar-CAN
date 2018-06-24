#include "mbed.h"
#include "bamocar-can.h"
#include "bamocar-registers.h"

using namespace std;
 
Ticker ticker;
Bamocar can;
 
void send() {
    printf("send()\r\n");
    //can.getStatus(INTVL_IMMEDIATE);
    //can.setSoftEnable(false);
    //can.getHardEnable(INTVL_IMMEDIATE);
    //can.setSoftEnable(true);
    can.setAccel();
    can.setDecel();
    //can.setSpeed(32767);

}
 
int main() {
    ticker.attach(&send, 2);

    while(1) {
        printf("loop wait()\r\n");
        can.listenCAN();
        wait(0.5);
    }
}