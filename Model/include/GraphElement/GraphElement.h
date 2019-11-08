#ifndef GRAPHSEARCH_GRAPHELEMENT_HPP
#define GRAPHSEARCH_GRAPHELEMENT_HPP

#include <cstddef>

namespace Polaris
{
class GraphElement
{
using ID = size_t;
public:
    GraphElement();
    GraphElement( GraphElement const & );
    GraphElement( GraphElement && ) noexcept;
    ~GraphElement() = default;
    ID getId() { return id_; }
private:
    ID id_;
};
}//namespace Polaris

#endif //GRAPHSEARCH_GRAPHELEMENT_HPP
