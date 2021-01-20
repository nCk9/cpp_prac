# include<bits/stdc++.h> 
using namespace std;

class node
{
    public :
    list<node> children = new list<node>();
    node parent;
    int *puzzle = new int[9];
    int x = 0;
    int col = 3;

    node(int *arr)
    {
        set_puzzle(arr);
    }

    void set_puzzle(int *arr)
    {
        for(int i=0; i<9; i++)
            this.puzzle[i] = arr[i];
    }

    void ExpandMove()
    {
        for(int i=0; i<9; i++)
            if(puzzle[i] == 0)
                x = i;
        Move_Right(puzzle, x);
        Move_Left(puzzle ,x);
        Move_Up(puzzle, x);
        Move_Down(puzzle, x);
    }

    void Move_Right(int *arr, int i)
    {
        if( i%col < col-1)
        {
            int *pc = new int[9];
            copy_puzz(pc, arr);

            int temp = pc[i+1];
            pc[i+1] = pc[i];
            pc[i] = temp;

            node child = new node(pc);
            children.Add(child);
            child.parent = this;
        }
    }

    void Move_Left(int *arr, int i)
    {
        if( i%col > 0)
        {
            int *pc = new int[9];
            copy_puzz(pc, arr);

            int temp = pc[i-1];
            pc[i-1] = pc[i];
            pc[i] = temp;

            node child = new node(pc);
            children.Add(child);
            child.parent = this;
        }
    }

    void Move_Up(int *arr, int i)
    {
        if( i-col >= 0)
        {
            int *pc = new int[9];
            copy_puzz(pc, arr);

            int temp = pc[i-3];
            pc[i-3] = pc[i];
            pc[i] = temp;

            node child = new node(pc);
            children.Add(child);
            child.parent = this;
        }
    }    

    void Move_Down(int *arr, int i)
    {
        if( i + col < 9)
        {
            int *pc = new int[9];
            copy_puzz(pc, arr);

            int temp = pc[i+3];
            pc[i+3] = pc[i];
            pc[i] = temp;

            node child = new node(pc);
            children.Add(child);
            child.parent = this;
        }
    }

    void print_puzzle()
    {
        int m=0;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
                cout << puzzle[m] << " ";
            cout << "\n";
        }  
    }

    bool isSamePuzz(int *arr)
    {
        bool samePuzz = true;
        for(int i=0; i<9; i++)
            if(puzzle[i] != arr[i])
               samePuzz = false;
        return samePuzz;
    }

    void copy_puzz(int *a, int *b)
    {
        for(int i=0; i<9; i++)
            a[i] = b[i];
    }

    bool Goal_test()
    {
        bool isGoal = true;
        int m = puzzle[0];

        for(int i=0; i<9; i++)
          {
            if(m > puzzle[i])
                {
                    isGoal = false;
                    break;
                }
            m = puzzle[i];
          }      
          return isGoal;
    }
};

class BFS
{
    public:
    BFS()
}


int main()
{
    cout << "Enter the initial state of the 3x3 puzzle problem : ";
    int arr[9];
    for(int i=0; i<sz; i++)
        cin >> arr[i];

    node init_node(arr);
}