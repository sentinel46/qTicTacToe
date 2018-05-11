#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tictactoewidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void startNewGame();
    void updateNameLabels();
    void handleGameOver(TicTacToeWidget::Player winner);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
