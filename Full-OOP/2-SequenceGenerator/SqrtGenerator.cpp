#include "SqrtGenerator.h"

SqrtGenerator::SqrtGenerator()
{
}

SqrtGenerator::SqrtGenerator(int startInteger, int endInteger) :
	startInteger(startInteger),
	endInteger(endInteger)
{
	this->name = "Sqrt( )";
	this->memory = new double[this->endInteger - this->startInteger];
	generateSequence();
}

SqrtGenerator::SqrtGenerator(SqrtGenerator & old):
	startInteger(old.startInteger),
	endInteger(old.endInteger)
{
	this->name = old.name;
	this->memory = new double[this->endInteger - this->startInteger];
	for (size_t i = 0; i < this->endInteger - this->startInteger; i++)
	{
		this->memory[i] = old.memory[i];
	}
}

SqrtGenerator & SqrtGenerator::operator=(const SqrtGenerator & old)
{
	if(this != &old)
	{
		delete[] this->memory;

		this->name = old.name;
		this->memory = new double[old.endInteger - old.startInteger];
		for (size_t i = 0; i < old.endInteger - old.startInteger; i++)
		{
			this->memory[i] = old.memory[i];
		}
		this->startInteger = old.startInteger;
		this->endInteger = old.endInteger;
		
	}
	return *this;
}

SqrtGenerator::~SqrtGenerator()
{
	delete[] this->memory;
}

std::string SqrtGenerator::Getname(int index)
{
	try
	{
		if(index < this->endInteger - this->startInteger )
		{
			std::size_t pos = (this->name.find('(') + 1);

			std::string str_res(std::to_string(index + this->startInteger));
			int res = str_res.size();
			this->name.replace(pos, res, std::to_string(index + this->startInteger));

			if (this->name.find(')') == std::string::npos)
			{
				this->name.append(")");
			}
			return this->name;
		}
		else
		{
			return std::string();
		}
	}
	catch(std::exception ex)
	{
		return std::string();
	}
}

double SqrtGenerator::GetValue(int index)
{
	if (index < this->endInteger - this->startInteger)
	{
		return this->memory[index];
	}
	return -1;
}

void SqrtGenerator::generateSequence()
{
	int index_ = 0;
	for (size_t i = this->startInteger; i < this->endInteger ; i++)
	{
		this->memory[index_] = sqrt(i);
		index_++;
	}

}