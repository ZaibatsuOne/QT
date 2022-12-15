#include "quad.h"
#include "ui_quad.h"
#include<QMessageBox>
#include<QString>

double A, B, C, Discriminant, X1, X2;
QString a, b, c, d, x1, x2;
quad::quad(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::quad)
{
    ui->setupUi(this);
}
void quad::showWarn1(){
    QMessageBox warn1;
    warn1.setText("Дискриминант меньше 0!\nВозможна ошибка!");
    warn1.setIcon(QMessageBox::Warning);
    warn1.setWindowTitle("Внимание");
    warn1.exec();
}
void quad::showWarn2(){
    QMessageBox warn2;
    warn2.setText("Вероятно вы ввели не все поля!\nНеобходимо запонить все поля.");
    warn2.setIcon(QMessageBox::Warning);
    warn2.setWindowTitle("Внимание");
    warn2.exec();
}

double quad::calcDisc(){
    Discriminant = B*B - 4*A*C;
    if(Discriminant < 0){
        showWarn1();
    }
    return Discriminant;
}

double quad::calcRoot(){
    if(Discriminant>=0)
      {
        X1 = (-B + sqrt(Discriminant))/ (2* A);
        X2 = (-B - sqrt(Discriminant))/ (2* A);
      }
    ui->disc_Answer->setText(QString::number(Discriminant));
    ui->x1_Answer->setText(QString::number(X1));
    ui->x2_Answer->setText(QString::number(X2));
}
quad::~quad()
{
    delete ui;
}

void quad::on_calc_Button_clicked()
{
    a = ui->a_input->text();
    b = ui->b_input->text();
    c = ui->c_input->text();

    if(a.isEmpty() || b.isEmpty() || c.isEmpty()){
        showWarn2();
    }else{
        B = b.toDouble();
        A = a.toDouble();
        C = c.toDouble();
        Discriminant = d.toDouble();

        calcDisc();
        calcRoot();

        ui->disc_Answer->setText(QString::number(Discriminant));

        x1 = QString::number(X1);
        x2 = QString::number(X2);
        d = QString::number(Discriminant);
}
}

void quad::on_back_button_clicked()
{
    this -> close();
    emit firstWindow();
}


void quad::on_pushButton_2_released()
{
    ui->a_input->setText("");
    ui->b_input->setText("");
    ui->c_input->setText("");
    ui->disc_Answer->setText("");
    ui->x1_Answer->setText("");
    ui->x2_Answer->setText("");

}

