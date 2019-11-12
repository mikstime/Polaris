#ifndef GRAPHSEARCH_GRAPHCONNECTION_HPP
#define GRAPHSEARCH_GRAPHCONNECTION_HPP

#include "include/GraphElement/GraphElement.h"
#include <cstddef> //std::size_t
namespace Polaris
{
using Price = double;
using Id = std::size_t;
struct ConnectionParams
{
    Price cost;
};
struct GraphConnection: public GraphElement
{
public:
    Id from, to;
    Price cost;
};
}//namespace Polaris

#endif //GRAPHSEARCH_GRAPHCONNECTION_HPP
