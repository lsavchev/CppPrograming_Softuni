#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <istream>
#include <vector>
#include <regex>
using namespace std;

enum Type
{
	UNKNOWN = 0,
	STAR,
	ROCKY,
	PLANET,
	GAS_GIANT,
};

Type ParseToType(string s)
{
	if (!s.compare("UNKNOWN"))
	{
		return UNKNOWN;
	}
	else if (!s.compare("STAR"))
	{
		return STAR;
	}
	else if (!s.compare("ROCKY"))
	{
		return ROCKY;
	}
	else if (!s.compare("PLANET"))
	{
		return PLANET;
	}
	else if (!s.compare("GAS_GIANT"))
	{
		return GAS_GIANT;
	}
}

class AstronomicalObject
{

private:
	string name_of_home_solar_system;
	int position;
	double mass;
	double radius;
	Type type;
	string nickname;

public:
	AstronomicalObject(string solar_name, int pos, double mass, double radius, Type type_, string nickname) :
		name_of_home_solar_system(solar_name),
		mass(mass),
		radius(radius),
		type(type_),
		nickname(nickname)
	{
		if (type_ == STAR)
		{
			this->position = 1;
		}
		else
		{
			this->position = pos;
		}
	}

	AstronomicalObject(string solar_name, int pos, double mass, double radius, Type type_) :
		name_of_home_solar_system(solar_name),
		mass(mass),
		radius(radius),
		type(type_)
	{
		if (type_ == STAR)
		{
			this->position = 1;
		}
		else
		{
			this->position = pos;
		}
	}

	void Name_of_home_solar_system(string& name)
	{
		this->name_of_home_solar_system = name;
	}

	string Name_of_home_solar_system() const
	{
		return this->name_of_home_solar_system;
	}

	int Position() const
	{
		return this->position;
	}

	void SetPosition(int& p)
	{
		this->position = p;
	}

	double Mass() const
	{
		return this->mass;
	}

	void Mass(double& m)
	{
		this->mass = m;
	}

	void Radius(double& r)
	{
		this->radius = r;
	}

	double Radius() const
	{
		return this->radius;
	}

	string Nickname() const
	{
		return this->nickname;
	}

	void Nickname(string& s)
	{
		this->nickname = s;
	}

	Type GetType() const
	{
		return this->type;
	}

	void SetType(Type& t)
	{
		if (t == UNKNOWN)
		{
			this->type = t;
		}
	}

	string output_format()
	{
		stringstream sstream;

		sstream << this->name_of_home_solar_system << "-" << this->position << " " << ParseTypeToString() << " ";
		if (this->nickname != "")
		{
			sstream << "(" + this->nickname + ") ";
		}

		sstream << "{mass: " << this->mass << ", radius: " << this->radius << "}" << endl;
		return sstream.str();
	}

	string ParseTypeToString()
	{
		string output;
		switch (this->type)
		{
			case UNKNOWN : 
				output = "UNKNOWN";
				break;
			case STAR:
				output = "STAR";
				break;
			case ROCKY:
				output = "ROCKY";
				break;
			case PLANET:
				output = "PLANET";
				break;
			case GAS_GIANT:
				output = "GAS_GIANT";
				break;
		}
		return output;
	}

};

void LoadData(ifstream& f, vector<AstronomicalObject *> *astroObjects)
{
	if (f.is_open())
	{
		string name_of_home_solar_system;
		int position = 0;
		string position_read;
		double mass = 0;
		double radius = 0;
		Type type;
		string nickname;
		string line;
		string command;
		while (getline(f, line))
		{
			try
			{
				stringstream ss(line);
				ss >> command;
				size_t pos = command.find("-");
				name_of_home_solar_system = command.substr(0, pos);

				for (string::iterator it = command.begin(); it < command.end(); it++)
				{
					if ((*it >= '0') && (*it <= '9'))
					{
						position_read += *it;
					}
				}
				position = stoi(position_read);
				position_read = "";
				ss >> command;
				type = ParseToType(command);
				ss >> command;
				if (command[0] == '(')
				{
					size_t i = 1;
					while (command[i] != ')')
					{
						nickname += command[i];
						i++;
						if (command[i] == '\0')
						{
							nickname += ' ';
							ss >> command;
							i = 0;
						}
					}
					ss >> command;
				}

				ss >> command;
				mass = stod(command);
				ss >> command;
				ss >> command;
				radius = stod(command);

				astroObjects->push_back(new AstronomicalObject{ name_of_home_solar_system, position, mass, radius, type, nickname });
				nickname = "";
			}
			catch (exception ex)
			{

			}
		}
		f.close();
	}
}

void WriteInfoToFile(vector<AstronomicalObject *> *astroObjects)
{
	stringstream outputInfo;

	for (std::vector<AstronomicalObject *>::iterator it = astroObjects->begin(); it != astroObjects->end(); ++it)
	{
		outputInfo << (*it)->output_format();
	}
	ofstream f;
	f.open("custom.txt");
	f << outputInfo.str();
	f.close();
}

AstronomicalObject * ChangeObject(vector<AstronomicalObject *> *astroObjects, string search) 
{
	for (std::vector<AstronomicalObject *>::iterator it = astroObjects->begin(); it != astroObjects->end(); ++it)
	{
		if (!(*it)->Name_of_home_solar_system().compare(search))
		{
			return (AstronomicalObject *)*it;
		}
	}
}

string getAllObjectsAsString(vector<AstronomicalObject *> *astroObjects)
{
	stringstream outputInfo;
	int counter = 0;
	for (std::vector<AstronomicalObject *>::iterator it = astroObjects->begin(); it != astroObjects->end(); ++it)
	{
		outputInfo<< counter <<". "<< (*it)->output_format();
		counter++;
	}

	return outputInfo.str();
}

string findSolarSystem(vector<AstronomicalObject *> *astroObjects, string search)
{
	int end = 0;
	stringstream outputInfo;
	string current_search_case;
	stringstream search_cases(search);
	while (search_cases >> current_search_case)
	{
		end++;
	}
	
	int matches = 0;

	for (std::vector<AstronomicalObject *>::iterator it = astroObjects->begin(); it != astroObjects->end(); ++it)
	{
		matches = 0;
		stringstream search_cases_(search);
		for (size_t i = 0; i < end; i++)
		{
			search_cases_ >> current_search_case;
			if (!isdigit(current_search_case[0]))
			{
				if ((!(*it)->Name_of_home_solar_system().compare(current_search_case)) ||
					(!(*it)->Nickname().compare(current_search_case)) ||
					((*it)->GetType() == ParseToType(current_search_case))
					)
				{
					matches++;
					if (matches == end)
						outputInfo << (*it)->output_format();
				}
			}
			else
			{
				if ((!(*it)->Name_of_home_solar_system().compare(current_search_case)) ||
					(!(*it)->Nickname().compare(current_search_case)) ||
					((*it)->Position() == stoi(current_search_case)) ||
					((*it)->Mass() == stod(current_search_case)) ||
					((*it)->Radius() == stod(current_search_case)) ||
					((*it)->GetType() == ParseToType(current_search_case))
					)
				{
					matches++;
					if (matches == end)
						outputInfo <<(*it)->output_format();
				}
			}

		}
	}

	return outputInfo.str();
}

int main()
{
	vector<AstronomicalObject *> *astroObjects = new vector<AstronomicalObject *> ();
	ifstream file("custom.txt");
	LoadData(file, astroObjects);
	string command;
	stringstream strst;
	bool exit = false;
	while (!exit)
	{
		cout << "Select option from menu: " << endl << endl;
		cout << "1. Search..." << endl;
		cout << "2. Add..." << endl;
		cout << "3. Edit..." << endl;
		cout << "4. Exit..." << endl;
		getline(cin, command);
		stringstream strst(command);
		try
		{
			switch (stoi(command))
			{
			case 1:
				cout << "Press 4 to exit searching..." << endl;
				while (command != "4")
				{
					cout << endl;
					cout << "Search keywords: ";
					getline(cin, command);
					if (command == "4")
					{
						break;
					}
					cout << findSolarSystem(astroObjects, command);
				}
				break;
			case 2:
				cout << "Press 4 to exit adding..." << endl;
				cout << "Add in format: astronomical_object_name position type mass radius nickname" << endl;
				while (command != "4")
				{
					string parser;
					string as_name;
					int position = 0;
					Type type;
					string nickname;
					double mass = 0;
					double radius = 0;
					getline(cin, command);
					if (command == "4")
					{
						break;
					}

					try
					{
						stringstream s(command);
						s >> as_name;
						s >> parser;
						position = stoi(parser);
						s >> parser;
						type = ParseToType(parser);
						s >> parser;
						mass = stod(parser);
						s >> parser;
						radius = stod(parser);
						s >> nickname;
						if (nickname == "")
						{
							astroObjects->push_back(new AstronomicalObject{ as_name, position, mass, radius, type });
						}
						else
						{
							astroObjects->push_back(new AstronomicalObject{ as_name, position, mass, radius, type, nickname });
						}
						
						WriteInfoToFile(astroObjects);
						cout << "Saved !!!" << endl;
					}
					catch (exception ex)
					{
						cout << "wrong input" << endl;
						cout << "Add in format: astronomical_object_name position type nickname mass radius" << endl;
					}
				}
				break;
			case 3:
				cout << "Select Astronomical object you want to change: " << endl;
				cout << getAllObjectsAsString(astroObjects) << endl;
				try 
				{
					string command;
					int vector = 0;
					int option_choise = 0;
					getline(cin, command);
					vector = stoi(command);
					cout << "1. Change Astronomical object Name: " << endl;
					cout << "2. Change position " << endl;
					cout << "3. Change type " << endl;
					cout << "4. Change nickname " << endl;
					cout << "5. Change mass " << endl;
					cout << "6. Change radius " << endl;
					cout << "7. Exit " << endl;
					getline(cin, command);
					option_choise = stoi(command);

					cout << "Replace with: ";				
					int res = 0;
					double res2 = 0;
					Type t;
					double res3 = 0;
					while (command != "7")
					{
						getline(cin, command);

						switch (option_choise)
						{
							case 1: 
								astroObjects->at(vector)->Name_of_home_solar_system(command);
								WriteInfoToFile(astroObjects);
								cout << "Changed !!!" << endl;
								break;
							case 2: 
								
								res = stoi(command);
								astroObjects->at(vector)->SetPosition(res);
								WriteInfoToFile(astroObjects);
								cout << "Changed !!!" << endl;
								break;
							case 3:					
								t = ParseToType(command);
								astroObjects->at(vector)->SetType(t);
								break;
							case 4: astroObjects->at(vector)->Nickname(command);
								WriteInfoToFile(astroObjects);
								cout << "Changed !!!" << endl;
								break;
							case 5:

								res2 = stod(command);
								astroObjects->at(vector)->Mass(res2);
								WriteInfoToFile(astroObjects);
								cout << "Changed !!!" << endl;
								break;
							case 6:

								res3 = stod(command);
								astroObjects->at(vector)->Radius(res3);
								WriteInfoToFile(astroObjects);
								cout << "Changed !!!" << endl;
								break;
						}
	
					}
					
				}
				catch (exception)
				{
					cout << "Invlid Input..." << endl;
				}
				
				break;
			case 4:
				exit = true;
				break;
			}
		}
		catch (exception ex)
		{
			cout << "Wrong Input"<<endl;
		}
	}

	return 0;
}


