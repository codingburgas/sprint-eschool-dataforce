#include "teacherDiary.h"
#include <QMessageBox>
#include <login.h>

TeacherDiary::TeacherDiary(QWidget *parent) : QMainWindow(parent), ui(new Ui::TeacherDiaryClass())
{
	ui->setupUi(this);
	menuWindow = parent;
    loadGrades();

    connect(ui->addGradeButton, &QPushButton::clicked, this, &TeacherDiary::addGrade);
    connect(ui->deleteGradeButton, &QPushButton::clicked, this, &TeacherDiary::deleteGrade);
    connect(ui->logoutButton, &QPushButton::clicked, this, &TeacherDiary::logout);
}

TeacherDiary::~TeacherDiary()
{
	delete ui;
}

void TeacherDiary::loadGrades()
{
    QVector<Student> students = StudentService::getStudentsByClass(CurrentUser::className);
    ui->gradeTable->setRowCount(0);

    for (const Student& s : students)
    {
        int row = ui->gradeTable->rowCount();
        ui->gradeTable->insertRow(row);

        QVector<Grade> grades = GradeService::getGradesByStudentId(s.StudentId);
        Teacher t = TeacherService::getTeacherById(CurrentUser::teacherId);

        // Add Student Id as the first column
        ui->gradeTable->setItem(row, 0, new QTableWidgetItem(QString::number(s.StudentId)));

        // Student Name
        ui->gradeTable->setItem(row, 1, new QTableWidgetItem(s.FirstName + " " + s.LastName));

        // Teacher Name
        ui->gradeTable->setItem(row, 2, new QTableWidgetItem(t.FirstName + " " + t.LastName));

        // Display Grade or Empty Cell
        if (!grades.isEmpty())
        {
            QString gradeText;
            for (const Grade& g : grades)
            {
                gradeText += g.GradeValue + ", ";
            }
            gradeText.chop(2); // Remove last comma
            ui->gradeTable->setItem(row, 3, new QTableWidgetItem(gradeText));
        }
        else
        {
            ui->gradeTable->setItem(row, 3, new QTableWidgetItem("-"));
        }
    }

}

void TeacherDiary::deleteGrade()
{
    if (ui->gradeTable->currentRow() == -1)
    {
        QMessageBox::warning(this, "Selection Error", "Please select a student to delete a grade.");
        return;
    }

    int selectedRow = ui->gradeTable->currentRow();
    int studentId = ui->gradeTable->item(selectedRow, 0)->text().toInt();

    QVector<Grade> grades = GradeService::getGradesByStudentId(studentId);

    if (grades.isEmpty())
    {
        QMessageBox::warning(this, "No Grades", "This student has no grades to delete.");
        return;
    }

    QMessageBox::StandardButton reply;
 
    reply = QMessageBox::question(this, "Delete Grade",
        "Are you sure you want to delete the last entered grade?",
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::No)
    {
        return;
    }

    GradeService::deleteGrade(grades.last().GradeId);

    loadGrades();
}


void TeacherDiary::addGrade()
{
    if (ui->gradeTable->currentRow() == -1)
    {
        QMessageBox::warning(this, "Selection Error", "Please select a student to add a grade.");
        return;
    }

    int selectedRow = ui->gradeTable->currentRow();

    int studentId = ui->gradeTable->item(selectedRow, 0)->text().toInt();

    QString gradeValue = ui->gradeComboBox->currentText();

    if (studentId <= 0 || gradeValue.isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields.");
        return;
    }

    GradeService::addGrade(studentId, CurrentUser::teacherId, gradeValue, QDateTime::currentDateTime());
    loadGrades();
}


void TeacherDiary::logout()
{
    Login* loginWindow = new Login();
    loginWindow->show();

    this->close();
}
