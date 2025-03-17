#include "teacherTestWindow.h"
#include "../BLL/studentService.h"

TeacherTestWindow::TeacherTestWindow(QWidget *parent) : QDialog(parent), ui(new Ui::TeacherTestWindowClass())
{
	ui->setupUi(this);
    
    // Connect UI signals to slots
    connect(ui->nextButton, &QPushButton::clicked, this, &TeacherTestWindow::nextQuestion);
    connect(ui->previousButton, &QPushButton::clicked, this, &TeacherTestWindow::previousQuestion);
    connect(ui->saveButton, &QPushButton::clicked, this, &TeacherTestWindow::saveQuestion);
    connect(ui->addButton, &QPushButton::clicked, this, &TeacherTestWindow::addQuestion);
    connect(ui->deleteButton, &QPushButton::clicked, this, &TeacherTestWindow::deleteQuestion);
    connect(ui->viewGradesButton, &QPushButton::clicked, this, &TeacherTestWindow::viewGrades);
    
}

TeacherTestWindow::~TeacherTestWindow()
{}

void TeacherTestWindow::setTest(int id)
{
    this->testId = id;
    this->currentTest = TestService::getTestById(testId);
    loadQuestions();
}

void TeacherTestWindow::loadQuestions()
{
    this->questions = QuestionService::getQuestionsByTest(testId);

    if (!questions.isEmpty())
    {
        currentQuestion = 0;
        loadQuestion(questions[currentQuestion].QuestionId);
    }
}

void TeacherTestWindow::loadQuestion(int questionId)
{
    if (currentQuestion == questions.count() - 1)
    {
        ui->nextButton->hide();
    }
    else
    {
        ui->nextButton->show();
    }

    if (currentQuestion == 0)
    {
        ui->previousButton->hide();
    }
    else
    {
        ui->previousButton->show();
    }

    for (const Question& q : questions)
    {
        if (q.QuestionId == questionId)
        {
            ui->title->setText(currentTest.Title);
            ui->question->setText(q.Text);
            ui->optionA->setText("  A: " + q.OptionA);
            ui->optionB->setText("  B: " + q.OptionB);
            ui->optionC->setText("  C: " + q.OptionC);
            ui->optionD->setText("  D: " + q.OptionD);
            ui->correctAnswer->setCurrentText(q.CorrectAnswer);
            return;
        }
    }
}

void TeacherTestWindow::nextQuestion()
{
    if (currentQuestion < questions.count() - 1)
    {
        currentQuestion++;
        loadQuestion(questions[currentQuestion].QuestionId);
    }
}

void TeacherTestWindow::previousQuestion()
{
    if (currentQuestion > 0)
    {
        currentQuestion--;
        loadQuestion(questions[currentQuestion].QuestionId);
    }
}

void TeacherTestWindow::saveQuestion()
{
    if (questions.isEmpty() || currentQuestion >= questions.size())
        return;

    Question q = questions[currentQuestion];

    q.Text = ui->question->text();
    q.OptionA = ui->optionA->text().mid(5); // remove A:
    q.OptionB = ui->optionB->text().mid(5);
    q.OptionC = ui->optionC->text().mid(5);
    q.OptionD = ui->optionD->text().mid(5);
    q.CorrectAnswer = ui->correctAnswer->currentText();

    QuestionService::updateQuestion(q);
}

void TeacherTestWindow::addQuestion()
{
    Question newQuestion;
    newQuestion.TestId = testId;
    newQuestion.Text = "Question";
    newQuestion.OptionA = "Option A";
    newQuestion.OptionB = "Option B";
    newQuestion.OptionC = "Option C";
    newQuestion.OptionD = "Option D";
    newQuestion.CorrectAnswer = "A";

    QuestionService::addQuestion(newQuestion);

    currentQuestion = questions.count();
    this->questions = QuestionService::getQuestionsByTest(testId);
    loadQuestion(questions[currentQuestion].QuestionId);
}

void TeacherTestWindow::deleteQuestion()
{
    if (questions.isEmpty() || currentQuestion >= questions.size())
        return;

    Question& q = questions[currentQuestion];

    QuestionService::deleteQuestion(q.QuestionId);

    this->questions = QuestionService::getQuestionsByTest(testId);

    
    if (currentQuestion >= questions.count())
    {
        currentQuestion = questions.count() - 1;
    }

    if (questions.count() > 0)
    {
        loadQuestion(questions[currentQuestion].QuestionId);
    }
    else
    {
        ui->title->clear();
        ui->question->clear();
        ui->optionA->clear();
        ui->optionB->clear();
        ui->optionC->clear();
        ui->optionD->clear();
        ui->correctAnswer->clear();

        ui->nextButton->hide();
        ui->previousButton->hide();
    }
}

void TeacherTestWindow::viewGrades()
{
    QVector<TestStudent> grades = TestStudentService::getTestGradesByTestId(testId);

    if (grades.isEmpty())
    {
        QMessageBox::information(this, "No Grades", "No students have attempted this test yet.");
        return;
    }

    QString gradeInfo = "Student Name - Grade\n----------------------\n";
    
    for (const TestStudent& grade : grades)
    {
        Student student = StudentService::getStudentById(grade.StudentId);
        QString studentName = student.FirstName + " " + student.LastName;

        gradeInfo += QString("%1 - %2\n").arg(studentName).arg(grade.Grade);
    }

    QMessageBox::information(this, "Student Grades", gradeInfo);
}