#include <cstdlib>
#include <iostream>
#include <ctype.h>
#include <stdlib.h> //Biblioteki użyte w programie
#include <stdio.h>
#include <string>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <algorithm>
#include <cctype>
#include <errno.h>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <list>
#include <cstring>
#pragma warning(disable : 4996) //Usunięcie błedy kompilatora

#define PLIK1 "InformacjeZwrotne.txt"
#define PLIK2 "InformacjeZwrotneCSV.csv" //Definicja pliku z danymi
FILE* InformacjeZwrotne;
FILE* InformacjeZwrotneCSV;

using namespace std;

int DaneOsobowe(); //Definicja wszystkich funkcji
int Units();
int Imperial();
int Metric();
float BMI();
float BasalMetabolicRate();
float BasicActivities();
float TotalDailyEnergyExpenditure();
float Macro();
int IloscLiter(string Imie);
bool Plec(string Imie, int IloscLiter);
string PoprawImie(string Imie);
bool SprawdzDane(string Imie);

int age; //Definicje zmiennych globalnych
int sex = 0;
float unit = 0;
float weight = 1;
float growth = 1;
double bmi;
int pick;
int choice;
double BMR;
double lbm;
int BAF;
double TDEE;
double TDEE_weight_gain;
double TDEE_slim;
string pImie;

int main(int argc, char* argv[])
{
	printf("------------------------------------------------\n"); //Informacje na temat autora
	printf("Projekt na zaliczenie z Podstaw informatyki i programowania \n");
	printf("Autor : Tymoteusz Maj \n");
	printf("Numer indeksu 401370 \n");
	printf("Geoinformacja \n");
	printf("Grupa 1 \n");
	printf("Data utworzenia kodu: Listopad/Grudzien 2020r. \n");
	printf("------------------------------------------------\n");
	
	time_t result = time(NULL);
	if (result != (time_t)(-1))

	printf("Korzystasz z programu w dniu:  %s(%jd sekund od rozpoczecia epoki)\n \n", asctime(gmtime(&result)), (intmax_t)result);

	system("pause");
	system("cls");

	InformacjeZwrotne = fopen(PLIK1, "w"); //Otwieramy plik txt
	FILE* InformacjeZwrotne;

	InformacjeZwrotneCSV = fopen(PLIK2, "w"); // Otwieramy plik csv
	FILE* InformacjeZwrotneCSV;

	printf("Podaj swoje imie: ");
	cin >> pImie;

	system("cls");
	
	if (!SprawdzDane(pImie)) {
		while (!SprawdzDane(pImie)) {
			printf(" Podales bledne dane. Sprobuj jeszcze raz: ");
			cin >> pImie;
		}
	}

	
	cout << "Witaj! " << PoprawImie(pImie) << " \nWedlug podanego przez ciebie imienia jestes:";
	if (Plec(PoprawImie(pImie), IloscLiter(pImie))) cout << " mezczyzna. \n" << endl;
	else cout << " kobieta. \n" << endl;

	

	printf("Imie ktore podales pozwolilo nam okreslic twoja plec. \n");
	printf("W dalszej czesci te informacje beda dla nas niezbedne do przeprowadzenia prawidlowej analizy. \n");
	
	if (Plec(PoprawImie(pImie), IloscLiter(pImie)))
	{
			sex = 0;
	}
	else sex = 1;

	system("pause");
	system("cls");
	DaneOsobowe();
	return 0;
}

bool SprawdzDane(string Imie) {
	int i = 0; int a = 0;
	while (Imie[i] != 0) {
		if ((Imie[i] < 'a' || Imie[i] > 'z') && (Imie[i] < 'A' || Imie[i] > 'Z') || (Imie[i] == 32)) a++;
		i++;
	}
	if (a > 0) return false;
	else return true;
}

string PoprawImie(string Imie) {
	int i = 0;
	while (Imie[i] != '\0') {
		Imie[i] = tolower(Imie[i]);
		i++;
	}
	Imie[0] = toupper(Imie[0]);
	return Imie;
}

bool Plec(string Imie, int IloscLiter) {
	if (Imie[IloscLiter] == 'a' && Imie == "Kuba") return true;
	if (Imie[IloscLiter] != 'a') return true;
	else return false;
}

int IloscLiter(string Imie) {
	int i = 0;
	while (Imie[i] != '\0') i++;
	return i - 1;
}

int DaneOsobowe() // Zebranie podstawowych informacji o uzytkowniku
{
	fprintf(InformacjeZwrotne, "%s \n", PoprawImie(pImie).c_str() );
	fprintf(InformacjeZwrotneCSV, "%s \n", PoprawImie(pImie).c_str());
	printf("Podaj swoj wiek: ");
	scanf_s("%i", &age);
	fprintf(InformacjeZwrotne, "Twoj wiek: %i \n", age);
	fprintf(InformacjeZwrotneCSV, "Wiek ; %i \n", age);

	if (sex == 1)
	{
		//printf("Kobieta \n");
		fprintf(InformacjeZwrotne, "Kobieta \n");
		fprintf(InformacjeZwrotneCSV, "Plec ; Kobieta \n");
	}
	if (sex == 0)
	{
		//printf(" Mezczyzna \n");
		fprintf(InformacjeZwrotne, "Mezczyzna \n");
		fprintf(InformacjeZwrotneCSV, "Plec ; Mezczyzna \n");

	}

	system("pause");
	system("cls");

	Units();
	return 0;
}

int Units() // Wybieramy system jednostek w ktorym chcemy obliczyc nasze BMI
{
	printf("Wybierz system jednostek, na ktorych chcesz pracowac: \n");
	printf("[1] Jednostki Imperialne\n");
	printf("[0] Jednostki Metryczne\n");
	scanf_s("%f", &unit);

	if (unit >= 2)
	{
		printf("Twoj wybor jest nie prawidlowy! - Zakonczenie pracy programu \n");
		printf("------------------------------------------------\n");
		fprintf(InformacjeZwrotne, "Twoj wybor jest nie prawidlowy! - Zakonczenie pracy programu \n");
		exit(1);
	}

	if (unit == 1)
	{
		printf("Wybrano jednostki Imperialne.\n");
		fprintf(InformacjeZwrotne, "Wybrano jednostki Imperialne. \n");
		fprintf(InformacjeZwrotneCSV, "Jednostki ; Imperialne \n");

		system("pause");
		system("cls");

		Imperial();
		return 0;
	}
	else
	{
		printf("Wybrano jednostki Metryczne. \n");
		fprintf(InformacjeZwrotne, "Wybrano jednostki Metryczne. \n");
		fprintf(InformacjeZwrotneCSV, "Jednostki ; Metryczne \n");

		system("pause");
		system("cls");

		Metric();
		return 0;
	}


}

int Imperial() // System imperialny (brytyjski)
{
	printf("[Oblicz swoje BMI (Body Mass Index)]\n");
	printf("Podaj swoja wage w funtach : ");
	scanf_s("%f.2", &weight);
	printf("Podaj swoj wzrost w stopach : ");
	scanf_s("%f.2", &growth);

	weight = weight * 0.45359237;
	growth = growth * 30.48;

	fprintf(InformacjeZwrotne, "Wzrost %.2f \n", growth);
	fprintf(InformacjeZwrotneCSV, "Wzrost ; %.2f \n", growth);

	fprintf(InformacjeZwrotne, "Waga %.2f", weight);
	fprintf(InformacjeZwrotneCSV, "Waga ; %.2f", weight);

	BMI();
	return 0;
}

int Metric() // System Metryczny
{
	printf("[Oblicz swoje BMI (Body Mass Index)]\n");
	printf("Podaj swoja wage w kilogramach : ");
	scanf_s("%f.2", &weight);
	printf("Podaj swoj wzrost w centymetrach : ");
	scanf_s("%f.2", &growth);

	fprintf(InformacjeZwrotne, "Wzrost %.2f \n", growth);
	fprintf(InformacjeZwrotneCSV, "Wzrost ; %.2f \n", growth);

	fprintf(InformacjeZwrotne, "Waga %.2f \n", weight);
	fprintf(InformacjeZwrotneCSV, "Waga ; %.2f \n", weight);

	BMI();
	return 0;
}

float BMI() //Obliczenie BMI oraz poszczególnych podziałów według WHO
{
	bmi = weight / ((growth * growth) / 10000); //BMI wzor

	printf("\n");
	printf("-----------------------------------------------------------------------------\n");
	printf("Twoje obecne BMI wynosi : %.2f", bmi);
	fprintf(InformacjeZwrotne, "Twoje obecne BMI wynosi : %.2f \n ", bmi);
	fprintf(InformacjeZwrotneCSV, "BMI ; %.2f - ", bmi);
	printf("\n");
	printf("\n");
	printf("Zgodnie z kategoria masy ciala wedlug klasyfikacji WHO twoje BMI oznacza : "); //BMI klasyfikacja WHO

	if (bmi < 16.0)
	{
		printf("Wyglodzenie \n");
		printf("Ryzyko chorob spowodowanych przez otylosc w twoim przypadku jest : ");
		printf("minimalne, ale zwiekszony poziom wystapienia innych problemow zdrowotnych. \n");
		printf("-----------------------------------------------------------------------------\n");
		fprintf(InformacjeZwrotne, "Wyglodzenie \n");
	}

	if (bmi > 16.0 && bmi <= 16.99)
	{
		printf("Wychudzenie \n");
		printf("Ryzyko chorob spowodowanych przez otylosc w twoim przypadku jest :  ");
		printf("minimalne, ale zwiekszony poziom wystapienia innych problemow zdrowotnych. \n");
		printf("-----------------------------------------------------------------------------\n");
		fprintf(InformacjeZwrotne, "Wychudzenie \n");
	}

	if (bmi > 17.0 && bmi <= 18.49)
	{
		printf("Niedowaga \n");
		printf("Ryzyko chorob spowodowanych przez otylosc w twoim przypadku jest : ");
		printf("minimalne, ale zwiekszony poziom wystapienia innych problemow zdrowotnych. \n");
		printf("-----------------------------------------------------------------------------\n");
		fprintf(InformacjeZwrotne, "Niedowaga \n");
	}

	if (bmi > 18.5 && bmi <= 24.99)
	{
		printf("Pozadana masa ciala\n");
		printf("Ryzyko chorob spowodowanych przez otylosc w twoim przypadku jest :  ");
		printf("minimalne \n");
		printf("-----------------------------------------------------------------------------\n");
		fprintf(InformacjeZwrotne, "Pozadana masa ciala \n");
	}

	if (bmi > 25.0 && bmi <= 29.99)
	{
		printf("Nadwaga \n");
		printf("Ryzyko chorob spowodowanych przez otylosc w twoim przypadku jest :  ");
		printf("srednie. \n");
		printf("-----------------------------------------------------------------------------\n");
		fprintf(InformacjeZwrotne, "Nadwaga \n");
	}

	if (bmi > 30.0 && bmi <= 34.99)
	{
		printf("Otylosc I stopnia \n");
		printf("Ryzyko chorob spowodowanych przez otylosc w twoim przypadku jest : ");
		printf("wysokie. \n");
		printf("-----------------------------------------------------------------------------\n");
		fprintf(InformacjeZwrotne, "Otylosc I stopnia \n");
	}

	if (bmi > 35.0 && bmi <= 39.99)
	{
		printf("Otylosc II stopnia (duza)\n");
		printf("Ryzyko chorob spowodowanych przez otylosc w twoim przypadku jest : ");
		printf("bardzo wysokie. \n");
		printf("-----------------------------------------------------------------------------\n");
		fprintf(InformacjeZwrotne, "Otylosc II stopnia (duza) \n");
	}

	if (bmi > 40.0)
	{
		printf("Otylosc III stopnia (Chorobliwa) \n");
		printf("Ryzyko chorob spowodowanych przez otylosc w twoim przypadku jest : ");
		printf("ekstremalny poziom ryzyka.\n");
		printf("-----------------------------------------------------------------------------\n");
		fprintf(InformacjeZwrotne, "Otylosc III stopnia (Chorobliwa) \n");
	}

	system("pause");
	system("cls");
	BasalMetabolicRate();
	return 0;
}

float BasalMetabolicRate()
{
start:
	//Wybór obliczenie BMR
	printf("Wybierz metode obliczenia twojego BMR (Basal Metabolic Rate): \n");
	printf("[0] Metoda Mifflin – St Jeor \n");
	printf("[1] Metoda Katch – McArdle \n");
	printf("[2] Metoda Revised Harris-Benedict \n");
	scanf_s("%i.2", &pick);
	printf("-----------------------------------------------------------------------------\n");


	switch (pick) // BMR Obliczenie
	{

	case 0:
	{
		printf("Format Mifflina-St Jeor'a oblicza BMR (wskaznik podstawowej przemiany materii) na podstawie masy ciala, informacji o plci, wysokosci i wieku uzytkownika. \n");
		printf("-----------------------------------------------------------------------------\n");
		printf("[1] Kontynnuj\n");
		printf("[2] Zmien Metoded\n");
		printf("[3] Zakoncz dzialanie programu\n");
		scanf_s("%i.2", &choice);
		printf("-----------------------------------------------------------------------------\n");

		if (choice == 1)
		{
			if (sex == 1)
			{
				BMR = (9.99 * weight) + (6.25 * growth) - (4.92 * age) - 161;
				printf("Twoje BMR wynosi : %.2f kcal \n", BMR);
				printf("-----------------------------------------------------------------------------\n");
				fprintf(InformacjeZwrotne, "Twoje BMR wynosi : %f \n", BMR);
				fprintf(InformacjeZwrotneCSV, "BMR ; %f \n", BMR);
				fprintf(InformacjeZwrotne, "Basal Metabolic Rate - Metoda Mifflin – St Jeor \n");
			}
		}
		if (sex == 0)
		{
			BMR = (9.99 * weight) + (6.25 * growth) - (4.92 * age) + 5;
			printf("Twoje BMR wynosi : %.2f kcal \n", BMR);
			printf("-----------------------------------------------------------------------------\n");
			fprintf(InformacjeZwrotne, "Twoje BMR wynosi : %f \n", BMR);
			fprintf(InformacjeZwrotneCSV, "BMR ; %f \n", BMR);
			fprintf(InformacjeZwrotne, "Basal Metabolic Rate - Metoda Mifflin – St Jeor \n");
		}


		if (choice == 2)
		{
			goto start;
			printf("-----------------------------------------------------------------------------\n");
		}
		if (choice == 3)
		{
			printf("[KONIEC] - Nacisnij dowolny klawisz aby zakonczyc dzialanie programu . \n");
			printf("------------------------------------------------\n");
			fprintf(InformacjeZwrotne, "[KONIEC] - Nacisnij dowolny klawisz aby zakonczyc dzialanie programu e \n");
			exit(1);
		}
		break;

	}
	case 1:
	{
		printf("Jest to zdecydowanie najlatwiejsza metoda, ktora pomimo swojej prostoty moze byc bardzo dokladna. Posiada jednak jedna znaczaca wade - odnosi sie tylko do podstawowej przemiany materii.\n");
		printf("-----------------------------------------------------------------------------\n");
		printf("[1] Kontynnuj\n");
		printf("[2] Zmien Metoded\n");
		printf("[3] Zakoncz dzialanie programu\n");
		scanf_s("%i.2", &choice);
		printf("-----------------------------------------------------------------------------\n");

		if (choice == 1)
		{
			if (sex == 1)
			{

				lbm = 0.240 * weight + 0.177 * growth;
				BMR = 370 + (21.6 * lbm);
				printf("Twoje BMR wynosi : %.2f kcal \n", BMR);
				printf("-----------------------------------------------------------------------------\n");
				fprintf(InformacjeZwrotne, "Twoje BMR wynosi : %f \n", BMR);
				fprintf(InformacjeZwrotneCSV, "BMR ; %f \n", BMR);
				fprintf(InformacjeZwrotne, "Basal Metabolic Rate - Metoda Katch – McArdle \n");
			}
		}
		if (sex == 0)
		{

			lbm = 0.488 * weight + 0.089 * growth;
			BMR = 370 + (21.6 * lbm);
			printf("Twoje BMR wynosi : %.2f kcal \n", BMR);
			printf("-----------------------------------------------------------------------------\n");
			fprintf(InformacjeZwrotne, "Twoje BMR wynosi : %f \n", BMR);
			fprintf(InformacjeZwrotneCSV, "BMR ; %f \n", BMR);
			fprintf(InformacjeZwrotne, "Basal Metabolic Rate - Metoda Katch – McArdle \n");


		}
		if (choice == 2)
		{
			goto start;
			printf("-----------------------------------------------------------------------------\n");

		}

		if (choice == 3)
		{
			printf("[KONIEC] - Nacisnij dowolny klawisz aby zakonczyc dzialanie programu  \n");
			printf("------------------------------------------------\n");
			fprintf(InformacjeZwrotne, "[KONIEC] - Nacisnij dowolny klawisz aby zakonczyc dzialanie programu  \n");
			exit(1);
		}

		break;

	}
	case 2:
	{
		printf("Najbardziej popularna metoda,ktora charakteryzuje sie zawiloscia. Metoda Harrisa-Benedicta wymaga informacje takich jak wiek, plec, waga i wysokosc.\n");
		printf("-----------------------------------------------------------------------------\n");
		printf("[1] Kontynnuj\n");
		printf("[2] Zmien Metoded\n");
		printf("[3] Zakoncz dzialanie programu\n");
		scanf_s("%i.2", &choice);
		printf("-----------------------------------------------------------------------------\n");

		if (choice == 1)
		{
			if (sex == 1)
			{
				BMR = 655.1 + (9.567 * weight) + (1.85 * growth) - (4.68 * age);
				printf("Twoje BMR wynosi : %.2f kcal \n", BMR);
				printf("-----------------------------------------------------------------------------\n");
				fprintf(InformacjeZwrotne, "Twoje BMR wynosi : %f \n", BMR);
				fprintf(InformacjeZwrotneCSV, "BMR ; %f \n", BMR);
				fprintf(InformacjeZwrotne, "Basal Metabolic Rate - Metoda Revised Harris-Benedict \n");
			}

			if (sex == 0)
			{
				BMR = 66.47 + (13.7 * weight) + (5.0 * growth) - (6.76 * age);
				printf("Twoje BMR wynosi : %.2f kcal \n", BMR);
				printf("-----------------------------------------------------------------------------\n");
				fprintf(InformacjeZwrotne, "Twoje BMR wynosi : %f \n", BMR);
				fprintf(InformacjeZwrotneCSV, "BMR ; %f \n", BMR);
				fprintf(InformacjeZwrotne, "Basal Metabolic Rate - Metoda Revised Harris-Benedict \n");
			}

		}

		if (choice == 2)
		{
			goto start;
			printf("-----------------------------------------------------------------------------\n");

		}
		if (choice == 3)
		{
			printf("[KONIEC] - Nacisnij dowolny klawisz aby zakonczyc dzialanie programu  \n");
			printf("------------------------------------------------\n");
			fprintf(InformacjeZwrotne, "[KONIEC] - Nacisnij dowolny klawisz aby zakonczyc dzialanie programu  \n");
			exit(1);
		}
		break;
	}
	}

end:

	if (pick >= 3)
	{
		printf("Twoj wybor jest nie prawidlowy! - Zakonczenie pracy programu \n");
		printf("------------------------------------------------\n");
		exit(1);
	}

	system("pause");
	system("cls");
	BasicActivities();
	return 0;

}

float BasicActivities()
{
	printf("Okresl swoja aktywnosc fizyczna wybierajac jedna z ponizszych opcji :  \n"); //Choose BAF
	printf("\n");
	printf("[1]Siedzacy - (bardzo malo cwiczenia, praca przy biurku) \n");
	printf("[2]Lekko aktywny - (lekkie cwiczenia / sport 1-3 dni w tygodniu) \n");
	printf("[3]Stosunkowo czynny - (umiarkowane cwiczenia / sport 6-7 dni w tygodniu)\n");
	printf("[4]Bardzo aktywny - (ciezkie cwiczenia kazdego dnia, lub lekki trening dwa razy dziennie) \n");
	printf("[5]Szczegolnie aktywny - (ciezkie cwiczenia dwa lub wiecej razy dziennie/ trening do maratonu lub triatlonu itp.) \n");
	scanf_s("%i", &BAF);
	switch (BAF) //BAF calculation
	{
	case 1:
		TDEE = BMR * 1.2;
		printf("-----------------------------------------------------------------------------\n");
		fprintf(InformacjeZwrotne, "Siedzacy - (bardzo malo cwiczenia, praca przy biurku) \n");
		break;

	case 2:
		TDEE = BMR * 1.375;
		printf("-----------------------------------------------------------------------------\n");
		fprintf(InformacjeZwrotne, "Lekko aktywny - (lekkie cwiczenia / sport 1-3 dni w tygodniu)\n");
		break;

	case 3:
		TDEE = BMR * 1.55;
		printf("-----------------------------------------------------------------------------\n");
		fprintf(InformacjeZwrotne, "Stosunkowo czynny - (umiarkowane cwiczenia / sport 6-7 dni w tygodniu) \n");
		break;

	case 4:
		TDEE = BMR * 1.725;
		printf("-----------------------------------------------------------------------------\n");
		fprintf(InformacjeZwrotne, "Bardzo aktywny - (ciezkie cwiczenia kazdego dnia, lub lekki trening dwa razy dziennie) \n");
		break;

	case 5:
		TDEE = BMR * 1.9;
		printf("-----------------------------------------------------------------------------\n");
		fprintf(InformacjeZwrotne, "Szczegolnie aktywny - (ciezkie cwiczenia dwa lub wiecej razy dziennie/ trening do maratonu lub triatlonu itp.) \n");
		break;


	}

	if (BAF >= 6)
	{
		printf("Twoj wybor jest nie prawidlowy! - Zakonczenie pracy programu \n");
		printf("-----------------------------------------------------------------------------\n");
		fprintf(InformacjeZwrotne, "Twoj wybor jest nie prawidlowy! - Zakonczenie pracy programu \n");
		exit(1);

	}

	TotalDailyEnergyExpenditure();
	return 0;
}

float TotalDailyEnergyExpenditure() //Obliczenie Podstawowej przemiany materii
{

	TDEE_weight_gain = TDEE * 1.075;
	TDEE_slim = TDEE * 0.935;

	printf("Twoje TDEE wynosi : %2.f kcal \n", TDEE);
	fprintf(InformacjeZwrotne, "Twoje TDEE wynosi : %2.f kcal \n", TDEE);
	fprintf(InformacjeZwrotneCSV, "TDEE ;  %2.f\n", TDEE);

	printf("\n");
	printf("Jezeli chcesz osiagnac prawidlowa mase ciala zgodnie z kryteriami BMI powinienes wykorzystac nastepujaca wartosc wskadnika TDEE\n");
	printf("\n");

	if (bmi > 0 && bmi <= 18.49)
	{
		printf("TDEE wymagane do osiagniecia prawidlowej masy ciala wynosi (BMI) : %2.f kcal\n", TDEE_weight_gain);
		fprintf(InformacjeZwrotne, "TDEE wymagane do osiagniecia prawidlowej masy ciala wynosi (BMI) : %2.f kcal\n", TDEE_weight_gain);
		fprintf(InformacjeZwrotneCSV, "TDEE wymagane ; %2.f kcal\n", TDEE_weight_gain);
	}

	if (bmi > 18.50 && bmi <= 24.99)
	{
		printf("Twoje TDEE jest odpowiednie, utrzymaj je aby utrzymac prawidlowa mase ciala (BMI) : %2.f kcal \n", TDEE);
		fprintf(InformacjeZwrotne, "Twoje TDEE jest odpowiednie, utrzymaj je aby utrzymac prawidlowa mase ciala (BMI) : %2.f kcal \n", TDEE);
		fprintf(InformacjeZwrotneCSV, "TDEE wymagane ; %2.f \n", TDEE);
	}

	if (bmi > 25.0)
	{
		printf("TDEE wymagane do osiagniecia prawidlowej masy ciala wynosi (BMI) : %2.f kcal \n", TDEE_slim);
		fprintf(InformacjeZwrotne, "TDEE wymagane do osiagniecia prawidlowej masy ciala wynosi (BMI) : %2.f kcal \n", TDEE_slim);
		fprintf(InformacjeZwrotne, "TDEE wymagane ; %2.f kcal \n", TDEE_slim);
	}

	printf("Jezeli chcesz schudnac, albo przybrac na wadze to powinienes w pierwszym kroku odliczac albo dodawac 7.5 procent zapotrzebowania kalorycznego, a nastepnie po dwoch tygodniach powinienes zrobic kalkulacja jeszcze raz. Musisz pamietac, ze zdrowe tempo wzrostu/zmniejszenia/ twojej wagi to 0.5 kg  roznicy na tydzień \n");
	printf("-----------------------------------------------------------------------------\n");
	Macro();
	return 0;
}

float Macro() // Obliczenie oraz podanie odpowiedniej ilosci makroskladnikow zgodnie z zamierzonym celem
{
	double protein_grams = weight * 1.1;
	double  protein_calories = protein_grams * 4;
	double  carbohydrates_calories = 0.5 * TDEE;
	double  carbohydrates_grams = carbohydrates_calories / 4;
	double  fats_calories = TDEE - protein_calories - carbohydrates_calories;
	double  fats_grams = fats_calories / 9;

	system("pause");
	system("cls");

	printf("Nastepujaca tabela pokazuje makra wartosci w przyblizeniu, ktore powinienes jesc codziennie.  \n");
	fprintf(InformacjeZwrotne, "Nastepujaca tabela pokazuje makra wartosci w przyblizeniu, ktore powinienes jesc codziennie.  \n");
	printf("\n");
	printf("------------------------------------------------\n");
	printf("Gramy : \n");
	printf("Bialko - %1.f gramow \n", protein_grams);
	printf("Weglowodany - %1.f gramow \n", carbohydrates_grams);
	printf("Tluszcze - %1.f gramow \n", fats_grams);
	printf("------------------------------------------------\n");
	printf("Kilokalorie : \n");
	printf("Bialko - %1.f kcal \n", protein_calories);
	printf("Weglowodany - %1.f kcal \n", carbohydrates_calories);
	printf("Tluszcze - %1.f kcal \n", fats_calories);
	printf("------------------------------------------------\n");

	fprintf(InformacjeZwrotne, "------------------------------------------------\n");
	fprintf(InformacjeZwrotne, "Gramy : \n");
	fprintf(InformacjeZwrotne, "Bialko - %1.f gramow\n", protein_grams);
	fprintf(InformacjeZwrotne, "Weglowodany - %1.f gramow \n", carbohydrates_grams);
	fprintf(InformacjeZwrotne, "Tluszcze - %1.f gramow \n", fats_grams);
	fprintf(InformacjeZwrotne, "------------------------------------------------\n");
	fprintf(InformacjeZwrotne, "Kilokalorie : \n");
	fprintf(InformacjeZwrotne, "Bialko - %1.f kcal \n", protein_calories);
	fprintf(InformacjeZwrotne, "Weglowodany- %1.f kcal \n", carbohydrates_calories);
	fprintf(InformacjeZwrotne, "Tluszcze - %1.f kcal \n", fats_calories);
	fprintf(InformacjeZwrotne, "------------------------------------------------\n");

	fprintf(InformacjeZwrotneCSV, "Gramy ; \n");
	fprintf(InformacjeZwrotneCSV, "Bialko ; %1.f \n", protein_grams);
	fprintf(InformacjeZwrotneCSV, "Weglowodany ; %1.f \n", carbohydrates_grams);
	fprintf(InformacjeZwrotneCSV, "Tluszcze ; %1.f \n", fats_grams);
	fprintf(InformacjeZwrotneCSV, "Kilokalorie ; \n");
	fprintf(InformacjeZwrotneCSV, "Bialko ; %1.f \n", protein_calories);
	fprintf(InformacjeZwrotneCSV, "Weglowodany ; %1.f \n", carbohydrates_calories);
	fprintf(InformacjeZwrotneCSV, "Tluszcze ; %1.f \n", fats_calories);
	

	system("pause");
	system("cls");

	printf("Gratulacje! W folderze  naszego programu znajduja sie pliki .txt oraz .csv z danymi ktore uzyskales. Mozesz wykorzystac go w wybrany przez siebie sposob.\n \n \n");
	printf("[KONIEC] - Nacisnij dowolny klawisz aby zakonczyc dzialanie programu \n");
	printf("------------------------------------------------\n");
	printf("\n");

	fclose(InformacjeZwrotne);
	fclose(InformacjeZwrotneCSV);
	return 0;

}