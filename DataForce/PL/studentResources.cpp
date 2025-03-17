#include "studentResources.h"
#include <login.h>

StudentResources::StudentResources(QWidget *parent) : QMainWindow(parent), ui(new Ui::StudentResourcesClass())
{
	ui->setupUi(this);
    menuWindow = parent;

    connect(ui->openResourceButton, &QPushButton::clicked, this, &StudentResources::openResource);
    connect(ui->backButton, &QPushButton::clicked, this, &StudentResources::onBackButtonClicked);
    
    loadPdfList();
}

StudentResources::~StudentResources()
{
	delete ui;
}

void StudentResources::loadPdfList()
{
    ui->pdfListWidget->clear();

    QString directoryPath = QDir::currentPath() + "/pdfs/9th-grade";

    QDir directory(directoryPath);
    QStringList filters;
    filters << "*.pdf"; // Filter only PDF files

    QFileInfoList files = directory.entryInfoList(filters, QDir::Files);

    for (const QFileInfo& fileInfo : files)
    {
        ui->pdfListWidget->addItem(fileInfo.filePath());
    }
}

void StudentResources::openResource()
{
    QListWidgetItem* selectedItem = ui->pdfListWidget->currentItem();

    if (selectedItem)
    {
        QString filePath = selectedItem->text();
        QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
    }
}

void StudentResources::onBackButtonClicked()
{
    this->hide();
    menuWindow->show();
}
