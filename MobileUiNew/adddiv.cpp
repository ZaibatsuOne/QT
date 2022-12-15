#include "adddiv.h"
#include "ui_adddiv.h"
#include <QValidator>
#include <QRegularExpression>
#include <QMessageBox>

QString f, s;
AddDiv::AddDiv(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddDiv)
{
    ui->setupUi(this);

}
void AddDiv::showWarn1(){
    QMessageBox warn1;
    warn1.setText("Вероятно вы ввели не все поля!\nНеобходимо запонить все поля.");
    warn1.setIcon(QMessageBox::Warning);
    warn1.setWindowTitle("Внимание");
    warn1.exec();
}
AddDiv::~AddDiv()
{
    delete ui;
}
double AddDiv::getNum(){

    num1 = ui->firstNum->text().toDouble();
    num2 = ui->secNum->text().toDouble();

}


void AddDiv :: writeResult(double tmpResult){

    ui->resLabel->setText(QString :: number(tmpResult, 'g', 15));
    result = 0;

}
void AddDiv::on_pushButton_14_clicked(){
    f = ui->firstNum->text();
    s = ui->secNum->text();
    if(f.isEmpty() || s.isEmpty()){
        showWarn1();
    }
    else{
    getNum();
    result = num1 + num2;
    writeResult(result);
    }

}


void AddDiv::on_pushButton_15_clicked()
{
    f = ui->firstNum->text();
    s = ui->secNum->text();
    if(f.isEmpty() || s.isEmpty()){
        showWarn1();
    }
    else{
    getNum();
    result = num1 / num2;
    writeResult(result);
    }

}


void AddDiv::on_pushButton_17_clicked()
{
    this->close();
}


void AddDiv::on_firstNum_textEdited(const QString &arg1)
{
    QRegularExpression rx1("\\d+\\.\\d+?$");
    auto firstNumVal = new QRegularExpressionValidator(rx1, this);
    ui->firstNum->setValidator(firstNumVal);
}


void AddDiv::on_secNum_textEdited(const QString &arg1)
{
    QRegularExpression rx2("\\d+\\.\\d+?$");
    auto secNumVal = new QRegularExpressionValidator(rx2, this);
    ui->secNum->setValidator(secNumVal);
}


void AddDiv::on_pushButton_2_released()
{
    ui->firstNum->setText("");
    ui->secNum->setText("");
    ui->resLabel->setText("");
}


void AddDiv::on_pushButton_clicked()
{
    this -> close();
    emit firstWindow();
}



void AddDiv::on_firstNum_cursorPositionChanged(int arg1, int arg2)
{

}

