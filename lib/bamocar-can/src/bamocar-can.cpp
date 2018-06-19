#include "bamocar-can.h"
#include "bamocar-registers.h"

/**
 * ==========
 * Bamocar
 * ==========
 */
Bamocar::Bamocar()
{
    // Do nothing
}

MCP_CAN CAN(9);

/**
 * ==========
 * Bamocar::setupCAN
 * ==========
 */
void Bamocar::setupCAN(uint16_t txID, uint16_t rxID, uint8_t baudrate)
{
    m_txID = txID;
    m_rxID = rxID;
    m_baudrate = baudrate;
}

/**
 * ==========
 * Bamocar::startCAN
 * ==========
 */
void Bamocar::startCAN()
{
    while (CAN_OK != CAN.begin(m_baudrate))
    {
        printf("CAN BUS Shield init fail\r\n");
        printf("Init CAN BUS Shield again\r\n");
        delay(100);
    }
    printf("CAN BUS Shield init ok!\r\n");
}

/**
 * ==========
 * Bamocar::sendCAN
 * ==========
 */
void Bamocar::sendCAN(unsigned char stmp[])
{
    CAN.sendMsgBuf(m_rxID, 0, 0x03, stmp);
    Serial.println("Sent message");
    for (int x = 0; x < 3; x++)
    {
        Serial.print("0x");
        Serial.print(stmp[x], HEX);
        Serial.print("\t");
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


    if (CAN_MSGAVAIL == CAN.checkReceive()) // check if data coming
    {
        CAN.readMsgBuf(&len, buf); // read data,  len: data length, buf: data buf

        unsigned int canId = CAN.getCanId();

        Serial.println("-----------------------------");
        Serial.print("Get data from ID: ");
        Serial.println(canId, HEX);

        for (int x = 0; x < 5; x++)
        {
            Serial.print("0x");
            Serial.print(buf[x], HEX);
            Serial.print("\t");
        }
        Serial.println();
    }
}

void Bamocar::getSpeed(char interval)
{
    m_data[0] = REG_N_ACTUAL;
    m_data[1] = 0x30;
    m_data[2] = interval;
    sendCAN(m_data);
}
void setSpeed(char32_t speed)
{
}
void setTorque(char32_t torque)
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
