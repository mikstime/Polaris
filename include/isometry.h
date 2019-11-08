#ifndef ISOMETRY_H
#define ISOMETRY_H

#include <vector>

namespace Polaris;
{
	
template < typename C3V, typename C2V > // C3V - трехмерные координаты, C2V - двухмерные координаты
class Isometry
{
public:
	Isometry( double angle, double scale ); // Инициализация конструктора углом поворота и коэффицентом масштабирования
	~Isometry();

	void TransformCoordinates( std::vector< C3V > & coordinates, std::vector< C2V > & flat_coordinates ); // Трехмерные координаы в двухмерные
	void Zooming( double scale ); // Изменение коэффицента масштабирования
	void Scaling( double scale ); // Изменение угла поворота

private:
	double angle;
	double scale;

};
	
} // namespace Polaris
#endif // ISOMETRY_H
