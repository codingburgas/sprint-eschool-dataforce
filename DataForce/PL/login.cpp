#include "login.h"

Login::Login(QWidget *parent) : QMainWindow(parent), ui(new Ui::LoginClass)
{
	ui->setupUi(this);

    CurrentUser::className = "";
    CurrentUser::role = "";
    CurrentUser::username = "";
    CurrentUser::studentId = 0;
    CurrentUser::teacherId = 0;
    CurrentUser::userId = 0;

	connect(ui->loginButton, &QPushButton::clicked, this, &Login::checkLogin);
}

Login::~Login()
{}

void Login::checkLogin() 
{
    QString username = ui->usernameInput->text();
    QString password = ui->passwordInput->text();

    if (UserService::validateUser(username, password))
    {
        QMessageBox::information(this, "Login Successful", "Welcome, " + CurrentUser::username + "!");

        if (!menuWindow)
        {
            menuWindow = new Menu(this);
        }

        menuWindow->show();
        this->hide();

    }
    else
    {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password!");
    }
}