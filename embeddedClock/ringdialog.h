#ifndef RINGDIALOG_H
#define RINGDIALOG_H

#include <QDialog>
#include <QAbstractButton>
#include <QPushButton>

namespace Ui {
class RingDialog;
}

class RingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RingDialog(QWidget *parent = nullptr);
    ~RingDialog();

signals:
    void offRing(bool);

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::RingDialog *ui;
};

#endif // RINGDIALOG_H
