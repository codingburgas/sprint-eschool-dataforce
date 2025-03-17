#pragma once

#include "ui_teacherResources.h"
#include <QMainWindow>
#include <QDir>
#include <QListWidget>
#include <QVBoxLayout>
#include <QDesktopServices>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QPushButton>

class TeacherResources : public QMainWindow
{
	Q_OBJECT

public:
	TeacherResources(QWidget *parent = nullptr);
	~TeacherResources();

private slots:
	void openResource();
	void addResource();
	void deleteResource();
	void onBackButtonClicked();

private:
	Ui::TeacherResourcesClass *ui;
	QWidget* menuWindow;

	void loadPdfList();
};
