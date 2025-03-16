#include "teacherDiary.h"
#include <QMessageBox>

TeacherDiary::TeacherDiary(QWidget *parent) : QMainWindow(parent), ui(new Ui::TeacherDiaryClass())
{
	ui->setupUi(this);
	menuWindow = parent;
    loadGrades();

	connect(ui->backButton, &QPushButton::clicked, this, &TeacherDiary::onBackButtonClicked);
    connect(ui->addGradeButton, &QPushButton::clicked, this, &TeacherDiary::addGrade);
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


//
//void TeacherDiary::loadGrades()
//{
//    QVector<Grade> grades = GradeService::getGradesByClass(CurrentUser::className);
//
//    ui->gradeTable->setRowCount(0);
//
//    for (const Grade& g : grades)
//    {
//        int row = ui->gradeTable->rowCount();
//
//        qDebug() << StudentService::getStudentById(g.StudentId).FirstName;
//
//        ui->gradeTable->insertRow(row);
//        ui->gradeTable->setItem(row, 0, new QTableWidgetItem(StudentService::getStudentById(g.StudentId).FirstName + " " + StudentService::getStudentById(g.StudentId).LastName));
//        ui->gradeTable->setItem(row, 1, new QTableWidgetItem(TeacherService::getTeacherById(g.TeacherId).FirstName + " " + TeacherService::getTeacherById(g.TeacherId).LastName));
//        ui->gradeTable->setItem(row, 2, new QTableWidgetItem(g.GradeValue));
//    }
//}

void TeacherDiary::updateGrade()
{
    int selectedRow = ui->gradeTable->currentRow();

    if (selectedRow == -1)
    {
        QMessageBox::warning(this, "Selection Error", "Please select a grade to update.");
        return;
    }

    int gradeId = ui->gradeTable->item(selectedRow, 0)->text().toInt();
    QString newGrade = ui->gradeComboBox->currentText();

    GradeService::updateGrade(gradeId, newGrade);
    loadGrades();
}

void TeacherDiary::addGrade()
{
    if (ui->gradeTable->currentRow() == -1)
    {
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

    qDebug() << "dddd";

    GradeService::addGrade(studentId, CurrentUser::teacherId, CurrentUser::className, gradeValue);
    loadGrades();
}


void TeacherDiary::onBackButtonClicked()
{
	this->hide();
	menuWindow->show();
}
