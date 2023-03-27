#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <algorithm>
//#include <array>

// Service functions prototypes ------------------------------------
int Get_Int_SA();				// String-analysis вариант фильтра INTEGER
int Get_Int_Positive();			// String-Analysis вариант проверки ввода INTEGER_POSITIVE		
int Get_Int_PG();				// peek&get вариант проверки ввода INTEGER	
double Get_Dbl_SA();		// String-analysis вариант фильтра DOUBLE.
double Get_Dbl_Positive();	// String-analysis вариант фильтра DOUBLE_POSITIVE
double Get_Dbl_PG();		// peek&get вариант проверки ввода DOUBLE	
int Get_Random(int Range_min, int Range_max);
double Get_Random(double Range_min, double Range_max);
template <typename ANY> void Fill_Array_with_Random(ANY arr[], int Size, ANY Range_min, ANY Range_max);
template <typename ANY> void Array_Console_Out(ANY arr[], int Size);

// Classwork DD.MM.YYYY ----------------------------------------------------	

//Task 1 Dynamic variables. Intro
void Task_1()
{
	int* _pointer_ = new int; //allocated 4 bytes (int) in heap (Dynamic memory)
	*_pointer_ = 7;
	std::cout << "\n" << " *_pointer_ = " << *_pointer_;
	std::cout << "\n" << " _pointer_ = " << _pointer_;

	delete _pointer_; //freeing up used memory
	std::cout << "\n\n" << "delete _pointer_";
	//std::cout << "\n" << " *_pointer_ = " << *_pointer_; //Cannot read and write because pointer is an neutral position




	std::cout << "\n" << " _pointer_ = " << _pointer_;
	_pointer_ = nullptr;
	std::cout << "\n\n" << "_pointer_ = nullptr";
		//std::cout << "\n" << " *_pointer_ = " << *_pointer_; //Cannot read and write because pointer is an neutral position
	std::cout << "\n" << " _pointer_ = " << _pointer_;
	
	std::cout << "\n\n" << "delete _pointer_";
	delete _pointer_; //freeing up used memory
	std::cout << "\n" << " _pointer_ = " << _pointer_;



	_pointer_ = new int;
	*_pointer_ = 15.5;
	std::cout << "\n" << " *_pointer_ = " << *_pointer_;
	std::cout << "\n" << " _pointer_ = " << _pointer_;

	delete _pointer_;
}
//Task 2 Dynamic arrays
void Task_2()
{
	std::cout << "\n" << "Enter Size of array -> ";
	//int Size = Get_Int_PG(), Range_int = 15;
	int Size = Get_Dbl_PG(), Range_int = 20;
	//std::cin >> Size;
	int* _pointer_Dynamic_Array = new int[Size];
	std::cout << "\n" << "Initialising of array with random";
	Fill_Array_with_Random(_pointer_Dynamic_Array, Size, -Range_int, Range_int);
	Array_Console_Out(_pointer_Dynamic_Array, Size);

	//delete _pointer_Dynamic_Array; // delete 0-th element
	delete[] _pointer_Dynamic_Array; // delete all elements of array

	std::cout << "\n" << "delete[] _pointer_Dynamic_Array";
	std::cout << "\n" << " _pointer_Dynamic_Array = " << _pointer_Dynamic_Array;

	//Array_Console_Out(_pointer_Dynamic_Array, Size);
}
//Task 3 2DIM Dynamic arrays
void Task_3()
{
	int rows, columns;
	std::cout << "\n" << "Enter rows ";
	rows = Get_Int_SA();
	std::cout << "\n" << "Enter columns ";
	columns = Get_Int_SA();

	//int* 2DIM_Array = new int[rows][columns]; Doesn't work like that
	int** DIM2_Array = new int*[rows];
	for (int i = 0; i < rows; i++)
		DIM2_Array[i] = new int [columns];

	for (int i = 0; i < rows; i++)
		delete[] DIM2_Array[i];
	delete DIM2_Array;
}
//Task 4 Dynamic arrays enlarge
//template <typename any> void Dynamic_arrays_enlarge(any arr[], int oldSize, int addSize) //Alternative variant: int arr[] / int* arr
template <typename any> void Dynamic_arrays_enlarge(any*& arr, int oldSize, int addSize)
{
	any* new_Dynamic_Array = new any[oldSize + addSize]{};


	std::cout <<"\n" << "arr adress = " << arr;
	std::cout << "\n" << "new_Dynamic_Array adress = " << new_Dynamic_Array;

	new_Dynamic_Array = arr;
	
	std::cout << "\n" << "arr adress = " << arr;
	std::cout << "\n" << "new_Dynamic_Array adress = " << new_Dynamic_Array;


	//for (int i = 0; i < oldSize; i++)
		//new_Dynamic_Array[i] = arr[i];	
	//delete[] arr;
	//arr = new_Dynamic_Array;	
	for (int i = 0; i < addSize; i++)
		new_Dynamic_Array[oldSize + i] = 0;
}

void Task_4()
{
	int Array_Size = 5, Range =100;
	int* Dynamic_Array = new int[Array_Size];
	Fill_Array_with_Random(Dynamic_Array, Array_Size, -Range, Range);
	Array_Console_Out(Dynamic_Array, Array_Size);
	std::cout << "\n" << "Enter new elements quantity -> ";
	int add_Array_Size = Get_Int_PG();
	Dynamic_arrays_enlarge(Dynamic_Array, Array_Size, add_Array_Size);
	Array_Console_Out(Dynamic_Array, Array_Size + add_Array_Size);


}

// MAIN ------- MAIN ------- MAIN ------- MAIN ------- MAIN --------
int main()
{
	srand(time(NULL));

	//Task_1();
	//Task_2();
	//Task_3();
	Task_4();
	
	std::cout << "\n\n";
	system("pause");
	return 0;
}

// Service functions -----------------------------------------
int Get_Int_SA() {
	std::string a;
	std::cin.sync(); 
	std::cin.clear(); 
	getline(std::cin, a);
	if (a != "")
	{

		if ((a.find_first_not_of("-0123456789") == -1))
		{
			for (int i = 1; i < a.size(); i++) // определяем есть ли минусы кроме первого символа
			{
				if (a[i] == '-') 
				{
					std::cout << "Input Error: Minus misstanding. [INTEGER] expected.\n";
					return Get_Int_SA();
				}
			}
			try
			{
				return stoi(a);
			}
			catch (std::out_of_range)
			{
				std::cout << "Input Error: Data type overflow. [INTEGER] expected.\n";
				return Get_Int_SA();
			}


		}
		else
		{
			std::cout << "Input Error: Incorrect symbol. [INTEGER] expected.\n";
			return Get_Int_SA();
		}
	}
	else
	{
		std::cout << "Input Error: NULL input. [INTEGER] expected.\n";
		return Get_Int_SA();
	}
}
int Get_Int_Positive()
{
	std::string a;
	std::cin.sync();
	std::cin.clear();
	getline(std::cin, a);
	if (a != "") 
	{

		if ((a.find_first_not_of("0123456789") == -1))
		{
			try{
				return stoi(a);
			}
			catch (std::out_of_range){
				std::cout << "Input Error: overflow. Positive [INTEGER] expected.\n";
			}
		}
		else
		{
			std::cout << "Input Error: Positive [INTEGER] expected.\n";
			return Get_Int_Positive();
		}		
	}
	else
		std::cout << "Input Error: NULL input. Positive [INTEGER] expected.\n";
	return Get_Int_Positive();
}
int Get_Int_PG()
{
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Input error! [INTEGER] expected. Repeat please...\n";
	}
	return a;
}
double Get_Dbl_SA(){
	std::string a;
	std::cin.sync();
	getline(std::cin, a);
	if (a == "") { std::cout << "\nInput Error : NULL input\n"; return Get_Dbl_SA(); }
	if ((a.find_first_not_of("-.0123456789") == -1))
	{
		for (int i = 1; i < a.size(); i++) // Проверяем отсутсвие лишних минусов
		{
			if (a[i] == '-')
			{
				std::cout << "\nInput Error: Minus misstanding. [DOUBLE] expected.\n";
				return Get_Dbl_SA();
			}

		}
		bool Dot_Flag = 0;
		for (int i = 0; i < a.size(); i++) // проверяем отсутсвие лишних точек
		{
			if (a[i] == '.')
			{
				if (Dot_Flag == 1)
				{
					std::cout << "\nInput Error: Dot misstandig. [DOUBLE] expected.\n";
					return Get_Dbl_SA();
				}
				Dot_Flag = 1;
			}

		}		 	
				try{
					return stod(a);
				}
				catch (std::out_of_range) {
					std::cout << "Input Error: overflow. [DOUBLE] expected.\n";
					return Get_Dbl_SA();					
				}						
	}
	else {		
		std::cout << "Incorrect symbols: [DOUBLE] expected.\nUse dot instead of coma. Example 50.64\n";
		return Get_Dbl_SA();
	}
}
double Get_Dbl_Positive()
{
	std::string a, dot = ".";
	std::cin.sync();
	std::cin.clear();
	getline(std::cin, a);
	if (a != "")
	{
		if ((a.find_first_not_of(".0123456789") == -1))
		{
			bool One_Dot_already = false;
			for (int i = 0; i < a.size(); i++)
			{				
				if (a[i] == dot[0] && One_Dot_already == true) //проверяем количество разделителей
				{
					std::cout << "Input Error: Dot misstandig. Positive [DOUBLE] expected.\n";
					return Get_Dbl_Positive();
				}
				if (a[i] == dot[0])	One_Dot_already = true;
			}
			try
			{				
				return stod(a);
			}
			catch (std::out_of_range)
			{
				std::cout << "Input Error: Data type overflow. Positive [DOUBLE] expected.\n";
				return Get_Dbl_Positive();
			}
		}
		else
		{
			//std::cout << "Incorrect symbols: positive REAL expected.\nUse coma instead of dot. Example 50,64\n"; // да точно говорю вот даже сообщение такое было, а теперь наоборот wtf*2?!
			std::cout << "Incorrect symbols: Positive [DOUBLE] expected.\nUse dot instead of coma. Example 50.64\n";
			return Get_Dbl_Positive();
		}
	}
	else
	{
		std::cout << "Input Error: NULL input. Positive [DOUBLE] expected.\n";
		return Get_Dbl_Positive();
	}
	return Get_Dbl_Positive();
}
double Get_Dbl_PG()
{
	double a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Input error! [DOUBLE] expected. Repeat please...\n";
	}
	return a;
}
int Get_Random(int Range_min=-999, int Range_max=999)
{
	if (Range_min > Range_max) 
	{ 
		std::cout << "\nError: Range_min > Range_max. New range: [Range_max..Range_min]\n";
		std::swap(Range_min, Range_max);
	}
	//return (Range_min + rand() % (Range_max - Range_min + 1));
	double K_random = double((rand() % RAND_MAX)) / RAND_MAX;
	int random = Range_min + ((Range_max - Range_min) * K_random);
	//return Range_min + (Range_max - Range_min) * (rand() % RAND_MAX) / RAND_MAX;
	return random;
}
double Get_Random(double Range_min=-9999.0, double Range_max=9999.0)
{
	if (Range_min > Range_max)
	{
		std::cout << "\nError: Range_min > Range_max. New range: [Range_max..Range_min]\n";
		std::swap(Range_min, Range_max);
	}
	return 	Range_min + (Range_max - Range_min) * double(rand() % RAND_MAX) / RAND_MAX;	
}
template <typename ANY> void Array_Console_Out(ANY arr[], int Size)
{
	std::cout << "\n[";
	for (int i = 0; i < Size; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
template <typename ANY> void Fill_Array_with_Random(ANY arr[], int Size, ANY Range_min, ANY Range_max)
{
	for (int i = 0; i < Size; i++)
	{
		arr[i] = Get_Random(Range_min, Range_max);		
	}
}
