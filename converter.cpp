#include "converter.h"

int unitCategory, noOfCategories;
char inputUnitTemperature, outputUnitTemperature;
int inputUnit, outputUnit, inputValue;

//general
void intro()
{
	cout << "~~~WELCOME~~~" << endl;
	cout << "~~~UNIT CONVERTER~~~" << endl;
}
void unitCategories()
{
	cout << "Please select your option from below and press 'Enter'." << endl;

	cout << " Simple units: " << endl;
	cout << " 1. Surface " << endl;
	cout << " 2. Length " << endl;
	cout << " 3. Volume " << endl;
	cout << " 4. Time " << endl;
	cout << " 5. Temperature " << endl;
	cout << " 6. Mass " << endl;
	cout << " 7. Energy " << endl;
	cout << " 8. Pressure " << endl;
	cout << " 9. Density" << endl;

	cout << " Combinational units: " << endl;
	cout << " 10. Speed " << endl;
	cout << " 11. Fuel consumption " << endl;
	noOfCategories = 11;
}
void isCategoryInsideBounds()
{
	if (unitCategory < 1 || unitCategory > noOfCategories)
	{
		cout << "Please enter an admissible value! " << endl;
	}
}



void userInput()
{
	cout << "Convert (numerical value to convert): ";
	cin >> inputValue;
	cout << "units from (please type in the letter or number corresponding to your option)";
	cin >> inputUnit;
	cout << "to (please type in the letter or number corresponding to your option): ";
	cin >> outputUnit;
}

//2. LENGTH
void displayLengthOptions()
{
	cout << "1. km (kilometers) " << endl;
	cout << "2. hm (hectometers)" << endl;
	cout << "3. dam (decameters) " << endl;
	cout << "4. m (meters) " << endl;
	cout << "5. dm (decimeters) " << endl;
	cout << "6. cm (centimeters) " << endl;
	cout << "7. mm (milimeters) " << endl;
	cout << "8. in (inches) " << endl;
	cout << "9. ft (feet) " << endl;
	cout << "10. mi (miles) " << endl;
	cout << "11. yd (yards) " << endl;
}
void lengthInputUnitCorespondence()
{
	switch (inputUnit)
	{
	case 1: cout << "kilometer(s)"; break;
	case 2: cout << "hectometer(s)"; break;
	case 3: cout << "decameter(s)"; break;
	case 4: cout << "meter(s)"; break;
	case 5: cout << "decimeter(s)"; break;
	case 6: cout << "centimeter(s)"; break;
	case 7: cout << "milimeter(s)"; break;
	case 8: cout << "inch(es)"; break;
	case 9: cout << "feet"; break;
	case 10: cout << "mile(s)"; break;
	case 11: cout << "yard(s)"; break;
	}
}
void lengthOutputUnitCorespondence()
{
	switch (outputUnit)
	{
	case 1: cout << "kilometer(s)"; break;
	case 2: cout << "hectometer(s)"; break;
	case 3: cout << "decameter(s)"; break;
	case 4: cout << "meter(s)"; break;
	case 5: cout << "decimeter(s)"; break;
	case 6: cout << "centimeter(s)"; break;
	case 7: cout << "milimeter(s)"; break;
	case 8: cout << "inch(es)"; break;
	case 9: cout << "feet"; break;
	case 10: cout << "mile(s)"; break;
	case 11: cout << "yard(s)"; break;
	}
}
long lengthConversion()
{
	vector lengthConversionTable;
	long i, inputIndex, outputIndex;

	for (int k = 0; k < MAX_ARRAY_LENGTH; k++)
	{
		lengthConversionTable.values[k] = 0;
	}

	for (i = 0; i < MAX_ARRAY_LENGTH; i++)
	{
		if (inputUnit == (i + 1))
		{
			lengthConversionTable.values[i] = inputValue; 
			inputIndex = i;
		}
		if (outputUnit == (i + 1))
		{
			outputIndex = i;
		}
	}
	for (i = 0; i < MAX_ARRAY_LENGTH; i++)
	{
		if (i < inputIndex)
		{
			lengthConversionTable.values[i] = inputValue / pow(10, inputIndex - i);
		}
		if (i > inputIndex)
		{
			lengthConversionTable.values[i] = inputValue * pow(10, i- inputIndex);
		}
	}
	return lengthConversionTable.values[outputIndex];
}



//5 TEMPERATURE
void displayTemperatureOptions()
{
	cout << "C. Celsius " << endl;
	cout << "F. Fahrenheit " << endl;
	cout << "K. Kelvin " << endl;
}
int temperatureConversion()
{
	if (inputUnitTemperature == 'C' || inputUnitTemperature == 'c')
	{
		if (outputUnitTemperature == 'K' || outputUnitTemperature == 'k')
		{
			return inputValue + CtoK;
		}
		if (outputUnitTemperature == 'F' || outputUnitTemperature == 'f')
		{
			return (inputValue * 9 / 5 + 32);
		}
	}
	else
	{
		if (inputUnitTemperature == 'K' || inputUnitTemperature == 'k')
		{
			if (outputUnitTemperature == 'C' || outputUnitTemperature == 'c')
			{
				return inputValue - CtoK;
			}
			if (outputUnitTemperature == 'F' || outputUnitTemperature == 'f')
			{
				return (inputValue * 9 / 5 - 459,67);
			}
		}
		else
		{
			if (outputUnitTemperature == 'C' || outputUnitTemperature == 'c')
			{
				return ((inputValue - 32) * 5/9);
			}
			if (outputUnitTemperature == 'K' || outputUnitTemperature == 'k')
			{
				return ((inputValue + 459, 67) * 5 / 9);
			}
		}
	}
}




int main()
{
	char continueOrExit;
	bool continueOrStop=0;

	do
	{
		cout << endl;
		intro();
		unitCategories();
		cin >> unitCategory;
		isCategoryInsideBounds();

		//length
		if (unitCategory == 2)
		{
			displayLengthOptions();
			userInput();
			cout << inputValue;
			cout << " ";
			lengthInputUnitCorespondence();
			cout << " is " << lengthConversion();
			cout << " ";
			lengthOutputUnitCorespondence();
			cout << endl;
		}

		//temperature
		if (unitCategory == 5) 
		{
			displayTemperatureOptions();
			userInput();
			cout << "The result is: " << temperatureConversion() << endl;
		}


		//continue or exit?
		cout << "Perform another conversion? (y/n) ";
		cin >> continueOrExit;
		if (continueOrExit == 'y' || continueOrExit == 'Y')
		{
			continueOrStop = 1;
		}
		else
		{
			cout << "Thank you for using this application! Goodbye! " << endl << endl;
			continueOrStop = 0;
		}

	} while (continueOrStop);
	
	return 0;
}
