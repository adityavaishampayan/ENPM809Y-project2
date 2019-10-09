#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>

using std::cout;
using std::vector;
using std::cin;
using std::endl;
using std::vector;
using std::string;

/**
 * The <code>ReadFile</code> function takes in a file path as a string (ex: "the_maze.txt").
 * It opens that text file and reads it, character by character, into a 2D vector (maze)
 */
int ReadFile(const char* fileName);

unsigned int col_total=6;
unsigned int line_count=6;
vector<vector<string>> maze(col_total+1, vector<string>(line_count+1));




//https://thispointer.com/c-how-to-read-a-file-line-by-line-into-a-vector/

int ReadFile(const char* fileName){
// Open the File
	FILE* pFile;
	pFile=fopen(fileName,"r");
	if (pFile==NULL) perror ("Error opening file");


	unsigned int col=0;
	unsigned int row=0;


	for(row=0; row<=line_count; row++){
		for(col=0; col<=col_total; col++){
			maze.at(col).at(row)=fgetc(pFile);
		}//fgetc(pFile);
	}	
	
	cout<<"Here is the maze:"<<"\n";
		for(row=0; row<=line_count; row++){
			for(col=0; col<=col_total; col++){
				//cout<<" r"<<row<<"c"<<col<<" ";
				cout<<maze.at(col).at(row);
			}
		}
	cout<<"\n";

	
	//Close The File
	fclose(pFile);
	
	return 0;
}


int FindPath(int Start_x,int Goal_x,int Start_y, int Goal_y)
{
    
	if ((Start_x>col_total || Start_y>line_count) || (Goal_x>col_total || Goal_y>line_count) )
    {
     cout<<"Co-ordinates are outside of the maze"<<endl;
    }
    if (Start_x==Goal_x && Start_y==Goal_y)
    {
     cout<<"Start and Goal positions are same"<<endl;
    }
    if((maze.at(Start_x).at(Start_y).compare("#")==0) || (maze.at(Goal_x).at(Goal_y).compare("#")==0))
     cout<<"Position entered is obstacle"<<endl;
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
	ReadFile("the_maze2.txt");
    int Start_x,Goal_x,Start_y, Goal_y, Pos_x, Pos_y;
    cout<<"enter start position x coordinate: ";
    cin>>Start_x;
    
    cout<<"\n enter start position y coordinate: ";
    cin>>Start_y;
    
    cout<<"\n enter goal position x coordinate: ";
    cin>>Goal_x;
    
    cout<<"\n enter goal position y coordinate: ";
    cin>>Goal_y;
    
    FindPath(Start_x,Start_y,Goal_x,Goal_y);
	CheckObstacle(Pos_x,Pos_y);
    CheckPath(Pos_x,Pos_y);

return 0;
}

