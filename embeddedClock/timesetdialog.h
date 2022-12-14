#ifndef TIMESETDIALOG_H
#define TIMESETDIALOG_H

#include <QDialog>
#include <QAbstractButton>
#include <QPushButton>

namespace Ui {
class timeSetDialog;
}

class timeSetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit timeSetDialog(QWidget *parent = nullptr);
    ~timeSetDialog();

signals:
    void sendSetTime(int,int,int,int,int,int);

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::timeSetDialog *ui;
};

#endif // TIMESETDIALOG_H
