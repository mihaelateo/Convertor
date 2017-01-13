#include "converter.h"

int unitCategory, noOfOptionsInTheCategory;
int noOfCategories, noTimeOptions, noUnitsMassMetric, noUnitsMassSpecial, noOfOptions;
int noOfAreaOptions, noUnitsAreaMetric;
int noOfLengthOptions, noUnitsLengthMetric;

//general
void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void setFont()
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 14;
	cfi.FontFamily = FF_MODERN;
	cfi.FontWeight = FW_BOLD;
	wcscpy_s(cfi.FaceName, L"Tahoma");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
void intro()
{
	setFont();
	setColor(14);
	cout << endl;
	cout << "\t ~~~ UNIT CONVERTER ~~~ " << endl;
	cout << endl;
}
void showUnitCategories()
{
	setColor(2);
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
void showCategory(int unitCategory)
{
	setColor(14);
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
void readUnitCategory()
{
	cin >> unitCategory;
}
void isCategoryInsideBounds(int unitCategory)
{
	if (unitCategory < 1 || unitCategory > noOfCategories)
	{
		cout << "Please enter an admissible value! " << endl;
	}
}
void showError()
{
	cout << "Please enter an admissible value! " << endl;
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
			oneMatrix.values[i][j] = oneMatrix.values[0][j] * oneMatrix.values[i][0] / inputValue;
		}
		for (int k = i - 1; k >= 0; k--)
		{
			oneMatrix.values[i][k] = oneMatrix.values[0][k] * oneMatrix.values[i][0] / inputValue;
		}
	}
}

void numberOfOptionsinEachCategory(int theChosenCategory)
{
	switch (theChosenCategory)
	{
	case 1: noOfOptionsInTheCategory = 11; break;
	case 2: noOfOptionsInTheCategory = 12; break;
	case 3: noOfOptionsInTheCategory = 12; break;
	case 4: noOfOptionsInTheCategory = 12; break;
	case 5: noOfOptionsInTheCategory = 3; break; //temp
	case 6: noOfOptionsInTheCategory = 6; break;
	case 7: noOfOptionsInTheCategory = 10; break;
	case 8: noOfOptionsInTheCategory = 8; break;
	case 9: noOfOptionsInTheCategory = 19; break;
	case 10: noOfOptionsInTheCategory = 10; break;
	case 11: noOfOptionsInTheCategory = 8; break;
	}
}


void printConversionTable(matrix &oneMatrix)
{
	cout << endl;
	for (int i = 0; i < noOfOptionsInTheCategory; i++)
	{
		for (int j = 0; j < noOfOptionsInTheCategory; j++)
		{
			cout << oneMatrix.values[i][j] << " / ";
		}
		cout << endl;
	}
	cout << endl;
}


//user input
double readInputValue()
{
	double inputValue;
	cout << endl;
	cout << "  Number of units to convert: ";
	cin >> inputValue;
	return inputValue;
}
int readInputUnit()
{
	int inputUnit;
	bool validInputUnit;
	cout << endl;
	numberOfOptionsinEachCategory(unitCategory);
	cout << "  Convert from (please enter the number corresponding to your option): ";
	do {
		validInputUnit = true;
		cin >> inputUnit;
		if (inputUnit<0 || inputUnit>noOfOptionsInTheCategory)
		{
			showError();
			validInputUnit = false;
		}
	} while (validInputUnit == false); 
	return inputUnit;
}
int readOutputUnit()
{
	int outputUnit;
	cout << endl;
	cout << "  Convert to (please type in the number corresponding to your option): ";
	numberOfOptionsinEachCategory(unitCategory);
	bool validOutputUnit;
	do {
		validOutputUnit = true;
		cin >> outputUnit;
		if (outputUnit<1 || outputUnit>noOfOptionsInTheCategory)
		{
			showError();
			validOutputUnit = false;
		}
	} while (validOutputUnit == false);
	return outputUnit;
}


//1 AREA 
void displayAreaOptions()
{
	setColor(2);
	cout << "\t\t 1. square kilometers " << endl;
	cout << "\t\t 2. square hectometers " << endl;
	cout << "\t\t 3. square decameters " << endl;
	cout << "\t\t 4. square meters " << endl;
	cout << "\t\t 5. square decimeters " << endl;
	cout << "\t\t 6. square centimeters " << endl;
	cout << "\t\t 7. square milimeters " << endl;
	noUnitsAreaMetric = 7;
	cout << "\t\t 8. square inches " << endl;
	cout << "\t\t 9. square feet " << endl;
	cout << "\t\t 10. square miles " << endl;
	cout << "\t\t 11. hectares " << endl;
	cout << "\t\t\t\t ~~ press 0 to go to the main menu ~~ " << endl;
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

void buildAreaConvTableMetric(vector &ConvTable, int inputIndex, double inputValue)
{
	int i;
	for (i = 0; i < noUnitsAreaMetric; i++)
	{
		if (i < inputIndex)
		{
			ConvTable.values[i] = inputValue / pow(pow(10, inputIndex - i), 2);
		}
		if (i > inputIndex)
		{
			ConvTable.values[i] = inputValue * pow(pow(10, i - inputIndex), 2);
		}
	}
}
double areaConversion(int inputUnit, int outputUnit, double inputValue)
{
	vector areaConversionTable;
	int i, inputIndex, outputIndex;
	double valueInSquareMeters, valueInSquareKm;
	arrayInitialization(areaConversionTable);

	inputIndex = determineInputIndex(inputUnit);
	outputIndex = determineOutputIndex(outputUnit);
	areaConversionTable.values[inputIndex] = inputValue;

	if (inputIndex < noUnitsAreaMetric)
	{
		buildAreaConvTableMetric(areaConversionTable, inputIndex, inputValue);
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
		for (i = 0; i < noUnitsAreaMetric; i++)
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

//2. LENGTH 
void displayLengthOptions()
{
	setColor(2);
	cout << "\t\t 1. km (kilometers) " << endl; //metric
	cout << "\t\t 2. hm (hectometers)" << endl;
	cout << "\t\t 3. dam (decameters) " << endl;
	cout << "\t\t 4. m (meters) " << endl;
	cout << "\t\t 5. dm (decimeters) " << endl;
	cout << "\t\t 6. cm (centimeters) " << endl;
	cout << "\t\t 7. mm (milimeters) " << endl;
	cout << "\t\t 8. in (inches) " << endl; //special units
	cout << "\t\t 9. ft (feet) " << endl;
	cout << "\t\t 10. mi (miles) " << endl;
	cout << "\t\t 11. yd (yards) " << endl;
	cout << "\t\t 12. nmi (nautical mile) " << endl;
	cout << "\t\t\t ~~press 0 to go to the previous screen~~ " << endl;
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

//3. VOLUME 
void displayVolumeOptions()
{
	setColor(2);
	cout << "\t\t 1. l (litres) " << endl;
	cout << "\t\t 2. dl (decilitres) " << endl;
	cout << "\t\t 3. cl (centilitres) " << endl;
	cout << "\t\t 4. ml (mililitres) " << endl;
	cout << "\t\t 5. cubic meters " << endl;
	cout << "\t\t 6. cubic decimeters " << endl; 
	cout << "\t\t 7. cubic centimeters " << endl;
	cout << "\t\t 8. gallons (US) " << endl;
	cout << "\t\t 9. gallons (UK) " << endl;
	cout << "\t\t 10. cubic ft " << endl;
	cout << "\t\t 11. cubic in (inches) " << endl;
	cout << "\t\t 12. cubic yd (yards) " << endl;
	cout << "\t\t\t ~~press 0 to go to the previous screen~~ " << endl;
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

//4. TIME 
void displayTimeOptions()
{
	setColor(2);
	cout << "\t\t 1. century " << endl; 	//largeUnits
	cout << "\t\t 2. decade " << endl;
	cout << "\t\t 3. year " << endl; 
	cout << "\t\t 4. month " << endl;
	cout << "\t\t 5. week (1 month = 4 weeks) " << endl;
	cout << "\t\t 6. day " << endl; // middleUnits
	cout << "\t\t 7. hour " << endl;
	cout << "\t\t 8. minute " << endl; 
	cout << "\t\t 9. second " << endl; //smallUnits
	cout << "\t\t 10. milisecond " << endl;
	cout << "\t\t 11. microsecond " << endl; 
	cout << "\t\t 12. nanosecond " << endl; 
	cout << "\t\t\t ~~press 0 to go to the previous screen~~ " << endl;
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

//5 TEMPERATURE 
void displayTemperatureOptions()
{
	setColor(2);
	cout << "\t\t 1. Celsius " << endl;
	cout << "\t\t 2. Fahrenheit " << endl;
	cout << "\t\t 3. Kelvin " << endl;
	cout << "\t\t\t ~~press 0 to go to the previous screen~~ " << endl;
}
void temperatureInputUnitCorespondence(int inputUnit)
{
	switch (inputUnit)
	{
	case 1: cout << "degrees Celsius"; break;
	case 2: cout << "degrees Fahrenheit"; break;
	case 3: cout << "degrees Kelvin"; break;
	}
}
void temperatureOutputUnitCorespondence(int outputUnit)
{
	switch (outputUnit)
	{
	case 1: cout << "degrees Celsius"; break;
	case 2: cout << "degrees Fahrenheit"; break;
	case 3: cout << "degrees Kelvin"; break;
	}
}
double temperatureConversion(int inputUnit, int outputUnit, double inputValue)
{
	if (inputUnit == 1)
	{
		if (outputUnit == 3)
		{
			return inputValue + 273.15;
		}
		if (outputUnit == 2)
		{
			return (inputValue * 9 / 5 + 32);
		}		
		if (outputUnit == 1)
		{
			return inputValue;
		}
	}
	if (inputUnit == 3)
	{
		if (outputUnit == 1)
		{
			return inputValue - 273.15;
		}
		if (outputUnit == 2)
		{
			return (inputValue - 273.15) * 9 / 5 + 32;
		}
		if (outputUnit == 3)
		{
			return inputValue;
		}
	}
	if (inputUnit == 2)
	{
		if (outputUnit == 1)
		{
			return ((inputValue - 32) * 5 / 9);
		}
		if (outputUnit == 3)
		{
			return (inputValue - 32) * 5 / 9 + 273.15;
		}
		if (outputUnit == 2)
		{
			return inputValue;
		}
	}
}

//6.MASS 
void displayMassOptions()
{
	setColor(2);
	cout << "\t\t 1. t (ton) " << endl;
	cout << "\t\t 2. kg " << endl;
	cout << "\t\t 3. g " << endl;
	cout << "\t\t 4. mg " << endl;
	cout << "\t\t 5. lb (pound) " << endl;
	cout << "\t\t 6. oz (ounce) " << endl;
	cout << "\t\t\t ~~press 0 to go to the previous screen~~ " << endl;
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


//7. ENERGY 
void displayEnergyOptions()
{
	setColor(2);
	cout << "\t\t 1. J " << endl;
	cout << "\t\t 2. kJ " << endl;
	cout << "\t\t 3. gcal (gram calorie) " << endl;
	cout << "\t\t 4. Kcal " << endl;
	cout << "\t\t 5. Gcal " << endl;
	cout << "\t\t 6. Watt hour" << endl;
	cout << "\t\t 7. Kilowatt hour" << endl;
	cout << "\t\t 8. British thermal unit " << endl;
	cout << "\t\t 9. US Therm Units " << endl;
	cout << "\t\t 10. Foot pound " << endl;
	cout << "\t\t\t ~~press 0 to go to the previous screen~~ " << endl;
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
		oneMatrix.values[0][i] = inputValue / conversionFactor; // prima linie
	}
	fin.close();
	buildRestOfMatrix(oneMatrix, inputValue);
}
double energyConversion(int inputUnit, int outputUnit, double inputValue)
{
	matrix energyConversionTable;
	buildEnergyConversionTable(energyConversionTable, inputValue);
	printMatrix(energyConversionTable);
	return energyConversionTable.values[inputUnit - 1][outputUnit - 1];
}

// 8. PRESSURE 
void displayPressureOptions()
{
	setColor(2);
	cout << "\t\t 1. atm (atmosphere) " << endl;
	cout << "\t\t 2. bar " << endl;
	cout << "\t\t 3. Pascal " << endl;
	cout << "\t\t 4. Pound-force per square inch (PSI) " << endl;
	cout << "\t\t 5. Torr " << endl;
	cout << "\t\t 6. N/mm2 " << endl;
	cout << "\t\t 7. mmHg " << endl;
	cout << "\t\t 8. mmH2O " << endl;
	cout << "\t\t\t ~~press 0 to go to the previous screen~~ " << endl;
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
		oneMatrix.values[0][i] = inputValue / conversionFactor;
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
	setColor(2);
	cout << "\t\t 1. kg/cm3 " << endl;
	cout << "\t\t 2. kg/l " << endl;
	cout << "\t\t 3. kg/m3 " << endl;
	cout << "\t\t 4. g/cm3 " << endl;
	cout << "\t\t 5. g/l " << endl;
	cout << "\t\t 6. g/m3 " << endl;
	cout << "\t\t 7. g/ml " << endl;
	cout << "\t\t 8. g/mm3 " << endl;
	cout << "\t\t 9. mg/cm3 " << endl;
	cout << "\t\t 10. mg/l " << endl;
	cout << "\t\t 11. mg/m3 " << endl;
	cout << "\t\t 12. lb/gal (US) " << endl;
	cout << "\t\t 13. lb/gal (UK) " << endl;
	cout << "\t\t 14. lb/ft3 " << endl;
	cout << "\t\t 15. lb/in3 " << endl;
	cout << "\t\t 16. oz/gal (US) " << endl;
	cout << "\t\t 17. oz/gal (UK) " << endl;
	cout << "\t\t 18. oz/ft3 " << endl;
	cout << "\t\t 19. oz/in3 " << endl;
	cout << "\t\t 20. Print the entire density conversion table " << endl;
	cout << "\t\t\t ~~press 0 to go to the previous screen~~ " << endl;
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
		oneMatrix.values[0][i] = inputValue / conversionFactor;
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
	setColor(2);
	cout << "Metric units: " << "\t\t\t" << "Imperial units: " << endl;
	cout << "1. km/h " << "\t\t\t" << " 5. mps (miles per second)" << endl;
	cout << "2. km/s " << "\t\t\t" << " 6. mph (miles per hour)" << endl;
	cout << "3. m/s " << "\t\t\t\t" << "  7. fps (feet per second)" << endl;
	cout << "4. m/min " << "\t\t\t" << "8. fpm (feet per minute)" << endl;
	cout << "\t\t\t ~~press 0 to go to the previous screen~~ " << endl;
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
		aMatrix.values[0][i] = inputValue / conversionFactor;
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
{
	setColor(2);
	cout << "\t\t\t ~~press 0 to go to the previous screen~~ " << endl; //metric
	cout << "\t\t 1. l/100km " << endl;
	cout << "\t\t 2. km/l " << endl;
	cout << "\t\t 3. mpg (miles per gallon- US) " << endl; //us
	cout << "\t\t 4. gal(US)/100 mi " << endl;
	cout << "\t\t 5. mpg (miles per gallon - UK) " << endl; //uk
	cout << "\t\t 6. gal(UK)/100 mi " << endl;
	cout << "\t\t 7. mi/l " << endl;
	cout << "\t\t 8. l/100mi " << endl;
}
void fuelInputUnitCorespondence(int inputUnit)
{
	switch (inputUnit)
	{
	case 1: cout << " l/100km " << endl; break;
	case 2: cout << " km/l " << endl; break;
	case 3: cout << " mpg (miles per gallon- US) " << endl; break;
	case 4: cout << " gal(US)/100 mi " << endl; break;
	case 5: cout << " mpg (miles per gallon - UK) " << endl; break;
	case 6: cout << " gal(UK)/100 mi " << endl; break;
	case 7: cout << " mi/l " << endl; break;
	case 8: cout << " l/100mi " << endl; break;
	}
}
void fuelOutputUnitCorespondence(int outputUnit)
{
	switch (outputUnit)
	{
	case 1: cout << " l/100km " << endl; break;
	case 2: cout << " km/l " << endl; break;
	case 3: cout << " mpg (miles per gallon- US) " << endl; break;
	case 4: cout << " gal(US)/100 mi " << endl; break;
	case 5: cout << " mpg (miles per gallon - UK) " << endl; break;
	case 6: cout << " gal(UK)/100 mi " << endl; break;
	case 7: cout << " mi/l " << endl; break;
	case 8: cout << " l/100mi " << endl; break;
	}
}
void buildFuelConversionTable(matrix &aMatrix, double inputValue)
{
	int i;
	double conversionFactor;
	matrixInitialization(aMatrix);
	ifstream fin("fuelToLPer100Km.in");
	aMatrix.values[0][0] = inputValue;
	for (i = 1; (i < MAX_ARRAY_LENGTH && !fin.eof()); i++)
	{
		fin >> conversionFactor;
		aMatrix.values[i][0] = conversionFactor * inputValue;
		aMatrix.values[i][i] = inputValue;
		aMatrix.values[0][i] = inputValue / conversionFactor;
	}
	fin.close();
	buildRestOfMatrix(aMatrix, inputValue);
}
double fuelConversion(int inputUnit, int outputUnit, double inputValue)
{
	matrix fuelConversionTable;
	buildFuelConversionTable(fuelConversionTable, inputValue);
	return fuelConversionTable.values[inputUnit - 1][outputUnit - 1];
}

int main()
{
	char userAnswer;
	bool continueOrStop=0;
	int inputUnit, outputUnit;
	double inputValue;

MAIN_MENU: 
	intro();
	do
	{
		cout << endl;
		showUnitCategories();
		readUnitCategory();
		isCategoryInsideBounds(unitCategory);

		//area
		if (unitCategory == 1)
		{
			showCategory(unitCategory);
			displayAreaOptions();
			inputUnit = readInputUnit(); 
			if (inputUnit == 0)
			{
				system("CLS");
				goto MAIN_MENU;
			}
			outputUnit = readOutputUnit();
			inputValue = readInputValue();
			cout << endl;
			setColor(14);
			cout << "  " << inputValue;
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
			showCategory(unitCategory);
			displayLengthOptions();
			inputUnit = readInputUnit();
			if (inputUnit == 0)
			{
				system("CLS");
				goto MAIN_MENU;
			}
			outputUnit = readOutputUnit();
			inputValue = readInputValue();
			cout << endl;
			setColor(14);
			cout << "  " << inputValue;
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
			showCategory(unitCategory);
			displayVolumeOptions();
			inputUnit = readInputUnit();
			if (inputUnit == 0)
			{
				system("CLS");
				goto MAIN_MENU;
			}
			outputUnit = readOutputUnit();
			inputValue = readInputValue();
			cout << endl;
			setColor(14);
			cout << "  " << inputValue;
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
			showCategory(unitCategory);
			displayTimeOptions();
			inputUnit = readInputUnit();
			if (inputUnit == 0)
			{
				system("CLS");
				goto MAIN_MENU;
			}
			outputUnit = readOutputUnit();
			inputValue = readInputValue();
			cout << endl;
			setColor(14);
			cout << "  " << inputValue;
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
			showCategory(unitCategory);
			displayTemperatureOptions();
			inputUnit = readInputUnit();
			if (inputUnit == 0)
			{
				system("CLS");
				goto MAIN_MENU;
			}
			outputUnit = readOutputUnit();
			inputValue = readInputValue();
			cout << endl;
			setColor(14);
			cout << "  " << inputValue;
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
			showCategory(unitCategory);
			displayMassOptions();
			inputUnit = readInputUnit();
			if (inputUnit == 0)
			{
				system("CLS");
				goto MAIN_MENU;
			}
			outputUnit = readOutputUnit();
			inputValue = readInputValue();
			cout << endl;
			setColor(14);
			cout << "  " << inputValue;
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
			showCategory(unitCategory);
			displayEnergyOptions();
			inputUnit = readInputUnit();
			if (inputUnit == 0)
			{
				system("CLS");
				goto MAIN_MENU;
			}
			outputUnit = readOutputUnit();
			inputValue = readInputValue();
			cout << endl;
			setColor(14);
			cout << "  " << inputValue;
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
			showCategory(unitCategory);
			displayPressureOptions();
			inputUnit = readInputUnit();
			if (inputUnit == 0)
			{
				system("CLS");
				goto MAIN_MENU;
			}
			outputUnit = readOutputUnit();
			inputValue = readInputValue();
			cout << endl;
			setColor(14);
			cout << "  " << inputValue;
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
			showCategory(unitCategory);
			displayDensityOptions();
			inputUnit = readInputUnit();
			if (inputUnit == 0)
			{
				system("CLS");
				goto MAIN_MENU;
			}
			/*
			if (inputUnit == 20)
			{
				printConversionTable() ///////////////
			}
			*/
			outputUnit = readOutputUnit();
			inputValue = readInputValue();
			cout << endl;
			setColor(14);
			cout << "  " << inputValue;
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
			showCategory(unitCategory);
			displaySpeedOptions();
			cout << endl;
			inputUnit = readInputUnit();
			if (inputUnit == 0)
			{
				system("CLS");
				goto MAIN_MENU;
			}
			outputUnit = readOutputUnit();
			inputValue = readInputValue();
			cout << endl;
			setColor(14);
			cout << "  " << inputValue << " ";
			speedInputUnitCorespondence(inputUnit);
			cout << " is " << speedConversion(inputUnit, outputUnit, inputValue);
			speedOutputUnitCorespondence(outputUnit);
			cout << endl;
		}
		//fuel cons
		if (unitCategory == 11)
		{
			showCategory(unitCategory);
			displayFuelOptions();
			inputUnit = readInputUnit();
			if (inputUnit == 0)
			{
				system("CLS");
				goto MAIN_MENU;
			}
			outputUnit = readOutputUnit();
			inputValue = readInputValue();
			cout << endl;
			setColor(14);
			cout << "  " << inputValue;
			cout << " ";
			fuelInputUnitCorespondence(inputUnit);
			cout << " is " << fuelConversion(inputUnit, outputUnit, inputValue);
			cout << " ";
			fuelOutputUnitCorespondence(outputUnit);
			cout << endl;
		}

		//continue or exit?
		setColor(2);
		cout << "  Perform another conversion? (y/n) " << endl;
		cin >> userAnswer;
		if (userAnswer == 'y' || userAnswer == 'Y')
		{
			system("CLS");
			continueOrStop = 1;
		}
		else
		{
			setColor(14);
			cout << " Thank you for using Unit Converter! " << endl << endl;
			continueOrStop = 0;
		}

	} while (continueOrStop);
	
	return 0;
}
