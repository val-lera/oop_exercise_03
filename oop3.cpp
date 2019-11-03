/*Лабораторная работа №3
Выполнила: Блистунова Валерия
Группа М8О-201Б

Вариант №12: Трапеция, Ромб, 5-угольник
Разработать классы согласно варианту задания, классы должны наследоваться от базового класса Figure.
Фигуры являются фигурами вращения. Все классы должны поддерживать набор общих методов:
1. Вычисление геометрического центра фигуры;
2. Вывод в стандартный поток вывода std::cout координат вершин фигуры;
3. Вычисление площади фигуры;
Создать программу, которая позволяет:
Вводить из стандартного ввода std::cin фигуры, согласно варианту задания.
Сохранять созданные фигуры в динамический массив std::vector<Figure*>
Вызывать для всего массива общие функции (1-3 см. выше).Т.е. распечатывать для каждой фигуры в массиве геометрический центр, 
координаты вершин и площадь.
Необходимо уметь вычислять общую площадь фигур в массиве.
Удалять из массива фигуру по индексу*/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define pi 3.14159265358979323846
class Figure
{
    public:
    Figure(){}
	virtual ~Figure(){}
    double x, y, ar, all;
    virtual void Center()=0;
    virtual void Coord()=0;
    virtual double Area()=0;
    vector<double> X;
    vector<double> Y;
    void pCenter(){
        cout << "Координаты центра: " << "(" << x << "; " << y << ")" << endl;
    }
    void pArea(){
        cout << "Площадь: " << Area() << endl;
    }

    double length(double a, double b, double c, double d){
        double l;
        l= sqrt(pow((c-a),2)+pow((d-b),2));
        return l;
    }
};
class Trap : public Figure
{
    public:
    Trap(){};
    Trap(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4){
        X.push_back(x1); X.push_back(x2); X.push_back(x3); X.push_back(x4);
        Y.push_back(y1); Y.push_back(y2); Y.push_back(y3); Y.push_back(y4);
    }
    ~Trap(){};
    double Area() override{
        double h;
        h=length(X[1],Y[0],X[1],Y[1]);
        ar = ((length(X[0],Y[0],X[3],Y[3])+length(X[2],Y[2],X[1],Y[1]))/2)*h;
    }
    void Center()override{
        x=0; y=0;
        for(int i=0; i < X.size(); i++){
            x+=X[i];
            y+=Y[i];
        }
    x = x / X.size();
	y = y / Y.size();
    }
    void Coord(){
		cout << "Координаты вершин трапеции: ";
		for(int i = 0; i < X.size(); i++)
			cout << "(" << X[i] << "; " << Y[i] << ") ";
		cout << endl;
	}
};
class Romb : public Figure
{
    public:
    Romb(){};
    Romb(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4){
        X.push_back(x1); X.push_back(x2); X.push_back(x3); X.push_back(x4);
        Y.push_back(y1); Y.push_back(y2); Y.push_back(y3); Y.push_back(y4);
    }
    ~Romb(){};
    double Area() override{
        ar = (length(X[0],Y[0],X[2],Y[2])*length(X[1],Y[1],X[3],Y[3]))/2;
    }
    void Center()override{
        x=0; y=0;
        for(int i=0; i < X.size(); i++){
            x+=X[i];
            y+=Y[i];
        }
        x = x / X.size();
		y = y / Y.size();
    }
    void Coord(){
		cout << "Координаты вершин ромба: ";
		for(int i = 0; i < X.size(); i++)
			cout << "(" << X[i] << "; " << Y[i] << ") ";
        cout << endl;
		}
};
class Pent : public Figure
{
    public:
    Pent(){};
    Pent(double r, double xc, double yc){
        for(int i=0; i<5; i++){
            X.push_back(xc+r*cos(2*pi*i/5));
            Y.push_back(yc+r*sin(2*pi*i/5));
        }
    }
    ~Pent(){};
    double Area()override{
        double a=length(X[0],Y[0],X[1],Y[1]);
        ar= (5/2)*a*sqrt((pow((a/(2*sin(pi/5))),2))-(pow(a,2)/4));
    }
    void Center()override{
        x=0; y=0;
        for(int i=0; i < X.size(); i++){
            x+=X[i];
            y+=Y[i];
        }
        x = x / X.size();
	    y = y / Y.size();
    }
    void Coord(){
		cout << "Координаты вершин пятиугольника: ";
		for(int i = 0; i < X.size(); i++)
			cout << "(" << X[i] << "; " << Y[i] << ") ";
		cout << endl;
	}
};
void Menu(){
    cout << "Введите число от 1 до 5 или 0 для действий: " << endl << 
			"1. Распечатать меню" << endl <<
			"2. Добавить фигуру" << endl <<
			"3. Общие функции для всего массива" << endl <<
			"4. Вычислить общую площадь фигур в массиве" << endl << 
			"5. Удалить фигуру из массива по индексу" << endl <<
            "0. Выход из программы" << endl;
}
double l(double a, double b, double c, double d){
        double l;
        l= sqrt(pow((c-a),2)+pow((d-b),2));
        return l;
    }
int main(){
vector<Figure*> f;
int user_command =1;
double x1, y1, x2, y2, x3, y3, x4, y4, xc, yc, r;
for(;;){
    switch (user_command){
        case 1:
            Menu();
            break;
        case 2:
            int k;
            cout << "Введите номер фигуры, которую нужно добавить "<< endl <<
                "1. Трапеция" << endl <<
                "2. Ромб"<< endl <<
                "3. 5-угольник"<< endl <<
                "0. Выход в основное меню"<< endl;
            cin >> k;
            switch (k){
                case 1:
                    {cout << "Введите координаты вершин трапеции ";
                    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
                    if(l(x1,y1,x2,y2)!=l(x3,y3,x4,y4)){
                        cout << "Трапеция не равнобедренная" << endl;
                        break;
                    }
                    else{
                        Figure *t;
                        t= new Trap(x1,y1,x2,y2,x3,y3,x4,y4);
                        f.push_back(t);}
                        break;
                    }
                case 2: 
                    cout << "Введите координаты вершин ромба ";
                    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
                    if(l(x1,y1,x2,y2)!=l(x2,y2,x3,y3) || l(x3,y3,x2,y2)!=l(x3,y3,x4,y4)){
                        cout << "Введены неверные координаты ромба" << endl;
                        break;
                        }
                    else {
                        Figure *t;
                        t= new Romb(x1,y1,x2,y2,x3,y3,x4,y4);
                        f.push_back(t);
                        }
                    break;
                case 3:
                    cout << "Введите радиус окружности, в которую вписан пятиугольник, координаты центра пятиугольника ";
                    cin >> r >> xc >> yc;
                    Figure *t;
                    t=new Pent(r,xc,yc);
                    f.push_back(t);
                    break;
                case 0:
                    Menu();
                    break;
                default:
                    cerr << "Нет такого пункта" << endl;
                    break; 
                }
            break;
        case 3:
            if (f.size()==0) {
                cout << "Массив фигур пуст" << endl;
                break;
                }
            else{
            for(int i = 0; i < f.size(); i++)
                (*f[i]).Area();
			for(int i = 0; i < f.size(); i++)
				(*f[i]).Center();
			for(int i = 0; i < f.size(); i++){
				(*f[i]).Coord();
				(*f[i]).pCenter();
				(*f[i]).pArea();
				}
            break;
            }
        case 4:
            double j;
            j=0;
            for(int i = 0; i < f.size(); i++)
				j+=(*f[i]).Area();
            cout << "Общая площадь фигур в массиве: " << j << endl;
            break;
        case 5:
            if (f.size()==0){
                cout << "Массив пуст" << endl;
                break;
            }
            else{
                cout << "Введите индекс: ";
                cin >> k;
                if(k <= 0 || k > f.size()){
					cout << "Неверный индекс" << endl;
					break;
                    }
                else{
                    f.erase(f.begin()+(k-1));
                    break;
                    }
                break;
            }
        case 0:
            {for(size_t i = 0; i < f.size(); i++){
					delete f[i];
				}
            exit(0);}
        default:
            cerr << "Нет такого пункта" << endl;
            break;
        }
        cout << endl << "Введите пункт меню: ";
        cin >> user_command;
    }
return 0;
}