#include "mainwindow.h"
#include "ui_mainwindow.h"

#define IS_ARM_IMX_6ULL false

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if(IS_ARM_IMX_6ULL)
    {
        this->setGeometry(0,0,QApplication::desktop()->screenGeometry().width(),QApplication::desktop()->screenGeometry().height());
        this->setWindowFlags(Qt::FramelessWindowHint);
        this->setStyleSheet("QMainWindow{background-image: url(./icon/qtbg.jpg);}");
        ui->label->setStyleSheet("QLabel{background-image: url(./icon/bilibilihead.png);}");
    }
    else
    {
        //this->setGeometry(0,0,800,480);
        this->setStyleSheet("QMainWindow{background-image: url(:/icon/qtbg.jpg);}");
        ui->label->setStyleSheet("QLabel{background-image: url(:/icon/bilibilihead.png);}");
    }

    /* 创建虚拟串口 */
    serialPort = new QSerialPort(this);

    if(IS_ARM_IMX_6ULL)
    {
        serialPort->setPortName("/dev/ttymxc2");
        serialPort->setBaudRate(115200);
        serialPort->setDataBits(QSerialPort::Data8);
        serialPort->setParity(QSerialPort::NoParity);
        serialPort->setStopBits(QSerialPort::OneStop);
        serialPort->setFlowControl(QSerialPort::NoFlowControl);
        if(!serialPort->open(QIODevice::ReadWrite))
        {
            printf("SerialPort open error!!!\n");
        }

    }

    connect(serialPort, SIGNAL(readyRead()), this, SLOT(serialPortReadyRead()));

    UpdateState = UPDATE_IDLE;
    CurPackNum = 0;
    ConfPackNum = -1;
    FirmwarePackNum = 0;
    TransportProtocol.Data = TransportProtocolBuf;
    memset(ReciveBuf,0,BUF_SIZE);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));

    timer->start(100);
}
static int count = 0;
void MainWindow::onTimeout()
{

    uint8_t FirmwareData[128];
    int i;
    //qDebug() << "hello\r\n";
    if(ReciveBuf[19] != 0)
    {
        HandleUpdate(ReciveBuf,ReciveBuf[19]);
        ReciveBuf[19] = 0;
    }

    if(UpdateState != UPDATE_IDLE)
    {
        if((UpdateState == UPDATE_ID_OK)||(UpdateState == UPDATE_WAIT_CONF))
        {
            if(ConfPackNum == CurPackNum)
            {
                CurPackNum ++;
                CurPackNum %= 256;
                count ++;
                if(count == FirmwarePackNum)
                {
                    UpdateState = UPDATE_IDLE;
                    ui->textEdit->append(QString("%1").arg("完成固件更新"));
                }
            }
            ui->textEdit->append(QString("%1%2").arg("数据帧：").arg(count));
            for(i=0;i<128;i++)
            {
                if(count * 128 + i < FirmwareArray.length())
                {
                    FirmwareData[i] = (uint8_t)FirmwareArray.at(count * 128 + i);
                }
            }
            FormatUpdateDate(1,1,CurPackNum%256,FirmwareData,128);
        }
    }
}

void MainWindow::HandleUpdate(unsigned char *buf, unsigned short len)
{
    if(len >= 5)
    {
        int crc = Checksum_Sum(buf,len - 1);
        if(crc == buf[len-1])
        {
            ui->textEdit->append("解包正确");

            if(*(buf + 1) == 0x05)
            {
                char bufm[120];
                sprintf(bufm,"V%.1f ID:0x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",\
                        (float)(*(buf + 4))/10,\
                        *(buf + 5),*(buf + 6),*(buf + 7),*(buf + 8),
                        *(buf + 9),*(buf + 10),*(buf + 11),*(buf + 12),
                        *(buf + 13),*(buf + 14),*(buf + 15),*(buf + 16));
                ui->label_Version->setText(QString((const char *)bufm));
                ui->textEdit->append("ID...");
                if(UpdateState == UPDATE_IDLE)
                {
                    UpdateState = UPDATE_ID_OK;
                    CurPackNum = 0;
                    count = 0;
                    ui->textEdit->append("ID确认状态");
                }
            }
            else if(*(buf + 1) == 0x01)
            {
                ui->textEdit->append("Conf...");
                ConfPackNum = *(buf + 2);
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::SendFOCData(QByteArray buf)
{
    /* 发送数据 */
    serialPort->write(buf);
    return true;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->label_8->setText(QString("%1 %2").arg("速度:").arg(value));
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    ui->label_9->setText(QString("%1 %2").arg("角度:").arg(value));
}

void MainWindow::on_horizontalSlider_3_valueChanged(int value)
{
    ui->label_10->setText(QString("%1 %2").arg("幅度:").arg(value));
}

void MainWindow::serialPortReadyRead()
{
    /* 读取下位机数据 */
    QByteArray buf = serialPort->readAll();
    int i;
    for(i=0;i<buf.length();i++)
    {
        ReciveBuf[i] = (uint8_t)buf.at(i);
    }
    ReciveBuf[19] = buf.length();
}

void MainWindow::on_pushButton_RefreshSerialPorts_clicked()
{
    if (true)
    {
        ui->comboBox_SerialPorts->clear();
        for (QSerialPortInfo port : QSerialPortInfo::availablePorts())
        {
            if ((port.vendorIdentifier() == 1155)&&(port.productIdentifier() == 22336))
            {
                /* 更新虚拟串口号 */
                ui->comboBox_SerialPorts->addItem(port.portName());

                ui->textEdit->append(QString("%1%2").arg("搜索到串口：").arg(port.portName()));
            }
        }
    }
}

void MainWindow::on_comboBox_SerialPorts_currentIndexChanged(int index)
{
    (void)index;
    if((ui->comboBox_SerialPorts->currentText() != NULL)&&(ui->comboBox_SerialPorts->currentText() != ""))
    {
        /* 设置虚拟串口号 */
        serialPort->setPortName(ui->comboBox_SerialPorts->currentText());

        ui->textEdit->append(QString("%1%2").arg("当前串口号设置为：").arg(ui->comboBox_SerialPorts->currentText()));
    }
    else
    {
        ui->textEdit->append(QString("%1").arg("未找到可用串口，请检查连接"));
    }
}

void MainWindow::on_pushButton_UpdateFirmware_clicked()
{
    uint8_t buf[1];buf[0] = 0x55;
    if(!serialPort->isOpen())
    {
        serialPort->setBaudRate(115200);
        serialPort->setDataBits(QSerialPort::Data8);
        serialPort->setParity(QSerialPort::NoParity);
        serialPort->setStopBits(QSerialPort::OneStop);
        serialPort->setFlowControl(QSerialPort::NoFlowControl);
        if((serialPort->open(QIODevice::ReadWrite) == true))
        {
            ui->textEdit->append(QString("%1").arg("虚拟串口打开成功"));
            ui->label_SerialPortState->setText("已连接");
            FormatUpdateDate(1,5,27,buf,1);

//            serialPort->close();
//            ui->label_SerialPortState->setText("已断开");
        }
        else
        {
            ui->label_SerialPortState->setText("连接失败");
        }
    }
    else
    {
        FormatUpdateDate(1,5,27,buf,1);
    }
}

uint16_t MainWindow::Checksum_Sum(uint8_t* buf,uint16_t len)
{
    uint8_t check = 0;
    while(len--)
    {
        check += *buf++;
    }
    check = 256 - check % 256;
    return (check) & 0xff;
}

void MainWindow::SendUpdateData(unsigned char *buf, unsigned short len)
{
    QByteArray array;
    array.resize(len);

    int i;

    for(i=0;i<len;i++)
    {
        array[i] = *(buf + i);
        //ui->textEdit->append(QString().sprintf("%d",(uint8_t)array[i]));
        //ui->textEdit->moveCursor(QTextCursor::End);
        //ui->textEdit->append(QString().sprintf("0x%02x  ",buf[i]));
    }
    if(serialPort->isOpen())
    {
        serialPort->write(array);
    }
    else
    {
        ui->textEdit->append(QString("%1").arg("虚拟串口未打开"));
    }
}

void MainWindow::FormatUpdateDate(int Device_Address, int Function_Type, int Sequence, unsigned char *buf, unsigned short len)
{
    TransportProtocol.Device_Address = Device_Address;
    //01 数据 05 查询版本
    TransportProtocol.Function_Type = Function_Type;
    TransportProtocol.Sequence = Sequence;

    //TransportProtocol.Data = buf;
    TransportProtocol.Data_Length = len;
    TransportProtocol.Checksum = 0;

    TransportProtocol.Data[0] = TransportProtocol.Device_Address;
    TransportProtocol.Data[1] = TransportProtocol.Function_Type;
    TransportProtocol.Data[2] = TransportProtocol.Sequence;
    if(Function_Type == 5)
    {
        TransportProtocol.Data_Length = 1;
    }
    else
    {
        TransportProtocol.Data_Length = len;
    }
    TransportProtocol.Data[3] = TransportProtocol.Data_Length;
    memcpy(&TransportProtocol.Data[4],buf,len);

    if(Function_Type == 5)
    {
        TransportProtocol.Data[3] = TransportProtocol.Data_Length;
        TransportProtocol.Data[4] = 0x55;
    }

    uint16_t check_sum = Checksum_Sum(TransportProtocol.Data,TransportProtocol.Data_Length + 4);
    if(check_sum <= 255)
    {
        TransportProtocol.Data[4 + TransportProtocol.Data_Length] = check_sum;
    }
    else
    {
        TransportProtocol.Data[4 + TransportProtocol.Data_Length + 1] = check_sum % 256;
        TransportProtocol.Data[4 + TransportProtocol.Data_Length] = check_sum / 256;
    }

    SendUpdateData(TransportProtocol.Data,(check_sum <= 255) ? (4 + TransportProtocol.Data_Length + 1) : (4 + TransportProtocol.Data_Length + 2));
}

void MainWindow::on_pushButton_SelectFirmware_clicked()
{
    static int i = 0;
    uint8_t buf[5];
    buf[0] = 0x55;
    buf[1] = 0x52;
    buf[2] = 0x21;
    buf[3] = 0x77;
    buf[4] = 0xFF;
/*
0x01
0x05
0x00
0x01
0x55
0xa4

0x 1  0x 5  0x 1  0x 1  0x55  0xa3

0x 1  0x 5  0x 2  0x 1  0x55  0xa2

0x 1  0x 5  0x 3  0x 1  0x55  0xa1

128字节数据

0x 1  0x 1  0x d  0x80  0x90  0x44  0x 0  0x20  0x99  0x25  0x 0  0x 8  0x25  0x4f  0x 0  0x 8
0x89  0x4c  0x 0  0x 8  0x41  0x4d  0x 0  0x 8  0xe1  0x32  0x 0  0x 8  0x39  0x5f  0x 0  0x 8
0x 0  0x 0  0x 0  0x 0  0x 0  0x 0  0x 0  0x 0  0x 0  0x 0  0x 0  0x 0  0x 0  0x 0  0x 0  0x 0
0x 1  0x25  0x 0  0x 8  0xe1  0x38  0x 0  0x 8  0x 0  0x 0  0x 0  0x 0  0x45  0x25  0x 0  0x 8
0xf5  0x5b  0x 0  0x 8  0xb3  0x25  0x 0  0x 8  0xb3  0x25  0x 0  0x 8  0xb3  0x25  0x 0  0x 8
0xb3  0x25  0x 0  0x 8  0xb3  0x25  0x 0  0x 8  0xb3  0x25  0x 0  0x 8  0xb3  0x25  0x 0  0x 8
0xb3  0x25  0x 0  0x 8  0xb3  0x25  0x 0  0x 8  0xb3  0x25  0x 0  0x 8  0xb3  0x25  0x 0  0x 8
0xb3  0x25  0x 0  0x 8  0xb3  0x25  0x 0  0x 8  0xb3  0x25  0x 0  0x 8  0xb3  0x25  0x 0  0x 8
0xb3  0x25  0x 0  0x 8  0xf4

0x 1  0x 1  0x e  0x80  0xb3  0x25  0x 0  0x 8  0xb3  0x25  0x 0  0x 8  0xb3  0x25  0x 0  0x 8
0xb3  0x25  0x 0  0x 8  0x49  0x5e  0x 0  0x 8  0xb3  0x25  0x 0  0x 8  0xb3  0x25  0x 0  0x 8
0xb3  0x25  0x 0  0x 8  0xb3  0x25  0x 0  0x 8  0xb3  0x25  0x 0  0x 8  0xb3  0x25  0x 0  0x 8
0xb3  0x25  0x 0  0x 8  0xb3  0x25  0x 0  0x 8  0xb3  0x25  0x 0  0x 8  0xb3  0x25  0x 0  0x 8
0xb3  0x25  0x 0  0x 8  0xb3  0x25  0x 0  0x 8  0xb3  0x25  0x 0  0x 8  0xb3  0x25  0x 0  0x 8
0xb3  0x25  0x 0  0x 8  0xb3  0x25  0x 0  0x 8  0xb3  0x25  0x 0  0x 8  0xb3  0x25  0x 0  0x 8
0xb3  0x25  0x 0  0x 8  0x25  0x3a  0x 0  0x 8  0xb3  0x25  0x 0  0x 8  0x79  0x5c  0x 0  0x 8
0xdf  0xf8  0x c  0xd0  0x 0  0xf0  0xd2  0xfc  0x 0  0x48  0x 0  0x47  0x 1  0x81  0x 0  0x 8
0x90  0x44  0x 0  0x20  0xff

0x 1  0x 1  0x f  0x80  0x22  0x4b  0x19  0x68  0x 8  0x68  0xb0  0xe8  0xf0  0x f  0x80  0xf3
0x 9  0x88  0xbf  0xf3  0x6f  0x8f  0x4f  0xf0  0x 0  0x 0  0x80  0xf3  0x11  0x88  0x4e  0xf0
0x d  0x e  0x70  0x47  0x 0  0x 0  0x 0  0x 0  0x 6  0x48  0x 0  0x68  0x 0  0x68  0x80  0xf3
0x 8  0x88  0x62  0xb6  0x61  0xb6  0xbf  0xf3  0x4f  0x8f  0xbf  0xf3  0x6f  0x8f  0x 0  0xdf
0x 0  0xbf  0x 0  0xbf  0x 8  0xed  0x 0  0xe0  0xef  0xf3  0x 9  0x80  0xbf  0xf3  0x6f  0x8f
0x f  0x4b  0x1a  0x68  0x20  0xe9  0xf0  0x f  0x10  0x60  0x 8  0xb5  0x4f  0xf0  0x50  0x 0
0x80  0xf3  0x11  0x88  0xbf  0xf3  0x4f  0x8f  0xbf  0xf3  0x6f  0x8f  0x 9  0xf0  0x50  0xf8
0x4f  0xf0  0x 0  0x 0  0x80  0xf3  0x11  0x88  0xbd  0xe8  0x 8  0x40  0x19  0x68  0x 8  0x68
0xb0  0xe8  0xf0  0x f  0xa1



0x 1  0x 5  0x 1  0x d  0x d  0xff  0x78  0x 6  0x42  0x41  0x34  0x33  0x21  0x14  0x16  0x57  0xff  0xd7

0x 1  0x 5  0x 2  0x d  0x d  0xff  0x78  0x 6  0x42  0x41  0x34  0x33  0x21  0x14  0x16  0x57  0xff  0xd6

0x 1  0x 5  0x 3  0x d  0x d  0xff  0x78  0x 6  0x42  0x41  0x34  0x33  0x21  0x14  0x16  0x57  0xff  0xd5

0x 1  0x 5  0x 4  0x d  0x d  0xff  0x78  0x 6  0x42  0x41  0x34  0x33  0x21  0x14  0x16  0x57  0xff  0xd4

0x 1  0x 1  0x 5  0x 0  0xf9

0x 1  0x 1  0x 6  0x 0  0xf8

0x 1  0x 1  0x 7  0x 0  0xf7

0x 1  0x 1  0x 8  0x 0  0xf6

0x 1  0x 1  0x 9  0x 0  0xf5

0x 1  0x 1  0x a  0x 0  0xf4

0x 1  0x 1  0x b  0x 0  0xf3

0x 1  0x 1  0x c  0x 0  0xf2



ff 78 06  42 41 34 33 21 14 16 57 ff
*/
    //FormatUpdateDate(1,5,i++,buf,1);

    //定义文件对话框类
    QFileDialog *fileDialog = new QFileDialog(this);
    //定义文件对话框标题
    fileDialog->setWindowTitle(QStringLiteral("选择固件"));
    //设置默认文件路径
    fileDialog->setDirectory(".");
    //设置文件过滤器
    fileDialog->setNameFilter(tr("File(*.bin*)"));
    //设置可以选择多个文件,默认为只能选择一个文件
    fileDialog->setFileMode(QFileDialog::ExistingFile);
    //设置视图模式
    fileDialog->setViewMode(QFileDialog::Detail);
    //打印所有选择的文件的路径
    QStringList fileNames;
    if (fileDialog->exec())
    {
        fileNames = fileDialog->selectedFiles();
        ui->textEdit_Firmware->setText(fileNames.at(0));
        QString file_path = fileNames.at(0);
        QFile file(file_path);
        file.open(QIODevice::ReadOnly);
        FirmwareArray = file.readAll();
        FirmwarePackNum = FirmwareArray.length() / 128;
        if((FirmwareArray.length() % 128) > 0)
        {
            FirmwarePackNum += 1;
        }
        file.close();
        ui->textEdit->append(QString("%1%2 n:%3").arg("File size:").arg(FirmwareArray.length()).arg(FirmwarePackNum));
    }
}

void MainWindow::on_pushButton_Start_clicked()
{
}

void MainWindow::on_pushButton_Stop_clicked()
{
}
