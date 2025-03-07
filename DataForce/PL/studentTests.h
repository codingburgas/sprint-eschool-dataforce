#pragma once

#include <QMainWindow>
#include "ui_studentTests.h"

class StudentTests : public QMainWindow
{
	Q_OBJECT

public:
	StudentTests(QWidget *parent = nullptr);
	~StudentTests();

private:
	Ui::StudentTestsClass *ui;
};
