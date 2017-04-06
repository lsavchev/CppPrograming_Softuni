#include <iostream>
#include <string>
#include <sstream>

bool compArr(int arr1, int arr2)
{
	return arr1 == arr2;
}

int main()
{
	std::string input;
	int arr_size = 0;
	std::cout << "Enter size of array"<<std::endl;
	std::cin >> arr_size;
	int * arr = new int[arr_size];
	std::cout << "Enter array elements:" << std::endl;
	std::cin >> std::ws;
	std::getline(std::cin, input);
	std::istringstream inputStream(input);
	for (size_t i = 0; i < arr_size; i++)
	{
		inputStream >> arr[i];
	}

	int current_index_start_sequence = 0;			//�� ������� �������� �� �������� �������������� ��������
	int current_index_stop_sequence = 0;			//�� ������� ���� �� �������� �������������� ��������
	int prev_index_start_sequence = 0;		//�� ������� �������� �� ���-�������� �� ������� �������������� ��������
	int prev_index_stop_sequence = 0;		//�� ������� �������� �� ���-�������� �� ������� �������������� ��������
	
	current_index_start_sequence = 0; 
	current_index_stop_sequence = 0;

	for (size_t i = 1; i < arr_size ; i++)
	{
		if (compArr(arr[i], arr[i - 1]))
		{
			if (current_index_stop_sequence == current_index_start_sequence) //��� ������� �������� �� ��������
			{
				current_index_start_sequence = i - 1;    // ������� ������� ���������
				current_index_stop_sequence = i;		// ������� ����� ���������
			}
			else
			{
				current_index_stop_sequence++;	// ����������� �� ������� ��������� 
			}
		}
		else
		{
			if ((current_index_stop_sequence - current_index_start_sequence) >
				(prev_index_stop_sequence - prev_index_start_sequence))                       // �������� ���� �������� �������� � ��-������ �� ����������� �������
			{
				prev_index_start_sequence = current_index_start_sequence;			// ��� �������� � ������ �� ����������� � �������� �� ���-������.
				prev_index_stop_sequence = current_index_stop_sequence;	
				current_index_start_sequence = 0;
				current_index_stop_sequence = 0;
			}
		}
	}

	if ((current_index_stop_sequence - current_index_start_sequence) >
		(prev_index_stop_sequence - prev_index_start_sequence))
	{
		prev_index_start_sequence = current_index_start_sequence;
		prev_index_stop_sequence = current_index_stop_sequence;
	}

	for (size_t i = prev_index_start_sequence; i <= prev_index_stop_sequence; i++)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
	delete []arr;
	return 0;
}