#include "adminTeachers.h"

AdminTeachers::AdminTeachers(QWidget *parent) : QMainWindow(parent), ui(new Ui::AdminTeachersClass)
{
	ui->setupUi(this);
    adminMenu = parent;

    loadTeachers();

    connect(ui->addButton, &QPushButton::clicked, this, &AdminTeachers::addTeacher);
    connect(ui->backButton, &QPushButton::clicked, this, &AdminTeachers::onBackButtonClicked);
}

AdminTeachers::~AdminTeachers()
{}

void AdminTeachers::loadTeachers()
{
    ui->teacherTable->clearContents();
    ui->teacherTable->setRowCount(0);

    QVector<Teacher> teachers = TeacherService::getAllTeachers();
    ui->teacherTable->setRowCount(teachers.size());

    for (int i = 0; i < teachers.size(); i++)
    {
        User user = UserService::getUserById(teachers[i].UserId);

        ui->teacherTable->setItem(i, 0, new QTableWidgetItem(teachers[i].FirstName));
        ui->teacherTable->setItem(i, 1, new QTableWidgetItem(teachers[i].LastName));
        ui->teacherTable->setItem(i, 2, new QTableWidgetItem(teachers[i].Subject));
        ui->teacherTable->setItem(i, 3, new QTableWidgetItem(user.Username));
        ui->teacherTable->setItem(i, 4, new QTableWidgetItem(user.Password));
    }
}


void AdminTeachers::addTeacher()
{
    bool ok;

    QString firstName = QInputDialog::getText(this, "Add Teacher", "Enter First Name:", QLineEdit::Normal, "", &ok);
    if (!ok || firstName.isEmpty()) return;

    QString lastName = QInputDialog::getText(this, "Add Teacher", "Enter Last Name:", QLineEdit::Normal, "", &ok);
    if (!ok || lastName.isEmpty()) return;

    QString subject = QInputDialog::getText(this, "Add Teacher", "Enter Subject:", QLineEdit::Normal, "", &ok);
    if (!ok || subject.isEmpty()) return;

    int newTeacherId = TeacherService::getNextTeacherId();
    int newUserId = UserService::getNextUserId();

    Teacher newTeacher;

    newTeacher.TeacherId = newTeacherId;
    newTeacher.FirstName = firstName;
    newTeacher.LastName = lastName;
    newTeacher.Subject = subject;
    newTeacher.UserId = newUserId;

    TeacherService::addTeacher(newTeacher);

    User newUser;
    newUser.UserId = newUserId;
    newUser.Username = firstName[0].toLower() + lastName.toLower();
    newUser.Password = UserService::generateRandomPassword();
    newUser.Role = "teacher";

    UserService::addUser(newUser);

    loadTeachers();

    QMessageBox::information(this, "Success", "Teacher added successfully!");
}


void AdminTeachers::onBackButtonClicked()
{
    UserService::logout();

    this->hide();
    adminMenu->show();
}