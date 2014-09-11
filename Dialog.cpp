
#include <cmath>
#include <QMessageBox>
#include "Dialog.h"
#include "ui_Dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_resultButton_clicked()
{
    bool ok;

    double a = ui->aLineEdit->text().toDouble( &ok );
    if ( !ok ) {
        QMessageBox::information( this, tr( "Ошибка" ), tr( "Вы ввели некорректные данные" ) );
        return;
    }

    double b = ui->bLineEdit->text().toDouble( &ok );
    if ( !ok ) {
        QMessageBox::information( this, tr( "Ошибка" ), tr( "Вы ввели некорректные данные" ) );
        return;
    }

    double c = ui->cLineEdit->text().toDouble( &ok );
    if ( !ok ) {
        QMessageBox::information( this, tr( "Ошибка" ), tr( "Вы ввели некорректные данные" ) );
        return;
    }

    double m = std::sqrt( 2.0 * b * b + 2.0 * c * c - a * a  ) / 2.0;

    ui->mLineEdit->setText( QString::number( m ) );
}
