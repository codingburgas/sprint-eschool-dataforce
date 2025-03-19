#include "test.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

QVector<Test> Test::readFromFile()
{
    QVector<Test> tests = {};
    QFile file("../DAL/data/tests.txt");

    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        in.readLine(); // Skip header line

        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList fields = line.split(",");

            if (fields.size() == 3)
            {
                Test test;
                test.TestId = fields[0].toInt();
                test.Title = fields[1];
                test.TeacherId = fields[2].toInt();

                tests.push_back(test);
            }
        }
        file.close();
    }
    else {
        qDebug() << "Failed to open the file for reading!";
    }
    return tests;
}

void Test::writeToFile(QVector<Test> tests) {
    QFile file("../DAL/data/tests.txt");

    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        out << "TestId,Title,TeacherId\n";

        for (const Test& test : tests)
        {
            out << test.TestId << ","
                << test.Title << ","
                << test.TeacherId << "\n";
        }
        file.close();
    }
    else {
        qDebug() << "Failed to open the file for writing!";
    }
}
