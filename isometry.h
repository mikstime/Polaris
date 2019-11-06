#ifndef ISOMETRY_H
#define ISOMETRY_H
#include <vector>

template <typename T>
class Isometry
{
public:
	Isometry(std::vector<T> _x, std::vector<T> _y, std::vector<T> _z, double angle);
	Isometry(std::vector<T> _x, std::vector<T> _y, std::vector<T> _z, double angle, double scaling);
	Isometry(std::vector<T> _x, std::vector<T> _y, std::vector<T> _z, double scaling);

	~Isometry();

	void TransformCoordinates( double angle );
	void Zooming(double scaling);
	void UpdateCoordinates(std::vector<T> _x, std::vector<T> _y, std::vector<T> _z);
	void UpdateCoordinates_all(std::vector<T> _x, std::vector<T> _y, std::vector<T> _z, double angle, double scaling);
	void UpdateCoordinates_angle(std::vector<T> _x, std::vector<T> _y, std::vector<T> _z, double angle);
	void UpdateCoordinates_scaling(std::vector<T> _x, std::vector<T> _y, std::vector<T> _z, double scaling);

	std::pair<std::vector<T> px, std::vector<T> py>PlaneCoordinates();

private:
	std::vector<T> x;
	std::vector<T> y;
	std::vector<T> z;

};

#endif // !ISOMETRY_H