#pragma once

#include <QMainWindow>
#include "ui_diary.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DiaryClass; };
QT_END_NAMESPACE

class Diary : public QMainWindow
{
	Q_OBJECT

public:
	Diary(QWidget *parent = nullptr);
	~Diary();

private:
	Ui::DiaryClass *ui;
};
