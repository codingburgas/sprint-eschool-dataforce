#pragma once

#include <QMainWindow>
#include "ui_adminMenu.h"
#include "adminTeachers.h"
#include "adminStudents.h"

class AdminMenu : public QMainWindow
{
	Q_OBJECT

public:
	AdminMenu(QWidget *parent = nullptr);
	~AdminMenu();

private slots:
	void onStudentsButtonClicked();
	void onTeachersButtonClicked();
	void onBackButtonClicked();

private:
	Ui::AdminMenuClass* ui;
	QWidget* loginWindow;

	AdminTeachers* teachersWindow;
	AdminStudents* studentsWindow;
};
