//
// Created by jfrye on 11/2/16.
//

#ifndef ALGORITHMS_STUDY_CPP_SORTING_H
#define ALGORITHMS_STUDY_CPP_SORTING_H

void HelloWorld();

/** Search an array for a value, return index if found.
 * @param   vec     Sequence to be searched
 * @param   value   Value to be searched for
 * @return          Index that the value was found at.
 *      If value was not found, exception is thrown.
 */
long LinearSearch(const std::vector<int> &vec, const int value);

#endif //ALGORITHMS_STUDY_CPP_SORTING_H
