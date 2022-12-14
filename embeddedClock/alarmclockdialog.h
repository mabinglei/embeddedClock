#ifndef ALARMCLOCKDIALOG_H
#define ALARMCLOCKDIALOG_H

#include <QDialog>
#include <QAbstractButton>
#include <QPushButton>

namespace Ui {
class alarmclockDialog;
}

class alarmclockDialog : public QDialog
{
    Q_OBJECT

public:
    explicit alarmclockDialog(QWidget *parent = nullptr);
    ~alarmclockDialog();

signals:
    void sendAlarmTime(int,int,int,bool);

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::alarmclockDialog *ui;
};

#endif // ALARMCLOCKDIALOG_H
