#include "adminStudents.h"

AdminStudents::AdminStudents(QWidget *parent) : QMainWindow(parent), ui(new Ui::AdminStudentsClass)
{
	ui->setupUi(this);
	adminMenu = parent;

	loadStudents();

	connect(ui->addButton, &QPushButton::clicked, this, &AdminStudents::addStudent);
	connect(ui->backButton, &QPushButton::clicked, this, &AdminStudents::onBackButtonClicked);
}

AdminStudents::~AdminStudents()
{}

void AdminStudents::loadStudents()
{
    ui->studentsTable->clearContents();
    ui->studentsTable->setRowCount(0);

    QVector<Student> students = StudentService::getAllStudents();

    ui->studentsTable->setRowCount(students.size());

    for (int i = 0; i < students.size(); i++)
    {
        User user = UserService::getUserById(students[i].UserId);
        QVector<Grade> grades = GradeService::getGradesByStudentId(students[i].StudentId);

        ui->studentsTable->setItem(i, 0, new QTableWidgetItem(students[i].FirstName));
        ui->studentsTable->setItem(i, 1, new QTableWidgetItem(students[i].LastName));
        
        if (!grades.isEmpty())
        {
            QString gradeText;

            for (const Grade& g : grades)
            {
                gradeText += g.GradeValue + ", ";
            }
            gradeText.chop(2); // Remove last comma

            ui->studentsTable->setItem(i, 2, new QTableWidgetItem(gradeText));
        }
        else
        {
            ui->studentsTable->setItem(i, 2, new QTableWidgetItem("-"));
        }


        ui->studentsTable->setItem(i, 3, new QTableWidgetItem(user.Username));
        ui->studentsTable->setItem(i, 4, new QTableWidgetItem(user.Password));
    }
}


void AdminStudents::addStudent()
{
    bool ok;

    QString firstName = QInputDialog::getText(this, "Add Student", "Enter First Name:", QLineEdit::Normal, "", &ok);
    if (!ok || firstName.isEmpty()) return;

    QString lastName = QInputDialog::getText(this, "Add Student", "Enter Last Name:", QLineEdit::Normal, "", &ok);
    if (!ok || lastName.isEmpty()) return;

    int newStudentId = StudentService::getNextStudentId();
    int newUserId = UserService::getNextUserId();

    Student newStudent;

    newStudent.StudentId = newStudentId;
    newStudent.FirstName = firstName;
    newStudent.LastName = lastName;
    newStudent.UserId = newUserId;

    StudentService::addStudent(newStudent);

    User newUser;

    newUser.UserId = newUserId;
    newUser.Username = firstName[0].toLower() + lastName.toLower();
    newUser.Password = UserService::generateRandomPassword();
    newUser.Role = "student";

    UserService::addUser(newUser);

    loadStudents();

    QMessageBox::information(this, "Success", "Student added successfully!");
}


void AdminStudents::onBackButtonClicked()
{
    UserService::logout();

    this->hide();
    adminMenu->show();
}