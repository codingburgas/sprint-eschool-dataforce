#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Menu.h"

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void onDiaryButtonClicked();

private:
    Ui::Menu* ui;
};
