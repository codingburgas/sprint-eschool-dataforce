#include "studentTestWindow.h"
#include "../BLL/testStudentService.h"

StudentTestWindow::StudentTestWindow(QWidget *parent) : QDialog(parent), ui(new Ui::StudentTestWindowClass())
{
	ui->setupUi(this);

    connect(ui->nextButton, &QPushButton::clicked, this, &StudentTestWindow::nextQuestion);
    connect(ui->previousButton, &QPushButton::clicked, this, &StudentTestWindow::previousQuestion);
    connect(ui->optionA, &QPushButton::clicked, this, &StudentTestWindow::selectOptionA);
    connect(ui->optionB, &QPushButton::clicked, this, &StudentTestWindow::selectOptionB);
    connect(ui->optionC, &QPushButton::clicked, this, &StudentTestWindow::selectOptionC);
    connect(ui->optionD, &QPushButton::clicked, this, &StudentTestWindow::selectOptionD);
}

StudentTestWindow::~StudentTestWindow()
{}


void StudentTestWindow::setTest(int id)
{
    this->testId = id;
    this->currentTest = TestService::getTestById(testId);
    loadQuestions();
}

void StudentTestWindow::loadQuestions()
{
    this->questions = QuestionService::getQuestionsByTest(testId);

    if (!questions.isEmpty())
    {
        currentQuestion = 0;
        loadQuestion(questions[currentQuestion].QuestionId);
    }
}

void StudentTestWindow::loadQuestion(int questionId)
{
    if (currentQuestion == questions.count() - 1)
    {
        ui->nextButton->setText("Finish"); // Change the button to "Finish Test" on the last question
    }
    else
    {
        ui->nextButton->setText("Next");
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
            ui->optionA->setText(q.OptionA);
            ui->optionB->setText(q.OptionB);
            ui->optionC->setText(q.OptionC);
            ui->optionD->setText(q.OptionD);

            return;
        }
    }
}

void StudentTestWindow::nextQuestion()
{
    if (currentQuestion < questions.count() - 1)
    {
        currentQuestion++;
        loadQuestion(questions[currentQuestion].QuestionId);
    }
    else
    {
        finishTest(); // If it's the last question, finish the test
    }
}

void StudentTestWindow::previousQuestion()
{
    if (currentQuestion > 0)
    {
        currentQuestion--;
        loadQuestion(questions[currentQuestion].QuestionId);
    }
}


void StudentTestWindow::selectOptionA()
{
    selectedAnswers[questions[currentQuestion].QuestionId] = "A";
    
    if (ui->nextButton->text() == "Finish")
    {
        finishTest();
    }
    else
    {
        nextQuestion();
    }
}

void StudentTestWindow::selectOptionB()
{
    selectedAnswers[questions[currentQuestion].QuestionId] = "B";
    
    if (ui->nextButton->text() == "Finish")
    {
        finishTest();
    }
    else
    {
        nextQuestion();
    }
}

void StudentTestWindow::selectOptionC()
{
    selectedAnswers[questions[currentQuestion].QuestionId] = "C";
    
    if (ui->nextButton->text() == "Finish")
    {
        finishTest();
    }
    else
    {
        nextQuestion();
    }
}

void StudentTestWindow::selectOptionD()
{
    selectedAnswers[questions[currentQuestion].QuestionId] = "D";
    
    if (ui->nextButton->text() == "Finish")
    {
        finishTest();
    }
    else
    {
        nextQuestion();
    }
}

QString StudentTestWindow::calculateGrade()
{
    score = 0;

    for (auto it = selectedAnswers.begin(); it != selectedAnswers.end(); ++it)
    {
        int questionId = it.key();
        QString selectedAnswer = it.value();

        for (const Question& q : questions)
        {
            if (q.QuestionId == questionId)
            {
                if (selectedAnswer == q.CorrectAnswer)
                {
                    score++;
                }
                break;
            }
        }
    }

    QString grade = "F";
    double percentage = (score / questions.count()) * 100;

    if (percentage > 90)
    {
        grade = "A";
    }
    else if (percentage > 80)
    {
        grade = "B";
    }
    else if (percentage > 70)
    {
        grade = "C";
    }
    else if (percentage > 60)
    {
        grade = "D";
    }


    qDebug() << "Student's Score: " << score;
    return grade;
}

void StudentTestWindow::finishTest()
{
    TestStudentService::addTestGrade(testId, CurrentUser::studentId, calculateGrade());

    // Show a message box with the result
    QMessageBox::information(this, "Test Finished", "Your score is: " + QString::number(score) + "/" + QString::number(questions.count()));

    // Disable all buttons after finishing the test
    ui->nextButton->setEnabled(false);
    ui->previousButton->setEnabled(false);
    ui->optionA->setEnabled(false);
    ui->optionB->setEnabled(false);
    ui->optionC->setEnabled(false);
    ui->optionD->setEnabled(false);
}