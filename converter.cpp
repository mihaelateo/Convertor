#include "converter.h"

int noOfCategories, noTimeOptions, noUnitsMassMetric, noUnitsMassSpecial;
int noOfAreaOptions, noUnitsAreaMetric;
int noOfLengthOptions, noUnitsLengthMetric;

//general
void setColor(int color) 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void intro()
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 16;
	cfi.FontFamily = FF_MODERN;
	cfi.FontWeight = FW_BOLD;
	wcscpy_s(cfi.FaceName, L"Tahoma");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	
	setColor(2);
	cout << "\t ~~~ UNIT CONVERTER~~~" << endl;
	cout << endl;
}
void unitCategories()
{
	cout << " Please select your option from the following: " << endl;
	cout << endl;
	cout << "\t\t 1. Area " << endl;
	cout << "\t\t 2. Length " << endl;
	cout << "\t\t 3. Volume " << endl;
	cout << "\t\t 4. Time " << endl;
	cout << "\t\t 5. Temperature " << endl;
	cout << "\t\t 6. Mass " << endl;
	cout << "\t\t 7. Energy " << endl;
	cout << "\t\t 8. Pressure " << endl;
	cout << "\t\t 9. Density" << endl;
	cout << "\t\t 10. Speed " << endl;
	cout << "\t\t 11. Fuel consumption " << endl;
	cout << endl;
	noOfCategories = 11;
}
void unitCategoriesCorrespondence(int unitCategory)
{
	switch (unitCategory)
	{
	case 1: cout << "\t \t \t \t CATEGORY: AREA " << endl; break;
	case 2: cout << "\t \t \t \t CATEGORY: LENGTH " << endl; break;
	case 3: cout << "\t \t \t \t CATEGORY: VOLUME " << endl; break;
	case 4: cout << "\t \t \t \t CATEGORY: TIME " << endl; break;
	case 5: cout << "\t \t \t \t CATEGORY: TEMPERATURE " << endl; break;
	case 6: cout << "\t \t \t \t CATEGORY: MASS " << endl; break;
	case 7: cout << "\t \t \t \t CATEGORY: ENERGY " << endl; break;
	case 8: cout << "\t \t \t \t CATEGORY: PRESSURE " << endl; break;
	case 9: cout << "\t \t \t \t CATEGORY: DENSITY " << endl; break;
	case 10: cout << "\t \t \t \t CATEGORY: SPEED " << endl; break;
	case 11: cout << "\t \t \t \t CATEGORY: FUEL CONSUMPTION " << endl; break;
	}
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

void printMatrix (matrix oneMatrix)
{
	cout << endl;
	for (int i = 0; i < MAX_ARRAY_LENGTH; i++)
	{
		for (int j = 0; j < MAX_ARRAY_LENGTH; j++)
		{
			cout << oneMatrix.values[i][j] << " / ";
		}
		cout << endl;
	}
	cout << endl;
}

void matrixInitialization(matrix &oneMatrix)
{
	for (int i = 0; i < MAX_ARRAY_LENGTH; i++)
	{
		for (int j = 0; j < MAX_ARRAY_LENGTH; j++)
		{
			oneMatrix.values[i][j] = 0;
		}
	}
}

void arrayInitialization(vector &oneVec)
{
	for (int i = 0; i < MAX_ARRAY_LENGTH; i++)
	{
		oneVec.values[i] = 0;
	}
}

void buildRestOfMatrix(matrix &oneMatrix, double inputValue)
{
	for (int i = 1; i < MAX_ARRAY_LENGTH; i++)
	{
		for (int j = i + 1; j < MAX_ARRAY_LENGTH; j++)
		{
			oneMatrix.values[i][j] = oneMatrix.values[0][j] * oneMatrix.values[i][0];
		}
		for (int k = i - 1; k >= 0; k--)
		{
			oneMatrix.values[i][k] = oneMatrix.values[0][k] * oneMatrix.values[i][0];
		}
	}
}

//user input
double readInputValue()
{
	double inputValue;
	cout << "Number of units to convert: ";
	cin >> inputValue;
	return inputValue;
}
int readInputUnit()
{
	int inputUnit;
	cout << "Convert from (please type in the number corresponding to your option): ";
	cin >> inputUnit;
	return inputUnit;
}
int readOutputUnit()
{
	int outputUnit;
	cout << "Convert to (please type in the number corresponding to your option): ";
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
	int i, inputIndex, outputIndex;
	double valueInMeters;

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

//3. VOLUME - done
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
	case 1: cout << " l "; break;
	case 2: cout << " dl "; break;
	case 3: cout << " cl "; break;
	case 4: cout << " ml "; break;
	case 5: cout << " cubic m "; break;
	case 6: cout << " cubic dm "; break;
	case 7: cout << " cubic cm "; break;
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
	case 1: cout << " l "; break;
	case 2: cout << " dl "; break;
	case 3: cout << " cl "; break;
	case 4: cout << " ml "; break;
	case 5: cout << " cubic m "; break;
	case 6: cout << " cubic dm "; break;
	case 7: cout << " cubic cm "; break;
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
	case 1: VolumeInputIndex = 0; break;
	case 2: VolumeInputIndex = 1; break;
	case 3: VolumeInputIndex = 2; break;
	case 4: VolumeInputIndex = 3; break;
	case 5: VolumeInputIndex = 0; break;
	case 6: VolumeInputIndex = 1; break;
	case 7: VolumeInputIndex = 2; break;
	case 8: VolumeInputIndex = 1; break;
	case 9: VolumeInputIndex = 2; break;
	case 10: VolumeInputIndex = 3; break;
	case 11: VolumeInputIndex = 4; break;
	case 12: VolumeInputIndex = 5; break;
	}
	return VolumeInputIndex;
}
int determineVolumeOutputColumn(int outputUnit)
{
	int VolumeOutputColumn;
	
		switch (outputUnit)
		{
		case 1: VolumeOutputColumn = 0; break;
		case 2: VolumeOutputColumn = 1; break;
		case 3: VolumeOutputColumn = 2; break;
		case 4: VolumeOutputColumn = 3; break;
		case 5: VolumeOutputColumn = 0; break;
		case 6: VolumeOutputColumn = 1; break;
		case 7: VolumeOutputColumn = 2; break;
		case 8: VolumeOutputColumn = 1; break;
		case 9: VolumeOutputColumn = 2; break;
		case 10: VolumeOutputColumn = 3; break;
		case 11: VolumeOutputColumn = 4; break;
		case 12: VolumeOutputColumn = 5; break;
		}
	return VolumeOutputColumn;
}

void updateTableConversionSpecial(matrix &tableConversionSpecial, double inputValue)
{
	int i, j, k;
	vector specialUnits;
	arrayInitialization(specialUnits);
	specialUnits.values[0] = 1;
	specialUnits.values[1] = LtoUSgal;
	specialUnits.values[2] = LtoUKgal;
	specialUnits.values[3] = LtoCubicFt;
	specialUnits.values[4] = LtoCubicIn;
	specialUnits.values[5] = LtoCubicYd;

	i = 0; // val din L in special unit
	tableConversionSpecial.values[i][i] = inputValue;
	for (j = i + 1; j < MAX_ARRAY_LENGTH; j++)
	{
		tableConversionSpecial.values[i][j] = tableConversionSpecial.values[i][i] * specialUnits.values[j];
	}
	for (i = 1; i < MAX_ARRAY_LENGTH; i++)
	{
		tableConversionSpecial.values[i][i] = inputValue;
		for (j = i + 1; j < MAX_ARRAY_LENGTH; j++)
		{
			tableConversionSpecial.values[i][j] = tableConversionSpecial.values[0][j] / tableConversionSpecial.values[0][i];
		}
		for (k = i - 1; k >= 0; k--)
		{
			tableConversionSpecial.values[i][k] = tableConversionSpecial.values[0][k] / tableConversionSpecial.values[0][i];
		}
	}
}
void updateTableConversionLitres(matrix &tableConversionLitres, double inputValue)
{
	int i, j;
	for (i = 0; i < MAX_ARRAY_LENGTH; i++)
	{
		tableConversionLitres.values[i][i] = inputValue;
		for (j = i + 1; j < MAX_ARRAY_LENGTH; j++)
		{
			tableConversionLitres.values[i][j] = tableConversionLitres.values[i][i] * pow(10, j - i);
		}
		for (j = i - 1; j >= 0; j--)
		{
			tableConversionLitres.values[i][j] = tableConversionLitres.values[i][i] / pow(10, i - j);
		}
	}
}
void updateTableConversionCubicM(matrix &tableConversionCubicM, double inputValue)
{
	int i, j;
	for (i = 0; i < MAX_ARRAY_LENGTH; i++)
	{
		tableConversionCubicM.values[i][i] = inputValue;
		for (j = i + 1; j < MAX_ARRAY_LENGTH; j++)
		{
			tableConversionCubicM.values[i][j] = tableConversionCubicM.values[i][i] * pow(1000, j - i);
		}
		for (j = i - 1; j >= 0; j--)
		{
			tableConversionCubicM.values[i][j] = tableConversionCubicM.values[i][i] / pow(1000, i - j);
		}
	}
}
double volumeConversion(int inputUnit, int outputUnit, double inputValue)
{
	matrix tableConversionLitres, tableConversionCubicM, tableConversionSpecial;
	int inputIndex, outputIndex;
	double inLitres;

	matrixInitialization(tableConversionLitres);
	matrixInitialization(tableConversionCubicM);
	matrixInitialization(tableConversionSpecial);
	inputIndex = determineVolumeInputIndex(inputUnit);
	outputIndex = determineVolumeOutputColumn(outputUnit);

	if (outputUnit < 5 && inputUnit <5)
	{
		updateTableConversionLitres(tableConversionLitres, inputValue);
		return tableConversionLitres.values[inputIndex][outputIndex];
	}
	if ((outputUnit > 4 && outputUnit < 8) && (inputUnit > 4 && inputUnit < 8))
	{
		updateTableConversionCubicM(tableConversionCubicM, inputValue);
		return tableConversionCubicM.values[inputIndex][outputIndex];
	}
	if (outputUnit > 7 && inputUnit > 7)
	{
		updateTableConversionSpecial(tableConversionSpecial, inputValue);
		return tableConversionSpecial.values[inputIndex][outputIndex];
	}
	if (inputUnit <5 && (outputUnit > 4 && outputUnit < 8))
	{
		updateTableConversionLitres(tableConversionLitres, inputValue);
		inLitres = tableConversionLitres.values[inputIndex][0]; 
		updateTableConversionCubicM(tableConversionCubicM, inLitres);
		return tableConversionCubicM.values[1][outputIndex];
	}
	if ((inputUnit > 4 && inputUnit < 8) && outputUnit < 5)
	{
		updateTableConversionCubicM(tableConversionCubicM, inputValue);
		inLitres = tableConversionCubicM.values[inputIndex][1];
		updateTableConversionLitres(tableConversionLitres, inLitres);
		return tableConversionLitres.values[0][outputIndex];
	}
	if (inputUnit < 5 && outputUnit > 7)
	{
		updateTableConversionLitres(tableConversionLitres, inputValue);
		inLitres = tableConversionLitres.values[inputIndex][0];
		updateTableConversionSpecial(tableConversionSpecial, inLitres);
		return tableConversionSpecial.values[0][outputIndex];
	}
	if (inputUnit > 7 && outputUnit < 5)
	{
		updateTableConversionSpecial(tableConversionSpecial, inputValue);
		inLitres = tableConversionSpecial.values[inputIndex][0];
		updateTableConversionLitres(tableConversionLitres, inLitres);
		return tableConversionLitres.values[0][outputIndex];
	}
	if ((inputUnit > 4 && inputUnit < 8) && outputUnit > 7)
	{
		updateTableConversionCubicM(tableConversionCubicM, inputValue);
		inLitres = tableConversionCubicM.values[inputIndex][1];
		updateTableConversionSpecial(tableConversionSpecial, inLitres);
		return tableConversionSpecial.values[0][outputIndex];
	}
	if (inputUnit > 7 && (outputUnit > 4 && outputUnit < 8))
	{
		updateTableConversionSpecial(tableConversionSpecial, inputValue);
		inLitres = tableConversionSpecial.values[inputIndex][0];
		updateTableConversionCubicM(tableConversionCubicM, inLitres);
		return tableConversionCubicM.values[1][outputIndex];
	}
}

//4. TIME - done
void displayTimeOptions()
{
	cout << "1. century " << endl; 	//largeUnits
	cout << "2. decade " << endl;
	cout << "3. year " << endl; 
	cout << "4. month " << endl;
	cout << "5. week (1 month = 4 weeks) " << endl;
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
	int i;
	//large = century -> day exclusiv; middle = day -> second; small = second -> ns
	int conversionTableLarge[] = { 1, 10, 10, 12, 4, 7 };
	int conversionTableMiddle[] = {1, 24, 60, 60};
	int conversionTableSmall[] = {1, 1000, 1000, 1000};

	vector largeUnit, middleUnit, smallUnit;
	largeUnit.length = largeUnits;
	middleUnit.length = middleUnits;
	smallUnit.length = smallUnits;

	arrayInitialization(largeUnit);
	arrayInitialization(middleUnit);
	arrayInitialization(smallUnit);

	switch (inputUnit)		
	{
	case 1: largeUnit.values[0] = inputValue; break;
	case 2: largeUnit.values[0] = inputValue / productFirstXElementsArray(conversionTableLarge, 2); break;
	case 3: largeUnit.values[0] = inputValue / productFirstXElementsArray(conversionTableLarge, 3); break;
	case 4: largeUnit.values[0] = inputValue / productFirstXElementsArray(conversionTableLarge, 4); break;
	case 5: largeUnit.values[0] = inputValue / productFirstXElementsArray(conversionTableLarge, 5); break;
	case 6: largeUnit.values[0] = inputValue / productFirstXElementsArray(conversionTableLarge, 6); break;
	case 7: { middleUnit.values[0] = inputValue / productFirstXElementsArray(conversionTableMiddle, 2);
		largeUnit.values[2] = middleUnit.values[0] / 365;
		largeUnit.values[0] = largeUnit.values[2] / 100;
		break; }
	case 8: {middleUnit.values[0] = inputValue / productFirstXElementsArray(conversionTableMiddle, 3);
		largeUnit.values[2] = middleUnit.values[0] / 365;
		largeUnit.values[0] = largeUnit.values[2] / 100;
		break; }
	case 9: {middleUnit.values[0] = inputValue / productFirstXElementsArray(conversionTableMiddle, 4);
		largeUnit.values[2] = middleUnit.values[0] / 365;
		largeUnit.values[0] = largeUnit.values[2] / 100;
		break; }
	case 10: {smallUnit.values[0] = inputValue / productFirstXElementsArray(conversionTableSmall, 2);
		largeUnit.values[largeUnit.length-1] = smallUnit.values[0]/(24*60*60);
		largeUnit.values[0] = largeUnit.values[largeUnit.length - 1] / 365;
		break; }
	case 11: {smallUnit.values[0] = inputValue / productFirstXElementsArray(conversionTableSmall, 2);
		largeUnit.values[largeUnit.length - 1] = smallUnit.values[0] / (24 * 60 * 60);
		largeUnit.values[0] = largeUnit.values[largeUnit.length - 1] / 365;
		break; }
	case 12: {smallUnit.values[0] = inputValue / productFirstXElementsArray(conversionTableSmall, 2);
		largeUnit.values[largeUnit.length - 1] = smallUnit.values[0] / (24 * 60 * 60);
		largeUnit.values[0] = largeUnit.values[largeUnit.length - 1] / 365;
		break; }
	}
	
	for (i = 1; i < largeUnit.length; i++)
	{
		largeUnit.values[i] = largeUnit.values[i - 1] * conversionTableLarge[i];
	} // here, it is considered that all months have 30 days
	
	middleUnit.values[0] = largeUnit.values[2] * 365; // correct no of days
	for (i = 1; i < middleUnit.length; i++)
	{
		middleUnit.values[i] = middleUnit.values[i - 1] * conversionTableMiddle[i];
	}

	smallUnit.values[0] = middleUnit.values[middleUnit.length - 1]; // no seconds
	for (i = 1; i < smallUnit.length; i++)
	{
		smallUnit.values[i] = smallUnit.values[i - 1] * conversionTableSmall[i];
	}

	switch (outputUnit)
	{
	case 1: return largeUnit.values[0]; break;
	case 2: return largeUnit.values[1]; break;
	case 3: return largeUnit.values[2]; break;
	case 4: return largeUnit.values[3]; break;
	case 5: return largeUnit.values[4]; break;
	case 6: return middleUnit.values[0]; break;
	case 7: return middleUnit.values[1]; break;
	case 8: return middleUnit.values[2]; break;
	case 9: return middleUnit.values[3]; break;
	case 10: return smallUnit.values[1]; break;
	case 11: return smallUnit.values[2]; break;
	case 12: return smallUnit.values[3]; break;
	}
}

//5 TEMPERATURE -done
void displayTemperatureOptions()
{
	cout << "C. Celsius " << endl;
	cout << "F. Fahrenheit " << endl;
	cout << "K. Kelvin " << endl;
}
void temperatureInputUnitCorespondence(char inputUnit)
{
	if (inputUnit == 'C' || inputUnit == 'c')
	{
		cout << " ° Celsius ";
	}
	if (inputUnit == 'F' || inputUnit == 'f')
	{
		cout << " ° Fahrenheit ";
	}
	if (inputUnit == 'K' || inputUnit == 'k')
	{
		cout << " ° Kelvin ";
	}
}
void temperatureOutputUnitCorespondence(int outputUnit)
{
	if (outputUnit == 'C' || outputUnit == 'c')
	{
		cout << " ° Celsius ";
	}
	if (outputUnit == 'F' || outputUnit == 'f')
	{
		cout << " ° Fahrenheit ";
	}
	if (outputUnit == 'K' || outputUnit == 'k')
	
		cout << " ° Kelvin ";
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
			return (inputValue * 9 / 5 - 459, 67);
		}
	}
	if (inputUnitTemperature == 'F' || inputUnitTemperature == 'f')
	{
		if (outputUnitTemperature == 'C' || outputUnitTemperature == 'c')
		{
			return ((inputValue - 32) * 5 / 9);
		}
		if (outputUnitTemperature == 'K' || outputUnitTemperature == 'k')
		{
			return ((inputValue + 459, 67) * 5 / 9);
		}
	}
}

//6.MASS - done
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
	int i, inputIndex, outputIndex, indexKg = 1;
	double valueInKg;

	for (int k = 0; k < MAX_ARRAY_LENGTH; k++)
	{
		massConversionTable.values[k] = 0;
	}

	inputIndex = determineInputIndex(inputUnit);
	outputIndex = determineOutputIndex(outputUnit);
	massConversionTable.values[inputIndex] = inputValue;

	if (inputIndex < noUnitsMassMetric)
	{
		for (i = inputIndex + 1; i < noUnitsMassMetric; i++)
		{
			massConversionTable.values[i] = inputValue * pow(1000, i - inputIndex);
		}
		for (i = inputIndex - 1; i >=0; i--)
		{
			massConversionTable.values[i] = inputValue / pow(1000, inputIndex - i);
		}
		valueInKg = massConversionTable.values[1];
		switch (outputUnit)
		{
		case 5: massConversionTable.values[outputIndex] = valueInKg * KgToPounds; break;
		case 6: massConversionTable.values[outputIndex] = valueInKg * KgToOunce; break;
		}
	}
	else
	{
		switch (inputUnit)
		{
		case 5: valueInKg = inputValue / KgToPounds; break;
		case 6: valueInKg = inputValue / KgToOunce; break;
		}
		for (i = indexKg; i < noUnitsMassMetric; i++)
		{
			massConversionTable.values[i] = valueInKg * pow(1000, i - indexKg);
		}
		for (i = indexKg - 1; i >=0 ; i--)
		{
			massConversionTable.values[i] = valueInKg / pow(1000, indexKg - i);
		}
		switch (outputUnit)
		{
		case 5: massConversionTable.values[outputIndex] = valueInKg * KgToPounds; break;
		case 6: massConversionTable.values[outputIndex] = valueInKg * KgToOunce; break;
		}
	}
	return massConversionTable.values[outputIndex];
}


//7. ENERGY - done
void displayEnergyOptions()
{
	cout << "1. J " << endl;
	cout << "2. kJ " << endl;
	cout << "3. gcal (gram calorie) " << endl;
	cout << "4. Kcal " << endl;
	cout << "5. Gcal " << endl;
	cout << "6. Watt hour" << endl;
	cout << "7. Kilowatt hour" << endl;
	cout << "8. British thermal unit " << endl;
	cout << "9. US Therm Units " << endl;
	cout << "10. Foot pound " << endl;
}
void energyInputUnitCorespondence(int inputUnit)
{
	switch (inputUnit)
	{
	case 1: cout << " Joule(s) "; break;
	case 2: cout << " Kilojoule(s) "; break;
	case 3: cout << " Gram Calorie(s) "; break;
	case 4: cout << " Kilo calorie(s) "; break;
	case 5: cout << " Giga calorie(s) "; break;
	case 6: cout << " Watt(s)/hour "; break;
	case 7: cout << " Kilowatt(s)/hour "; break;
	case 8: cout << " British thermal unit(s) "; break;
	case 9: cout << " US Therm Unit(s) "; break;
	case 10: cout << " Foot pound(s) "; break;
	}
}
void energyOutputUnitCorespondence(int outputUnit)
{
	switch (outputUnit)
	{
	case 1: cout << " Joule(s) "; break;
	case 2: cout << " Kilojoule(s) "; break;
	case 3: cout << " Gram Calorie(s) "; break;
	case 4: cout << " Kilo calorie(s) "; break;
	case 5: cout << " Giga calorie(s) "; break;
	case 6: cout << " Watt(s)/hour "; break;
	case 7: cout << " Kilowatt(s)/hour "; break;
	case 8: cout << " British thermal unit(s) "; break;
	case 9: cout << " US Therm Unit(s) "; break;
	case 10: cout << " Foot pound(s) "; break;
	}
}

void buildEnergyConversionTable(matrix &oneMatrix, double inputValue)
{
	int i;
	double conversionFactor;
	matrixInitialization(oneMatrix);
	ifstream fin("EnergytoJoule.in");
	oneMatrix.values[0][0] = inputValue;
	for (i = 1; (i < MAX_ARRAY_LENGTH && !fin.eof()); i++)
	{
		fin >> conversionFactor;
		oneMatrix.values[i][0] = conversionFactor * inputValue; // prima col
		oneMatrix.values[i][i] = inputValue; //diag princ
		oneMatrix.values[0][i] = inputValue / oneMatrix.values[i][0]; // prima linie
	}
	fin.close();
	buildRestOfMatrix(oneMatrix, inputValue);
}
double energyConversion(int inputUnit, int outputUnit, double inputValue)
{
	matrix energyConversionTable;
	buildEnergyConversionTable(energyConversionTable, inputValue);
	return energyConversionTable.values[inputUnit - 1][outputUnit - 1];
}

// 8. PRESSURE - done
void displayPressureOptions()
{
	cout << "1. atm (atmosphere) " << endl;
	cout << "2. bar " << endl;
	cout << "3. Pascal " << endl;
	cout << "4. Pound-force per square inch (PSI) " << endl;
	cout << "5. Torr " << endl;
	cout << "6. N/mm2 " << endl;
	cout << "7. mmHg " << endl;
	cout << "8. mmH2O " << endl;
}
void pressureInputUnitCorespondence(int inputUnit)
{
	switch (inputUnit)
	{
	case 1: cout << " atmosphere(s) "; break;
	case 2: cout << " bar(s) "; break;
	case 3: cout << " Pascal(s) "; break;
	case 4: cout << " Pound-force per square inch(es) "; break;
	case 5: cout << " Torr(s) "; break;
	case 6: cout << " N/mm2 "; break;
	case 7: cout << " mmHg "; break;
	case 8: cout << " mmH2O "; break;
	}
}
void pressureOutputUnitCorespondence(int outputUnit)
{
	switch (outputUnit)
	{
	case 1: cout << " atmosphere(s) "; break;
	case 2: cout << " bar(s) "; break;
	case 3: cout << " Pascal(s) "; break;
	case 4: cout << " Pound-force per square inch(es) "; break;
	case 5: cout << " Torr(s) "; break;
	case 6: cout << " N/mm2 "; break;
	case 7: cout << " mmHg "; break;
	case 8: cout << " mmH2O "; break;
	}
}

void buildPressureConversionTable(matrix &oneMatrix, double inputValue)
{
	int i;
	double conversionFactor;
	matrixInitialization(oneMatrix);
	ifstream fin("PressuretoAtmospheres.in");
	oneMatrix.values[0][0] = inputValue;
	for (i = 1; (i < MAX_ARRAY_LENGTH && !fin.eof()); i++)
	{
		fin >> conversionFactor;
		oneMatrix.values[i][0] = conversionFactor * inputValue;
		oneMatrix.values[i][i] = inputValue; 
		oneMatrix.values[0][i] = inputValue / oneMatrix.values[i][0];
	}
	fin.close();
	buildRestOfMatrix(oneMatrix, inputValue);
}

double pressureConversion(int inputUnit, int outputUnit, double inputValue)
{
	matrix pressureConversionTable;
	buildPressureConversionTable(pressureConversionTable, inputValue);
	return pressureConversionTable.values[inputUnit - 1][outputUnit - 1];
}

//9. DENSITY
void displayDensityOptions()
{
	cout << "1. kg/cm3 " << endl;
	cout << "2. kg/l " << endl;
	cout << "3. kg/m3 " << endl;
	cout << "4. g/cm3 " << endl;
	cout << "5. g/l " << endl;
	cout << "6. g/m3 " << endl;
	cout << "7. g/ml " << endl;
	cout << "8. g/mm3 " << endl;
	cout << "9. mg/cm3 " << endl;
	cout << "10. mg/l " << endl;
	cout << "11. mg/m3 " << endl;
	cout << "12. lb/gal (US) " << endl;
	cout << "13. lb/gal (UK) " << endl;
	cout << "14. lb/ft3 " << endl;
	cout << "15. lb/in3 " << endl;
	cout << "16. oz/gal (US) " << endl;
	cout << "17. oz/gal (UK) " << endl;
	cout << "18. oz/ft3 " << endl;
	cout << "19. oz/in3 " << endl;
}
void densityInputUnitCorespondence(int inputUnit)
{
	switch (inputUnit)
	{
	case 1: cout << "1. kg/cm3 " << endl; break;
	case 2: cout << "2. kg/l " << endl; break;
	case 3: cout << "3. kg/m3 " << endl; break;
	case 4: cout << "4. g/cm3 " << endl; break;
	case 5: cout << "5. g/l " << endl; break;
	case 6: cout << "6. g/m3 " << endl; break;
	case 7: cout << "7. g/ml " << endl; break;
	case 8:	cout << "8. g/mm3 " << endl; break;
	case 9: cout << "9. mg/cm3 " << endl; break;
	case 10: cout << "10. mg/l " << endl; break;
	case 11: cout << "11. mg/m3 " << endl; break;
	case 12: cout << "12. lb/gal (US) " << endl; break;
	case 13: cout << "13. lb/gal (UK) " << endl; break;
	case 14: cout << "14. lb/ft3 " << endl; break;
	case 15: cout << "15. lb/in3 " << endl; break;
	case 16: cout << "16. oz/gal (US) " << endl; break;
	case 17: cout << "17. oz/gal (UK) " << endl; break;
	case 18: cout << "18. oz/ft3 " << endl; break;
	case 19: cout << "19. oz/in3 " << endl; break;
	}
}
void densityOutputUnitCorespondence(int outputUnit)
{
	switch (outputUnit)
	{
	case 1: cout << "1. kg/cm3 " << endl; break;
	case 2: cout << "2. kg/l " << endl; break;
	case 3: cout << "3. kg/m3 " << endl; break;
	case 4: cout << "4. g/cm3 " << endl; break;
	case 5: cout << "5. g/l " << endl; break;
	case 6: cout << "6. g/m3 " << endl; break;
	case 7: cout << "7. g/ml " << endl; break;
	case 8:	cout << "8. g/mm3 " << endl; break;
	case 9: cout << "9. mg/cm3 " << endl; break;
	case 10: cout << "10. mg/l " << endl; break;
	case 11: cout << "11. mg/m3 " << endl; break;
	case 12: cout << "12. lb/gal (US) " << endl; break;
	case 13: cout << "13. lb/gal (UK) " << endl; break;
	case 14: cout << "14. lb/ft3 " << endl; break;
	case 15: cout << "15. lb/in3 " << endl; break;
	case 16: cout << "16. oz/gal (US) " << endl; break;
	case 17: cout << "17. oz/gal (UK) " << endl; break;
	case 18: cout << "18. oz/ft3 " << endl; break;
	case 19: cout << "19. oz/in3 " << endl; break;
	}
}

void buildDensityConversionTable(matrix &oneMatrix, double inputValue)
{
	int i;
	double conversionFactor;
	matrixInitialization(oneMatrix);
	ifstream fin("DensitytoKgPerCm3.in");
	oneMatrix.values[0][0] = inputValue;
	for (i = 1; (i < MAX_ARRAY_LENGTH && !fin.eof()); i++)
	{
		fin >> conversionFactor;
		oneMatrix.values[i][0] = conversionFactor * inputValue;
		oneMatrix.values[i][i] = inputValue;
		oneMatrix.values[0][i] = inputValue / oneMatrix.values[i][0];
	}
	fin.close();
	buildRestOfMatrix(oneMatrix, inputValue);
}

double densityConversion(int inputUnit, int outputUnit, double inputValue)
{
	matrix densityConversionTable;
	buildDensityConversionTable(densityConversionTable, inputValue);
	return densityConversionTable.values[inputUnit - 1][outputUnit - 1];
}

//10.SPEED
void displaySpeedOptions()
{
	cout << "Metric units: " << "\t\t\t" << "Imperial units: " << "\t\t\t\t\t" << " For joggers: " << endl;
	cout << "1. km/h " << "\t\t\t" << " 5. mps (miles per second)" << "\t\t\t\t" << "9. min/km " << endl;
	cout << "2. km/s " << "\t\t\t" << " 6. mph (miles per hour)" << "\t\t\t\t" << " 10. s/100m " << endl;
	cout << "3. m/s " << "\t\t\t\t" << "  7. fps (feet per second)" << endl;
	cout << "4. m/min " << "\t\t\t" << "8. fpm (feet per minute)" << endl;
}
void speedInputUnitCorespondence(int inputUnit)
{
	switch (inputUnit)
	{
	case 1: cout << " km/h " << endl; break;
	case 2: cout << " km/s " << endl; break;
	case 3: cout << " m/s " << endl; break;
	case 4: cout << " m/min " << endl; break;
	case 5: cout << " mps " << endl; break;
	case 6: cout << " mph " << endl; break;
	case 7: cout << " feet/s " << endl; break;
	case 8: cout << " feet/min " << endl; break;
	case 9: cout << " min/km " << endl; break;
	case 10: cout << "s/100m " << endl; break;
	}
}
void speedOutputUnitCorespondence(int outputUnit)
{
	switch (outputUnit)
	{
	case 1: cout << " km/h " << endl; break;
	case 2: cout << " km/s " << endl; break;
	case 3: cout << " m/s " << endl; break;
	case 4: cout << " m/min " << endl; break;
	case 5: cout << " mps " << endl; break;
	case 6: cout << " mph " << endl; break;
	case 7: cout << " feet/s " << endl; break;
	case 8: cout << " feet/min " << endl; break;
	case 9: cout << " min/km " << endl; break;
	case 10: cout << "s/100m " << endl; break;
	}
}
void buildSpeedConversionTable(matrix &aMatrix, double inputValue)
{
	int i;
	double conversionFactor;
	matrixInitialization(aMatrix);
	ifstream fin("speedToKmPerHour.in");
	aMatrix.values[0][0] = inputValue;
	for (i = 1; (i < MAX_ARRAY_LENGTH && !fin.eof()); i++)
	{
		fin >> conversionFactor;
		aMatrix.values[i][0] = conversionFactor * inputValue;
		aMatrix.values[i][i] = inputValue;
		aMatrix.values[0][i] = inputValue / aMatrix.values[i][0];
	}
	fin.close();
	buildRestOfMatrix(aMatrix, inputValue);
}

double speedConversion(int inputUnit, int outputUnit, double inputValue)
{
	matrix speedConversionTable;
	buildSpeedConversionTable(speedConversionTable, inputValue);
	return speedConversionTable.values[inputUnit - 1][outputUnit - 1];
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
	char userAnswer;
	bool continueOrStop=0;
	int unitCategory, inputUnit, outputUnit;
	double inputValue;
	char inputUnitTemperature, outputUnitTemperature;

	intro();
	do
	{
		cout << endl;
		unitCategories();
		cin >> unitCategory;
		isCategoryInsideBounds(unitCategory);

		//area
		if (unitCategory == 1)
		{
			unitCategoriesCorrespondence(unitCategory);
			displayAreaOptions();
			inputUnit = readInputUnit();
			outputUnit = readOutputUnit();
			inputValue = readInputValue();
			cout << endl;
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
			unitCategoriesCorrespondence(unitCategory);
			displayLengthOptions();
			inputUnit = readInputUnit();
			outputUnit = readOutputUnit();
			inputValue = readInputValue();
			cout << endl;
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
			unitCategoriesCorrespondence(unitCategory);
			displayVolumeOptions();
			inputUnit = readInputUnit();
			outputUnit = readOutputUnit();
			inputValue = readInputValue();
			cout << endl;
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
			unitCategoriesCorrespondence(unitCategory);
			displayTimeOptions();
			inputUnit = readInputUnit();
			outputUnit = readOutputUnit();
			inputValue = readInputValue();
			cout << endl;
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
			unitCategoriesCorrespondence(unitCategory);
			displayTemperatureOptions();
			inputUnitTemperature = readInputUnitLetter();
			outputUnitTemperature = readOutputUnitLetter();
			inputValue = readInputValue();
			cout << endl;
			cout << inputValue;
			cout << " ";
			temperatureInputUnitCorespondence(inputUnit);
			cout << " is " << temperatureConversion(inputUnit, outputUnit, inputValue);
			cout << " ";
			temperatureOutputUnitCorespondence(outputUnit);
			cout << endl;
		}

		//mass
		if (unitCategory == 6)
		{
			unitCategoriesCorrespondence(unitCategory);
			displayMassOptions();
			inputUnit = readInputUnit();
			outputUnit = readOutputUnit();
			inputValue = readInputValue();
			cout << endl;
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
			unitCategoriesCorrespondence(unitCategory);
			displayEnergyOptions();
			inputUnit = readInputUnit();
			outputUnit = readOutputUnit();
			inputValue = readInputValue();
			cout << endl;
			cout << inputValue;
			cout << " ";
			energyInputUnitCorespondence(inputUnit);
			cout << " is " << energyConversion(inputUnit, outputUnit, inputValue);
			cout << " ";
			energyOutputUnitCorespondence(outputUnit);
			cout << endl;
		}

		//pressure
		if (unitCategory == 8)
		{
			unitCategoriesCorrespondence(unitCategory);
			displayPressureOptions();
			inputUnit = readInputUnit();
			outputUnit = readOutputUnit();
			inputValue = readInputValue();
			cout << endl;
			cout << inputValue;
			cout << " ";
			pressureInputUnitCorespondence(inputUnit);
			cout << " is " << pressureConversion(inputUnit, outputUnit, inputValue);
			cout << " ";
			pressureOutputUnitCorespondence(outputUnit);
			cout << endl;
		}


		//density
		if (unitCategory == 9)
		{
			unitCategoriesCorrespondence(unitCategory);
			displayDensityOptions();
			inputUnit = readInputUnit();
			outputUnit = readOutputUnit();
			inputValue = readInputValue();
			cout << endl;
			cout << inputValue;
			cout << " ";
			densityInputUnitCorespondence(inputUnit);
			cout << " is " << densityConversion(inputUnit, outputUnit, inputValue);
			cout << " ";
			densityOutputUnitCorespondence(outputUnit);
			cout << endl;
		}

		//speed
		if (unitCategory == 10)
		{
			unitCategoriesCorrespondence(unitCategory);
			displaySpeedOptions();
			cout << endl;
			inputUnit = readInputUnit();
			outputUnit = readOutputUnit();
			inputValue = readInputValue();
			cout << endl;
			cout << inputValue << " ";
			speedInputUnitCorespondence(inputUnit);
			cout << " is " << speedConversion(inputUnit, outputUnit, inputValue);
			speedOutputUnitCorespondence(outputUnit);
			cout << endl;
		}
		/*
		//fuel cons
		if (unitCategory == 11)
		{
			unitCategoriesCorrespondence(unitCategory);
			displayFuelOptions();
			inputUnit = readInputUnit();
			outputUnit = readOutputUnit();
			inputValue = readInputValue();
			cout << endl;
			cout << inputValue;
			cout << " ";
			fuelInputUnitCorespondence(inputUnit);
			cout << " is " << fuelConversion(inputUnit, outputUnit, inputValue);
			cout << " ";
			fuelOutputUnitCorespondence(outputUnit);
			cout << endl;
		}
		*/

		//continue or exit?
		cout << " Perform another conversion? (y/n) ";
		cin >> userAnswer;
		if (userAnswer == 'y' || userAnswer == 'Y')
		{
			continueOrStop = 1;
		}
		else
		{
			cout << " Thank you for using Unit Converter! " << endl << endl;
			continueOrStop = 0;
		}

	} while (continueOrStop);
	
	return 0;
}
