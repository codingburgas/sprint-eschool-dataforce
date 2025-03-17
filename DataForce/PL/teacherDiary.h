#pragma once

#include <QMainWindow>
#include "ui_teacherDiary.h"
#include "../BLL/currentUser.h"
#include "../BLL/gradeService.h"
#include "../BLL/studentService.h"
#include "../BLL/teacherService.h"

class TeacherDiary : public QMainWindow
{
	Q_OBJECT

public:
	TeacherDiary(QWidget *parent = nullptr);
	~TeacherDiary();

private slots:
	void loadGrades();
	void addGrade();
	void deleteGrade();
	void logout();

private:
	Ui::TeacherDiaryClass *ui;
	QWidget* menuWindow;
};
