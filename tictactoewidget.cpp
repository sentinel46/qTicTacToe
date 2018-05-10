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

}

TicTacToeWidget::setupBoard()
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
            connect(button, &QPushButton::clicked, mapper, &QSignalMapper::map);
        }
    }
    connect(mapper, &QSignalMapper::mapped, this, &TicTacToeWidget::handleButtonClick);
    setLayout(gridLayout);
}
