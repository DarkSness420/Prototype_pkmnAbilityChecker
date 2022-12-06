

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
	string fname;
	string fname2;
	string fname3;
	string pokemonIDinvoeren;

	cout << "Enter the Pokemon_ability_ids file name: ";
	cin >> fname;
	cout << "Enter the ability_id_name file name: ";
	cin >> fname2;
	cout << "Enter the Pokemon_id file name : ";
	cin >> fname3;
	cout << endl;


	while (true) {
		cout << "Wat is je pokemon's pokedex ID: ";
		cin >> pokemonIDinvoeren;


		vector<vector<string>> content;
		vector<string> row;
		string line, word;


		vector<vector<string>> content2;
		vector<string> row2;
		string line2, word2;

		vector<vector<string>> content3;
		vector<string> row3;
		string line3, word3;

		fstream file(fname, ios::in);
		if (file.is_open())
		{
			while (getline(file, line))
			{
				row.clear();

				stringstream str(line);

				while (getline(str, word, ','))
					row.push_back(word);
				content.push_back(row);
			}
		}
		else
			cout << "Could not open the file\n";

		fstream file2(fname2, ios::in);
		if (file2.is_open())
		{
			while (getline(file2, line2))
			{
				row2.clear();

				stringstream str2(line2);

				while (getline(str2, word2, ','))
					row2.push_back(word2);
				content2.push_back(row2);
			}
		}

		fstream file3(fname3, ios::in);
		if (file3.is_open())
		{
			while (getline(file3, line3))
			{
				row3.clear();

				stringstream str3(line3);

				while (getline(str3, word3, ','))
					row3.push_back(word3);
				content3.push_back(row3);
			}
		}

		int k;
		int z;
		string abilityID;

		cout << "Deze pokemon (";

		for (int i = 0; i < content3.size(); i++)
		{
			for (int j = 0; j < content3[i].size(); j++)
			{
				z = j + 1;
				if (content3[i][j] == pokemonIDinvoeren) {

					cout << content3[i][z];

				}
				break;
			}
		}
		cout << ") heeft de abilities : " << endl;



		for (int i = 0; i < content.size(); i++)
		{
			for (int j = 0; j < content[i].size(); j++)
			{
				k = j + 1;
				if (content[i][j] == pokemonIDinvoeren) {

					abilityID = content[i][k];
					cout << endl;

					for (int p = 0; p < content2.size(); p++)
					{
						for (int q = 0; q < content2[p].size(); q++)
						{
							int d = q + 1;
							if (content2[p][q] == abilityID) {

								cout << content2[p][d];

							}
							break;
						}

					}

				}
				break;
			}
		}
		cout << endl << endl;
	}
	
	return 0;
}