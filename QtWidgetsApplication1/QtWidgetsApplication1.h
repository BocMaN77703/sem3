#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtWidgetsApplication1.h"

class QtWidgetsApplication1 : public QWidget
{
    Q_OBJECT

public:
    QtWidgetsApplication1(QWidget *parent = Q_NULLPTR);

private slots:
   // void on_closebtn_clicked();

private:
    Ui::QtWidgetsApplication1Class ui;
};
