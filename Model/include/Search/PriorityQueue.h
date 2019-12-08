#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <queue>

namespace Polaris
{
/******************************************************************************
 * class PriorityQueue.
 * Wrapper for std::priority_queue sorting items in ascending order
 *****************************************************************************/
template< typename T, typename P >
class PriorityQueue
{
private:
    using key = std::pair< P, T >;
    std::priority_queue< key, std::vector< key >, std::greater< key > > queue_;
public:
    /**************************************************************************
     * empty
     * Return value:
     * true if empty, false if not
     *************************************************************************/
    [[nodiscard]] bool empty() const {return queue_.empty();};
    /**************************************************************************
     * put
     * store item with priority in queue
     *************************************************************************/
    void put( T item, P priority ){
        queue_.emplace( priority, item );
    };
    /**************************************************************************
     * pop() Removes element with least priority in queue and returns it
     * Return value:
     * element with least priority.
     *************************************************************************/
    T pop(){
        T e = queue_.top().second;
        queue_.pop();
        return e;
    }
};
} //namespace Polaris

#endif //MAINAPP_PRIORITYQUEUE_H
