#include "tictactoewidget.h"

#include <QGridLayout>
#include <QPushButton>
#include <QSignalMapper>

TicTacToeWidget::TicTacToeWidget(QWidget *parent)
    : QWidget(parent)
{
    setupBoard();
}

TicTacToeWidget::~TicTacToeWidget()
{

}

void TicTacToeWidget::handleButtonClick(int index)
{
    if (index < 0 || index >= board.size())
        return;

    auto button = board.at(index);
    if (button->text() != " ")
        return;

    button->setText(currentPlayer() == Player1 ? "X" : "O");
    auto winner = checkWinCondition(index/3, index%3);
    if (winner == Invalid)
    {
        setCurrentPlayer(currentPlayer() == Player1 ? Player2 : Player1);
        return;
    }
    else
        emit gameOver(winner);
}

void TicTacToeWidget::initNewGame()
{
    for (auto button: board)
        button->setText(" ");
    setCurrentPlayer(Player1);
}

void TicTacToeWidget::setupBoard()
{
    auto gridLayout = new QGridLayout;
    auto mapper = new QSignalMapper(this);
    for (auto row = 0; row < 3; ++row)
    {
        for (auto col = 0; col < 3; ++col)
        {
            auto button = new QPushButton;
            button->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
            button->setText(" ");
            gridLayout->addWidget(button, row, col);
            board.append(button);
            mapper->setMapping(button, board.count()-1);
            connect(button, SIGNAL(clicked()), mapper, SLOT(map()));
        }
    }
    connect(mapper, SIGNAL(mapped(int)), this, SLOT(handleButtonClick(int)));
    setLayout(gridLayout);
}

TicTacToeWidget::Player TicTacToeWidget::checkWinCondition(int, int)
{
    return Invalid;
    // TODO: implement
}
