#include "isometry.h"

using namespace Polaris;

template < typename C3V, typename C2V >
Isometry< C3V, C2V >::Isometry( double angle = 0.0 , double scale = 1.0 )
{
}

template < typename C3V, typename C2V >
Isometry< C3V, C2V >::~Isometry()
{
}

template < typename C3V, typename C2V >
void Isometry< C3V, C2V >::TransformCoordinates( std::vector< C3V > & coordinates,
                                                std::vector< C2V > & flat_coordinates )
{
}

template < typename C3V, typename C2V >
void Isometry< C3V, C2V >::Zooming( double scale )
{
}

template < typename C3V, typename C2V >
void Isometry< C3V, C2V >::Scaling( double scale )
{
}
