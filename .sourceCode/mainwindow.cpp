#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


//internal operations
struct Internalinput{
    int check( int data){
        if (data > 1){
            return 1;
        }
        else{
            return data;
        }
    }

    int check2(int data){
        if (data < 2){
            return data;
        }
        else{
            return 0;
        }
     }
    int reverse(int data){
        if (data == 1){
            return 0;
        }
        else{
            return 1;
        }
     }
 };

Internalinput internal1;
//Main operations
int AND(int A,int B){
    int out = A*B;
    return out;
    }
int OR(int A,int B){
    int out = internal1.check(A+B);
    return out;
    }

int NOT(int A){
    int out = internal1.reverse(A);
    return out;
    }
int NAND(int A,int B){
    int out = internal1.reverse(A*B);
    return out;
    }
int NOR(int A,int B){
    int out = internal1.reverse(A+B);
    return out;
    }
int EXOR(int A,int B){
    int out = internal1.check2(A+B);
    return out;
    }
int EXNOR(int A,int B){
    int out = internal1.reverse(internal1.check2(A+B));
    return out;
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->error_handler->clear();
    int i1 = ui->input1->text().toInt();
    int i2 = ui->input2->text().toInt();
    if (i1 < 2 && i2 < 2){
    ui->and_out->setNum(AND(i1,i2));
    ui->nand_out->setNum(NAND(i1,i2));
    ui->nor_out->setNum(NOR(i1,i2));
    ui->or_out->setNum(OR(i1,i2));
    ui->exor_out->setNum(EXOR(i1,i2));
    ui->exnor_out->setNum(EXNOR(i1,i2));
    ui->not_out->setNum(NOT(i1));
    ui->input1->clear();
    ui->input2->clear();

    }
    else {
        ui->error_handler->setStyleSheet("color:red");
        ui->error_handler->setText("Input should be in 1 bit and binary only!");
        ui->and_out->clear();
        ui->or_out->clear();
        ui->nor_out->clear();
        ui->nand_out->clear();
        ui->not_out->clear();
        ui->exor_out->clear();
        ui->exnor_out->clear();
    }
}
