#include <iostream>

const char Goal = 'G';
const char START = 's';
const char PATH =   'x';
const char WALL = '#';
const char VISITED = '+';


using namespace std;



bool FIndPath(int row, int col, char maze[][6])
{
        if(row>5 || row<0 || col>5 || col<0 )
                return false;
		
        if (maze[row][col]== Goal){
            //cout<<"goal check"<<endl;
				return true;
			}
		
        if (maze[row][col] == WALL || maze[row][col] == VISITED ){
            //cout<<"wall n visit check"<<endl;
				return false;
		   } 
		else{
            //cout<<"c"<<endl;
			maze[row][col] = VISITED;
           for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
			cout << maze[i][j];
		cout << endl;
        
	}
    cout<<"\n";
            
				if (FIndPath(row-1, col, maze)==true)
                    //maze[row][col] = PATH;
					return true;

				 if (FIndPath(row, col+1, maze)==true)
                    //maze[row][col] = PATH;
					return true;

				 if (FIndPath(row+1, col, maze)==true)
                    //maze[row][col] = PATH;
					return true;

				 if(FIndPath(row, col-1, maze)==true)
                    //maze[row][col] = PATH;
					return true;
                
				maze[row][col] = PATH;
                
            }
				return false;
		}


void print_maze(const char maze[][6])
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
			cout << maze[i][j];
		cout << endl;
	}
}



int main()
{
           
            char my_maze[ 6][6] =
			{{ '.', '#', '#', '#' , '#' , '#' },
			{  '.', '.' , '.' , '.' , '.' , '#' },
			{  '#' , '.', '#' , '#' , '#' , '#' },
			{  '#', '.' , '#' , '#' , '#' , '#' },
			{  '.' , '.' , '.' , '#' , '.' , '.' },
			{  '#' , '#' , '.' , '.' , '.' , '#'}};

	print_maze(my_maze);
	cout << endl;
   
    int in1,in2,gin1,gin2;
    cout<<"enter start position"<<endl;
    cin>>in1>>in2;
    cout<<"enter goal postion"<<endl;
    cin>>gin1>>gin2;
    //my_maze[in1][in2]=START;
    my_maze[gin1][gin2]=Goal;
    
    

	bool result = false;
    result = FIndPath(in1, in2, my_maze);
	
	if (result !=true )
		cout << "No path found";
	else
		print_maze(my_maze);

	char held;
	cout << endl << "Enter a character to quit" << endl;
	cin >> held;

	return 0;
} 