#include "timesetdialog.h"
#include "ui_timesetdialog.h"

timeSetDialog::timeSetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::timeSetDialog)
{

    ui->setupUi(this);
}

timeSetDialog::~timeSetDialog()
{
    delete ui;
}

void timeSetDialog::on_buttonBox_clicked(QAbstractButton *button)
{

    if (ui->buttonBox->button(QDialogButtonBox::Ok) == button)
    {
        emit sendSetTime(ui->setHourBox->value(),ui->setMinuteBox->value(),ui->setSecondBox->value(),ui->calendarWidget->selectedDate().year(),ui->calendarWidget->selectedDate().month(),ui->calendarWidget->selectedDate().day());
        //将设置的时分秒年月日发送到主线程
    }

}

