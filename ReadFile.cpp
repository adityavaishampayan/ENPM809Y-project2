#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>

/**
 * The <code>ReadFile</code> function takes in a file path as a string (ex: "the_maze.txt").
 * It opens that text file and reads it, character by character, into a 2D vector (maze)
 */
int ReadFile(const char* fileName);

std::vector<std::vector<std::string>> maze(45, std::vector<std::string>(32));


//https://thispointer.com/c-how-to-read-a-file-line-by-line-into-a-vector/

int ReadFile(const char* fileName){
// Open the File
	FILE* pFile;
	pFile=fopen(fileName,"r");
	if (pFile==NULL) perror ("Error opening file");


    unsigned int col_total=45;
	unsigned int line_count=31;
	unsigned int col=0;
	unsigned int row=0;


	for(row=0; row<=line_count; row++){
		for(col=0; col<col_total; col++){
			maze.at(col).at(row)=fgetc(pFile);
		}fgetc(pFile);
	}	
	
	std::cout<<"Here is the maze:"<<"\n";
		for(row=0; row<=line_count; row++){
			for(col=0; col<col_total; col++){
				std::cout<<maze.at(col).at(row);
			}
		}
	std::cout<<"\n";

	
	//Close The File
	fclose(pFile);
	
	return 0;
}


int FindPath(int Start_x,int Goal_x,int Start_y, int Goal_y)
{
    
	if ((Start_x>45 || Start_y>30) || (Goal_x>45 || Goal_y>30) )
    {
     std::cout<<"Co-ordinates are outside of the maze"<<std::endl;
    }
    if (Start_x==Goal_x && Start_y==Goal_y)
    {
     std::cout<<"Start and Goal positions are same"<<std::endl;
    }
    if((maze.at(Start_x).at(Start_y).compare("#")==0) || (maze.at(Goal_x).at(Goal_y).compare("#")==0))
     std::cout<<"Position entered is obstacle"<<std::endl;
    return 0;
}

int CheckObstacle(int Pos_x,int Pos_y)
{
    bool position;
   if(maze.at(Pos_x).at(Pos_y).compare("#")== 0){ 
    position=false;   
   }return 0;
}
 
int CheckPath(int Pos_x,int Pos_y)
{
    bool position;
   if(maze.at(Pos_x).at(Pos_y).compare(" ")== 0){ 
    position= true;
   }  
    return 0;
}



int main()
{
	ReadFile("the_maze.txt");
    int Start_x,Goal_x,Start_y, Goal_y, Pos_x, Pos_y;
    std::cout<<"Enter the start and goal position: "<<std::endl;
    std::cin>>Start_x>>Start_y>>Goal_x>>Goal_y;
    FindPath(Start_x,Start_y,Goal_x,Goal_y);
	CheckObstacle(Pos_x,Pos_y);
    CheckPath(Pos_x,Pos_y);

return 0;
}

