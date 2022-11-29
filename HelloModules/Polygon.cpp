module Shape;


namespace MyStuff {

Polygon::Polygon(size_t numVertices)
{
	m_vertices = std::vector<Vertex>(numVertices, { 0,0 });
}

Polygon::Polygon(std::vector<Vertex>&& vertices)
{
	m_vertices = std::move(vertices);
}

std::string Polygon::Type() const
{
	return "Polygon";
}

}