#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>

#include "register.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

    void paintEvent(QPaintEvent*);

    void setRegister(Register* r);

private slots:
    void on_pbRegister_clicked();

private:
    Ui::Login *ui;

    Register *reg;
};
#endif // LOGIN_H
