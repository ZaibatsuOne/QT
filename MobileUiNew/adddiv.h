#ifndef ADDDIV_H
#define ADDDIV_H

#include <QWidget>

namespace Ui {
class AddDiv;
}

class AddDiv : public QWidget
{
    Q_OBJECT
    double num1=0, num2=0, result=0;
    double getNum();
    void writeResult(double tmpResult);

public:
    explicit AddDiv(QWidget *parent = nullptr);
    ~AddDiv();

signals:
    void firstWindow();

private slots:
    void showWarn1();
    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_17_clicked();

    void on_firstNum_textEdited(const QString &arg1);

    void on_secNum_textEdited(const QString &arg1);

    void on_pushButton_2_released();

    void on_pushButton_clicked();

    void on_firstNum_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::AddDiv *ui;
};

#endif // ADDDIV_H
