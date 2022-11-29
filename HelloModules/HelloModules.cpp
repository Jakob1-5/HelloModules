import Shape;
import <iostream>;

using namespace MyStuff;

void Print(const BaseShape& shape)
{
    std::cout << "---\n";
    std::cout << shape.Type() << '\n';
    std::cout << shape.ToString() << '\n';
    std::cout << "---\n";
}

struct Foo
{
    static constexpr const char* foo = "foo";
};

auto main() -> int
{
    std::cout << "Hello World!\n";

    BaseShape shape;
    Print(shape);

    Triangle triangle;
    Print(triangle);

    Triangle triangle2({ 0,0 }, { 4,0 }, { 4,4 });
    Print(triangle2);

    Polygon poly(8);
    Print(poly);

    Polygon poly2({ {2,3}, {0,0}, {32, 42}, {-12, 41} });
    Print(poly2);


    GenericVertex<double> a{ 2, 3 };
    a += {-4, -6};

    GenericVertex<double> b{ -2, -3 };
    b = a - b;

    std::cout << "(" << a.x << ", " << a.y << ")\n";
    std::cout << "(" << b.x << ", " << b.y << ")\n";

    //GenericVertex<Foo> foo{ Foo(), Foo() }; // compiles fine if template doesn't use `requires`, but will get trouble when e.g., trying to use the operator overloads
    //foo += { Foo(), Foo() };

}