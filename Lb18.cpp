#include <iostream>
#include <string>

template<typename T>
struct coords {
	T x, y, z;

	coords& operator+=(const coords& cd)
	{
		this->x = cd.x;
		this->y = cd.y;
		this->z = cd.z;

		return *this;
	}
};

template<typename T>
coords<T> make_cords(T x = 0, T y = 0, T z = 0)
{
	coords<T> tmp;
	tmp.x = x;
	tmp.y = y;
	tmp.z = z;

	return tmp;
}

class faculty
{
private:
	std::string type;
	coords<double> cordinates;
public:
	faculty(std::string type) {
		this->type = type;
	};
	~faculty() {

	}

	void changeCoords(const coords<double>& cd)
	{
		this->cordinates += cd;
	}

	const std::string& gettype();
	void settype(const std::string& in);
	virtual void move(const coords<double>& step) = 0;
};

class Lawyer : public faculty
{
private:
	int wings_length;

public:
	Lawyer(int wl) : faculty("Lawyer"), wings_length(wl) {

	}

	~Lawyer() {

	};

	void move(const coords<double>& step)
	{
		std::cout << "Law!" << std::endl;
		this->changeCoords(step);
	}
};

class Medicine : public faculty
{
private:
	int age, heigth;

public:
	/*
	 * @param a age
	 * @param heigh heingh
	 *
	*/
	Medicine(int a, int heigth) : faculty("Medicine"), age(a), heigth(heigth) {

	}

	virtual ~Medicine() {

	};

	void update_age()
	{
		(this->age)++;
	}

	void move(const coords<double>& step)
	{
		std::cout << "Heals and saves!" << std::endl;
		this->changeCoords(step);
	}
};

class engineer : public faculty
{
private:
	std::string spice;

public:
	/*
	 * @param a age
	 * @param heigh heingh
	 *
	*/
	engineer(std::string spice) : faculty("engineer"), spice(spice) {

	}

	~engineer() {

	};

	void move(const coords<double>& step)
	{
		std::cout << "Works 24/7!" << std::endl;
		this->changeCoords(step);
	}
};

void do_something(faculty& a)
{
	a.move(make_cords<double>());
}

int main(int argc, char *argv[]) {

	auto am = Lawyer(12);
	do_something(am);

	auto an = Medicine(12, 135);
	do_something(an);

	auto ah = engineer(std::string("Hi"));
	do_something(ah);

}
