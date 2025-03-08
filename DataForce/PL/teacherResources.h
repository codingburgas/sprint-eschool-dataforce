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


private:
	Ui::TeacherResourcesClass *ui;

	QPushButton* openResourceButton;
	QPushButton* addResourceButton;
	QPushButton* deleteResourceButton;
	QListWidget* pdfListWidget;

	void loadPdfList();
};
