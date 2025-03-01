#include <iostream>
#include <conio.h>
using namespace std;
#include<windows.h>
#include<math.h>
void sleep(int m)
{
        for(int j=0;j<m*21000;j++)
        {

        }
}
void init(char A[], int dim)
{
    for(int i=0;i<dim*dim ;i++)
    {
        A[i]=' ';
    }
}

void fillboard(char A[], int dim)
{
    for(int i=0;i<dim*dim;i++)
    {
        cout<<"__"<<A[i]<<"__";
        if((i+1)%dim==0)
        {
            cout<<endl;
        }
        if((i+1)%dim!=0)
        {
            cout<<"|";
        }
    }
}

int td_to_od(int &ri,int &ci,int dim)
{
    return  (((ri*dim)-(dim-ci))-1);
}

void turnchange(bool &turn)
{
    if(turn==1)
        turn=0;
    else
        turn=1;
}
bool legalmove(char A[], int ri, int ci, int dim, int res)
{
    if (ri >= 1 && ci >= 1 && ri <= dim && ci <= dim && A[res] == ' ')
    {
        return true;
    }
    else
    {
        cout<<"Illegal move"<<endl;
        return false;
    }
}

bool write_on_board(char A[], int ri, int ci , int dim , bool &turn , char symbol[])
{
    int res=td_to_od(ri,ci,dim);    // res store in one dim
    if(legalmove(A,ri,ci,dim, res))
    {
        A[res]=symbol[turn];
        system("cls");
        fillboard(A,dim);
        return true;
    }
    else
        return false;
}

char horizontal_win(char A[], int dim, char symbol[])
{
    char ch;
    for (int i = 0; i < dim; i++)
    {
        int p1 = 0;
        int p2 = 0;
        for (int j = 0; j < dim; j++)
        {
            if (A[i * dim + j] == symbol[0])
                p1++;
            if (A[i * dim + j] == symbol[1])
                p2++;
        }

        if (p1 == dim)
        {
            return symbol[0];
        }

        if (p2 == dim)
        {
            return symbol[1];
        }
    }
    return ch=' ';
}
char vertical_win(char A[] , int dim , char symbol[])
{
    char ch;
    for(int i=0;i<dim;i++)
    {   int p1=0;
        int p2=0;
        for(int j=0;j<dim;j++)
        {
            if(A[j*dim+i]==symbol[0])
                p1++;
            if(A[j*dim+i]==symbol[1])
                p2++;
        }
        if(p1==dim)
            {
                return symbol[0];
            }
        if(p2==dim)
            {
                return symbol[1];
            }
    }
    return ch=' ';
}
char diagonal_win(char A[] , int dim , char symbol[])
{       char ch;
        int p1=0;
        int p2=0;
        int pd1=0;
        int pd2=0;
        int a=1;

    for(int i=0;i<dim;i++)
    {

        if(A[i*dim+i]==symbol[0])
                p1++;
        if(A[i*dim+i]==symbol[1])
                p2++;
        if(A[(i+1)*dim-a]==symbol[0])
                pd1++;
        if(A[(i+1)*dim-a]==symbol[1])
                pd2++;
        a++;
    }

    if(p1==dim)
    {
        return symbol[0];
    }
    if(p2==dim)
    {
        return symbol[1];       // p2 win diagonally
    }

    if(pd1==dim)
    {
       return symbol[0];            // p1 win pre diagonally
    }
    if(pd2==dim)
    {
       return symbol[1];            // p2 win  pre diagonally
    }
    return ch=' ';
}
 bool is_win(char A[] , int dim , char symbol[])
 {
     char ch1=horizontal_win(A,dim,symbol);
     char ch2=vertical_win(A,dim,symbol);
     char ch3=diagonal_win(A,dim,symbol);
     cout<<ch1;
     cout<<ch2;
     cout<<ch3;
    if(ch1==symbol[0])
        {
            cout<<"player 1 (X) have won horizontally";
            return true;
            }
    if(ch1==symbol[1])
        {
            cout<<"player 2 (0) have won horizontally";
            return true;
        }
    if(ch2==symbol[0])
        {
            cout<<"player 1 (X) have won vertically";
            return true;
            }
    if(ch2==symbol[1])
        {
            cout<<"player 2 (0) have won vertically";
            return true;
        }
    if(ch3==symbol[0])
        {cout<<"player 1 (X) have win diagonally";
        return true;
        }
    if(ch3==symbol[1])
        {
            cout<<"player 2 (0) have win diagonally";
            return true;
        }
    return false;
 }

bool is_draw(char A[] , int dim)
{
    for(int i=0;i<dim*dim;i++)
    {
        if(A[i]==' ')
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int dim;
    bool turn=0;
    char symbol[2];
    symbol[0]='X';
    symbol[1]='0';
    cout<<"Player 1 = X"<<endl;
    cout<<"Player 2 = 0"<<endl;
    int ri,ci;
    cout<<"Enter Dimension of Box:  ";
    cin>>dim;
    char A[dim*dim];
    init(A,dim);
    fillboard(A,dim);
    bool b;
    do
    {
    cout<<"\n Enter row and column: ";
    cin>>ri>>ci;
    b=write_on_board(A,ri,ci,dim , turn , symbol);
    turnchange(turn);
    if(is_win(A,dim,symbol))
    {
        break;
    }
    if(b==false)
    {
        turnchange(turn);
        continue;
    }
    if(is_draw(A,dim)==true)
        {
            cout<<"Game has Draw";
            break;
        }

    }while(true);
return 0;
}

