#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QTime>

namespace Ui {
class MainWindow;
}
/**
 * @brief A classe MainWindown é a janela e classe principal do Cliente Produtor de Dados.
 * Ela será responsável por gerar dados aleatórios que são enviados para um servidor.
 */
class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
    /**
   * @brief MainWindow Construtr da classe
   * @param parent ponteiro que sinaliza a origem da classe
   */
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  
public slots:
    /**
   * @brief putData Função responsável por gerar os dados e enviar ao servidor
   */
  void putData();
  /**
   * @brief tcpConnect Função que realiza a conexão com o servidor
   */
  void tcpConnect();

private slots:
  /**
     * @brief disconnect Função responsável por desconectar o produtor do servidor
     */
    void disconnect();
    /**
     * @brief start Representa o início da produção dos dados
     */
    void start();
    /**
     * @brief stop Representa o fim da produção dos dados
     */
    void stop();
    /**
 * @brief timerEvent Determina o tempo que será gerado um novo dado
 * @param a  Ponteiro
 */
void timerEvent(QTimerEvent *a);

private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  int timer;
};

#endif // MAINWINDOW_H
