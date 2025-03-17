#include "adminMenu.h"

AdminMenu::AdminMenu(QWidget *parent) : QMainWindow(parent), ui(new Ui::AdminMenuClass)
{
	ui->setupUi(this);
    loginWindow = parent;

	connect(ui->studentsButton, &QPushButton::clicked, this, &AdminMenu::onStudentsButtonClicked);
	connect(ui->teachersButton, &QPushButton::clicked, this, &AdminMenu::onTeachersButtonClicked);
    connect(ui->backButton, &QPushButton::clicked, this, &AdminMenu::onBackButtonClicked);
}

AdminMenu::~AdminMenu()
{}

void AdminMenu::onStudentsButtonClicked()
{
    if (!studentsWindow)
    {
        studentsWindow = new AdminStudents(this);
    }

    studentsWindow->show();
    this->hide();
}

void AdminMenu::onTeachersButtonClicked()
{
    if (!teachersWindow)
    {
        teachersWindow = new AdminTeachers(this);
    }

    teachersWindow->show();
    this->hide();
}

void AdminMenu::onBackButtonClicked()
{
    UserService::logout();

    this->hide();
    loginWindow->show();
}