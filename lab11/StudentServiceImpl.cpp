//
// Created by Boti on 12/8/2023.
//

#include <stdexcept>
#include <vector>

#include "StudentServiceImpl.h"


bool StudentServiceImpl::isEnrolled(int id) const {
    Student student = dao->findById(id);
}

