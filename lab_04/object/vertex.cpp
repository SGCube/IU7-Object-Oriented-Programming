#include <cmath>

#include "vertex.h"

Vertex::Vertex() : x(0), y(0), z(0) {}

Vertex::Vertex(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}

Vertex::Vertex(const Vertex &vertex)
{
	this->x = vertex.x;
	this->y = vertex.y;
	this->z = vertex.z;
}

Vertex::Vertex(Vertex &&vertex)
{
	this->x = vertex.x;
	this->y = vertex.y;
	this->z = vertex.z;
	vertex.~Vertex();
}

Vertex &Vertex::operator=(const Vertex &vertex)
{
	this->x = vertex.x;
	this->y = vertex.y;
	this->z = vertex.z;
	return *this;
}

Vertex &Vertex::operator=(Vertex &&vertex)
{
	this->x = vertex.x;
	this->y = vertex.y;
	this->z = vertex.z;
	vertex.~Vertex();
	return *this;
}

double Vertex::getX() const
{
	return x;
}

void Vertex::setX(double value)
{
	x = value;
}

double Vertex::getY() const
{
	return y;
}

void Vertex::setY(double value)
{
	y = value;
}

double Vertex::getZ() const
{
	return z;
}

void Vertex::setZ(double value)
{
	z = value;
}

void Vertex::move(double dx, double dy, double dz)
{
	x += dx;
	y += dy;
	z += dz;
}

void Vertex::scale(double kx, double ky, double kz)
{
	x *= kx;
	y *= ky;
	z *= kz;
}

void Vertex::rotateX(double angle)
{
	y = y * cos(angle) + z * sin(angle);
	z = -y * sin(angle) + z * cos(angle);
}

void Vertex::rotateY(double angle)
{
	z = z * cos(angle) + x * sin(angle);
	x = -z * sin(angle) + x * cos(angle);
}

void Vertex::rotateZ(double angle)
{
	x = x * cos(angle) + y * sin(angle);
	y = -x * sin(angle) + y * cos(angle);
}
