#include "converter.h"

int noOfCategories, noTimeOptions, noUnitsMassMetric, noUnitsMassSpecial;
int noOfAreaOptions, noUnitsAreaMetric;
int noOfLengthOptions, noUnitsLengthMetric;


//general
void intro()
{
	system("Color A");
	cout << "~~~WELCOME~~~" << endl;
	cout << "~~~UNIT CONVERTER~~~" << endl;
	system("Color");
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
	//noUnitsAreaMetric
	cout << "1. square kilometers " << endl;
	cout << "2. square hectometers " << endl;
	cout << "3. square decameters " << endl;
	cout << "4. square meters " << endl;
	cout << "5. square decimeters " << endl;
	cout << "6. square centimeters " << endl;
	cout << "7. square milimeters " << endl;
	//Special Units
	cout << "8. square inches " << endl;
	cout << "9. square feet " << endl;
	cout << "10. square miles " << endl;
	cout << "11. hectares " << endl;
	noUnitsAreaMetric = 7;
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
	double valueInSquareMeters, valueInSquareKm;

	for (int k = 0; k < MAX_ARRAY_LENGTH; k++)
	{
		areaConversionTable.values[k] = 0;
	}

	inputIndex = determineInputIndex(inputUnit);
	outputIndex = determineOutputIndex(outputUnit);
	areaConversionTable.values[inputIndex] = inputValue;

	if (inputIndex < noUnitsAreaMetric)
	{
		for (i = 0; i < noUnitsAreaMetric; i++)
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
		valueInSquareMeters = areaConversionTable.values[3];
		valueInSquareKm = areaConversionTable.values[0];
		//  to square inches, feet, miles, hectares
		switch (outputIndex)
		{
		case 7: areaConversionTable.values[outputIndex] = valueInSquareMeters * oneSquareMeterInSquareInches; break;
		case 8: areaConversionTable.values[outputIndex] = valueInSquareMeters * oneSquareMeterInSquareFeet; break;
		case 9: areaConversionTable.values[outputIndex] = valueInSquareKm * oneSquareKilometerInSquareMiles; break;
		case 10: areaConversionTable.values[outputIndex] = valueInSquareMeters * oneSquareMeterInHectares; break;
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
{   //noUnitsLengthMetric
	cout << "1. km (kilometers) " << endl;
	cout << "2. hm (hectometers)" << endl;
	cout << "3. dam (decameters) " << endl;
	cout << "4. m (meters) " << endl;
	cout << "5. dm (decimeters) " << endl;
	cout << "6. cm (centimeters) " << endl;
	cout << "7. mm (milimeters) " << endl;
	//special units
	cout << "8. in (inches) " << endl;
	cout << "9. ft (feet) " << endl;
	cout << "10. mi (miles) " << endl;
	cout << "11. yd (yards) " << endl;
	cout << "12. nmi (nautical mile) " << endl;
	noOfLengthOptions = 12;
	noUnitsLengthMetric = 7;

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
	int i, inputIndex, outputIndex, valueInMeters;

	for (int k = 0; k < MAX_ARRAY_LENGTH; k++)
	{
		lengthConversionTable.values[k] = 0;
	}

	inputIndex = determineInputIndex(inputUnit);
	outputIndex = determineOutputIndex(outputUnit);
	lengthConversionTable.values[inputIndex] = inputValue;

	// km --> mm
	if (inputIndex < noUnitsLengthMetric)
	{
		for (i = 0; i < noUnitsLengthMetric; i++)
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
		valueInMeters = lengthConversionTable.values[3];

		// to inches, feet, miles, yards
		switch (outputIndex)
		{
		case 7: lengthConversionTable.values[outputIndex] = valueInMeters * oneMeterIninches; break;
		case 8: lengthConversionTable.values[outputIndex] = valueInMeters * oneMeterInFeet; break;
		case 9: lengthConversionTable.values[outputIndex] = valueInMeters * oneMeterInMiles; break;
		case 10: lengthConversionTable.values[outputIndex] = valueInMeters * oneMeterInYards; break;
		case 11: lengthConversionTable.values[outputIndex] = valueInMeters * oneMeterInNauticalMiles; break;
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
		for (i = 0; i < noUnitsLengthMetric; i++)
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
	cout << "1. century " << endl; 	//largeUnits
	cout << "2. decade " << endl;
	cout << "3. year " << endl; 
	cout << "4. month " << endl;
	cout << "5. week " << endl;
	cout << "6. day " << endl; // middleUnits
	cout << "7. hour " << endl;
	cout << "8. minute " << endl; 
	cout << "9. second " << endl; //smallUnits
	cout << "10. milisecond " << endl;
	cout << "11. microsecond " << endl; 
	cout << "12. nanosecond " << endl; 
	noTimeOptions = 12;
}
void timeInputUnitCorespondence(int inputUnit)
{
	switch (inputUnit)
	{
	case 1: cout << "century(s)"; break;
	case 2: cout << "decade(s)"; break;
	case 3: cout << "year(s)"; break;
	case 4: cout << "month(s)"; break;
	case 5: cout << "week(s)"; break;
	case 6: cout << "day(s)"; break;
	case 7: cout << "hour(s)"; break;
	case 8: cout << "minute(s)"; break;
	case 9: cout << "second(s)"; break;
	case 10: cout << "milisecond(s)"; break;
	case 11: cout << "microsecond(s)"; break;
	case 12: cout << "nanosecond(s)"; break;
	}
}
void timeOutputUnitCorespondence(int outputUnit)
{
	switch (outputUnit)
	{
	case 1: cout << "century(s)"; break;
	case 2: cout << "decade(s)"; break;
	case 3: cout << "year(s)"; break;
	case 4: cout << "month(s)"; break;
	case 5: cout << "week(s)"; break;
	case 6: cout << "day(s)"; break;
	case 7: cout << "hour(s)"; break;
	case 8: cout << "minute(s)"; break;
	case 9: cout << "second(s)"; break;
	case 10: cout << "milisecond(s)"; break;
	case 11: cout << "microsecond(s)"; break;
	case 12: cout << "nanosecond(s)"; break;
	}
}

int productFirstXElementsArray(int vec[MAX_ARRAY_LENGTH], int x)
{
	int product = 1;
	for (int i = 0; i < x; i++)
	{
		product *= vec[i];
	}
	return product;
}

double timeConversion(int inputUnit, int outputUnit, double inputValue)
{
	int i, j, k;
	//large = century -> day exclusiv; middle = day -> second; small = second -> ns
	int conversionTableLarge[] = { 1, 10, 10, 12, 4, 7 };
	int conversionTableMiddle[] = {1, 24, 60, 60};
	int conversionTableSmall[] = {1, 1000, 1000, 1000};

	vector large, middle, small;
	large.length = largeUnits;
	middle.length = middleUnits;
	small.length = smallUnits;
	
	switch (inputUnit)		
	{
	case 1: large.values[0] = inputUnit; break;
	case 2: large.values[0] = inputUnit / productFirstXElementsArray(conversionTableLarge, 2); break;
	case 3: large.values[0] = inputUnit / productFirstXElementsArray(conversionTableLarge, 3); break;
	case 4: large.values[0] = inputUnit / productFirstXElementsArray(conversionTableLarge, 4); break;
	case 5: large.values[0] = inputUnit / productFirstXElementsArray(conversionTableLarge, 5); break;
	case 6: large.values[0] = inputUnit / productFirstXElementsArray(conversionTableLarge, 6); break; 
	case 7: { middle.values[0] = inputUnit / productFirstXElementsArray(conversionTableMiddle, 2);
		large.values[2] = middle.values[0] / 365;
		large.values[0] = large.values[2] / 100;
		break; }
	case 8: {middle.values[0] = inputUnit / productFirstXElementsArray(conversionTableMiddle, 3);
		large.values[2] = middle.values[0] / 365;
		large.values[0] = large.values[2] / 100;
		break; }
	case 9: {middle.values[0] = inputUnit / productFirstXElementsArray(conversionTableMiddle, 4); 
		large.values[2] = middle.values[0] / 365;
		large.values[0] = large.values[2] / 100;
		break; }
	case 10: {small.values[0] = inputUnit / productFirstXElementsArray(conversionTableSmall, 2); 
		large.values[large.length-1] = small.values[0]/(24*60*60);
		large.values[0] = large.values[large.length - 1] / 365;
		break; }
	case 11: {small.values[0] = inputUnit / productFirstXElementsArray(conversionTableSmall, 2); 
		large.values[large.length - 1] = small.values[0] / (24 * 60 * 60);
		large.values[0] = large.values[large.length - 1] / 365;
		break; }
	case 12: {small.values[0] = inputUnit / productFirstXElementsArray(conversionTableSmall, 2); 
		large.values[large.length - 1] = small.values[0] / (24 * 60 * 60);
		large.values[0] = large.values[large.length - 1] / 365;
		break; }
	}
	
	for (i = 1; i < large.length; i++)
	{
		large.values[i] = large.values[i - 1] * conversionTableLarge[i];
	} // here, it is considered that all months have 30 days
	
	middle.values[0] = large.values[2] * 365; // correct no of days
	for (j = 1; j < middle.length; j++)
	{
		middle.values[j] = middle.values[j - 1] * conversionTableMiddle[j];
	}

	small.values[0] = middle.values[middle.length - 1]; // no seconds
	for (k = 1; k < small.length; k++)
	{
		small.values[k] = small.values[k - 1] * conversionTableSmall[k];
	}

	switch (outputUnit)
	{
	case 1: return large.values[0]; break;
	case 2: return large.values[1]; break;
	case 3: return large.values[2]; break;
	case 4: return large.values[3]; break;
	case 5: return large.values[4]; break;
	case 6: return middle.values[0]; break;
	case 7: return middle.values[1]; break;
	case 8: return middle.values[2]; break;
	case 9: return middle.values[3]; break; 
	case 10: return small.values[1]; break;
	case 11: return small.values[2]; break;
	case 12: return small.values[3]; break;
	}
}


//5 TEMPERATURE -done
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


//7. ENERGY
void displayEnergyOptions()
{
	cout << "1. Joule " << endl;
	cout << "2. Kilojoule " << endl;
	cout << "3. Gram Calorie " << endl;
	cout << "4. Kilo calorie " << endl;
	cout << "5. Watt hour " << endl;
	cout << "6. Kilowatt hour " << endl;
	cout << "7. Electronvolt" << endl;
	cout << "8. British thermal unit " << endl;
	cout << "9. US Therm " << endl;
	cout << "10. Foot pound " << endl;
}

// 8. PRESSURE
void displayPressureOptions()
{
	cout << "1. atm (atmosphere) " << endl;
	cout << "2. bar " << endl;
	cout << "3. Pascal " << endl;
	cout << "4. Pound-force per square inch (PSI) " << endl;
	cout << "5. Torr " << endl;
	cout << "6. N/mm2 " << endl;
	cout << "7. mmHg" << endl;
	cout << "8. mmH2O" << endl;
}

//9. DENSITY
void displayDensityOptions()
{

}

//10.SPEED
void displaySpeedOptions()
{
	cout << "1. km/s " << endl;
	cout << "2. km/h " << endl;
	cout << "3. m/s " << endl;
	cout << "4. m/min " << endl;
	cout << "5. mps " << endl;
	cout << "6. mph " << endl;
	cout << "7. foot/s " << endl;
	cout << "8. foot/min " << endl;
	//joggers
	cout << "9. min/km " << endl;
	cout << "10. s/100m " << endl;

}

//11. FUEL CONSUMPTION
void displayFuelOptions()
{//metric
	cout << "1. l/100km " << endl;
	cout << "2. km/l " << endl;
	//us
	cout << "3. mpg (miles per gallon- US) " << endl;
	cout << "4. gal(US)/100 mi " << endl;
	//uk
	cout << "5. mpg (miles per gallon - UK) " << endl;
	cout << "6. gal(UK)/100 mi " << endl;
	cout << "7. mi/l " << endl;
	cout << "7. l/100mi " << endl;
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
			displayTimeOptions();
			inputUnit = readInputUnit();
			outputUnit = readOutputUnit();
			inputValue = readInputValue();
			cout << inputValue;
			cout << " ";
			timeInputUnitCorespondence(inputUnit);
			cout << " is " << timeConversion(inputUnit, outputUnit, inputValue);
			cout << " ";
			timeOutputUnitCorespondence(outputUnit);
			cout << endl;
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

		//energy
		if (unitCategory == 7)
		{

		}

		//pressure
		if (unitCategory == 8)
		{

		}

		//density
		if (unitCategory == 9)
		{

		}

		//speed
		if (unitCategory == 10)
		{

		}

		//fuel cons
		if (unitCategory == 11)
		{

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
