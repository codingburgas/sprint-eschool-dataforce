#pragma once

#include <QMainWindow>
#include <QMessageBox>
#include <QInputDialog>
#include "ui_adminTeachers.h"
#include "../BLL/teacherService.h"


class AdminTeachers : public QMainWindow
{
	Q_OBJECT

public:
	AdminTeachers(QWidget *parent = nullptr);
	~AdminTeachers();

private slots:
    void loadTeachers();
    void addTeacher();
	void onBackButtonClicked();
   
private:
	Ui::AdminTeachersClass* ui;
	QWidget* adminMenu;
};
