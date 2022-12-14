#include "ringdialog.h"
#include "ui_ringdialog.h"

RingDialog::RingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RingDialog)
{
    ui->setupUi(this);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText(QString::fromUtf8("关闭闹钟"));//将OK按钮显示文本替换为"关闭闹钟"
}

RingDialog::~RingDialog()
{
    delete ui;
}

void RingDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    if (ui->buttonBox->button(QDialogButtonBox::Ok) == button)//铃响界面点击"关闭闹钟"发送关闭闹钟信号到主线程
    {
        emit offRing(true);
    }
}

