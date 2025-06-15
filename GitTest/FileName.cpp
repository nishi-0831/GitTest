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

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct User
{
	string nickname;
	int old;
	string birth;
	string state;

	void ChangeName(string name)
	{
		nickname = name;
	}
};

int main(void) {

	int N,K;
	cin >> N >> K;
	vector<User> users;
	users.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> users[i].nickname;
		cin >> users[i].old;
		cin >> users[i].birth;
		cin >> users[i].state;
	}
	/*std::sort(users.begin(), users.end(), [](User a, User b)
		{
			return a.old < b.old;
		});*/
	int number;
	string newName;
	for (int i = 0; i < K; i++)
	{
		cin >> number >> newName;
		users[number - 1].ChangeName(newName);
	}
	for (int i = 0; i < N; i++)
	{
		cout << users[i].nickname << " " << users[i].old << " " << users[i].birth << " " << users[i].state << endl;
	}
	return 0;
}

#endif