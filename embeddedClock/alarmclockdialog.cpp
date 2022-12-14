#include "alarmclockdialog.h"
#include "ui_alarmclockdialog.h"

alarmclockDialog::alarmclockDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alarmclockDialog)
{
    ui->setupUi(this);
}

alarmclockDialog::~alarmclockDialog()
{
    delete ui;
}

//点击设定闹钟窗体的OK按钮时，将设定的闹钟时间和是否启用发送到主线程
void alarmclockDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    if (ui->buttonBox->button(QDialogButtonBox::Ok) == button)
    {
           sendAlarmTime(ui->setHourBox->value(),ui->setMinuteBox->value(),ui->setSecondBox->value(),ui->checkBox->isChecked());//最后一个参数即是否启用闹钟
    }
}

