#ifndef ISOMETRY_H
#define ISOMETRY_H
#include <vector>

//C3V - трехмерные координаты, C2V - двухмерные координаты
template <typename C3V, typename C2V>
class Isometry
{
public:
	//Инициализация конструктора углом поворота и коэффицентом масштабирования
	Isometry(double angle, double scale);

	~Isometry();

	//Перевод трехмерных координат в двухмерные с учетом угла и масштаба
	void TransformCoordinates(std::vector<C3V> coordinates, std::vector<C2V> flat_coordinates);

	//Изменение коэффицента масштабирования
	void Zooming(double scale);
	//Изменение угла поворота
	void Scaling(double scale);

private:
	double angle;
	double scale;

};

#endif // !ISOMETRY_H
