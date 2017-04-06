#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

// imam dobaveni funcii koito zapiswat v fail kogato se syzdade nowa registraciq na kola ili person, ili se edit-ne informaciqta
class Person
{
private:
	string name;
	int age;
	static int id;
	int ID;
public:

	int getId() const
	{
		return this->ID;
	}

	Person(string name, int age) :
		name(name),
		age(age)
	{
		ID = id++;
	}

	void SetName(string& name)
	{
		this->name = name;
	}

	void SetAge(int& age)
	{
		this->age = age;
	}

	string Name() const
	{
		return this->name;
	}

	int Age() const
	{
		return this->age;
	}
};

class Car
{
private:
	string manufacturer_name;
	string model_name;
	Person * person;
	int horse_power;
	string registration_number;
public:
	Car(string manufacturerName, string modelname, Person * person, int horsePower, string regNumber) :
		manufacturer_name(manufacturerName),
		model_name(modelname),
		person(person),
		horse_power(horsePower),
		registration_number(regNumber)
	{
	}

	string Manufacturer_name() const
	{
		return this->manufacturer_name;
	}

	string Model_name() const
	{
		return this->model_name;
	}
	void ChangePerson(Person * p)
	{
		this->person = p;
	}

	Person * Person() const
	{
		return this->person;
	}

	int Horse_power() const
	{
		return this->horse_power;
	}

	string Registration_number() const
	{
		return this->registration_number;
	}

	void Registration_number(string& reg)
	{
		this->registration_number = reg;
	}
};

int Person::id = 0;

void write_all_person_to_file(vector<Person *> * p, string filePath)
{
	stringstream stream;
	for (std::vector<Person *>::iterator it = p->begin(); it != p->end(); ++it)
	{
		stream << "Name: " << (*it)->Name() << endl
			   << "Age: " << (*it)->Age() << endl;
	}
	ofstream ofstreamm;
	ofstreamm.open("Person.txt");
	ofstreamm << stream.str();
	ofstreamm.close();
}

void write_person_to_file(Person * p, string filePath)
{
	stringstream stream;
	stream << "Name: " << p->Name() << endl
		<< "Age: " << p->Age() << endl;
	ofstream ofstreamm;
	ofstreamm.open("Person.txt", ios::app);
	ofstreamm << stream.str();
	ofstreamm.close();
}

void write_car_to_file(Car * p, string filePath)
{
	stringstream stream;
	stream << "Manufacturer: " << p->Manufacturer_name() << endl
		<< "Model name: " << p->Model_name() << endl
		<< "Owner: " << p->Person()->Name() << endl
		<< "Owner age: " << p->Person()->Age() << endl
		<< "Horse power: " << p->Horse_power() << endl
		<< "Registration number: " << p->Registration_number() << endl;
	ofstream ofstreamm;
	ofstreamm.open("car_registration.txt", ios::app);
	ofstreamm << stream.str();
	ofstreamm.close();
}

void write_all_cars_to_file(vector<Car *> * p, string filePath)
{
	stringstream stream;
	for (std::vector<Car *>::iterator it = p->begin(); it != p->end(); ++it)
	{
		stream 
			<< "Manufacturer: " << (*it)->Manufacturer_name() << endl
			<< "Model name: " << (*it)->Model_name() << endl
			<< "Owner: " << (*it)->Person()->Name() << endl
			<< "Owner age: " << (*it)->Person()->Age() << endl
			<< "Horse power: " << (*it)->Horse_power() << endl
			<< "Registration number: " << (*it)->Registration_number() << endl;
	}
	ofstream ofstreamm;
	ofstreamm.open("car_registration.txt");
	ofstreamm << stream.str();
	ofstreamm.close();
}
void show_person_info_to_console(vector<Person *> * p)
{
	int counterIndex = 1;
	for (std::vector<Person *>::iterator it = p->begin(); it != p->end(); ++it, counterIndex++)
	{
		cout << "--------" << (*it)->getId() << "--------" << endl
			<< "Name: " << (*it)->Name() << endl
			<< "Age: " << (*it)->Age() << endl;
	}
}

void show_car_info_to_console(vector<Car *> * p)
{
	int numberCar = 0;
	for (std::vector<Car *>::iterator it = p->begin(); it != p->end(); ++it, numberCar++)
	{
		cout << "--------" << to_string(numberCar) << "--------" << endl
			<< "Manufacturer: " << (*it)->Manufacturer_name() << endl
			<< "Model name: " << (*it)->Model_name() << endl
			<< "Owner: " << (*it)->Person()->Name() << endl
			<< "Owner age: " << (*it)->Person()->Age() << endl
			<< "Horse power: " << (*it)->Horse_power() << endl
			<< "Registration number: " << (*it)->Registration_number() << endl;
	}

}

void show_help_menu()
{
	cout << "Replace ... with person/car information." << endl;
	cout << "Command List : " << endl << endl;

	cout << "Add Commands: " << endl;
	cout << "Add person:  -add -p -name ... -age ..." << endl
		<< "Example: -add -p -name Ivan -age 30" << endl;
	cout << "Add car reg: -add -c -mfname ... -mlname ... -pID ... -hp ... -rn ..." << endl
		<< "Example: -add -c -mfname Ford -mlname Fiesta -pID 0 -hp 120 -rn CA0001AA" << endl << endl;

	cout << "Edit Commands: " << endl;
	cout << "Edit person: -edit -p -id ... -name ... -age ..." << endl
		<< "Example: -edit -o -id 0 -name Ivelin -age 10" << endl;
	cout << "Edit car: -edit -c ... -pID ... -rn..." << endl
		<< "Example: -edit -c 0 -pID 0 -rn CA0002AA" << endl << endl;


	cout << "Show Commands: " << endl;
	cout << "Show persons: -show -p " << endl;
	cout << "Show cars: -show -c " << endl << endl;

}

Person * pPointer(vector<Person *> * p, int id)
{
	for (vector<Person *>::iterator it = p->begin(); it != p->end(); ++it)
	{
		if ((*it)->getId() == id)
		{
			return (*it);
		}
	}
}

void edit_person(vector<Person *> * p, int id, string newName, int age)
{
	for (std::vector<Person *>::iterator it = p->begin(); it != p->end(); ++it)
	{
		if ((*it)->getId() == id)
		{
			(*it)->SetName(newName);
			(*it)->SetAge(age);
		}
	}
}

int main()
{
	vector<Person *> * PersonVector = new vector<Person *>();
	vector<Car *> * CarVector = new vector<Car *>();

	cout << "Welcome to Road Transport Administration Agency" << endl;
	cout << "Type: -help for more information." << endl;

	string input;
	string command;
	int personcounter = 0;
	int carcounter = 0;
	string person_name;
	int person_age = 0;
	while (1)
	{
		getline(cin, input);
		stringstream inputstream(input);

		while (inputstream >> command)
		{
			if (!command.compare("-add"))
			{
				inputstream >> command;

				if (!command.compare("-p"))
				{
					inputstream >> command;
					if (!command.compare("-name"))
					{
						try
						{ 
							inputstream >> command;
							while (command.compare("-age"))
							{
								person_name.append(command);
								inputstream >> command;
								person_name + " ";
							}
							inputstream >> command;
							person_age = stoi(command);

							PersonVector->push_back(new Person{ person_name ,person_age });
							write_person_to_file(PersonVector->at(personcounter),"");
							person_name = "";
							personcounter++;
						}
						catch (exception ex)
						{
							cout << "invlid input " <<endl;
						}
					}

				}
				else if (!command.compare("-c"))
				{
					inputstream >> command;
					if (!command.compare("-mfname"))
					{
						inputstream >> command;
						string mfname = command;
						inputstream >> command;
						if (!command.compare("-mlname"))
						{
							try
							{
								inputstream >> command;
								string mlname = command;
								inputstream >> command;

								if (!command.compare("-pID"))
								{
									inputstream >> command;
									int id = 0;
									id = stoi(command);
									inputstream >> command;

									if (!command.compare("-hp"))
									{
										inputstream >> command;
										int hp = 0;
										hp = stoi(command);
										inputstream >> command;
										if (!command.compare("-rn"))
										{
											inputstream >> command;
											string regnumber;
											regnumber = command;
											CarVector->push_back(new Car{ mfname ,mlname, pPointer(PersonVector,id), hp, regnumber });
											write_car_to_file(CarVector->at(carcounter), "");
											carcounter++;
										}
									}
								}
							}
							catch (exception ex)
							{
								cout << "invlid input..." << endl;
							}
						}
					}


				}

			}
			else if (!command.compare("-show"))
			{
				inputstream >> command;
				if (!command.compare("-p"))
				{
					show_person_info_to_console(PersonVector);
				}
				else if (!command.compare("-c"))
				{
					show_car_info_to_console(CarVector);
				}
			}
			else if (!command.compare("-edit"))
			{
				inputstream >> command;

				if (!command.compare("-p"))
				{
					inputstream >> command;
					if (!command.compare("-id"))
					{
						try
						{
							inputstream >> command;
							int idTochange = 0;
							idTochange = stoi(command);
							inputstream >> command;

							if (!command.compare("-name"))
							{
								inputstream >> command;
								while (command.compare("-age"))
								{
									person_name.append(command);
									inputstream >> command;
									person_name.append(" ");
								}
								inputstream >> command;
								person_age = stoi(command);

								edit_person(PersonVector, idTochange, person_name, person_age);
								write_all_person_to_file(PersonVector, "");
								person_name = "";
							}
						}
						catch (exception ex)
						{
							cout << "invalid input " << endl;
						}
					}

				}
				else if (!command.compare("-c"))
				{
					inputstream >> command;
					int oldCarnumber = 0;
					oldCarnumber = stoi(command);
					inputstream >> command;
					if (!command.compare("-pID"))
					{
						try
						{
							inputstream >> command;
							int idTochange = 0;
							idTochange = stoi(command);
							inputstream >> command;

							if (!command.compare("-rn"))
							{
								inputstream >> command;
								string reg_number;
								reg_number = command;

								CarVector->at(oldCarnumber)->ChangePerson(PersonVector->at(idTochange));
								CarVector->at(oldCarnumber)->Registration_number(reg_number);
								write_all_cars_to_file(CarVector, "");
							}
						}
						catch (exception)
						{
							cout << "invliad input..."<<endl;
						}
					}
				}
			}
			else if (!command.compare("-help"))
			{
				show_help_menu();
			}
			else if (!command.compare("-exit"))
			{
				for (vector<Person *>::iterator it = PersonVector->begin(); it != PersonVector->end(); ++it)
				{
					delete *it;
				}
				for (vector<Car *>::iterator it = CarVector->begin(); it != CarVector->end(); ++it)
				{
					delete *it;
				}

				PersonVector->clear();
				CarVector->clear();
				delete PersonVector;
				delete CarVector;
				return 0;
			}
		}

	}

	return 0;
}