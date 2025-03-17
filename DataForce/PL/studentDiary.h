#pragma once

#include <QMainWindow>
#include "ui_studentDiary.h"

class StudentDiary : public QMainWindow
{
	Q_OBJECT

public:
	StudentDiary(QWidget *parent = nullptr);
	~StudentDiary();

private slots:
	void logout();
	void loadGrades();

private:
	Ui::StudentDiaryClass *ui;
	QWidget* menuWindow;
};
