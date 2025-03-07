#include "studentDiary.h"

StudentDiary::StudentDiary(QWidget *parent) : QMainWindow(parent), ui(new Ui::StudentDiaryClass())
{
	ui->setupUi(this);
	menuWindow = parent;  // Store the menu reference

	connect(ui->backButton, &QPushButton::clicked, this, &StudentDiary::onBackButtonClicked);
}

StudentDiary::~StudentDiary()
{
	delete ui;
}

void StudentDiary::onBackButtonClicked()
{
	this->hide();
	menuWindow->show();
}