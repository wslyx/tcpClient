#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
{
    client = new QTcpSocket(this);
    client->connectToHost(QHostAddress("47.102.221.64"), 5678);

    text=new QTextEdit;
    button_0=new QPushButton;
    line=new QLineEdit;

    QVBoxLayout *layout=new QVBoxLayout(this);
    layout->addWidget(text);
    text->setReadOnly(true);
    layout->addWidget(line);
    line->setFocus();
    layout->addWidget(button_0);

    button_0->setText("发送");
    text->insertPlainText("可以输入");
    text->insertPlainText("\n");

    recThread=new RecvThread();
//    recThread->start();

//    QTimer *timer = new QTimer(this);
//    connect(timer, SIGNAL(timeout()), this, SLOT(read()));
//    timer->start(500);
    connect(client,SIGNAL(readyRead()),this,SLOT (read()));
    connect(button_0,SIGNAL(clicked()),this,SLOT(send()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::send()
{
    *msg=line->displayText();
    text->insertPlainText(*msg);
    const char *buffer = msg->toStdString().data();
    client->write(buffer,256);
    text->insertPlainText("\n");
    line->setText("");
}

void MainWindow::read()
{
    while(client->bytesAvailable()>0)
    {
        QByteArray datagram;
        datagram.resize(client->bytesAvailable());
        client->read(datagram.data(),datagram.size());
        QString msg=datagram.data();
        text->insertPlainText(msg);
        text->insertPlainText("\n");
    }


}
