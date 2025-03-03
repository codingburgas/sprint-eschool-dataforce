#include "PL.h"
#include <iostream>

PL::PL(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    connect(ui.diaryButton, &QPushButton::clicked, this, &PL::onDiaryButtonClicked);

}

PL::~PL()
{}


void PL::onDiaryButtonClicked()
{
    ui.diaryButton->setText("Clicked");

}