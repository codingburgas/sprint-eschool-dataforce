#pragma once

#include <QDialog>
#include <QMessageBox>
#include <QListWidgetItem>
#include "ui_teacherTestWindow.h"
#include "../DAL/test.h"
#include "../BLL/testService.h"
#include "../BLL/questionService.h"
#include "../DAL/testStudent.h"
#include "../BLL/testStudentService.h"

class TeacherTestWindow : public QDialog
{
	Q_OBJECT

public:
	void setTest(int id);
	TeacherTestWindow(QWidget *parent = nullptr);
	~TeacherTestWindow();

private slots:
	void nextQuestion();
	void previousQuestion();
	void saveQuestion();
	void addQuestion();
	void deleteQuestion();
	void viewGrades();

private:
	Ui::TeacherTestWindowClass* ui;
	int testId;
	int currentQuestion = 0;
	Test currentTest;
	QVector<Question> questions;

	void loadQuestions(int question = 0);
	void loadQuestion(int questionId);
};
