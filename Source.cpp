//14.—оздать класс Ђ—ериалї со следующими данными : 
//id Ц уникальный номер, 
//name Ц название, 
//review Ц отзыв.
//—оздать дружественный класс Ђ«рительї, в котором реализовать метод добавлени€ отзыва на сериал.

#include<iostream>
#include<string>
#include<array>

class Show {
	int id;
	std::string name;
	std::string review;
public:
	Show(int id, std::string name) : id{ id }, name{ name }, review{""} {}
	~Show() = default;
	
	friend class Viewer;
	friend void print_show(Show);
};
class Viewer {
public:
	void add_review(Show &show, std::string review) {
		show.review = review;
	}
};
void print_show(Show show) {
	std::cout << "ID:" << show.id << std::endl;
	std::cout << "Name:" << show.name << std::endl;
	std::cout << "Review:" << show.review << std::endl;
}
int main() {
	std::array<Show, 4> shows{
		Show(72,"The Platform"), Show(73,"Little Women"), Show(74,"The Sisters Brothers"), Show(75,"The Book of Henry")
	};
	Viewer viewer;
	for (int i = 0; i < 4; i++) {
		print_show(shows[i]);
		std::cout << std::endl;
		std::cout << "Enter review:";
		std::string review;
		std::getline(std::cin, review);
		viewer.add_review(shows[i], review);
		std::cout << std::endl;
		print_show(shows[i]);
		std::cout << std::endl;
	}
	return 0;
}
