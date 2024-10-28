#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "CalcList.hpp"

using namespace std;

CalcList::CalcList(){
    head = NULL;
}

void CalcList::newOperation(const FUNCTIONS func, const double operand){
    nodePtr curr = new node;
    curr->next = NULL;
    if (head == NULL){ //if list is empty set total and number of steps to 0
	    curr->step_total = 0; 
	    curr->step_num = 0;
    }
    else{
        curr->step_total = head->step_total;
        curr->step_num = head->step_num;
    }
    switch (func) {
        case ADDITION: //logs the previous total, the sum, the operator, and operand
	        curr->prev_total = curr->step_total;
            curr->step_total += operand;
            curr->step_func = '+';
            curr->step_op = operand;
            break;
        case SUBTRACTION: //logs the previous total, the difference, the operator, and operand
	        curr->prev_total = curr->step_total;
            curr->step_total -= operand;
            curr->step_func = '-';
            curr->step_op = operand;
            break;
        case MULTIPLICATION: //logs the previous total, the product, the operator, and operand
	        curr->prev_total = curr->step_total;
            curr->step_total *= operand;
            curr->step_func = '*';
            curr->step_op = operand;
            break;
        case DIVISION:      
            if (operand == 0){ //throws if divided by 0
		        throw 10;
	        }
            else{               //logs the previous total, the quotient, the operator, and operand
                curr->prev_total = curr->step_total;
                curr->step_total /= operand;
                curr->step_func = '/';
                curr->step_op = operand;
                }		
                break;
        }
    curr->step_num = curr->step_num + 1; //updates number of steps/equations
    curr->next = head; //adds curr to front of list
    head = curr; //sets head to curr

}

void CalcList::removeLastOperation(){
    if (head == NULL) { //throws if trying to remove node from empty list
        throw 10;
    }
    
    nodePtr temp = head;
    head = head->next;
    delete temp;
    }

double CalcList::total() const{
    if (head == NULL){ //sets total to zero if list is empty
	    return 0;
    }
    return head->step_total;
}
std::string CalcList::toString(unsigned short precision) const{
    ostringstream os;
    
    for(nodePtr curr = head; curr != NULL; curr = curr->next){    
        os << curr->step_num << ": "
        << fixed << setprecision(precision) << curr->prev_total << curr->step_func 
        << fixed << setprecision(precision) << curr->step_op << "=" 
        << fixed << setprecision(precision) << curr->step_total << "\n";
    }   
    return os.str();

}
