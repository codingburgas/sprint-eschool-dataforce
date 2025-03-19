#pragma once

#include <QMainWindow>
#include "ui_testsMenu.h"
#include "../BLL/questionService.h"
#include "../BLL/testService.h"
#include "../BLL/testStudentService.h"
#include "teacherTestWindow.h"
#include "studentTestWindow.h"
#include <QGridLayout>
#include <QInputDialog>

class TestsMenu : public QMainWindow
{
	Q_OBJECT

public:
	TestsMenu(QWidget *parent = nullptr);
	~TestsMenu();

private slots:
	void loadTests();
	void openTest(int testId);
	void onBackButtonClicked();
	void addTest();
		

private:
	Ui::TestsMenuClass* ui;
	QWidget* menuWindow;
	QWidget* scrollAreaWidget;
	QGridLayout* scrollLayout;

	TeacherTestWindow* teacherTestWindow;
	StudentTestWindow* studentTestWindow;
};
