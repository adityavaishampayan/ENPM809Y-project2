#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using std::ifstream;

std::vector<std::vector<std::string> > maze;

//https://thispointer.com/c-how-to-read-a-file-line-by-line-into-a-vector/

int ReadFile(std::string fileName){
// Open the File
	std::ifstream myfile(fileName);
 
	// Check if object is valid
	if(!myfile)
	{
		std::cerr << "Cannot open the File : "<<fileName<<std::endl;
		return 0;
	}

	//https://stackoverflow.com/questions/3482064/counting-the-number-of-lines-in-a-text-file
    // new lines will be skipped unless we stop it from happening:    
    myfile.unsetf(std::ios_base::skipws);

    // count the newlines with an algorithm specialized for counting:
    unsigned line_count = std::count(
        std::istream_iterator<char>(myfile),
        std::istream_iterator<char>(), 
        '\n');
    unsigned int col_total=45;
 
	unsigned int col=0;
	unsigned int row=0;
	char c;
	
		for(row=0; row<line_count; row++){
			for(col=0; col<col_total; col++){
				maze.at(col).at(row).insert(myfile.get(c));
			}
		}


	//Close The File
	myfile.close();

	
	return 0;
}

	



 
int main()
{
	ReadFile("maze.txt");


return 0;
}

