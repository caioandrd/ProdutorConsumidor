#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include<vector>

using namespace std;

class Plotter : public QWidget
{
    Q_OBJECT
private:
    vector<double> tempo;
    vector<double> valor;
    double time;
public:
    /** @brief Construtor do componente Plotter
   * @details adiciona os valores aos vectores  de tempos e de dados
  **/
    explicit Plotter(QWidget *parent = nullptr);
    /** @brief Paint event
   * @details Desenha o  grafico utilizando retas, usando dois pontos de cada vez.
  **/
    void paintEvent(QPaintEvent *p);
    /** @brief Função que carrega os dados referentes aos tempos e aos dados
   * @details Recebe os 30 ultimos dados e os usa na classe Plotter.
  **/
public slots:
    void receberdados(vector<double> &t, vector<double> &v);
};

#endif // PLOTTER_H
