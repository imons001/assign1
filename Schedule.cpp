#include <utility>

#include "Schedule.h"

using namespace std::rel_ops;

Schedule::Node::Node(Course c)
    :data(c),
     next(nullptr)
{
}

//------------------------------------------------------------------------------
Schedule::Schedule()
    :head(nullptr),
     tail(nullptr),
     totalCredits(0)
{
}

/**
 * @todo implement this function (it is similar to Review 01)
 */
Schedule::Schedule(const Schedule& src)
    :head(nullptr),
     tail(nullptr),
     totalCredits(0)
{
    // Start the Copy Operations
    Node* srcIt = src.head;

    while (srcIt != nullptr) {

        this->appendNoCheck(srcIt->data);

        srcIt = srcIt->next;
    }
}

/**
 * @todo implement this function (it is similar to Review 01)
 */
Schedule::~Schedule()
{
    //create new nodes and set to nullptr
    Node *this_iterator = nullptr;
    Node *to_delete = nullptr;

    //starts at the beginning "head"
    this_iterator = this->head;

    //move through and delete each node
    while (this_iterator != nullptr){
        //set the first node to be deleted
        to_delete = this_iterator;

        //move to next node
        this_iterator = this_iterator->next;

        //delete current node
        delete to_delete;

        //don't have dangling pointers
        to_delete = nullptr;
    }

    head = nullptr;
    tail = nullptr;
    totalCredits = 0;
}

/**
 * @todo implement this function (it is similar to Review 01)
 */
void Schedule::appendNoCheck(Course course)
{
    //Create a new node
    Node *new_node = nullptr;

    //store data in new node
    new_node = new Node(course);

    //Check if it is the first node being added
    if (this->totalCredits == 0) {
        //If it is the first node then add it in
        this->head = new_node;
        this->tail = new_node;
    }
    else {
        //if it is not the first node, add to the end
        (this->tail)->next = new_node;
        this->tail = new_node;
    }

    //increase the total number of credits

    this->totalCredits = (this->totalCredits) + course.getCredits();

    new_node = nullptr;
}

/**
 * @todo implement this function
 */
bool Schedule::wouldViolateCreditLimit(Course course) const
{
    //Check if adding the course would exceed the credit limit
    if ((course.getCredits() + this->totalCredits) > CREDIT_LIMIT) {
        return true;
    } else {
        return false;
    }
}

/**
 * @todo implement this function
 */
bool Schedule::alreadyInSchedule(Course course) const
{
    // Check if the student is registered
    // for a different section of the same course

    Node* it = head;

    while (it != nullptr){
        //if the same course is already found then return true
        if (it->data.getNumber() == course.getNumber()) {
            return true;
        }
        it = it->next;
    }
    //if the same course was not found then return false
    return false;
}

//------------------------------------------------------------------------------
void Schedule::display(std::ostream& outs) const
{
    Node* it = head;

    outs << "  (" << totalCredits << " Total Credits)" << "\n";

    while (it != nullptr) {
        outs << "  - " << (it->data) << "\n";

        it = it->next;
    }
}

//------------------------------------------------------------------------------
Schedule& Schedule::operator=(Schedule rhs)
{
    swap(*this, rhs);

    return *this;
}
