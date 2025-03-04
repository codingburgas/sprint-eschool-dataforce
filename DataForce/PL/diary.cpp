#include "diary.h"

Diary::Diary(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::DiaryClass())
{
	ui->setupUi(this);
}

Diary::~Diary()
{
	delete ui;
}
