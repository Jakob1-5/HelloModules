module Shape;

//import <string>;

namespace MyStuff {

Triangle::Triangle() 
	: Polygon(3)
{
	//m_vertices = std::vector<Vertex>(3, { 0,0 });
}

Triangle::Triangle(Vertex a, Vertex b, Vertex c)
	: Polygon({a, b, c})
{
	//m_vertices = { a, b, c };
}

std::string Triangle::Type() const
{
	return "Triangle";
}

}