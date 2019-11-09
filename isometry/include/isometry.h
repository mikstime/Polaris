#ifndef ISOMETRY_H
#define ISOMETRY_H

#include <vector>

namespace Polaris
{
	template < typename C3V, typename C2V > // C3V - ���������� ����������, C2V - ���������� ����������
	class Isometry
	{
	public:
		// ������������� ������������ ����� �������� � ������������ ���������������
		Isometry( double angle, double scale );
		~Isometry();

		// ���������� ��������� � ����������
		void TransformCoordinates( std::vector< C3V > & coordinates,
			std::vector< C2V > & flat_coordinates );
		void Rotate( double angle ); // ��������� ����������� ���������������
		void Scaling( double scale ); // ��������� ���� ��������

	private:
		double angle;
		double scale;

	};

} // namespace Polaris
#endif // ISOMETRY_H