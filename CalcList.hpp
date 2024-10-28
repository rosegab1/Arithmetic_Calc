#ifndef CALCLIST_H
#define CALCLIST_H
#include "CalcListInterface.hpp"
#include <string>

class CalcList : public CalcListInterface{
    public:
        CalcList();
        double total() const;
        void newOperation(const FUNCTIONS func, const double operand);
        void removeLastOperation();
        std::string toString(unsigned short precision) const;
    private:
        typedef struct node{
        int step_num;
        double step_total = 0;
        double prev_total;
        double step_op;
        std::string step_func;
        node* next;
        }* nodePtr;
        nodePtr head;
        
};
#endif  /*CALCLIST_H*/
