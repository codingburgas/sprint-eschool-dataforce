#pragma once

#include <QMainWindow>
#include <QMessageBox>
#include <QInputDialog>
#include "ui_adminStudents.h"
#include "../BLL/studentService.h"
#include "../BLL/gradeService.h"

class AdminStudents : public QMainWindow
{
	Q_OBJECT

public:
	AdminStudents(QWidget *parent = nullptr);
	~AdminStudents();

private slots:
	void loadStudents();
	void addStudent();
	void onBackButtonClicked();

private:
	Ui::AdminStudentsClass* ui;
	QWidget* adminMenu;
};
