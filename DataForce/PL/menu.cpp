#include "menu.h"

Menu::Menu(QWidget *parent) : QMainWindow(parent), ui(new Ui::Menu)
{
    ui->setupUi(this);

    connect(ui->diaryButton, &QPushButton::clicked, this, &Menu::onDiaryButtonClicked);
}

Menu::~Menu()
{}


void Menu::onDiaryButtonClicked()
{
}