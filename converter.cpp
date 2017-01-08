#include "converter.h"

int noOfCategories, noOfAreaOptions, noOfLengthOptions, noTimeOptions, noUnitsMassMetric, noUnitsMassSpecial;

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
	cout << " 1. Area " << endl;
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
void isCategoryInsideBounds(int unitCategory)
{
	if (unitCategory < 1 || unitCategory > noOfCategories)
	{
		cout << "Please enter an admissible value! " << endl;
	}
}

int determineInputIndex(int inputUnit)
{
	int inputIndex;
	for (int i = 0; i < MAX_ARRAY_LENGTH; i++)
	{
		if (inputUnit == (i + 1))
		{
			inputIndex = i;
			break;
		}
	}
	return inputIndex;
}
int determineOutputIndex(int outputUnit)
{
	int outputIndex;
	for (int i = 0; i < MAX_ARRAY_LENGTH; i++)
	{
		if (outputUnit == (i + 1))
		{
			outputIndex = i;
			break;
		}
	}
	return outputIndex;
}

//user input
double readInputValue()
{
	double inputValue;
	cout << "Convert (number of units to convert): ";
	cin >> inputValue;
	return inputValue;
}
int readInputUnit()
{
	int inputUnit;
	cout << "units from (please type in the number corresponding to your option): ";
	cin >> inputUnit;
	return inputUnit;
}
int readOutputUnit()
{
	int outputUnit;
	cout << "to (please type in the number corresponding to your option): ";
	cin >> outputUnit;
	return outputUnit;
}
char readInputUnitLetter()
{
	char inputUnitLetter;
	cout << "units from (please type in the letter corresponding to your option): ";
	cin >> inputUnitLetter;
	return inputUnitLetter;
}
char readOutputUnitLetter()
{
	char outputUnitLetter;
	cout << "to (please type in the letter corresponding to your option): ";
	cin >> outputUnitLetter;
	return outputUnitLetter;
}


//1 AREA - done
void displayAreaOptions()
{
	cout << "1. square kilometers " << endl;
	cout << "2. square hectometers " << endl;
	cout << "3. square decameters " << endl;
	cout << "4. square meters " << endl;
	cout << "5. square decimeters " << endl;
	cout << "6. square centimeters " << endl;
	cout << "7. square milimeters " << endl;
	cout << "8. square inches " << endl;
	cout << "9. square feet " << endl;
	cout << "10. square miles " << endl;
	cout << "11. hectares " << endl;
	noOfAreaOptions = 11;
}
void areaInputUnitCorespondence(int inputUnit)
{
	switch (inputUnit)
	{
	case 1: cout << "square kilometer(s)"; break;
	case 2: cout << "square hectometer(s)"; break;
	case 3: cout << "square decameter(s)"; break;
	case 4: cout << "square meter(s)"; break;
	case 5: cout << "square decimeter(s)"; break;
	case 6: cout << "square centimeter(s)"; break;
	case 7: cout << "square milimeter(s)"; break;
	case 8: cout << "square inch(es)"; break;
	case 9: cout << "square feet"; break;
	case 10: cout << "square mile(s)"; break;
	case 11: cout << "hectares"; break;
	}
}
void areaOutputUnitCorespondence(int outputUnit)
{
	switch (outputUnit)
	{
	case 1: cout << "square kilometer(s)"; break;
	case 2: cout << "square hectometer(s)"; break;
	case 3: cout << "square decameter(s)"; break;
	case 4: cout << "square meter(s)"; break;
	case 5: cout << "square decimeter(s)"; break;
	case 6: cout << "square centimeter(s)"; break;
	case 7: cout << "square milimeter(s)"; break;
	case 8: cout << "square inch(es)"; break;
	case 9: cout << "square feet"; break;
	case 10: cout << "square mile(s)"; break;
	case 11: cout << "hectares"; break;
	}
}
double areaConversion(int inputUnit, int outputUnit, double inputValue)
{
	vector areaConversionTable;
	int i, inputIndex, outputIndex;

	for (int k = 0; k < MAX_ARRAY_LENGTH; k++)
	{
		areaConversionTable.values[k] = 0;
	}

	inputIndex = determineInputIndex(inputUnit);
	outputIndex = determineOutputIndex(outputUnit);
	areaConversionTable.values[inputIndex] = inputValue;

	if (inputIndex < 7)
	{
		for (i = 0; i < 7; i++)
		{
			if (i < inputIndex)
			{
				areaConversionTable.values[i] = inputValue / pow(pow(10, inputIndex - i), 2);
			}
			if (i > inputIndex)
			{
				areaConversionTable.values[i] = inputValue * pow(pow(10, i - inputIndex), 2);
			}
		}
		//  to square inches, feet, miles, hectares
		switch (outputIndex)
		{
		case 7: areaConversionTable.values[outputIndex] = areaConversionTable.values[3] * oneSquareMeterInSquareInches; break;
		case 8: areaConversionTable.values[outputIndex] = areaConversionTable.values[3] * oneSquareMeterInSquareFeet; break;
		case 9: areaConversionTable.values[outputIndex] = areaConversionTable.values[0] * oneSquareKilometerInSquareMiles; break;
		case 10: areaConversionTable.values[outputIndex] = areaConversionTable.values[3] * oneSquareMeterInHectares; break;
		}
	}
	else //  input square inches, feet, miles, hectares
	{
		switch (inputIndex)
		{
		case 7: areaConversionTable.values[3] = inputValue / oneSquareMeterInSquareInches; break;
		case 8: areaConversionTable.values[3] = inputValue / oneSquareMeterInSquareFeet; break;
		case 9: {areaConversionTable.values[0] = inputValue * 2.58999;
				areaConversionTable.values[3] = areaConversionTable.values[0] * 1000000;
				break;
				}
		case 10: areaConversionTable.values[3] = inputValue / oneSquareMeterInHectares; break;
		}
		for (i = 0; i < 7; i++)
		{
			if (i < 3)
			{
				areaConversionTable.values[i] = areaConversionTable.values[3] / pow(pow(10, 3 - i), 2);
			}
			if (i > 3)
			{
				areaConversionTable.values[i] = areaConversionTable.values[3] * pow(pow(10, i - 3), 2);
			}
		}
		switch (outputIndex)
		{
		case 7: areaConversionTable.values[outputIndex] = areaConversionTable.values[3] * oneSquareMeterInSquareInches; break;
		case 8: areaConversionTable.values[outputIndex] = areaConversionTable.values[3] * oneSquareMeterInSquareFeet; break;
		case 9: areaConversionTable.values[outputIndex] = areaConversionTable.values[0] * oneSquareKilometerInSquareMiles; break;
		case 10: areaConversionTable.values[outputIndex] = areaConversionTable.values[3] * oneSquareMeterInHectares; break;
		}
	}
	return areaConversionTable.values[outputIndex];
}

//2. LENGTH - done
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
	cout << "12. nmi (nautical mile) " << endl;
}
void lengthInputUnitCorespondence(int inputUnit)
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
void lengthOutputUnitCorespondence(int outputUnit)
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
double lengthConversion(int inputUnit, int outputUnit, double inputValue)
{
	vector lengthConversionTable;
	int i, inputIndex, outputIndex;

	for (int k = 0; k < MAX_ARRAY_LENGTH; k++)
	{
		lengthConversionTable.values[k] = 0;
	}

	inputIndex = determineInputIndex(inputUnit);
	outputIndex = determineOutputIndex(outputUnit);
	lengthConversionTable.values[inputIndex] = inputValue;

	// km --> mm
	if (inputIndex < 7)
	{
		for (i = 0; i < 7; i++)
		{
			if (i < inputIndex)
			{
				lengthConversionTable.values[i] = inputValue / pow(10, inputIndex - i);
			}
			if (i > inputIndex)
			{
				lengthConversionTable.values[i] = inputValue * pow(10, i - inputIndex);
			}
		}

		// to inches, feet, miles, yards
		switch (outputIndex)
		{
		case 7: lengthConversionTable.values[outputIndex] = lengthConversionTable.values[3] * oneMeterIninches; break;
		case 8: lengthConversionTable.values[outputIndex] = lengthConversionTable.values[3] * oneMeterInFeet; break;
		case 9: lengthConversionTable.values[outputIndex] = lengthConversionTable.values[3] * oneMeterInMiles; break;
		case 10: lengthConversionTable.values[outputIndex] = lengthConversionTable.values[3] * oneMeterInYards; break;
		case 11: lengthConversionTable.values[outputIndex] = lengthConversionTable.values[3] * oneMeterInNauticalMiles; break;
		}
	}
	else // input: inches, feet, miles, yards
	{
		switch (inputIndex)
		{
		case 7: lengthConversionTable.values[3] = inputValue / oneMeterIninches; break;
		case 8: lengthConversionTable.values[3] = inputValue / oneMeterInFeet; break;
		case 9: lengthConversionTable.values[3] = inputValue / oneMeterInMiles; break;
		case 10: lengthConversionTable.values[3] = inputValue / oneMeterInYards; break;
		case 11: lengthConversionTable.values[3] = inputValue / oneMeterInNauticalMiles; break;
		}
		for (i = 0; i < 7; i++)
		{
			if (i < 3)
			{
				lengthConversionTable.values[i] = lengthConversionTable.values[3] / pow(10, 3 - i);
			}
			if (i > 3)
			{
				lengthConversionTable.values[i] = lengthConversionTable.values[3] * pow(10, i - 3);
			}
		}
		switch (outputIndex)
		{
		case 7: lengthConversionTable.values[outputIndex] = lengthConversionTable.values[3] * oneMeterIninches; break;
		case 8: lengthConversionTable.values[outputIndex] = lengthConversionTable.values[3] * oneMeterInFeet; break;
		case 9: lengthConversionTable.values[outputIndex] = lengthConversionTable.values[3] * oneMeterInMiles; break;
		case 10: lengthConversionTable.values[outputIndex] = lengthConversionTable.values[3] * oneMeterInYards; break;
		case 11: lengthConversionTable.values[outputIndex] = lengthConversionTable.values[3] * oneMeterInNauticalMiles; break;
		}
	}
	return lengthConversionTable.values[outputIndex];
}

//3. VOLUME
void displayVolumeOptions()
{
	cout << "1. l (litres) " << endl;
	cout << "2. dl (decilitres) " << endl;
	cout << "3. cl (centilitres) " << endl;
	cout << "4. ml (mililitres) " << endl;
	cout << "5. cubic meters " << endl;
	cout << "6. cubic decimeters " << endl; 
	cout << "7. cubic centimeters " << endl;
	cout << "8. gallons (US) " << endl;
	cout << "9. gallons (UK) " << endl;
	cout << "10. cubic ft " << endl;
	cout << "11. cubic in (inches) " << endl;
	cout << "12. cubic yd (yards) " << endl;
}
void volumeInputUnitCorespondence(int inputUnit)
{
	switch (inputUnit)
	{
	case 1: cout << "cubic meter(s)"; break;
	case 2: cout << "litre(s)"; break;
	case 3: cout << "cubic decimeter(s)"; break;
	case 4: cout << "cubic centimeter(s)"; break;
	case 5: cout << "decilitre(s)"; break;
	case 6: cout << "centilitre(s)"; break;
	case 7: cout << "mililitre(s)"; break;
	case 8: cout << "US gallon(s)"; break;
	case 9: cout << "UK gallon(s)"; break;
	case 10: cout << "cubic ft"; break;
	case 11: cout << "cubic inch(es)"; break;
	case 12: cout << "cubic yard(s)"; break;
	}
}
void volumeOutputUnitCorespondence(int outputUnit)
{
	switch (outputUnit)
	{
	case 1: cout << "cubic meter(s)"; break;
	case 2: cout << "litre(s)"; break;
	case 3: cout << "cubic decimeter(s)"; break;
	case 4: cout << "cubic centimeter(s)"; break;
	case 5: cout << "decilitre(s)"; break;
	case 6: cout << "centilitre(s)"; break;
	case 7: cout << "mililitre(s)"; break;
	case 8: cout << "US gallon(s)"; break;
	case 9: cout << "UK gallon(s)"; break;
	case 10: cout << "cubic ft"; break;
	case 11: cout << "cubic inch(es)"; break;
	case 12: cout << "cubic yard(s)"; break;
	}
}
int determineVolumeInputIndex(int inputUnit)
{
	int VolumeInputIndex;
	switch (inputUnit)
	{
	case 1: VolumeInputIndex = 1; break;
	case 2: VolumeInputIndex = 2; break;
	case 3: VolumeInputIndex = 3; break;
	case 4: VolumeInputIndex = 4; break;
	case 5: VolumeInputIndex = 0; break;
	case 6: VolumeInputIndex = 1; break;
	case 7: VolumeInputIndex = 4; break;
	case 8: VolumeInputIndex = 5; break;
	case 9: VolumeInputIndex = 6; break;
	case 10: VolumeInputIndex = 7; break;
	case 11: VolumeInputIndex = 8; break;
	case 12: VolumeInputIndex = 9; break;
	}
	return VolumeInputIndex;
}
int determineVolumeOutputIndex(int outputUnit)
{
	int VolumeOutputIndex;
	switch (outputUnit)
	{
	case 1: VolumeOutputIndex = 1; break;
	case 2: VolumeOutputIndex = 2; break;
	case 3: VolumeOutputIndex = 3; break;
	case 4: VolumeOutputIndex = 4; break;
	case 5: VolumeOutputIndex = 0; break;
	case 6: VolumeOutputIndex = 1; break;
	case 7: VolumeOutputIndex = 4; break;
	case 8: VolumeOutputIndex = 5; break;
	case 9: VolumeOutputIndex = 6; break;
	case 10: VolumeOutputIndex = 7; break;
	case 11: VolumeOutputIndex = 8; break;
	case 12: VolumeOutputIndex = 9; break;
	}
	return VolumeOutputIndex;
}

double volumeConversion(int inputUnit, int outputUnit, double inputValue)
{
	vector volumeConversionTable;
	int VolumeInputIndex, VolumeOutputIndex;

	for (int k = 0; k < MAX_ARRAY_LENGTH; k++)
	{
		volumeConversionTable.values[k] = 0;
	}

	VolumeInputIndex = determineVolumeInputIndex(inputUnit);
	VolumeOutputIndex = determineVolumeOutputIndex(outputUnit);
	volumeConversionTable.values[VolumeInputIndex] = inputValue;

	if (VolumeInputIndex == 0)
	{
		volumeConversionTable.values[1] = inputValue *1000;
		for (int i = 2; i < 5; i++)
		{
			volumeConversionTable.values[i] = volumeConversionTable.values[1] * pow(10, i - VolumeInputIndex);
		}
	}
	else
	{
		if (VolumeInputIndex == 1)
		{
			volumeConversionTable.values[0] = inputValue / 1000;
			for (int i = 2; i < 5; i++)
			{
				volumeConversionTable.values[i] = volumeConversionTable.values[1] * pow(10, i - VolumeInputIndex);
			}
		}
		else
		{
			if ((VolumeInputIndex > 1) && (VolumeInputIndex < 5))
			{
				for (int i = 1; i < 5; i++)
				{
					if (i < VolumeInputIndex)
					{
						volumeConversionTable.values[i] = inputValue / pow(10, VolumeInputIndex - i);
					}
					if (i > VolumeInputIndex)
					{
						volumeConversionTable.values[i] = inputValue * pow(10, i - VolumeInputIndex);
					}
				}
			}
			else
			{
				switch (VolumeInputIndex)
				{
				case 5:; break;
				}
			}
		}
	}
	return volumeConversionTable.values[VolumeOutputIndex];
}

//4. TIME
void displayTimeOptions()
{
	cout << "1. nanosecond " << endl;
	cout << "2. microsecond " << endl;
	cout << "3. milisecond " << endl;
	cout << "4. second " << endl;
	cout << "5. minute " << endl;
	cout << "6. hour " << endl;
	cout << "7. day " << endl;
	cout << "8. week " << endl;
	cout << "9. month " << endl;
	cout << "10. year " << endl;
	cout << "11. decade " << endl;
	cout << "12. century " << endl;
	noTimeOptions = 12;
}
void timeInputUnitCorespondence(int inputUnit)
{
	switch (inputUnit)
	{
	case 1: cout << "nanosecond(s)"; break;
	case 2: cout << "microsecond(s)"; break;
	case 3: cout << "milisecond(s)"; break;
	case 4: cout << "second(s)"; break;
	case 5: cout << "minute(s)"; break;
	case 6: cout << "hour(s)"; break;
	case 7: cout << "day(s)"; break;
	case 8: cout << "week(s)"; break;
	case 9: cout << "month(s)"; break;
	case 10: cout << "year(s)"; break;
	case 11: cout << "decade(s)"; break;
	case 12: cout << "century(s)"; break;
	}
}
void timeOutputUnitCorespondence(int outputUnit)
{
	switch (outputUnit)
	{
	case 1: cout << "nanosecond(s)"; break;
	case 2: cout << "microsecond(s)"; break;
	case 3: cout << "milisecond(s)"; break;
	case 4: cout << "second(s)"; break;
	case 5: cout << "minute(s)"; break;
	case 6: cout << "hour(s)"; break;
	case 7: cout << "day(s)"; break;
	case 8: cout << "week(s)"; break;
	case 9: cout << "month(s)"; break;
	case 10: cout << "year(s)"; break;
	case 11: cout << "decade(s)"; break;
	case 12: cout << "century(s)"; break;
	}
}
/*
double timeConversion(int inputUnit, int outputUnit, double inputValue)
{





}
*/

//5 TEMPERATURE
void displayTemperatureOptions()
{
	cout << "C. Celsius " << endl;
	cout << "F. Fahrenheit " << endl;
	cout << "K. Kelvin " << endl;
}
double temperatureConversion(char inputUnitTemperature, char outputUnitTemperature, double inputValue)
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
	if (inputUnitTemperature == 'F' || inputUnitTemperature == 'f')
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

//6.MASS
void displayMassOptions()
{
	cout << "1. t (ton) " << endl;
	cout << "2. kg " << endl;
	cout << "3. g " << endl;
	cout << "4. mg " << endl;
	cout << "5. lb (pound) " << endl;
	cout << "6. oz (ounce) " << endl;
	noUnitsMassMetric = 4;
	noUnitsMassSpecial = 2;
}
void massInputUnitCorespondence(int inputUnit)
{
	switch (inputUnit)
	{
	case 1: cout << "ton(s)"; break;
	case 2: cout << "kilo(s)"; break;
	case 3: cout << "gram(s)"; break;
	case 4: cout << "miligram(s)"; break;
	case 5: cout << "pounds(s)"; break;
	case 6: cout << "ounce(s)"; break;
	}
}
void massOutputUnitCorespondence(int outputUnit)
{
	switch (outputUnit)
	{
	case 1: cout << "ton(s)"; break;
	case 2: cout << "kilo(s)"; break;
	case 3: cout << "gram(s)"; break;
	case 4: cout << "miligram(s)"; break;
	case 5: cout << "pounds(s)"; break;
	case 6: cout << "ounce(s)"; break;
	}
}

double massConversion(int inputUnit, int outputUnit, double inputValue)
{
	vector massConversionTable;
	int i, inputIndex, outputIndex;

	for (int k = 0; k < MAX_ARRAY_LENGTH; k++)
	{
		massConversionTable.values[k] = 0;
	}

	inputIndex = determineInputIndex(inputUnit);
	outputIndex = determineOutputIndex(outputUnit);
	massConversionTable.values[inputIndex] = inputValue;

	if (inputIndex < noUnitsMassMetric)
	{
		for (int i = 0; i < noUnitsMassMetric; i++)
		{
			if (i < inputIndex)
			{
				massConversionTable.values[i] = inputValue / pow(1000, inputIndex - i);
			}
			if (i > inputIndex)
			{
				massConversionTable.values[i] = inputValue * pow(1000, i - inputIndex);
			}
		}
		switch (outputUnit)
		{
		case 5: massConversionTable.values[outputUnit] = massConversionTable.values[2] / oneLbinGrams;
		case 6: massConversionTable.values[outputUnit] = massConversionTable.values[2] / oneOzinGrams;
		}
	}
	else
	{
		switch (inputUnit)
		{
		case 5: massConversionTable.values[2] = inputValue * oneLbinGrams;
		case 6: massConversionTable.values[2] = inputValue * oneOzinGrams;
		}
		for (int i = 0; i < noUnitsMassMetric; i++)
		{
			if (i < 2)
			{
				massConversionTable.values[i] = massConversionTable.values[2] / pow(1000, 2 - i);
			}
			else
			{
				massConversionTable.values[i] = massConversionTable.values[2] * pow(1000, i - 2);
			}
		}
		switch (outputUnit)
		{
		case 5: massConversionTable.values[outputUnit] = massConversionTable.values[2] / oneLbinGrams;
		case 6: massConversionTable.values[outputUnit] = massConversionTable.values[2] / oneOzinGrams;
		}
	}
	return massConversionTable.values[outputUnit];
}



int main()
{
	char continueOrExit;
	bool continueOrStop=0;
	int unitCategory, inputUnit, outputUnit;
	double inputValue;
	char inputUnitTemperature, outputUnitTemperature;

	do
	{
		cout << endl;
		intro();
		unitCategories();
		cin >> unitCategory;
		isCategoryInsideBounds(unitCategory);

		//area
		if (unitCategory == 1)
		{
			displayAreaOptions();
			inputUnit = readInputUnit();
			outputUnit = readOutputUnit();
			inputValue = readInputValue();
			cout << inputValue;
			cout << " ";
			areaInputUnitCorespondence(inputUnit);
			cout << " is " << areaConversion(inputUnit, outputUnit, inputValue);
			cout << " ";
			areaOutputUnitCorespondence(outputUnit);
			cout << endl;
		}

		//length
		if (unitCategory == 2)
		{
			displayLengthOptions();
			inputUnit = readInputUnit();
			outputUnit = readOutputUnit();
			inputValue = readInputValue();
			cout << inputValue;
			cout << " ";
			lengthInputUnitCorespondence(inputUnit);
			cout << " is " << lengthConversion(inputUnit, outputUnit, inputValue);
			cout << " ";
			lengthOutputUnitCorespondence(outputUnit);
			cout << endl;
		}

		//volume
		if (unitCategory == 3)
		{
			displayVolumeOptions();
			inputUnit = readInputUnit();
			outputUnit = readOutputUnit();
			inputValue = readInputValue();
			cout << inputValue;
			cout << " ";
			volumeInputUnitCorespondence(inputUnit);
			cout << " is " << volumeConversion(inputUnit, outputUnit, inputValue);
			cout << " ";
			volumeOutputUnitCorespondence(outputUnit);
			cout << endl;
		}

		//time
		if (unitCategory == 4)
		{

		}

		//temperature
		if (unitCategory == 5) 
		{
			displayTemperatureOptions();
			inputUnitTemperature = readInputUnitLetter();
			outputUnitTemperature = readOutputUnitLetter();
			inputValue = readInputValue();
			cout << "The result is: " << temperatureConversion(inputUnitTemperature, outputUnitTemperature, inputValue) << endl;
		}

		//mass
		if (unitCategory == 6)
		{
			displayMassOptions();
			inputUnit = readInputUnit();
			outputUnit = readOutputUnit();
			inputValue = readInputValue();
			cout << inputValue;
			cout << " ";
			massInputUnitCorespondence(inputUnit);
			cout << " is " << massConversion(inputUnit, outputUnit, inputValue);
			cout << " ";
			massOutputUnitCorespondence(outputUnit);
			cout << endl;
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
