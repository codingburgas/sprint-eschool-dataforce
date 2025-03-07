#include "studentTests.h"

StudentTests::StudentTests(QWidget *parent) : QMainWindow(parent), ui(new Ui::StudentTestsClass())
{
	ui->setupUi(this);
}

StudentTests::~StudentTests()
{
	delete ui;
}
