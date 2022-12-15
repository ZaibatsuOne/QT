#ifndef QUAD_H
#define QUAD_H

#include <QWidget>

namespace Ui {
class quad;
}

class quad : public QWidget
{
    Q_OBJECT

public:
    explicit quad(QWidget *parent = nullptr);
    ~quad();


private slots:
    void on_calc_Button_clicked();

    void on_back_button_clicked();

    void on_pushButton_2_released();

signals:
    void firstWindow();

private:
    Ui::quad *ui;
    void showWarn1();
    void showWarn2();
    double calcDisc();
    double calcRoot();
};

#endif // QUAD_H
