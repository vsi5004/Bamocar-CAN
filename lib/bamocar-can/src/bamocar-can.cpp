#include "bamocar-can.h"
#include "bamocar-registers.h"
#include "mbed.h"

/**
 * ==========
 * Bamocar
 * ==========
 */
Bamocar::Bamocar()
{
    // Do nothing
}

CAN can1(PB_8 ,PB_9 );

/**
 * ==========
 * Bamocar::startCAN
 * ==========
 */
void Bamocar::startCAN()
{
    can1.frequency(100000);
    printf("CAN init ok!\r\n");
}

/**
 * ==========
 * Bamocar::sendCAN
 * ==========
 */
void Bamocar::sendCAN(unsigned char stmp[])
{
    const char* strOut = (const char *)stmp;
    if(can1.write(CANMessage(1100, strOut, 8))) {
        printf("loop send()\r\n");
        printf("Message sent: %s\r\n", stmp);
    }
}

/**
 * ==========
 * Bamocar::listenCAN
 * ==========
 */
void Bamocar::listenCAN()
{
    unsigned char len = 5;
    unsigned char buf[5];


}

void Bamocar::getSpeed(char interval)
{
    m_data[0] = REG_N_ACTUAL;
    m_data[1] = 0x30;
    m_data[2] = interval;
    sendCAN(m_data);
}
void setSpeed(unsigned int speed)
{
}
void setTorque(unsigned int	torque)
{
}
void Bamocar::getCurrent(char interval)
{
    m_data[0] = REG_I_ACTUAL;
    m_data[1] = 0x20;
    m_data[2] = interval;
    sendCAN(m_data);
}
void getCurrentDevice(char interval)
{
}
void getMotorTemp(char interval)
{
}
void getStatus()
{
}
void setSoftEnable(bool enable)
{
}
void setHardEnable(bool enable)
{
}
