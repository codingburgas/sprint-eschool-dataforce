#pragma once

#include "ui_studentResources.h"
#include <QMainWindow>
#include <QDir>
#include <QFileInfoList>
#include <QListWidget>
#include <QVBoxLayout>
#include <QDesktopServices>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>


class StudentResources : public QMainWindow
{
	Q_OBJECT

public:
	StudentResources(QWidget *parent = nullptr);
	~StudentResources();

private slots:
	void openResource();
	void logout();

private:
	Ui::StudentResourcesClass* ui;

    void loadPdfList();
};