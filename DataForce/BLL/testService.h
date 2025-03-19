#pragma once

#include "../DAL/test.h"
#include "currentUser.h"
#include <QVector>

class TestService {
public:
    static QVector<Test> getAllTests();
    static void addTest(Test test);
    static void editTest(int id, QString title);
    static void deleteTest(int id);
    static Test getTestById(int testId);
    static int getNextTestId();
};