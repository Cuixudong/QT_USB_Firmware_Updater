#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>
#include <QFileDialog>
#include "qdebug.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum
{
    SERIAL_PORT_STATE_DISABLE = 1,
    SERIAL_PORT_STATE_ENABLE,
}SerialPortState;

enum
{
    UPDATE_IDLE = 0,//空闲状态
    UPDATE_ID_OK = 1,//连接确认ID
    UPDATE_WAIT_CONF = 2,//等待固件确认
    UPDATE_FINISH = 3,
}UpdateState;

#ifndef uint8_t
#define uint8_t unsigned char
#endif
#ifndef uint16_t
#define uint16_t unsigned short
#endif
#ifndef uint32_t
#define uint32_t unsigned int
#endif


#define MAX_FRAME_LENGTH (256+6)        //最大帧长度

#define MIN_FRAME_LENGTH  5             //最小帧长度
#define BUF_SIZE MAX_FRAME_LENGTH

//传输帧对象
typedef struct
{
    uint8_t Device_Address;     //设备地址
    uint8_t Function_Type;      //帧功能
    uint8_t Sequence;           //帧序列
    uint8_t Data_Length;        //有效数据长度
    uint8_t *Data;              //数据
    uint16_t Checksum;          //校验值
} TransportProtocol_Typedef;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool SendFOCData(QByteArray buf);
    uint16_t Checksum_Sum(uint8_t* buf,uint16_t len);
    void SendUpdateData(uint8_t* buf,uint16_t len);
    void FormatUpdateDate(int Device_Address,int Function_Type,int Sequence,uint8_t* buf,uint16_t len);
    QByteArray FirmwareArray;
    int FirmwarePackNum,CurPackNum,ConfPackNum;
    int UpdateState;
    uint8_t TransportProtocolBuf[BUF_SIZE];
    uint8_t ReciveBuf[BUF_SIZE];
    void HandleUpdate(uint8_t* buf,uint16_t len);
    QTimer *timer;

    TransportProtocol_Typedef TransportProtocol;

private slots:
    void on_horizontalSlider_valueChanged(int value);
    void on_horizontalSlider_2_valueChanged(int value);
    void on_horizontalSlider_3_valueChanged(int value);
    void serialPortReadyRead();

    void on_pushButton_RefreshSerialPorts_clicked();

    void on_comboBox_SerialPorts_currentIndexChanged(int index);

    void on_pushButton_UpdateFirmware_clicked();

    void on_pushButton_SelectFirmware_clicked();

    void on_pushButton_Start_clicked();
    void onTimeout();

    void on_pushButton_Stop_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort * serialPort;

};
#endif // MAINWINDOW_H
