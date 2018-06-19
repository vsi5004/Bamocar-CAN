#ifndef bamocar_can_h
#define bamocar_can_h



class Bamocar
{
public:
  Bamocar();

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