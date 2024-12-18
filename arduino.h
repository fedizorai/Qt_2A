#ifndef ARDUINO_H
#define ARDUINO_H
#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>

//8


class arduino
{
public:
    arduino();
    int connect_arduino();
    int close_adruino();
    int write_to_arduino(QByteArray);
    QByteArray read_from_arduino();
    QSerialPort* getserial();
    QString getarduino_port_name();

private:
    QSerialPort *serial;
    static const quint16 arduino_uno_vendor_id=9025;
    static const quint16 arduino_uno_producy_id=67;
    QString arduino_port_name;
    bool arduino_is_available;
    QString cap;
    QByteArray data;

};

#endif // ARDUINO_H

