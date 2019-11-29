#ifndef GRAPHSEARCH_GRAPHCONNECTION_HPP
#define GRAPHSEARCH_GRAPHCONNECTION_HPP

#include "include/GraphElement/GraphElement.h"
namespace Polaris
{
struct GraphConnection: public GraphElement
{
using Price = double;
public:
    GraphConnection();
    GraphConnection( GraphConnection const & );
    GraphConnection( GraphConnection && ) noexcept;
    ~GraphConnection();

    GraphElement * Neighbor;
    Price cost;
};
}//namespace Polaris

#endif //GRAPHSEARCH_GRAPHCONNECTION_HPP
