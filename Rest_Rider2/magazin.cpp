#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <string>
#include <iomanip>

//ÀÊÊÀÓÍÒÛ
int userCount = 2;
bool isAdmin = false;
std::string* loginArr = new std::string[userCount]{ "admin","user" };
std::string* passArr = new std::string[userCount]{ "admin","user" };

//ÑÊËÀÄ
int size = 10;
int* idArr = new int[size];
std::string* nameArr = new std::string[size];
int* countArr = new int[size];
double* priceArr = new double[size];

//ÊÀÑÑÀ
double cash = 2000;
double cashMoney{};
double webMoney{};

//×ÅÊ
int checkSize = 1;
std::string* nameCheckArr = new std::string[checkSize];
int* countCheckArr = new int[checkSize];
double* priceCheckArr = new double[checkSize];
double* totalPriceCheckArr = new double[checkSize];


//ÈÍÈÖÈÀËÈÇÀÖÈß ÔÓÍÊÖÈÉ
void Start();
bool Login();
bool IsNumber(std::string string);
void CreateStaticStorage();
void ShowAdminMenu();
void ShowUserMenu();
void ShowStorage(int mode = 0);
void RefillProducts();
void RemoveProducts();
void ChangeStorage();
void ChangeEmployee();
void ChangePrice();
int GetID(int mode = 0);

void AddNewProduct();
void EditProduct();
void DeleteProduct();

void AddNewEmployee();
void EditEmployee();
void DeleteEmployee();

void Selling();
void AddNewCheckSize();
void PrintCheck(double &totalSum);
void Income();
bool CloseShift();

void Getline(std::string& stringName);

template <typename Arr>
void FillStorage(Arr staticArr[], Arr dynamicArr[], int staticSize);

//-----MAIN-----
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	std::cout << "\t\tÄîøèÐàé\n\n";
	Start();
	delete[]loginArr;
	delete[]passArr;
	delete[]idArr;
	delete[]nameArr;
	delete[]countArr;
	delete[]priceArr;
	delete[]totalPriceCheckArr;
	delete[]countCheckArr;
	delete[]countCheckArr;
	delete[]priceCheckArr;

}
//-----MAIN-----

//ÔÓÍÊÖÈÈ
void Start() {
	if (Login() == true)
		if (isAdmin == true) {
			std::string choose;
			while (true)
			{
				std::cout << "1 - Èñïîëüçîâàòü ãîòîâûé ñêëàä\n2 - Ñîçäàòü ñêëàä\n Ââîä: ";
				Getline(choose);
				if (choose == "1") {
					CreateStaticStorage();
					break;
				}
				else if (choose == "2")
				{

					break;
				}
				else
				{
					std::cout << "\n\nÂâåäè íîðìàëüíî...\n\n";
				}
			}
			ShowAdminMenu();
		}


		else
		{
			CreateStaticStorage();
		}
	else
	{
		std::cerr << "Òû êàê óìóäðèëñÿ, ëîøàðà?..";
	}
}
bool Login()
{
	std::string login, pass;
	while (true)
	{
		std::cout << "Ëîãèí: ";
		Getline(login);
		std::cout << "Ïàðîëü: ";
		Getline(pass);

		if (login == loginArr[0] && pass == passArr[0]) {
			std::cout << "Àâòîðèçàöèÿ: " << loginArr[0] << "\n\n";
			isAdmin = true;
			return true;
		}

		for (int i = 1; i < userCount; i++)
		{
			if (login == loginArr[0] && pass == passArr[i]) {
				std::cout << "Àâòîðèçàöèÿ: " << loginArr[i] << "\n\n";
				isAdmin = false;
				return true;
			}

		}

		system("cls");
		std::cout << "Íåâåðíûé ëîãèí èëè ïàðîëü\n\n";
	}
}
bool IsNumber(std::string string)
{
	for (int i = 0; i < string.size(); i++)
	{
		if (!std::isdigit(string[i]))
		{
			return false;
		}
		return true;
	}
}
void CreateStaticStorage() {
	const int tempSize = 10;
	int tempId[tempSize]{ 1,2,3,4,5,6,7,8,9,10 };
	std::string tempName[tempSize]{
	"Äîøèê ñ êóðèöåé",
	"Äîøèê ñ ãîâÿäèíîé",
	"Äîøèê ñ ãðèáàìè",
	"Äîøèê ñ îâîùàìè",
	"Äîøèê ñ ñûðîì",
	"Äîøèê ñ êðåâåòêîé",
	"Äîøèê îñòðûé",
	"Äîøèê âîñòî÷íûé",
	"×àí ðàìåí ñ êóðèöåé",
	"×àí ðàìåí ñ ãîâÿäèíîé"
	};
	int tempCount[tempSize]{ 13, 65, 53, 62, 36, 67, 64, 23, 56, 51 };
	double tempPrice[tempSize]{ 34.0, 34.0, 40.0, 35.0, 50.0, 60.0, 55.0, 75.0, 90.0, 90.0 };
	FillStorage(tempId, idArr, tempSize);
	FillStorage(tempName, nameArr, tempSize);
	FillStorage(tempCount, countArr, tempSize);
	FillStorage(tempPrice, priceArr, tempSize);
}
void ShowStorage(int mode)
{
	system("cls");
	if (mode == 0)
	{
		std::cout << "ID\t" << "Íàçâàíèå\t\t\t" << "Êîëè÷åñòâî\t" << "Öåíà\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << countArr[i] << "\t" << priceArr[i] << "\n";
		}
		system("pause");
	}
	else if (mode == 1)
	{
		std::cout << "ID\t" << "Íàçâàíèå\t\t\t" << "Êîëè÷åñòâî\t" << "\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << countArr[i] << "\t" << "\n";
		}
	}
	else if (mode == 2)
	{
		std::cout << "ID\t" << "Íàçâàíèå\t\t\t" << "Öåíà\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << "\t" << priceArr[i] << "\n";
		}
	}
	else if (mode == 3)
	{
		std::cout << "ID\t" << "Íàçâàíèå\t\t\t" << "\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << "\t" << "\n";
		}
	}
	else
	{
		std::cerr << "\nMenuModeError\n";
	}

}
void RefillProducts()
{
	std::string choose, chooseCount;
	int id = 0, count;

	while (true)
	{
		system("cls");
		std::cout << "Ïîïîëíåíèå ñêëàäà\n\n";
		std::cout << "1 - Íà÷àòü\n0 - Îòìåíà\n\nÂâîä: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(1);
			id = GetID(0);
			while (true)
			{
				std::cout << "Êîëè÷åñòâî òîâàðà äëÿ ïîïîëíåíèÿ: ";
				Getline(chooseCount);
				if (IsNumber(chooseCount)) {
					count = std::stoi(chooseCount);
					if (count > 0 && count <= 1000) {
						countArr[id - 1] += count;
						std::cout << "\n\nÒîâàð óñïåøíî ïîïîëíåí\n\n";
						Sleep(1000);
						break;
					}
					else
					{
						std::cout << "\nÍåêîððåêòíîå ID\n";
					}
				}
				else
				{
					std::cout << "Îøèáêà, äîí";
				}
			}

		}
		else if (choose == "0")
		{
			break;
		}


	}
}
void RemoveProducts()
{
	std::string choose, chooseCount;
	int id = 0, count;

	while (true)
	{
		system("cls");
		std::cout << "Ñïèñàíèå òîâàðà\n\n";
		std::cout << "1 - Íà÷àòü\n0 - Îòìåíà\n\nÂâîä: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(1);
			id = GetID(0);
			while (true)
			{
				std::cout << "Êîëè÷åñòâî òîâàðà äëÿ ñïèñàíèÿ: ";
				Getline(chooseCount);
				if (IsNumber(chooseCount)) {
					count = std::stoi(chooseCount);
					if (count > 0 && count <= countArr[id - 1]) {
						countArr[id - 1] -= count;
						std::cout << "\n\nÒîâàð óñïåøíî ñïèñàí\n\n";
						Sleep(1000);
						break;
					}
					else
					{
						std::cout << "\nÍåêîððåêòíîå ID\n";
					}
				}
				else
				{
					std::cout << "Îøèáêà, äîí";
				}
			}

		}
		else if (choose == "0")
		{
			break;
		}


	}
}
void AddNewProduct() {
	std::string choose, nameStr, priceStr, countStr;
	int id = 0, count;
	while (true)
	{
		system("cls");
		std::cout << "Äîáàâëåíèå íîâîãî òîâàðà\n\n";
		std::cout << "1 - Íà÷àòü\n0 - Îòìåíà\n\nÂâîä: ";
		Getline(choose);
		if (choose == "1")
		{
			int* tempID = new int[size];
			int* tempCount = new int[size];
			double* tempPrice = new double[size];
			std::string* tempName = new std::string[size];

			for (int i = 0; i < size; i++)
			{
				tempID[i] = idArr[i];
				tempCount[i] = countArr[i];
				tempPrice[i] = priceArr[i];
				tempName[i] = nameArr[i];
			}

			delete[]idArr;
			delete[]nameArr;
			delete[]countArr;
			delete[]priceArr;

			size++;

			idArr = new int[size];
			countArr = new int[size];
			priceArr = new double[size];
			nameArr = new std::string[size];

			for (int i = 0; i < size - 1; i++)
			{
				idArr[i] = tempID[i];
				countArr[i] = tempCount[i];
				priceArr[i] = tempPrice[i];
				nameArr[i] = tempName[i];
			}

			while (true)
			{
				std::cout << "Ââåäèòå íàçâàíèå íîâîãî òîâàðà: ";
				Getline(nameStr);
				if (nameStr.size() > 2 && nameStr.size() <= 60)
				{
					nameArr[size - 1] = nameStr;
					break;
				}
				else
				{
					std::cout << "\nÎøèáêà äîí! Îò 3 äî 60 ñèìâîëîâ!\n";
				}
			}

			while (true)
			{
				std::cout << "Êîëè÷åñòâî íîâîãî òîâàðà: ";
				Getline(countStr);
				if (IsNumber(countStr))
				{
					if (std::stoi(countStr) >= 0 && std::stoi(countStr) <= 1000) {
						countArr[size - 1] = std::stoi(countStr);
						break;
					}
					else {
						std::cout << "\nÎøèáêà ââîäà\n";
					}
				}
				else
				{
					std::cout << "\nÎøèáêà ââîäà\n";
				}
			}

			while (true)
			{
				std::cout << "Öåíà íîâîãî òîâàðà: ";
				Getline(priceStr);
				if (IsNumber(priceStr))
				{
					if (std::stod(priceStr) >= 0 && std::stod(priceStr) <= 10000.0) {
						priceStr[size - 1] = std::stoi(priceStr);
						break;
					}
					else {
						std::cout << "\nÎøèáêà ââîäà\n";
					}
				}
				else
				{
					std::cout << "\nÎøèáêà ââîäà\n";
				}
			}

			idArr[size - 1] = size;

			std::cout << idArr[size - 1] << "\t" << std::left << std::setw(30) << nameArr[size - 1] << "\t" << countArr[size - 1] << "\t" << "\t" << priceArr[size - 1] << "\n\n";
			std::cout << "Íîâûé òîâàð óñïåøíî äîáàëåí";

			delete[] tempID;
			delete[] tempCount;
			delete[] tempPrice;
			delete[] tempName;

			Sleep(3000);
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\nÎøèáêà äîí\n";
		}
	}
}
void EditProduct()
{
	std::string choose, newName;
	int id = 0;

	while (true) {
		system("cls");
		std::cout << "Ðåäàêòèðîâàíèå òîâàðà\n\n";
		std::cout << "1 - Íà÷àòü\n0 - Îòìåíà\n\nÂâîä: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(3);
			id = GetID(0);
			while (true)
			{
				std::cout << "Ââåäèòå íîâîå íàçâàíèå ïðîäóêòà: ";
				Getline(newName);
				if (newName.size() > 2 && newName.size() <= 60)
				{
					nameArr[id - 1] = newName;
					break;
				}
				else
				{
					std::cout << "\nÎøèáêà äîí! Îò 3 äî 60 ñèìâîëîâ!\n";
				}
			}
			std::cout << "\nÍàçâàíèå èçìåíåíî\n";
			Sleep(2000);
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			break;
		}
	}

}
void DeleteProduct()
{
	std::string choose;
	int id{};
	while (true)
	{
		system("cls");
		std::cout << "Óäàëåíèå òîâàðà\n\n";
		std::cout << "1 - Íà÷àòü\n0 - Îòìåíà\n\nÂâîä: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(3);
			int* tempID = new int[size];
			int* tempCount = new int[size];
			double* tempPrice = new double[size];
			std::string* tempName = new std::string[size];

			for (int i = 0; i < size; i++)
			{
				tempID[i] = idArr[i];
				tempCount[i] = countArr[i];
				tempPrice[i] = priceArr[i];
				tempName[i] = nameArr[i];
			}

			delete[]idArr;
			delete[]nameArr;
			delete[]countArr;
			delete[]priceArr;

			size--;

			idArr = new int[size];
			countArr = new int[size];
			priceArr = new double[size];
			nameArr = new std::string[size];

			id = GetID(0);

			for (int i = 0, j = 0; i < size, j < size + 1; i++, j++)
			{
				if (j == id - 1)
				{
					if (id == size + 1)
					{
						break;
					}
					j++;
					idArr[i] = tempID[i];
					countArr[i] = tempCount[j];
					priceArr[i] = tempPrice[j];
					nameArr[i] = tempName[j];
				}
				else
				{
					idArr[i] = tempID[i];
					countArr[i] = tempCount[j];
					priceArr[i] = tempPrice[j];
					nameArr[i] = tempName[j];
				}
			}



			std::cout << "Òîâàð óñïåøíî óäàë¸í";

			delete[] tempID;
			delete[] tempCount;
			delete[] tempPrice;
			delete[] tempName;

			Sleep(3000);
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\nÎøèáêà äîí\n";
		}
	}
}
void AddNewEmployee()
{
	std::string choose, newLogin, newPass;
	int id = 0, count;
	while (true)
	{
		system("cls");
		std::cout << "Äîáàâëåíèå íîâîãî ñîòðóäíèêà\n\n";
		std::cout << "1 - Íà÷àòü\n0 - Îòìåíà\n\nÂâîä: ";
		Getline(choose);
		if (choose == "1")
		{
			std::string* tempLogin = new std::string[userCount];
			std::string* tempPass = new std::string[userCount];


			for (int i = 0; i < userCount; i++)
			{
				tempLogin[i] = loginArr[i];
				tempPass[i] = passArr[i];
			}

			delete[]loginArr;
			delete[]passArr;

			userCount++;

			loginArr = new std::string[userCount];
			passArr = new std::string[userCount];

			for (int i = 0; i < userCount - 1; i++)
			{
				loginArr[i] = tempLogin[i];
				passArr[i] = tempPass[i];
			}

			while (true)
			{
				std::cout << "Ââåäèòå ëîãèí íîâîãî ïîëüçîâàòåëÿ: ";
				Getline(newLogin);
				if (newLogin.size() > 4 && newLogin.size() <= 15)
				{
					loginArr[userCount - 1] = newLogin;
					break;
				}
				else
				{
					std::cout << "\nÎøèáêà äîí! Îò 4 äî 15 ñèìâîëîâ!\n";
				}
			}

			while (true)
			{
				std::cout << "Ââåäèòå ïàðîëü íîâîãî ïîëüçîâàòåëÿ: ";
				Getline(newPass);
				if (newPass.size() > 4 && newPass.size() <= 15)
				{
					passArr[userCount - 1] = newPass;
					break;
				}
				else
				{
					std::cout << "\nÎøèáêà äîí! Îò 4 äî 15 ñèìâîëîâ!\n";
				}
			}

			std::cout << "Íîâûé ïîëüçîâàòåëü óñïåøíî äîáàëåí";

			delete[] tempPass;
			delete[] tempLogin;

			Sleep(2000);
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\nÎøèáêà äîí\n";
		}
	}

}
void EditEmployee()
{
	std::string choose, currentPass, newPass;
	int id = 0;

	while (true) {
		system("cls");
		std::cout << "Ðåäàêòèðîâàíèå äàííûõ ñîòðóäíèêà\n\n";
		std::cout << "1 - Íà÷àòü\n0 - Îòìåíà\n\nÂâîä: ";
		Getline(choose);
		if (choose == "1")
		{
			id = GetID(1);
			while (true)
			{
				std::cout << "Ââåäèòå ïàðîëü ïîëüçîâàòåëÿ " << loginArr[id - 1] << "\0 - Âûõîä\nÂâîä: ";
				Getline(currentPass);
				if (currentPass == passArr[id - 1])
				{
					while (true)
					{
						std::cout << "Ââåäèòå íîâûé ïàðîëü ïîëüçîâàòåëÿ: ";
						Getline(newPass);
						if (newPass.size() > 4 && newPass.size() <= 15)
						{
							passArr[id - 1] = newPass;
							std::cout << "\nÏàðîëü óñïåøíî èçìåí¸í\n";
							break;
						}
						else
						{
							std::cout << "\nÎøèáêà äîí! Îò 4 äî 15 ñèìâîëîâ!\n";
						}
					}
				}
				else if (currentPass == "0")
				{
					break;
				}
				else
				{
					std::cout << "\nÎøèáêà äîí!\n";
				}
			}
		}
	}
}
void DeleteEmployee()
{
	std::string choose;
	int id{};
	while (true)
	{
		system("cls");
		std::cout << "Óäàëåíèå ñîòðóäíèêîâ\n\n";
		std::cout << "1 - Íà÷àòü\n0 - Îòìåíà\n\nÂâîä: ";
		Getline(choose);

		if (userCount <= 1) {
			std::cout << "Òàéëåðà. Çäåñü. Íåò.";
			Sleep(1000);
			break;
		}
		if (choose == "1")
		{
			for (int i = 1; i < userCount; i++)
			{
				std::cout << i << " " << loginArr[i] << "\n";
			}
			std::cout << std::endl;
			std::string* tempLogin = new std::string[userCount];
			std::string* tempPass = new std::string[userCount];


			for (int i = 0; i < userCount; i++)
			{
				tempLogin[i] = loginArr[i];
				tempPass[i] = passArr[i];
			}

			delete[]loginArr;
			delete[]passArr;

			userCount--;

			loginArr = new std::string[userCount];
			passArr = new std::string[userCount];


			id = GetID(1);

			loginArr[0] = tempLogin[0];
			passArr[0] = tempPass[0];

			for (int i = 1, j = 1; i < userCount, j < userCount + 1; i++, j++)
			{
				if (j == id)
				{
					if (id == userCount)
					{
						break;
					}
					j++;
					loginArr[i] = tempLogin[j];
					passArr[i] = tempPass[j];
				}
				else
				{
					loginArr[i] = tempLogin[j];
					passArr[i] = tempPass[j];
				}
			}



			std::cout << "Ñîòðóäíèê óñïåøíî óäàë¸í";

			delete[] tempLogin;
			delete[] tempPass;

			Sleep(3000);
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\nÎøèáêà äîí\n";
		}
	}

}
void Selling()
{
	std::string choose, chooseID, chooseCount,choosePay ,mone;
	bool isFirst = true;
	int id{}, count;
	double totalSum{};
	while (true)
	{
		system("cls");
		std::cout << "1 - Íà÷àòü íîâóþ ïðîäàæó\n0 - Îòìåíà\n\nÂâîä: ";
		Getline(choose);
		if (choose == "1")
		{
			totalSum = 0;
			isFirst = true;
			delete[]totalPriceCheckArr;
			delete[]countCheckArr;
			delete[]countCheckArr;
			delete[]priceCheckArr;

			checkSize = 1;

			totalPriceCheckArr = new double[size];
			countCheckArr = new int[size];
			priceCheckArr = new double[size];
			nameCheckArr = new std::string[size];

			while (true)
			{
				system("cls");
				ShowStorage();
				std::cout << "Ââåäèòå ID òîâàðà èëè\"exit\" äëÿ çàâåðøåíèÿ ïîêóïîê\n\nÂâîä: ";
				Getline(chooseID);
				if (chooseID == "exit")
				{
					break;
				}
				else if (IsNumber(chooseID))
				{
					id = std::stoi(chooseID);
					if (id > 0 && id <= size)
					{
						std::cout << "Ââåäèòå êîë-âî " << nameArr[id - 1] << " äëÿ ïîêóïêè: ";
						Getline(chooseCount);
						if (IsNumber(chooseCount))
						{
							count = std::stoi(chooseCount);
							if (count >= 0 && count <= countArr[id - 1])
							{
								if (isFirst)
								{
									nameCheckArr[checkSize - 1] = nameArr[id - 1];
									countCheckArr[checkSize - 1] = count;
									priceCheckArr[checkSize - 1] = priceArr[id - 1];
									totalPriceCheckArr[checkSize - 1] = count * priceArr[id - 1];
									isFirst = false;
									countArr[id - 1] -= count;
									totalSum += count * priceArr[id - 1];
								}
								else
								{
									AddNewCheckSize();
									nameCheckArr[checkSize - 1] = nameArr[id - 1];
									countCheckArr[checkSize - 1] = count;
									priceCheckArr[checkSize - 1] = priceArr[id - 1];
									totalPriceCheckArr[checkSize - 1] = count * priceArr[id - 1];
									countArr[id - 1] -= count;
									totalSum += count * priceArr[id - 1];
								}
								Sleep(500);
							}
							else
							{
								std::cout << "\nÎøèáêà êîë-âî\n";
								Sleep(1000);
							}
						}
						else
						{
							std::cout << "\nÎøèáêà ââîäà\n";
							Sleep(1000);
						}
					}
					else
					{
						std::cout << "\nÎøèáêà ID\n";
						Sleep(1000);
					}
				}
				else
				{
					std::cout << "\nÎøèáêà ââîäà\n";
					Sleep(1000);
				}
			}
			if (!isFirst)
			{
				//принт чека
				PrintCheck(totalSum);
				system("pause");
				while (true)
				{
					std::cout << "Выберете способ оплаты\n1 - Наличные\n2 - Безналичный\nВвод: ";
					Getline(choosePay);
					if (choosePay == "1")
					{
						std::cout << "Введите кол-во наличных: ";
						Getline(mone);
						if (IsNumber(mone))
						{
							if (std::stod(mone) >= totalSum || std::stod(mone) - totalSum <= cash )
							{
								std::cout << "\nоплата прошла успешно\nваша сдача: " << mone - totalSum <<"\n";
								cash -= std::stod(mone);
								cash += std::stod(mone);
								cashMoney += std::stod(mone);
								Sleep(1000);
								break;
							}
							else if (std::stod(mone) < totalSum)
							{
								std::cout << "\nНедостаточно сретств\n";
							}
							else
							{
								std::cout << "\nНет сдачи\n";
							}
						}
						else
						{
							std::cout << "\nОшибка ввода\n";
							Sleep(1000);
						}
					}
					else if (choosePay == "2")
					{
						system("cls");
						std::cout << "\nприложите карту\n";
						std::cout << "Соединение с банком: ";
						for (int i = 0; i < rand() % 5 + 6; i++)
						{
							std::cout  << ". ";
							Sleep(750);
						}
						std::cout << "\n";
						std::cout << "\nоплата прошла успешно\n";
						webMoney += totalSum;
						Sleep(1000);
						break;
					}
					else
					{

					}
				}
			}
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\nÎøèáêà ââîäà\n";
			Sleep(800);
		}
	}
}
void AddNewCheckSize()
{
	int* tempCount = new int[checkSize];
	double* tempTotalPrice = new double[checkSize];
	double* tempPrice = new double[checkSize];
	std::string* tempName = new std::string[checkSize];

	for (int i = 0; i < checkSize; i++)
	{
		tempTotalPrice[i] = totalPriceCheckArr[i];
		tempCount[i] = countCheckArr[i];
		tempPrice[i] = priceCheckArr[i];
		tempName[i] = nameCheckArr[i];
	}

	delete[]totalPriceCheckArr;
	delete[]nameCheckArr;
	delete[]countCheckArr;
	delete[]priceCheckArr;

	checkSize++;

	totalPriceCheckArr = new double[checkSize];
	countCheckArr = new int[checkSize];
	priceCheckArr = new double[checkSize];
	nameCheckArr = new std::string[checkSize];

	for (int i = 0; i < checkSize - 1; i++)
	{
		totalPriceCheckArr[i] = tempTotalPrice[i];
		countCheckArr[i] = tempCount[i];
		priceCheckArr[i] = tempPrice[i];
		nameCheckArr[i] = tempName[i];
	}

	delete[] totalPriceCheckArr;
	delete[] tempCount;
	delete[] tempPrice;
	delete[] tempName;

}
void ChangePrice()
{
	std::string choose, choosePrice;
	int id = 0;
	double price{};

	while (true)
	{
		system("cls");
		std::cout << "Èçìåíåíèå öåíû\n\n";
		std::cout << "1 - Íà÷àòü\n0 - Îòìåíà\n\nÂâîä: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(1);
			id = GetID(0);
			while (true)
			{
				std::cout << "Íîâàÿ öåíà: ";
				Getline(choosePrice);
				if (IsNumber(choosePrice)) {
					price = std::stod(choosePrice);
					if (price > 0 && price <= 1000.0) {
						priceArr[id - 1] = price;
						std::cout << "\n\nÖåíà óñïåøíî èçìåíåíà\n\n";
						Sleep(1000);
						break;
					}
					else
					{
						std::cout << "\nÍåêîððåêòíîå ID\n";
					}
				}
				else
				{
					std::cout << "Îøèáêà, äîí";
				}
			}

		}
		else if (choose == "0")
		{
			break;
		}


	}
}
void ChangeStorage() {
	std::string choose, chooseCount;
	int id = 0, count;

	while (true)
	{
		system("cls");
		std::cout << "Èçìåíåíèå ñêëàäà\n\n";
		std::cout << "1 - Äîáàâèòü íîâûé òîâàð\n2 - Ðåäàêòèðîâàòü íàçâàíèå\n3 - Óäàëèòü òîâàð\n0 - Îòìåíà\n\nÂâîä: ";
		Getline(choose);
		if (choose == "1")
		{
			AddNewProduct();
		}
		else if (choose == "2") {
			EditProduct();
		}
		else if (choose == "3") {
			DeleteProduct();
		}
		else if (choose == "0") {
			break;
		}
		else {
			std::cout << "\nÎøèáêà äîí\n";
		}
	}
}
void ChangeEmployee()
{
	std::string choose, chooseCount;
	int id = 0, count;

	while (true)
	{
		system("cls");
		std::cout << "Èçìåíåíèå ñîòðóäíèêîâ\n\n";
		std::cout << "1 - Äîáàâèòü íîâîãî ñîòðóäíèêà\n2 - Ðåäàêòèðîâàòü ñîòðóäíèêà\n3 - Óäàëèòü ñîòðóäíèêà\n0 - Îòìåíà\n\nÂâîä: ";
		Getline(choose);
		if (choose == "1")
		{
			AddNewEmployee();
		}
		else if (choose == "2") {
			EditEmployee();
		}
		else if (choose == "3") {
			if (userCount > 1)
			{
				DeleteEmployee();
			}
			else
			{
				std::cout << "\nÍåêîãî óäàëÿòü\n";
				Sleep(1500);
			}
		}
		else if (choose == "0") {
			break;
		}
		else {
			std::cout << "\nÎøèáêà äîí\n";
		}
	}
}
int GetID(int mode)
{
	std::string stringID;
	int result{};
	int currentSize = 0;
	if (mode == 1)
	{
		currentSize = userCount;
	}
	else if (mode == 0)
	{
		currentSize = size;
	}
	std::cout << "Ââåäèòå ID òîâàðà: ";
	Getline(stringID);
	if (IsNumber(stringID)) {
		result = std::stoi(stringID);
		if (result > 0 && result <= currentSize) {
			return result;
		}
		else
		{
			std::cout << "\nÍåêîððåêòíîå ID\n";
		}
	}
	else
	{
		std::cout << "Îøèáêà, äîí";
	}
}
void Getline(std::string& stringName)
{
	std::getline(std::cin, stringName, '\n');
}
void ShowAdminMenu()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - Начать продажу\n";
		std::cout << "2 - Ïîêàçàòü ñêëàä\n";
		std::cout << "3 - Ïîïîëíèòü ñêëàä\n";
		std::cout << "4 - Ñïèñàòü ñî ñêëàäà\n";
		std::cout << "5 - Èçìåíèòü öåíó\n";
		std::cout << "6 - Èçìåíèòü ñêëàä\n";
		std::cout << "7 - Èçìåíèòü ñîòðóäíèêîâ\n";
		std::cout << "8 - Îò÷¸ò î ïðèáûëè\n";
		std::cout << "0 - Çàêðûòü ñìåíó\n";
		std::cout << "\nÂâîä:";
		Getline(choose);
		if (choose == "1") 
		{
			Selling();
		}
		else if (choose == "2")
		{
			ShowStorage();
			system("pause");
		}
		else if (choose == "3")
		{
			RefillProducts();
		}
		else if (choose == "4")
		{
			RemoveProducts();
		}
		else if (choose == "5")
		{
			ChangePrice();
		}
		else if (choose == "6")
		{
			ChangeStorage();
		}
		else if (choose == "7")
		{
			ChangeEmployee();
		}
		else if (choose == "8")
		{
			Income();
		}
		else if (choose == "0")
		{
			if (CloseShift())
			{
				break;
		    }
		}
		else
		{
			std::cout << "\nÎøèáêà ââîäà\n";
			Sleep(500);
		}
	}
}
void ShowUserMenu() {
	std::string choose;

	while (true)
	{
		std::cout << "1 - Начать продажу\n";
		std::cout << "2 - Показать склад\n";
		std::cout << "3 - пополнить склад\n";
		std::cout << "4 - Списать со склада\n";
		std::cout << "5 - Отчёт о прибыли\n";
		std::cout << "0 - закрыть смену\n";
		std::cout << "\nВвод:";
		std::getline(std::cin, choose, '\n');
		if (choose == "1") 
		{
			Selling();
		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{
			RefillProducts();
		}
		else if (choose == "4")
		{
			RemoveProduct();
		}
		else if (choose == "5")
		{
			Income();
		}
		else if (choose == "0")
		{
			if (CloseShift())
			{
				break;
			}
		}
		else
		{
			std::cout << "\nÎøèáêà ââîäà\n";
			Sleep(500);
		}
	}
}
template<typename Arr>
void FillStorage(Arr staticArr[], Arr dynamicArr[], int staticSize)
{
	for (int i = 0; i < staticSize; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}
void PrintCheck(double& totalSum)
{
	std::cout << "№  "<< std::left << std::setw(25) << " Название" <<  "\tЦена за ед.\tКол - во\tИтого\n";
	for  (int i = 0; i < checkSize;  i++)
	{
		std::cout << "№" << i + 1<< "   " << std::left << std::setw(30) << nameCheckArr[i]
			<< "\t" << priceCheckArr[i] << "\t\t*" << countCheckArr[i]
			<< "\t\t" << totalPriceCheckArr[i] << "\n";
	}
	std::cout << "Итоговая сумма: " << totalSum << "\n\n";
}
void Income()
{
	std::cout << "Деньгив кассе: " << cash << "\n";
	std::cout << "прибыль за наличную оплату: " << cashMoney << "\n";
	std::cout << "прибыль за безналичную оплату: " << webMoney << "\n";
	std::cout << "Итоговая прибыль: " << cashMoney + webMoney << "\n";
	system("pause");
}
bool CloseShift()
{
	std::string choose;
	int id{};
	while (true)
	{
		system("cls");
		std::cout << "1 - Закрыть смену\n0 - нет\n\nВвод: ";
		Getline(choose);
		if (choose == "1")
		{
			Income();
			std::cout << "\nСмена закрыта. Доброй ночи\n";
			system("pause");
			return true;
		}
		else if (choose == "0")
		{
			return false;
		}
		else
		{
			std::cout << "\nÎøèáêà äîí\n";
		}
	}
}
