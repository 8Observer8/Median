
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

    // Input
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

    // Result
    double exp1 = 2.0 * b * b + 2.0 * c * c;
    double exp2 = a * a;
    if ( exp2 > exp1 ) {
        QMessageBox::information( this, tr( "Ошибка" ), tr( "Выражение (2*b^2 + 2*с^2) должно быть больше или равно чем (a^2)" ) );
        return;
    }
    double m = std::sqrt( exp1 - exp2  ) / 2.0;

    // Output
    ui->mLineEdit->setText( QString::number( m ) );
}
