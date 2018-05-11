#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include "configurationdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionNewGame, &QAction::triggered, this, &MainWindow::startNewGame);
    connect(ui->actionQuit, &QAction::triggered, qApp, &QApplication::quit);

    connect(ui->gameBoard, &TicTacToeWidget::currentPlayerChanged, this, &MainWindow::updateNameLabels);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startNewGame()
{
    ConfigurationDialog dlg(this);
    if (dlg.exec() == QDialog::Rejected)
        return;

    ui->player1->setText(dlg.player1Name());
    ui->player2->setText(dlg.player2Name());
    ui->gameBoard->initNewGame();
    ui->gameBoard->setEnabled(true);
}

void MainWindow::updateNameLabels()
{
    auto f = ui->player1->font();
    f.setBold(ui->gameBoard->currentPlayer() == TicTacToeWidget::Player1);
    ui->player1->setFont(f);
    f.setBold(ui->gameBoard->currentPlayer() == TicTacToeWidget::Player2);
    ui->player2->setFont(f);
}

void MainWindow::handleGameOver(TicTacToeWidget::Player winner)
{
    ui->gameBoard->setEnabled(false);
    QString message;
    if (winner == TicTacToeWidget::Draw)
    {
        message = "Game ended with a draw.";
    }
    else
    {
        message = QString("%1 wins").arg(winner == TicTacToeWidget::Player1 ? ui->player1->text() : ui->player2->text());
    }
    QMessageBox::information(this, "Info", message);
}
