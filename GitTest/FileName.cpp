#include <refl.hpp>
#include <iostream>

using std::cout;
using std::endl;

struct Point
{
	int x;
	int y;
};

REFL_AUTO(
	type(Point),
	field(x),
	field(y)
)

int main()
{
	constexpr auto type = refl::reflect<Point>();
	
	cout << type.name << endl;
	refl::util::for_each(type.members, [](auto member) 
		{
			cout << member.name << endl;
		}
	);

	auto members = refl::descriptor::get_members(refl::reflect<Point>());
	refl::util::for_each(members, [](auto member)
	{
			cout << member.name << endl;
	}
		);
}

