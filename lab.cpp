#include<bits/stdc++.h>
using namespace std;
int helper(string a)
{
  if(a=="AA")return 10;
  else if(a=="AB")return 9;
  else if(a=="BB")return 8;
  else if(a=="BC")return 7;
  else if(a=="CC")return 6;
  else if(a=="CD")return 5;
  else if(a=="DD")return 4;

}
void fun(int ro,vector<string>a,vector<string>b)
{
  vector<string>name;
  vector<string>credits;
  vector<string>sem;
  for(int i=0;i<a.size();i++){
  fstream fin,fout;
  fin.open("courses.csv",ios::in);
  vector<string>row;
  string word,line,temp;
  while (!fin.eof()) {

   row.clear();

   getline(fin, line);
   stringstream s(line);

   while (getline(s, word, ',')) {
     row.push_back(word);
   }
    if  (row[1] ==a[i]   ) {
      name.push_back(row[2]);
      sem.push_back(row[0]);
      credits.push_back(row[6]);
        }
 }
 fin.close();
}
fstream fout;
char * filename;
sprintf(filename,"%d.txt",ro);
fout.open(filename,ios::out);
float spi[9]={ };
int cre[9]={ };
float cpi[9]={ };
for(int i=0;i<sem.size();i++)
{
  spi[helper(sem[i])]+=credits[i]*b[i];
  cre[helper(credits[i])]+=credits[i];
}
for(int i=1;i<=8;i++)
{
  int c=0;
for(int j=1;j<=i;j++)
{
  cpi[i]+=spi[j];
  c+=cre[j];
}
cpi[i]=cpi[i]/c;
}
for(int i=1;i<9;i++)
spi[i]=spi[i]/cre[i];







}
int main()
{
  fstream fin;
  fin.open("students.csv",ios::in);
	int rollnum, roll2, count = 0;
	vector<int>stud_roll;
  vector<string>names;
  vector<string>row;
	string line, word, temp;
	while (fin >> temp) {

		row.clear();

		// read an entire row and
		// store it in a string variable 'line'
		getline(fin, line);

		// used for breaking words
		stringstream s(line);

		// read every column data of a row and
		// store it in a string variable, 'word'
		while (getline(s, word,',')) {

			// add all the column data
			// of a row to a vector
			row.push_back(word);
		}
		roll2 = stoi(row[1]);
    stud_roll.push_back(roll2);
    names.push_back(row[0]);

}fin.close();


for(int i=0;i<stud_roll.size();i++)
{
  vector<string>course;
  vector<string>grade;
  fin.open("grades.csv",ios::in);
  while (!fin.eof()) {

		row.clear();

		getline(fin, line);
		stringstream s(line);

		while (getline(s, word, ',')) {
			row.push_back(word);
		}

		roll2 = stoi(row[0]);
		int row_size = row.size();

		if (roll2 ==  stud_roll[i]) {
      course.push_back(row[1]);
      grade.push_back(row[2]);


		}
	}
	fin.close();
  fun(stud_roll[i],course,grade);



}











}
