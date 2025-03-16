#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_menu.h"
#include "../BLL/userService.h"
#include "studentDiary.h"
#include "teacherDiary.h"
#include "studentResources.h"
#include "teacherResources.h"
#include <testsMenu.h>

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();


private slots:
    void onDiaryButtonClicked();
    void onTestsButtonClicked();
    void onResourcesButtonClicked();
    void onBackButtonClicked();

private:
    Ui::Menu* ui;

    QWidget* loginWindow;

    StudentDiary* studentDiaryWindow;
    TeacherDiary* teacherDiaryWindow;

    StudentResources* studentResourcesWindow;
    TeacherResources* teacherResourcesWindow;

    //StudentTests* studentResourcesWindow;
    TestsMenu* testsMenuWindow;
};
