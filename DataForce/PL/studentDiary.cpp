#include "studentDiary.h"
#include <login.h>

StudentDiary::StudentDiary(QWidget *parent) : QMainWindow(parent), ui(new Ui::StudentDiaryClass())
{
	ui->setupUi(this);
	menuWindow = parent;  // Store the menu reference
    loadGrades();

    connect(ui->backButton, &QPushButton::clicked, this, &StudentDiary::onBackButtonClicked);
}

StudentDiary::~StudentDiary()
{
	delete ui;
}

void StudentDiary::loadGrades()
{
    Student student = StudentService::getStudentById(CurrentUser::studentId);
    ui->gradeTable->setRowCount(0);

    QVector<Grade> grades = GradeService::getGradesByStudentId(CurrentUser::studentId);

    for (Grade& g : grades)
    {
        int row = ui->gradeTable->rowCount();
        ui->gradeTable->insertRow(row);

        Teacher t = TeacherService::getTeacherById(g.TeacherId);

        ui->gradeTable->setItem(row, 0, new QTableWidgetItem(g.GradeDate.toString("yyyy-MM-dd HH:mm:ss")));
        ui->gradeTable->setItem(row, 1, new QTableWidgetItem(student.FirstName + " " + student.LastName));
        ui->gradeTable->setItem(row, 2, new QTableWidgetItem(t.FirstName + " " + t.LastName));
        ui->gradeTable->setItem(row, 3, new QTableWidgetItem(g.GradeValue));
    }
}


void StudentDiary::onBackButtonClicked()
{
    this->hide();
    menuWindow->show();
}