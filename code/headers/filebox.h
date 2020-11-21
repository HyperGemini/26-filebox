#ifndef FILEBOX_H
#define FILEBOX_H

#include <QWidget>
#include <QPainter>
#include <QStyleOption>

QT_BEGIN_NAMESPACE
namespace Ui { class FileBox; }
QT_END_NAMESPACE

class FileBox : public QWidget
{
    Q_OBJECT

public:
    FileBox(QWidget *parent = nullptr);
    ~FileBox();

    void paintEvent(QPaintEvent*);

private:
    Ui::FileBox *ui;
};
#endif // FILEBOX_H
