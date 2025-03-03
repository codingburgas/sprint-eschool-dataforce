#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PL.h"

class PL : public QMainWindow
{
    Q_OBJECT

public:
    PL(QWidget *parent = nullptr);
    ~PL();

private slots:
    void onDiaryButtonClicked();

private:
    Ui::PLClass ui;
};
