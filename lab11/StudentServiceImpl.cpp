//
// Created by Boti on 12/8/2023.
//

#include "StudentServiceImpl.h"


bool StudentServiceImpl::isEnrolled(int id) const {
    try {
        dao->findById(id);
        return true;
    } catch (const std::out_of_range &ex) {
        return false;
    }
}

vector<string> StudentServiceImpl::getSubjects(int id) const {
    Student student = dao->findById(id);
}

double StudentServiceImpl::getResultBySubject(int id, const string &subject) const {
}
