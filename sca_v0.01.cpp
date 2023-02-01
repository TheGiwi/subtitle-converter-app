// Subtitle Converter App v0.01 source code [created by https://thegiwi.com/]
// MIT License
// The goal of this app is to convert the auto-generated formatting you will find on the YouTube "show transcript" section to one that is .srt compliant.

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	//Add path to file you want to read from
	std::fstream srcFile("PLACEHOLDER/PLACEHOLDER.txt", std::ios::in);

	//Add path to file you want to write to
	std::fstream newFile("PLACEHOLDER/PLACEHOLDER.srt", std::ios::out);

	
	std::string line;
	int counter = 0;
	int subNum = 0;

	std::string minuteStr;
	std::string secondStr;
	std::string minuteStrPrt;
	std::string secondStrPrt;
	std::string hourStr = "00";
	std::string miliSecStr = "000";
	int converterToInt;

	//Time Conversion Variables
	int hourInt;
	int minuteInt;
	int secondInt;
	int miliSecInt;
	std::string hourIntToStr;
	std::string minuteIntToStr;
	std::string secondIntToStr;



	if (srcFile.is_open() && newFile.is_open())
	{
		getline(srcFile, line);

		while (srcFile)
		{
			counter++;

			// Subtitle number with new line addition and timecode manipulation

			if (counter % 2 == 1)
			{
				subNum++;
				newFile << subNum << '\n';

				minuteStr = line;
				secondStr = line;

				secondStrPrt = secondStr.substr(secondStr.length() - 2, ((secondStr.length() - 2) + 2));
				minuteStrPrt = minuteStr.substr(0, minuteStr.length() - 3);

				converterToInt = stoi(secondStrPrt);

				hourInt = stoi(hourStr);
				minuteInt = stoi(minuteStrPrt);
				secondInt = stoi(secondStrPrt);
				miliSecInt = stoi(miliSecStr);


				//Add one to hour part when minute source crosses 59 (first hour)
				if (minuteInt > 59)
				{
					minuteInt = minuteInt - 60;
					hourInt++;
				}
				//Add one to hour part when minute source crosses 59 (second hour)
				if (minuteInt > 59)
				{
					minuteInt = minuteInt - 60;
					hourInt++;
				}
				//Add one to hour part when minute source crosses 59 (third hour)
				if (minuteInt > 59)
				{
					minuteInt = minuteInt - 60;
					hourInt++;
				}
				//Add one to hour part when minute source crosses 59 (fourth hour)
				if (minuteInt > 59)
				{
					minuteInt = minuteInt - 60;
					hourInt++;
				}

				//Addition of a zero in front of timecode when the number is less than 10
				if (minuteInt < 10)
				{
					minuteIntToStr = "0" + std::to_string(minuteInt);
				}

				else
				{
					minuteIntToStr = std::to_string(minuteInt);
				}

				if (hourInt < 10)
				{
					hourIntToStr = "0" + std::to_string(hourInt);
				}
				else
				{
					hourIntToStr = std::to_string(hourInt);
				}

				if (secondInt < 10)
				{
					secondIntToStr = "0" + std::to_string(secondInt + 3);
				}
				else
				{
					secondIntToStr = std::to_string(secondInt + 3);
				}
				


				newFile << hourIntToStr << ":" << minuteIntToStr << ":" << secondStrPrt << "," << miliSecStr << " --> " << hourIntToStr << ":" << minuteIntToStr << ":" << secondIntToStr << "," << miliSecStr << '\n';
			}
		
			//Transfering of subtitle text to new .srt file =================
			if (counter % 2 == 0)
			{
				newFile << line << '\n' << '\n';
			}

			getline(srcFile, line);
		}

		std::cout << "\n Success! Total lines in original document are: " << counter;


		srcFile.close();
		newFile.close();
	}
	else
		std::cout << "ERROR! \n";


		return 0;
}