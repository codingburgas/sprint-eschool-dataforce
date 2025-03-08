#include "studentResources.h"

StudentResources::StudentResources(QWidget *parent) : QMainWindow(parent), ui(new Ui::StudentResourcesClass())
{
	ui->setupUi(this);

    auto* centralWidget = new QWidget(this);
    auto* layout = new QVBoxLayout(centralWidget);

    // Create list widget for PDFs
    pdfListWidget = new QListWidget(this);
    openResourceButton = new QPushButton("Open Resource", this);

    layout->addWidget(pdfListWidget);
    layout->addWidget(openResourceButton);

    setCentralWidget(centralWidget);

    connect(openResourceButton, &QPushButton::clicked, this, &StudentResources::openResource);

    loadPdfList();
}

StudentResources::~StudentResources()
{
	delete ui;
}

void StudentResources::loadPdfList()
{
    pdfListWidget->clear();

    QString directoryPath = QDir::currentPath() + "/pdfs/9th-grade";

    QDir directory(directoryPath);
    QStringList filters;
    filters << "*.pdf"; // Filter only PDF files

    QFileInfoList files = directory.entryInfoList(filters, QDir::Files);

    for (const QFileInfo& fileInfo : files)
    {
        pdfListWidget->addItem(fileInfo.filePath());
    }
}

void StudentResources::openResource()
{
    QListWidgetItem* selectedItem = pdfListWidget->currentItem();

    if (selectedItem)
    {
        QString filePath = selectedItem->text();
        QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
    }
}