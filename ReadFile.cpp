#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
using std::ifstream;

std::vector<std::vector<std::string>> maze(45, std::vector<std::string>(30));


//https://thispointer.com/c-how-to-read-a-file-line-by-line-into-a-vector/

int ReadFile(std::string fileName){
// Open the File
	FILE* pFile;
	pFile=fopen("the_maze.txt","r");
	if (pFile==NULL) perror ("Error opening file");


    unsigned int col_total=45;
	unsigned int line_count=30;
	unsigned int col=0;
	unsigned int row=0;
	
	for(row=0; row<line_count; row++){
		for(col=0; col<col_total; col++){
			maze.at(col).at(row).push_back(fgetc(pFile));
		}
	}
			
	std::cout<<"Here is the maze:"<<"\n";
		for(row=0; row<line_count; row++){
			for(col=0; col<col_total; col++){
				std::cout<<maze.at(col).at(row);
			}
		}
	std::cout<<"\n";

	
	//Close The File
	fclose(pFile);
	
	return 0;
}




 
int main()
{
	ReadFile("the_maze.txt");


return 0;
}

