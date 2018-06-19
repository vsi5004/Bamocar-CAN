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
  void setupCAN(unsigned short txID, unsigned short rxID, unsigned short baudrate);

  void startCAN();

  void getSpeed(char interval);
  void setSpeed(unsigned int	 speed);
  void setTorque(unsigned int	 torque);
  void getCurrent(char interval);
  void getCurrentDevice(char interval);
  void getMotorTemp(char interval);
  void getStatus();
  void setSoftEnable(bool enable);
  void setHardEnable(bool enable);

  void listenCAN();

private:
  /**
     * Transmit ID of motor controller
     */
  unsigned short m_txID;
  /**
     * Receive ID of motor controller
     */
  unsigned short m_rxID;
  /**
     * Buadrate of motor controller
     */
  char m_baudrate;

  unsigned char m_data [3];

  void sendCAN(unsigned char stmp[]);
};

#endif