#pragma once

#include <QDialog>
#include <QMessageBox>
#include "ui_studentTestWindow.h"
#include "../BLL/testService.h"
#include "../BLL/questionService.h"
#include "../DAL/question.h"

class StudentTestWindow : public QDialog
{
	Q_OBJECT

public:

	void setTest(int id);
	StudentTestWindow(QWidget *parent = nullptr);
	~StudentTestWindow();

private slots:
	void nextQuestion();
	void previousQuestion();
	void selectOptionA();
	void selectOptionB();
	void selectOptionC();
	void selectOptionD();

private:
	void loadQuestions();
	void loadQuestion(int questionId);
	QString calculateGrade();  // Method to calculate the student's grade
	void saveGrade();       // Method to save the grade to the database
	void finishTest();       // Method to save the grade to the database

	Ui::StudentTestWindowClass* ui;
	int testId;
	int currentQuestion = 0;
	Test currentTest;
	QVector<Question> questions;
	QMap<int, QString> selectedAnswers;
	int score;

};