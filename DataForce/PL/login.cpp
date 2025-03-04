#include "login.h"
#include "../BLL/userService.h"

Login::Login(QWidget *parent) : QMainWindow(parent), ui(new Ui::LoginClass)
{
	ui->setupUi(this);

	connect(ui->loginButton, &QPushButton::clicked, this, &Login::checkLogin);
}

Login::~Login()
{}

void Login::checkLogin() {
    QString username = ui->usernameInput->text();
    QString password = ui->passwordInput->text();

    qDebug() << username << password;

    if (UserService::validateUser(username, password))
    {
        QMessageBox::information(this, "Login Successful", "Welcome, " + username + "!");

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