#include <iostream>
#include <vector>
#include <algorithm> //std::sort

//print vector v with space as delimiter
void printVector (std::vector<int> v) {

    for (int i = 0; i < v.size(); i++) {
        if (i) {
            std::cout << " ";
        }
        std::cout << v[i];
    }
}

int main() {

    //number of students
    int n;
    std::cin >> n;

    //container for failed students
    std::vector<int> failed;

    //container for passed students
    std::vector<int> passed;

    //fetch inputs
    for (int i = 0; i < n; i++) {
        int tmp;
        std::cin >> tmp;
        if (tmp < 60) {
            failed.push_back(tmp);
        } else {
            passed.push_back(tmp);
        }
    }

    //sort two vector
    std::sort(failed.begin(), failed.end());
    std::sort(passed.begin(), passed.end());

    //print all grades
    printVector(failed);
    std::cout << " ";
    printVector(passed);
    std::cout << std::endl;

    //no students are failed if fail is empty
    if (failed.empty()) {
        std::cout << "best case" << std::endl;
    } else {
        //print out the largest grade of fail
        std::cout << failed[failed.size()-1] << std::endl;
    }

    //no students are passed if pass is empty
    if (passed.empty()) {
        std::cout << "worst case" << std::endl;
    } else {
        //print out the smallest grade of pass
        std::cout << passed[0] << std::endl;
    }
}
