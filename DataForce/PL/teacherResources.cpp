#include "teacherResources.h"
#include <login.h>

TeacherResources::TeacherResources(QWidget *parent) : QMainWindow(parent), ui(new Ui::TeacherResourcesClass())
{
	ui->setupUi(this);

    connect(ui->openResourceButton, &QPushButton::clicked, this, &TeacherResources::openResource);
    connect(ui->addResourceButton, &QPushButton::clicked, this, &TeacherResources::addResource);
    connect(ui->deleteResourceButton, &QPushButton::clicked, this, &TeacherResources::deleteResource);
    connect(ui->logoutButton, &QPushButton::clicked, this, &TeacherResources::logout);

    loadPdfList();
}

TeacherResources::~TeacherResources()
{
	delete ui;
}


void TeacherResources::loadPdfList()
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

void TeacherResources::openResource()
{
    QListWidgetItem* selectedItem = ui->pdfListWidget->currentItem();

    if (selectedItem)
    {
        QString filePath = selectedItem->text();
        QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
    }
}

void TeacherResources::addResource()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Select PDF", "", "PDF Files (*.pdf)");

    if (!filePath.isEmpty())
    {
        QString targetDirectory = QDir::currentPath() + "/pdfs/9th-grade/";

        QDir dir(targetDirectory);

        if (!dir.exists())
        {
            dir.mkpath(targetDirectory);
        }

        QFile::copy(filePath, targetDirectory + QFileInfo(filePath).fileName());

        loadPdfList();
    }
}

void TeacherResources::deleteResource()
{
    QListWidgetItem* selectedItem = ui->pdfListWidget->currentItem();

    if (selectedItem)
    {
        QString filePath = selectedItem->text();

        // Confirm deletion
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Delete Resource", "Are you sure you want to delete this resource?", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes)
        {
            QFile::remove(filePath);
            loadPdfList();
        }
    }
    else
    {
        QMessageBox::information(this, "No selection", "Please select a PDF to delete.");
    }
}

void TeacherResources::logout()
{
    Login* loginWindow = new Login();
    loginWindow->show();

    this->close();
}