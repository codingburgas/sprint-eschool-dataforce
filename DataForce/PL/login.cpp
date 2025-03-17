#include "login.h"

Login::Login(QWidget *parent) : QMainWindow(parent), ui(new Ui::LoginClass)
{
	ui->setupUi(this);

    UserService::logout();

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

        if (CurrentUser::role == "admin")
        {
            adminWindow = new AdminMenu(this);

            adminWindow->show();
            this->hide();
            return;
        }

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