module Shape;

//import std;
import <sstream>;
import <string>;

namespace MyStuff {

std::string BaseShape::ToString() const
{
	std::stringstream ss;
	ss << "Num vertices: " << m_vertices.size();
	for (const auto [x, y] : m_vertices)
		ss << "\n(" << x << ", " << y << ")";
	return ss.str();
}

std::string BaseShape::Type() const
{
	return "Base shape";
}

}