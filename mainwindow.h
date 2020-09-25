#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <string>
#include <QDialog>
#include <QtNetwork>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <QDebug>
#include <QTextCodec>
#include "recvthread.h"



class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void send();
    void read();
public:
    QTcpSocket *client;
    QPushButton *button_0;
    QTextEdit *text;
    QLineEdit *line;
    QString *msg;
    RecvThread *recThread;
};

#endif // MAINWINDOW_H
