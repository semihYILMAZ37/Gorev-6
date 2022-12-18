#include <iostream>
#include <cmath>

class RegularPolygon{
	private:
		int n;
		double angle;
	public:
		static int count;
		RegularPolygon(int n){
			this->n = n;
			angle = M_PI /n;
			count++;
		}
		double area(double length){
			return (n*length*length*0.25)/std::tan(angle);
		}
		double length(double area){
			return std::pow((area*std::tan(angle)*4)/n,0.5);
		}
		~RegularPolygon(){
			count--;
		}
		int getCount(){
			return count;
		}
};

int RegularPolygon::count = 0;

int main() {
	RegularPolygon square(4);
	RegularPolygon triangle(3);
	RegularPolygon pentagon(5);
	std::cout << "area of square with length 10: " << "\t\t" << square.area(10) << "\n";
	std::cout << "length of square with area 100: " <<  "\t" << square.length(100) << "\n";
	std::cout << "area of triangle with length 10: " <<  "\t" << triangle.area(10) << "\n";
	std::cout << "length of triangle with area 100: " << "\t" << triangle.length(100) << "\n";
	std::cout << "area of pentagon with length 10: " << "\t" << pentagon.area(10) << "\n";
	std::cout << "length of pentagon with area 100: " << "\t" << pentagon.length(100) << "\n";
	std::cout << "number of polygons: " << square.getCount() << "\n";
}
