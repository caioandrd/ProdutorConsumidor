#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QTextBrowser>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  socket = new QTcpSocket(this);
  tcpConnect();


  connect(ui->pushButton_start,
          SIGNAL(clicked(bool)),
          this,
          SLOT(start()));

  connect(ui->pushButton_stop,
          SIGNAL(clicked(bool)),
          this,
          SLOT(stop()));

  connect(ui->pushButton_con,
          SIGNAL(clicked(bool)),
          this,
          SLOT(tcpConnect()));

  connect(ui->pushButton_dis,
          SIGNAL(clicked(bool)),
          this,
          SLOT(disconnect()));

}

void MainWindow::tcpConnect(){
  socket->connectToHost(ui->textEdit_IP->toPlainText(),1234);

  if(socket->waitForConnected(3000)){
    qDebug() << "Connected";
    ui->label_status->setText("Connected");
  }
  else{
    qDebug() << "Disconnected";

  }
}

void MainWindow::putData(){
  QDateTime datetime;
  QString str;
  qint64 msecdate;
  int min = 0;
  int max = 0;

  min=ui->horizontalSlider_min->value();
  max=ui->horizontalSlider_max->value();

  if(socket->state()== QAbstractSocket::ConnectedState){

    msecdate = QDateTime::currentDateTime().toMSecsSinceEpoch();
    str = "set "+ QString::number(msecdate) + " " + QString::number((float)qrand()/(RAND_MAX)*(max-min)+min)+ "\r\n";

      qDebug() << str;
      qDebug() << socket->write(str.toStdString().c_str()) << " bytes written";

      ui->textBrowser_dados->append(str);
      if(socket->waitForBytesWritten(3000)){
        qDebug() << "wrote";
      }
  }
}

void MainWindow::disconnect()
{
    socket->disconnectFromHost();
    qDebug() << "Disconnected";
    ui->label_status->setText("Disconnected");

}

void MainWindow::start()
{
    timer = startTimer(ui->horizontalSlider_timings->value()*1000);
    qDebug ()<< "Inicio da contagem de tempo";
}

void MainWindow::timerEvent(QTimerEvent *a)
{
    putData();
    qDebug() << "Sending Data";
}

void MainWindow::stop()
{
    killTimer(timer);
    timer=0;
    qDebug() << "Acabou a contagem de tempo";
}

MainWindow::~MainWindow(){
  delete socket;
  delete ui;
}
