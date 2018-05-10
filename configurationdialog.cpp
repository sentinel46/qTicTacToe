#include "configurationdialog.h"
#include "ui_configurationdialog.h"

#include <QPushButton>

ConfigurationDialog::ConfigurationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigurationDialog)
{
    ui->setupUi(this);
    updateOKButtonState();
}

ConfigurationDialog::~ConfigurationDialog()
{
    delete ui;
}

void ConfigurationDialog::setPlayer1Name(const QString &p1Name)
{
    ui->player1Name->setText(p1Name);
}

void ConfigurationDialog::setPlayer2Name(const QString &p2Name)
{
    ui->player2Name->setText(p2Name);
}

QString ConfigurationDialog::player1Name() const
{
    return ui->player1Name->text();
}

QString ConfigurationDialog::player2Name() const
{
    return ui->player2Name->text();
}

void ConfigurationDialog::updateOKButtonState()
{
    auto pl1NameEmpty = ui->player1Name->text().isEmpty();
    auto pl2NameEmpty = ui->player2Name->text().isEmpty();
    auto okButton = ui->buttonBox->button(QDialogButtonBox::Ok);
    okButton->setDisabled(pl1NameEmpty || pl2NameEmpty);
}
