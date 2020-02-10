#include <iostream.h>
#include <conio.h>

static int m,n;

class fish
{
  public :
	 int maze[5][6]; int x , y;


	 void set_danger();
	 void printmaze();
	 void set_dad();
	 void set_baby();
       /*void left();
	 void right();
	 void up();
	 void down();*/
	 inline void val()
	 {
	   cout<<"\n\t The value at a[m][n] now is : " << maze[m][n] ;
	  }
 };

 void fish::set_danger()
 {
	  int count;
	  cout<<"\n\t Enter the no. of danger elements : ";
	  cin>>count;

	  for(int i=0;i<count;i++)
	  {
	    cout<<"\n\t Enter the index : ";
	    cin>>x>>y;

	    maze[x][y]=0;
	  }
 }

 void fish::printmaze()
 {
	  for(int i=0;i<5;i++)
	   {
	    for(int j=0;j<6;j++)
	     {
	       if(maze[i][j]==0)
	      {
		cout<<"\t X";
	      }
	     else if(maze[i][j]==1)
	      {
		cout<<"\t dad";
	      }
	     else if(maze[i][j]==8)
	      {
		cout<<"\t baby ";
	      }
	     else
	      {
		cout<<"\t _ ";
	     // cout<<"\t"<< maze[i][j];

	      }
	     }
	     cout<<"\n";
	   }
 }

 void fish::set_dad()
 {
   int i , j;
   cout<<"\n\t Enter the index of the dad fish : ";
   cin>>i>>j;
   m=i;
   n=j;

   maze[i][j]=1;
 }

 void fish::set_baby()
 {
   int i,j;
   cout<<"\n\t Enter the index of the baby fish : ";
   cin>>i>>j;

   maze[i][j] = 8;
 }


 void main()
{
  clrscr();

  fish f;

  f.maze[0][0]=34;
  f.maze[2][4]=543;
  f.maze[3][4]=5436;
  f.maze[2][5]=433;
  f.maze[4][3]=342;

  f.set_danger();
  f.set_dad();
  f.set_baby();
  f.printmaze();

  while(1)
  {
    if(m<0 || n>5 || m>4 || n<0)
    {
     cout<<"\n\n\t\t OUT OF BOUNDS :( ";
     break;
    }


    if( f.maze[m][n] == 8)
    {
     cout<<"\n\n\t\t DADDY GOT BABY :) \n\t\t GOOD JOB!! ";
     break;
    }

    else if( f.maze[m][n] == 0)
    {
      cout<<"\n\n\t\t LANDED IN DANGER!!! :0 ";
      break;
    }


    int z = getch();

    if (z==72)
    {
     cout<<"\n\t GOING UP ";
     m--;

    }

    else if(z==80)
    {
     cout<<"\n\t GOING DOWN ";
     m++;
    }

    else if(z==75)
    {
     cout<<"\n\t GOING LEFT ";
     n--;
    }

    else if(z==77)
    {
     cout<<"\n\t GOING RIGHT ";
     n++;

    }

  /*  else
    {
      cout<<"\n\t WRONG KEY PRESSED ";
     }*/

  }



  /*f.left();
  f.left();
  f.down();
  f.down();
  f.down();
  f.down();
  f.left();
  f.left();
  f.left();*/


  //f.val();

  getch();

}