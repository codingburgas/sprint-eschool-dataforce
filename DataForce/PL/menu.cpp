#include "menu.h"

Menu::Menu(QWidget *parent) : QMainWindow(parent), ui(new Ui::Menu)
{
    ui->setupUi(this);
    loginWindow = parent;

    connect(ui->diaryButton, &QPushButton::clicked, this, &Menu::onDiaryButtonClicked);
    connect(ui->testsButton, &QPushButton::clicked, this, &Menu::onTestsButtonClicked);
    connect(ui->resourcesButton, &QPushButton::clicked, this, &Menu::onResourcesButtonClicked);

    connect(ui->backButton, &QPushButton::clicked, this, &Menu::onBackButtonClicked);
}

Menu::~Menu()
{}


void Menu::onDiaryButtonClicked()
{
    if (CurrentUser::role == "student")
    {
        if (!studentDiaryWindow)
        {
            studentDiaryWindow = new StudentDiary(this);
        }

        studentDiaryWindow->show();
        this->hide();
    }
    else if (CurrentUser::role == "teacher")
    {
        if (!teacherDiaryWindow)
        {
            teacherDiaryWindow = new TeacherDiary(this);
        }

        teacherDiaryWindow->show();
        this->hide();
    }
}

void Menu::onTestsButtonClicked()
{
    if (CurrentUser::role == "student")
    {
        if (!studentResourcesWindow)
        {
            studentResourcesWindow = new StudentResources(this);
        }

        studentResourcesWindow->show();
        this->hide();
    }
    else if (CurrentUser::role == "teacher")
    {
        if (!teacherDiaryWindow)
        {
            teacherResourcesWindow = new TeacherResources(this);
        }

        teacherResourcesWindow->show();
        this->hide();
    }
}

void Menu::onResourcesButtonClicked()
{
}

void Menu::onBackButtonClicked()
{
    this->hide();
    loginWindow->show();
}