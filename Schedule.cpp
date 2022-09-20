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
{
    // Start the Copy Operations
    std::cout << "in copy function" << std::endl;
    this->head = nullptr;
    this->tail = nullptr;
    this->totalCredits = 0;

    Node* srcIt = src.head;

    while (srcIt != nullptr) {
        std::cout << "in while function" << std::endl;
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
    ///nodes = 0;
}

/**
 * @todo implement this function (it is similar to Review 01)
 */
void Schedule::appendNoCheck(Course course)
{
    Node *new_node = nullptr;

    new_node = new Node(course);

    if (this->head == nullptr) {
        this->head = new_node;
        this->tail = new_node;
    } else {
        (this->tail)->next = new_node;
        this->tail = new_node;
    }
    this->totalCredits++;

    new_node = nullptr;
}

/**
 * @todo implement this function
 */
bool Schedule::wouldViolateCreditLimit(Course course) const
{
    // The following line is a placeholder (i.e., enough for the code to
    // compile). Remove it when you start implementing this function.

    Node* it = head;

    while (it != nullptr) {

        if ((course.getCredits() + this->totalCredits) > CREDIT_LIMIT) {
            return false;
        } else {
            return true;
        }

        it = it->next;
    }
}

/**
 * @todo implement this function
 */
bool Schedule::alreadyInSchedule(Course course) const
{
    // Check if the student is registered
    // for a different section of the same course

    // The following line is a placeholder (i.e., enough for the code to
    // compile). Remove it when you start implementing this function.
    return true;
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
