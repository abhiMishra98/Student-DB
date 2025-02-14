/*
 * SimpleUI.cpp
 *
 *  Created on: 13-Jan-2025
 *      Author: abhim
 */

#include "SimpleUI.h"

using namespace std;

SimpleUI::SimpleUI()
{
	// TODO Auto-generated constructor stub

}

SimpleUI::SimpleUI(StudentDB &db) :
		dataBase
		{ db }
{
}

int SimpleUI::run()
{
	cout << endl;
	cout << "Enter your choice" << endl << endl;
	cout << "1. Add New Course" << endl;
	cout << "2. List Courses" << endl;
	cout << "3. Add new student" << endl;
	cout << "4. Add enrollment" << endl;
	cout << "5. Print student" << endl;
	cout << "6. Search student" << endl;
	cout << "7. Update student" << endl;
	cout << "8. Write DB contents to file" << endl;
	cout << "9. Read contents from file" << endl;
	cout << "10. Connect to server" << endl;
	cout << "Press 0 to terminate" << endl;
	unsigned int choice;
	cin >> choice;
//	choice = 7;
// Handle invalid input
	if (cin.fail())
	{
		cin.clear(); // Clear the error flag
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the invalid input
		cout << "Invalid input. Please enter a number between 0 and 7." << endl;
		return 1; // Return a non-zero value to keep the loop running
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (choice == 0)
	{
		cout << "Exiting studentDB" << endl;
		return 0;
	}
	invokeClassMethod(choice);
	return 1;

}

void SimpleUI::invokeClassMethod(unsigned int &choice)
{
	switch (choice)
	{
	case 0:
	{
		break;
	}
	case 1:
	{
		addCourse();
		break;
	}
	case 2:
	{
		printCourses();
		break;
	}
	case 3:
	{
		addStudent();
		break;
	}
	case 4:
	{
		addEnrollment();
		break;
	}
	case 5:
	{
		printStudents();
		break;
	}
	case 6:
	{
		searchStudents();
		break;
	}
	case 7:
	{
		updateStudentDetails();
		break;
	}
	case 8:
	{
		writeToFile();
		break;
	}
	case 9:
	{
		readFromFile();
		break;
	}
	case 10:
	{
		fetchAndParseData();
		break;
	}
	default:
		break;
	}
}

void SimpleUI::addCourse()
{
	unsigned int courseKey;
	string title, majorName;
	float creditPoints;
	cout << "Enter the course key:" << endl;
	cin >> courseKey;
	if (cin.fail())
	{
		cin.clear(); // Clear the error flag
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the invalid input
		cout << "Invalid input. Please enter a number between 0 and 7." << endl;
		return; // Return a non-zero value to keep the loop running
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "Enter title:" << endl;
	getline(cin, title);
	cout << "Enter major:" << endl;
	getline(cin, majorName);
	cout << "Enter Credit Points:" << endl;
	cin >> creditPoints;

	cout << "Enter Block or weekly course(Press 1 for Block, 2 for Weekly)"
			<< endl;
	int courseChoice;
	cin >> courseChoice;
	if (cin.fail())
	{
		cin.clear(); // Clear the error flag
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the invalid input
		cout << "Invalid input. Please enter a number between 0 and 7." << endl;
		return; // Return a non-zero value to keep the loop running
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	switch (courseChoice)
	{
	case 1:
	{
		int date, month, year, hours, minutes;
		string sStartDate, sEndDate, sStartTime, sEndTime;
		Poco::Data::Date startDate, endDate;
		Poco::Data::Time startTime, endTime;
		cout << "Enter start date(dd/mm/yyyy):" << endl;
		getline(cin, sStartDate);
		char delimiter; // To handle the '/' character
		std::istringstream sdateStream(sStartDate);
		sdateStream >> date >> delimiter >> month >> delimiter >> year;
		startDate.assign(year, month, date);
		date = month = year = hours = minutes = 0;
		cout << "Enter end date(dd/mm/yyyy):" << endl;
		getline(cin, sEndDate);
		char edDelimiter; // To handle the '/' character
		std::istringstream edateStream(sEndDate);
		edateStream >> date >> edDelimiter >> month >> edDelimiter >> year;
		endDate.assign(year, month, date);
		cout << "Enter start time(hh:mm)" << endl;
		getline(cin, sStartTime);
		char sdelimiter;
		std::istringstream stimeStream(sStartTime);
		if (stimeStream >> hours >> sdelimiter >> minutes && sdelimiter == ':'
				&& hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60)
		{
			startTime.assign(hours, minutes, 0);
		}
		else
		{
			std::cerr
					<< "Invalid time format. Please enter the time in hh:mm format."
					<< std::endl;
		}
		cout << "Enter end time(hh:mm)" << endl;
		getline(cin, sEndTime);
		char edelimiter;
		std::istringstream etimeStream(sEndTime);
		if (etimeStream >> hours >> edelimiter >> minutes && edelimiter == ':'
				&& hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60)
		{
			endTime.assign(hours, minutes, 0);
		}
		else
		{
			std::cerr
					<< "Invalid time format. Please enter the time in hh:mm format."
					<< std::endl;
		}
		unique_ptr<BlockCourse> bCourseptr = make_unique<BlockCourse>(startDate,
				endDate, startTime, endTime, courseKey, title, majorName,
				creditPoints);
		dataBase.addCourses(courseKey, std::move(bCourseptr));
		break;
	}
	case 2:
	{
		Poco::DateTime::DaysOfWeek dayOfWeek;
		Poco::Data::Time startTime;
		Poco::Data::Time endTime;
		string sStartTime, sEndTime;
		int date, month, year, hours, minutes, dayOfWeekEnum;
		cout << "Enter start time(hh:mm)" << endl;
		getline(cin, sStartTime);
		char sdelimiter;
		std::istringstream stimeStream(sStartTime);
		if (stimeStream >> hours >> sdelimiter >> minutes && sdelimiter == ':'
				&& hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60)
		{
			startTime.assign(hours, minutes, 0);
		}
		else
		{
			std::cerr
					<< "Invalid time format. Please enter the time in hh:mm format."
					<< std::endl;
		}
		cout << "Enter end time(hh:mm)" << endl;
		getline(cin, sEndTime);
		char edelimiter;
		std::istringstream etimeStream(sEndTime);
		if (etimeStream >> hours >> edelimiter >> minutes && edelimiter == ':'
				&& hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60)
		{
			endTime.assign(hours, minutes, 0);
		}
		else
		{
			std::cerr
					<< "Invalid time format. Please enter the time in hh:mm format."
					<< std::endl;
		}
		do
		{
			cout
					<< "Enter the day when this course is taught (0 for Sunday, 1 for Monday, ..., 6 for Saturday): ";
			cin >> dayOfWeekEnum;

			// Validate input
			if (dayOfWeekEnum >= 0 && dayOfWeekEnum <= 6)
			{
				dayOfWeek =
						static_cast<Poco::DateTime::DaysOfWeek>(dayOfWeekEnum);
				break; // Exit the loop if valid input is entered
			}
			else
			{
				cout
						<< "Invalid day of the week. Please enter a value between 0 and 6."
						<< endl;
			}
		} while (true);
		unique_ptr<WeeklyCourse> bCourseptr = make_unique<WeeklyCourse>(
				dayOfWeek, startTime, endTime, courseKey, title, majorName,
				creditPoints);
		dataBase.addCourses(courseKey, std::move(bCourseptr));
		break;
	}
	default:
	{
		break;
	}

	}
}

void SimpleUI::addStudent()
{
	string firstName, lastName, street, cityName, additionalInfo;
	unsigned short postalCode;
	Poco::Data::Date dateOfBirth;
	string dob;
	int year, month, day;
	cout << "Enter student details:" << endl;
	cout << "First Name:" << endl;
	getline(cin, firstName);
	cout << "Last name" << endl;
	getline(cin, lastName);
	cout << "Enter DOB(dd/mm/yyyy):" << endl;
	getline(cin, dob);
	char delimiter; // To handle the '/' character
	std::istringstream dateStream(dob);
	dateStream >> day >> delimiter >> month >> delimiter >> year;
	dateOfBirth.assign(year, month, day);
	cout << "Enter street Name" << endl;
	getline(cin, street);
	cout << "Enter City name" << endl;
	getline(cin, cityName);
	cout << "Enter postal code" << endl;
	cin >> postalCode;
	if (cin.fail())
	{
		cin.clear(); // Clear the error flag
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the invalid input
		cout << "Invalid input. Please enter a number between 0 and 7." << endl;
		return; // Return a non-zero value to keep the loop running
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "Enter additional info" << endl;
	getline(cin, additionalInfo);

	Student newStudent
	{ firstName, lastName, dateOfBirth, street, postalCode, cityName,
			additionalInfo };
	unsigned int matrikelNumber = newStudent.getMatrikelNummer();
	dataBase.addStudents(matrikelNumber, newStudent);
}

void SimpleUI::printStudents()
{
	Student studObj;
	std::map<int, Student>::iterator itr;
	std::map<int, Student> studentList = dataBase.getStudents();
	for (itr = studentList.begin(); itr != studentList.end(); itr++)
	{
		studObj = itr->second;
		cout << studObj << endl;
	}
}

void SimpleUI::searchStudents()
{
	cout << "Enter the search string:";
	string searchParam;
	getline(cin, searchParam);
	Student studObj;
	std::list<Student> listOfStudents;
	string sfirstName, slastName;
	std::map<int, Student>::iterator itr;
	std::list<Student>::iterator studItr;
	std::map<int, Student> studentList = dataBase.getStudents();
	for (itr = studentList.begin(); itr != studentList.end(); itr++)
	{
		studObj = itr->second;
		sfirstName = studObj.getFirstName();
		slastName = studObj.getLastName();
		if (sfirstName.find(searchParam) || slastName.find(searchParam))
		{
			listOfStudents.push_back(itr->second);
		}
	}

	for (studItr = listOfStudents.begin(); studItr != listOfStudents.end();
			studItr++)
	{
		studObj = *studItr;
		cout << studObj << endl;
	}
}

void SimpleUI::updateStudentDetails()
{
	cout << "Enter the Matrikel number:" << endl;
	unsigned int matrikelNumber;
	cin >> matrikelNumber;
	if (cin.fail())
	{
		cin.clear(); // Clear the error flag
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the invalid input
		cout << "Invalid input. Please enter a number between 0 and 7." << endl;
		return; // Return a non-zero value to keep the loop running
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::map<int, Student>::iterator itr;
	std::map<int, Student> studentList = dataBase.getStudents();
	bool flag = false;
	Student studObj;
	for (itr = studentList.begin(); itr != studentList.end(); itr++)
	{
		studObj = itr->second;
		if (studObj.getMatrikelNummer() == matrikelNumber)
		{
			flag = true;
			break;
		}
	}
	if (flag)
	{
		cout << "Enter your choice to update details:" << endl;
		cout << "1) First name" << endl;
		cout << "2) Last name" << endl;
		cout << "3) DOB" << endl;
		cout << "4) Address" << endl;
		cout << "Enter 0 to terminate" << endl;
		int choice;
		cin >> choice;
		if (cin.fail())
		{
			cin.clear(); // Clear the error flag
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the invalid input
			cout << "Invalid input. Please enter a number between 0 and 7."
					<< endl;
			return; // Return a non-zero value to keep the loop running
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch (choice)
		{
		case 1:
		{
			string fName;
			cout << "Enter first name" << endl;
			getline(cin, fName);
			auto &studentsMap = dataBase.updateStudentMap();
			auto it = studentsMap.find(studObj.getMatrikelNummer());
			if (it != studentsMap.end())
			{
				Student &student = it->second;
				student.setFirstName(fName);
			}
			else
			{
				cout << "Student not found" << endl;
			}
			break;
		}
		case 2:
		{
			string lName;
			cout << "Enter last name" << endl;
			getline(cin, lName);
			auto &studentsMap = dataBase.updateStudentMap();
			auto it = studentsMap.find(studObj.getMatrikelNummer());
			if (it != studentsMap.end())
			{
				Student &student = it->second;
				student.setLastName(lName);
			}
			else
			{
				cout << "Student not found" << endl;
			}

			break;
		}
		case 3:
		{
			Poco::Data::Date updateDob;
			int month, year, day;
			string dob;
			cout << "Enter DOB(dd/mm/yyyy):" << endl;
			getline(cin, dob);
			char delimiter; // To handle the '/' character
			std::istringstream dateStream(dob);
			dateStream >> day >> delimiter >> month >> delimiter >> year;
			updateDob.assign(year, month, day);
			auto &studentsMap = dataBase.updateStudentMap();
			auto it = studentsMap.find(studObj.getMatrikelNummer());
			if (it != studentsMap.end())
			{
				Student &student = it->second;
				student.setDateOfBirth(updateDob);
			}
			else
			{
				cout << "Student not found" << endl;
			}
			break;
		}
		case 4:
		{
			int addUpdate;
			unsigned short postalCode;
			string street, city, addInfo;
			cout << "Enter your choice to update address details:" << endl;
			cout << "1) Street" << endl;
			cout << "2) City" << endl;
			cout << "3) Postal code" << endl;
			cout << "4) Additional info" << endl;
			cin >> addUpdate;
			if (cin.fail())
			{
				cin.clear(); // Clear the error flag
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the invalid input
				cout << "Invalid input. Please enter a number between 0 and 7."
						<< endl;
				return; // Return a non-zero value to keep the loop running
			}
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			switch (addUpdate)
			{
			case 1:
			{
				cout << "Enter the new street details" << endl;
				getline(cin, street);
				auto &studentsMap = dataBase.updateStudentMap();
				auto it = studentsMap.find(studObj.getMatrikelNummer());
				if (it != studentsMap.end())
				{
					Student &student = it->second;
					student.getAddress().setStreet(street);
				}
				else
				{
					cout << "Student not found" << endl;
				}
				break;
			}
			case 2:
			{
				cout << "Enter the new city details" << endl;
				getline(cin, city);
				auto &studentsMap = dataBase.updateStudentMap();
				auto it = studentsMap.find(studObj.getMatrikelNummer());
				if (it != studentsMap.end())
				{
					Student &student = it->second;
					student.getAddress().setCityName(city);
				}
				else
				{
					cout << "Student not found" << endl;
				}
				break;
			}
			case 3:
			{
				cout << "Enter the new postal code" << endl;
				cin >> postalCode;
				if (cin.fail())
				{
					cin.clear(); // Clear the error flag
					cin.ignore(std::numeric_limits<std::streamsize>::max(),
							'\n'); // Ignore the rest of the invalid input
					cout
							<< "Invalid input. Please enter a number between 0 and 7."
							<< endl;
					return; // Return a non-zero value to keep the loop running
				}
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
						'\n');
				auto &studentsMap = dataBase.updateStudentMap();
				auto it = studentsMap.find(studObj.getMatrikelNummer());
				if (it != studentsMap.end())
				{
					Student &student = it->second;
					student.getAddress().setPostalCode(postalCode);
				}
				else
				{
					cout << "Student not found" << endl;
				}
				break;
			}
			case 4:
			{
				cout << "Enter the updated additional information" << endl;
				getline(cin, addInfo);
				auto &studentsMap = dataBase.updateStudentMap();
				auto it = studentsMap.find(studObj.getMatrikelNummer());
				if (it != studentsMap.end())
				{
					Student &student = it->second;
					student.getAddress().setAdditionalInfo(addInfo);
				}
				else
				{
					cout << "Student not found" << endl;
				}
				break;
			}
			default:
			{
				break;
			}
			}
			break; //break statement for case 4 of the parent switch-case
		}
		default:
		{
			break;
		}

		}
	}
	else
	{
		cout << "No student found with the input matrikel number" << endl;
	}

}

void SimpleUI::printCourses()
{
	for (auto itr = dataBase.getCourses().begin();
			itr != dataBase.getCourses().end(); ++itr)
	{
		itr->second->printCourse();
	}
}

void SimpleUI::addEnrollment()
{
	string semester;
	int matrikelNr, courseId;
	float grade;
	cout << "Enter Matrikel Number:" << endl;
	cin >> matrikelNr;
	if (cin.fail())
	{
		cin.clear(); // Clear the error flag
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the invalid input
		cout << "Invalid input. Please enter a number between 0 and 7." << endl;
		return; // Return a non-zero value to keep the loop running
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "Enter Course ID:" << endl;
	cin >> courseId;
	if (cin.fail())
	{
		cin.clear(); // Clear the error flag
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the invalid input
		cout << "Invalid input. Please enter a number between 0 and 7." << endl;
		return; // Return a non-zero value to keep the loop running
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "Enter Semester Number:" << endl;
	getline(cin, semester);
	cout << "Enter grade:" << endl;
	cin >> grade;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid input. Please enter a number between 0 and 7." << endl;
		return;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	const auto &coursesMap = dataBase.getCourses();
	auto &studentsMap = dataBase.getStudents();
	const auto &itrStudents = studentsMap.find(matrikelNr);
	std::map<int, std::unique_ptr<const Course>>::const_iterator itr =
			coursesMap.find(courseId);
	if (itr != coursesMap.end() && itrStudents != studentsMap.end())
	{
		const Course *coursePtr = itr->second.get();
		Enrollment newEnrollment(grade, semester, coursePtr);
		itrStudents->second.addEnrollments(newEnrollment);
	}
}

void SimpleUI::writeToFile()
{
	cout << "Enter file name:" << endl;
	string fName;
	getline(cin, fName);
	fName = fName + ".csv";
	std::ofstream file(fName);
	const auto &coursesMap = dataBase.getCourses();
	auto &studentsMap = dataBase.getStudents();

	std::map<int, std::unique_ptr<const Course>>::const_iterator itr;
	file << coursesMap.size() << endl;
	for (itr = coursesMap.begin(); itr != coursesMap.end(); itr++)
	{
		if (itr->second.get())
		{

			itr->second.get()->write(file);
			file << endl;
		}
	}
	file << studentsMap.size() << endl;
	for (const auto &students : studentsMap)
	{
		students.second.write(file);
		file << endl;
	}
	unsigned short countEnrollments = 0;
	for (const auto &students : studentsMap)
	{
		int size = students.second.getEnrollments().size();
		countEnrollments += size;
	}
	file << countEnrollments << endl;
	for (const auto &students : studentsMap)
	{
		file << students.second.getMatrikelNummer() << ";";
		const auto &enrollments = students.second.getEnrollments(); // Get the vector of enrollments
		for (const auto &enrollment : enrollments)
		{
			enrollment.write(file); // Call the write method for each enrollment
		}
		file << std::endl;
	}

	file.close();
}

void SimpleUI::readFromFile()
{
	dataBase.getStudents().clear();
	dataBase.getCourses().clear();
	cout << "Enter the file name:" << endl;
	string fName;
	getline(cin, fName);
	ifstream file(fName);
	string line;
	int posCounter = 0;
	int noObjects = 0;
	unique_ptr<Course> courseUniquePtr;
	unique_ptr<const Course> constCoursePtr;
	while (getline(file, line))
	{
		stringstream ss(line), ps(line);
		string token;
		vector<string> fields;
		while (getline(ss, token, ';'))
		{
			fields.push_back(token);
		}
		if (fields.size() == 8) // weekly course
		{
			if (posCounter == 1)
			{
				for (int count = 0; count < noObjects; count++)
				{
					if (fields[0] == "W")
					{
						courseUniquePtr = make_unique<WeeklyCourse>();
					}
					else if (fields[0] == "B")
					{
						courseUniquePtr = make_unique<BlockCourse>();
					}
					else
					{
						//nothing
					}

					if (courseUniquePtr != nullptr)
					{
						courseUniquePtr->read(ps);
						constCoursePtr = std::move(courseUniquePtr);
						unsigned int courseId = static_cast<unsigned int>(stoul(
								fields[1]));
						dataBase.addCourses(courseId,
								std::move(constCoursePtr));
					}

				}
			}
		}
		else if (fields.size() == 9) // Block course
		{
			if (posCounter == 1)
			{
				for (int count = 0; count < noObjects; count++)
				{
					if (fields[0] == "W")
					{
						courseUniquePtr = make_unique<WeeklyCourse>();
					}
					else if (fields[0] == "B")
					{
						courseUniquePtr = make_unique<BlockCourse>();
					}
					else
					{
						//nothing
					}
					if (courseUniquePtr != nullptr)
					{
						courseUniquePtr->read(ps);
						constCoursePtr = std::move(courseUniquePtr);
						unsigned int courseId = static_cast<unsigned int>(stoul(
								fields[1]));
						dataBase.addCourses(courseId,
								std::move(constCoursePtr));
					}
				}
			}
		}
		else if (fields.size() == 7)
		{
			if (posCounter == 2)
			{
				Student readStudent;
				readStudent.read(ps);
				unsigned int matNr = readStudent.getMatrikelNummer();
				dataBase.addStudents(matNr, readStudent);
			}
		}
		else if (fields.size() == 4)
		{
			const auto &coursesMap = dataBase.getCourses();
			std::map<int, std::unique_ptr<const Course>>::const_iterator itr =
					coursesMap.find(static_cast<unsigned int>(stoi(fields[1])));
			auto &studentsMap = dataBase.getStudents();
			auto itrStudents = studentsMap.find(stoi(fields[0]));
			if (itrStudents != studentsMap.end())
			{
				Student &studentRef = itrStudents->second;
				if (itr != coursesMap.end())
				{
					const Course *coursePtr = itr->second.get();
					Enrollment newEnrollment
					{ stof(fields[3]), fields[2], coursePtr };
					studentRef.addEnrollments(newEnrollment);
				}
			}

		}
		else if (fields.size() == 1)
		{
			noObjects = stoi(fields[0]);
			posCounter++;
		}
		else
		{
			cerr << "Invalid line format!" << endl;
		}

		cout << endl;
	}
}

void SimpleUI::fetchAndParseData()
{
	cout << "Enter the number of student data to be added: " << endl;
	int studentCount;
	string responseLine;
	string studentJsonData;
	cin >> studentCount;
	boost::asio::ip::tcp::iostream connectionStream("www.hhs.users.h-da.cloud",
			"4242");
	if (!connectionStream)
	{
		cerr << "Error: Could not connect to the server" << endl;
		return;
	}
	for (int entries = 0; entries < studentCount; entries++)
	{
		connectionStream << "generate" << endl;
		connectionStream.flush();
		while (getline(connectionStream, responseLine))
		{
			if (responseLine.find("{") != string::npos
					&& responseLine.find("}") != string::npos)
			{
				studentJsonData = responseLine;
				break;
			}
		}
		if (studentJsonData.empty())
		{
			cerr << "No valid JSON data found" << endl;
			continue;
		}
		try
		{
			istringstream jsonStream(studentJsonData);
			boost::property_tree::ptree jsonTree;
			boost::property_tree::read_json(jsonStream, jsonTree);
			string fName = jsonTree.get<string>("name.firstName");
			string lName = jsonTree.get<string>("name.lastName");
			int dobYear = jsonTree.get<int>("dateOfBirth.year", 1900);
			int dobMonth = jsonTree.get<int>("dateOfBirth.month", 1) + 1;
			int dobDay = jsonTree.get<int>("dateOfBirth.date", 1);
			string street = jsonTree.get<string>("location.street", "Unknown");
			string city = jsonTree.get<string>("location.city", "Unknown");
			string pCodeStr = jsonTree.get<string>("location.postCode", "0");
			unsigned short pCode = static_cast<unsigned short>(stoi(pCodeStr));
			Poco::Data::Date dateOfBirth(dobYear, dobMonth, dobDay);
			std::string additionalInfo = "";
			Student newStudent
			{ fName, lName, dateOfBirth, street, pCode, city, additionalInfo };
			unsigned int matNr = newStudent.getMatrikelNummer();
			dataBase.addStudents(matNr, newStudent);
		} catch (const std::exception &e)
		{
			cerr << "Error parsing JSON: " << e.what() << endl;
		}
	}

	connectionStream << "quit" << endl;
	connectionStream.flush();
	cout << "Connection closed with server" << endl;
}

SimpleUI::~SimpleUI()
{
// TODO Auto-generated destructor stub
}

