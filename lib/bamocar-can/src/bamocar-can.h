#ifndef bamocar_can_h
#define bamocar_can_h



class Bamocar
{
public:
  Bamocar();
  /**
     * Initialise the select pin, transmit id, receive id, and baudrate of the class
     * @param txID          Transmit CAN ID
     * @param rxID          Receive CAN ID
     * @param baudRate      CAN Bus baud rate
     */
  void setupCAN(uint16_t txID, uint16_t rxID, uint8_t baudrate);

  void startCAN();

  void getSpeed(uint8_t interval);
  void setSpeed(uint32_t speed);
  void setTorque(uint32_t torque);
  void getCurrent(uint8_t interval);
  void getCurrentDevice(uint8_t interval);
  void getMotorTemp(uint8_t interval);
  void getStatus();
  void setSoftEnable(bool enable);
  void setHardEnable(bool enable);

  void listenCAN();

private:
  /**
     * Transmit ID of motor controller
     */
  uint16_t m_txID;
  /**
     * Receive ID of motor controller
     */
  uint16_t m_rxID;
  /**
     * Buadrate of motor controller
     */
  uint8_t m_baudrate;

  unsigned char m_data [3];

  void sendCAN(unsigned char stmp[]);
};

#endif