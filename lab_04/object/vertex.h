#ifndef VERTEX_H
#define VERTEX_H

class Vertex
{
public:
	Vertex();
	Vertex(double x_, double y_, double z_);
	Vertex(const Vertex &vertex);
	Vertex(Vertex &&vertex);

	Vertex& operator=(const Vertex &vertex);
	Vertex& operator=(Vertex &&vertex);

	double getX() const;
	void setX(double value);
	
	double getY() const;
	void setY(double value);
	
	double getZ() const;
	void setZ(double value);
	
	void move(double dx, double dy, double dz);
	void scale(double kx, double ky, double kz);
	void rotateX(double angle);
	void rotateY(double angle);
	void rotateZ(double angle);

private:
	double x, y, z;
};

#endif // VERTEX_H
