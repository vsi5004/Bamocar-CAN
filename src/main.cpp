#include "mbed.h"
 
#include <string>
using namespace std;
 
Ticker ticker;
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
 
CAN can1(PB_8 ,PB_9 );
CAN can2(PB_5, PB_6 ); // (rd, td)
 
string strMsg = "HallCan";
char counter = 0;
 
void send() {
    printf("send()\r\n");
    can1.frequency(100000);
    can2.frequency(100000);
    const char* strOut = (strMsg + " " + counter).c_str();;
    
    if(can1.write(CANMessage(1100, strOut, 8))) {
        printf("loop send()\r\n");
        counter++;
        printf("Message sent: %s\r\n", strOut);
        led1 = !led1;
    }
}
 
int main() {
    ticker.attach(&send, 2);
    CANMessage msg;
    while(1) {
        printf("loop wait()\r\n");
        if(can2.read(msg)) {
            printf("Message received: %c %c %c %c %c %c %c %d, from %d\r\n", msg.data[0], msg.data[1], msg.data[2], msg.data[3], msg.data[4], msg.data[5], msg.data[6], msg.data[7], msg.id);
            if(msg.id==1100)
                led2 = !led2;
            if(msg.id==1102)
                led3 = !led3;     
        }
        wait(0.5);
    }
}