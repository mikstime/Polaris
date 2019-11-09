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
		Isometry( int angle, int scale );
		~Isometry();

		// Трехмерные координаы в двухмерные
		void TransformCoordinates( std::vector< C3V > & coordinates,
			std::vector< C2V > & flat_coordinates );
		void Rotate( int angle ); // Изменение коэффицента масштабирования
		void Scaling( int scale ); // Изменение угла поворота

	private:
		int angle;
		int scale;

	};

} // namespace Polaris
#endif // ISOMETRY_H
