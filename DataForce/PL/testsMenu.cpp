#include "testsMenu.h"

TestsMenu::TestsMenu(QWidget *parent) : QMainWindow(parent), ui(new Ui::TestsMenuClass())
{
	ui->setupUi(this);
    menuWindow = parent;
    loadTests();

    connect(ui->tableWidget, &QTableWidget::itemDoubleClicked, this, &TestsMenu::openTest);
    connect(ui->backButton, &QPushButton::clicked, this, &TestsMenu::onBackButtonClicked);
    connect(ui->refreshButton, &QPushButton::clicked, this, &TestsMenu::loadTests);

}

TestsMenu::~TestsMenu()
{
}

void TestsMenu::loadTests() 
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    QVector<Test> tests = TestService::getAllTests();
    ui->tableWidget->setRowCount(tests.size());

    for (int i = 0; i < tests.size(); i++) 
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(tests[i].TestId)));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(tests[i].Title));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(tests[i].TeacherId)));

        if (CurrentUser::role == "student")
        {
            QString grade = TestStudentService::getTestGradeById(tests[i].TestId, CurrentUser::studentId);
            
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem(grade));
        }
        else
        {
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem(""));
        }
    }
}

void TestsMenu::openTest()
{
    QTableWidgetItem* selectedItem = ui->tableWidget->currentItem();

    if (selectedItem)
    {
        int row = selectedItem->row();
        int testId = ui->tableWidget->item(row, 0)->text().toInt();

        if (CurrentUser::role == "teacher")
        {
            TeacherTestWindow* teacherTestWindow = new TeacherTestWindow(this);
            teacherTestWindow->setTest(testId);
            teacherTestWindow->show();
        }
        else if (CurrentUser::role == "student")
        {
            QString grade = TestStudentService::getTestGradeById(testId, CurrentUser::studentId);

            if (grade == "Not Graded")  // Student doesn't have a grade, so they can open the test
            {
                StudentTestWindow* studentTestWindow = new StudentTestWindow(this);
                studentTestWindow->setTest(testId);
                studentTestWindow->show();
            }
            else 
            {
                QMessageBox::information(this, "Test already completed", "You have already completed this test and cannot take it again.");
            }
        }
    }
}

void TestsMenu::onBackButtonClicked()
{
    this->hide();
    menuWindow->show();
}