#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <queue>

namespace Polaris
{
template< typename T, typename P >
class PriorityQueue
{
private:
    using key = std::pair< P, T >;
    std::priority_queue< key, std::vector< key >, std::greater< key > > queue_;
public:
    [[nodiscard]] bool empty() const {return queue_.empty();};
    void put( T item, P priority ){
        queue_.emplace( priority, item );
    };
    T pop(){
        T e = queue_.top().second;
        queue_.pop();
        return e;
    }
};
} //namespace Polaris

#endif //MAINAPP_PRIORITYQUEUE_H
