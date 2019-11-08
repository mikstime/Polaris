#ifndef ISOMETRY_H
#define ISOMETRY_H

#include <vector>

namespace Polaris
{
	
template < typename C3V, typename C2V > // C3V - трехмерные координаты, C2V - двухмерные координаты
class Isometry
{
public:
	// Инициализация конструктора углом поворота и коэффицентом масштабирования
	Isometry( double angle = 0.0 , double scale = 1.0 );
	~Isometry();

	// Трехмерные координаы в двухмерные
	void TransformCoordinates( std::vector< C3V > & coordinates,
				  std::vector< C2V > & flat_coordinates );
	void Zooming( double scale ); // Изменение коэффицента масштабирования
	void Scaling( double scale ); // Изменение угла поворота

private:
	double angle;
	double scale;

};
	
} // namespace Polaris
#endif // ISOMETRY_H
