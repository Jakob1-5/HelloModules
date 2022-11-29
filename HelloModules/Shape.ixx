//module;
export module Shape;

import <vector>;
import <string>;

export namespace MyStuff {

template<typename T>
requires std::integral<T> || std::floating_point<T>
struct GenericVertex
{
	T x, y;
	GenericVertex operator+(const GenericVertex& rhs) const { return { this->x + rhs.x, this->y + rhs.y }; }
	GenericVertex operator-(const GenericVertex& rhs) const { return { this->x - rhs.x, this->y - rhs.y }; }
	GenericVertex operator*(const GenericVertex& rhs) const { return { this->x * rhs.x, this->y * rhs.y }; }
	GenericVertex operator/(const GenericVertex& rhs) const { return { this->x / rhs.x, this->y / rhs.y }; }
	void operator+=(const GenericVertex& rhs) { this->x += rhs.x; this->y += rhs.y; }
	void operator-=(const GenericVertex& rhs) { this->x -= rhs.x; this->y -= rhs.y; }
	void operator*=(const GenericVertex& rhs) { this->x *= rhs.x; this->y *= rhs.y; }
	void operator/=(const GenericVertex& rhs) { this->x /= rhs.x; this->y /= rhs.y; }
	GenericVertex operator*(const int scalar) const { return { this->x * scalar, this->y * scalar }; }
	GenericVertex operator/(const int scalar) const { return { this->x / scalar, this->y / scalar }; }
	void operator*=(const int scalar) { this->x *= scalar; this->y *= scalar; }
	void operator/=(const int scalar) { this->x /= scalar; this->y /= scalar; }
};
typedef GenericVertex<int> Vertex;


class BaseShape
{
protected:
	std::vector<Vertex> m_vertices;
public:
	std::string ToString() const;
	virtual std::string Type() const;
};


class Polygon : public BaseShape
{
public:
	Polygon(size_t numVertices);
	Polygon(std::vector<Vertex>&& vertices);
	virtual std::string Type() const override;
};


class Triangle : public Polygon 
{
public:
	Triangle();
	Triangle(Vertex a, Vertex b, Vertex c);
	std::string Type() const final;
};


}