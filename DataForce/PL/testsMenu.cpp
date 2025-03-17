#include "testsMenu.h"

TestsMenu::TestsMenu(QWidget* parent) : QMainWindow(parent), ui(new Ui::TestsMenuClass())
{
    ui->setupUi(this);
    menuWindow = parent;

    scrollAreaWidget = new QWidget();
    scrollLayout = new QGridLayout(scrollAreaWidget);

    ui->scrollArea->setWidget(scrollAreaWidget);
    ui->scrollArea->setWidgetResizable(true);

    loadTests();

    connect(ui->backButton, &QPushButton::clicked, this, &TestsMenu::onBackButtonClicked);
    connect(ui->refreshButton, &QPushButton::clicked, this, &TestsMenu::loadTests);
}

TestsMenu::~TestsMenu()
{
}

void TestsMenu::loadTests()
{
    // Clear previous buttons
    qDeleteAll(scrollLayout->children());

    QVector<Test> tests = TestService::getAllTests();
    int columns = 4;
    int row = 0, col = 0;

    QStringList colors = {
        "#ff9a9e, #fad0c4", "#a1c4fd, #c2e9fb", "#d4fc79, #96e6a1",
        "#fbc2eb, #a6c1ee", "#ffecd2, #fcb69f", "#f6d365, #fda085",
        "#84fab0, #8fd3f4", "#a18cd1, #fbc2eb"
    };

    for (int i = 0; i < tests.size(); i++)
    {
        QString testTitle = tests[i].Title;

        if (CurrentUser::role == "student")
        {
            QString grade = TestStudentService::getTestGradeById(tests[i].TestId, CurrentUser::studentId);

            if (grade != "Not Graded")
            {
                testTitle += " ✅";
            }
        }

        QPushButton* testButton = new QPushButton(testTitle);
        testButton->setFixedSize(120, 70);
        testButton->setProperty("testId", tests[i].TestId);

        QString gradientColor = colors[i % colors.size()];

        testButton->setStyleSheet(QString(R"(
            QPushButton {
                background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 %1, stop:1 %2);
                border: 2px solid rgba(0,0,0,0.2);
                border-radius: 10px;
                font-size: 14px;
                font-weight: bold;
                color: white;
                padding: 5px;
            }
            QPushButton:hover {
                background: rgba(255,255,255,0.2);
            }
        )").arg(gradientColor.split(", ")[0], gradientColor.split(", ")[1]));

        connect(testButton, &QPushButton::clicked, this, [=]() { openTest(tests[i].TestId); });

        scrollLayout->addWidget(testButton, row, col);
        col++;
        
        if (col >= columns) 
        {
            col = 0;
            row++;
        }
    }
}

void TestsMenu::openTest(int testId)
{
    if (CurrentUser::role == "teacher")
    {
        TeacherTestWindow* teacherTestWindow = new TeacherTestWindow(this);
        teacherTestWindow->setTest(testId);
        teacherTestWindow->show();
    }
    else if (CurrentUser::role == "student")
    {
        QString grade = TestStudentService::getTestGradeById(testId, CurrentUser::studentId);

        if (grade == "Not Graded")
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

void TestsMenu::onBackButtonClicked()
{
    this->hide();
    menuWindow->show();
}
