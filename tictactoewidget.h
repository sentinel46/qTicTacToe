#ifndef TICTACTOEWIDGET_H
#define TICTACTOEWIDGET_H

#include <QWidget>

class QPushButton;

class TicTacToeWidget : public QWidget
{
    Q_OBJECT

public:
    enum Player
    {
        Invalid, Player1, Player2, Draw
    }

    TicTacToeWidget(QWidget *parent = nullptr);
    ~TicTacToeWidget();

    Player currentPlayer() const { return m_currentPlayer; }
    void setCurrentPlayer(Player p)
    {
        if (m_currentPlayer == p)
            return;
        m_currentPlayer = p;
        emit currentPlayerChanged(p);
    }

signals:
    void currentPlayerChanged(Player);
    void gameOver(TicTacToeWidget::Player);

public slots:
    void handleButtonClick(int);

private:
    setupBoard();
    Player m_currentPlayer;
    QList<QPushButton*> board;
};

#endif // TICTACTOEWIDGET_H
