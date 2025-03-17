#pragma once

#include <QMainWindow>
#include <QMessageBox>
#include "ui_Login.h"
#include "menu.h"
#include "adminMenu.h"

class Login : public QMainWindow
{
	Q_OBJECT

public:
	Login(QWidget *parent = nullptr);
	~Login();

private slots:
	void checkLogin();

private:
	Ui::LoginClass* ui;
	QWidget* menuWindow;
	QWidget* adminWindow;

	QLineEdit* usernameField;
	QLineEdit* passwordField;
	QPushButton* buttonLogin;
};
