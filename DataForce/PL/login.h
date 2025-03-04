#pragma once

#include <QMainWindow>
#include <QMessageBox>
#include "ui_Login.h"
#include "menu.h"

class Login : public QMainWindow
{
	Q_OBJECT

public:
	Login(QWidget *parent = nullptr);
	~Login();

private slots:
	void checkLogin();  // Function to validate login

private:
	Ui::LoginClass* ui;
	Menu* menuWindow;

	QLineEdit* usernameField;
	QLineEdit* passwordField;
	QPushButton* loginButton;
};
