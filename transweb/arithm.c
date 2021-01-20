#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<unistd.h>

void childFunction(char *line)
{
    write(1, "I am a child working for my parent\n", strlen("I am a child working for my parent\n"));
    int op1,op2;
	char op; char ending;
	int ret = sscanf(line, "%d %c %d %c", &op1, &op, &op2, &ending);
    char *buff;
    buff = calloc(100, sizeof(char));
    int size_of_buff_req;
    int result;
    if(ret != 4)
        exit(50);
    else if(op2 == 0)
        exit(100);
    else if(op != '+' && op != '-' && op != '*' && op != '/')
            exit(200);
    else
    {
        switch(op)
        {
            case '+' :  result = op1 + op2;
            size_of_buff_req = sprintf(buff, "%d %c %d = %d\n", op1, op, op2, result);
            break;

            case '-' :  result = op1 - op2;
            size_of_buff_req = sprintf(buff, "%d %c %d = %d\n", op1, op, op2, result);
            break;

            case '*' :  result = op1 * op2;
            size_of_buff_req = sprintf(buff, "%d %c %d = %d\n", op1, op, op2, result);
            break;

            case '/' :  result = op1 / op2;
            size_of_buff_req = sprintf(buff, "%d %c %d = %d\n", op1, op, op2, result);
            break;
        }

        write(1, buff, size_of_buff_req);
        exit(0);
    }
}

int main()
{
    write(1, "This program makes simple arithmetics : \n", strlen("This program makes simple arithmetics : \n"));

    while(1)
    {
        write(1, "Enter an arithmetic statement, e.g. 34 + 132>\n", strlen("Enter an arithmetic statement, e.g. 34 + 132>\n"));
        char *inp;
        inp = calloc(100, sizeof(char));
        read(0, inp, 100);
        int status;
        int rc = fork();
        if(rc == 0)
            childFunction(inp);
        else if(rc > 0)
        {
            write(1, "Created a child to make your operation, waiting \n", strlen("Created a child to make your operation, waiting \n"));
            wait(&status);
            if(WIFEXITED(status))
            {
                int stat = WEXITSTATUS(status);
                switch(stat)
                {
                    case 50 : write(1, "Wrong statement.\n", strlen("Wrong statement.\n"));
                    break;

                    case 100 : write(1, "Division by zero.\n", strlen("Division by zero.\n"));
                    break;

                    case 200 : write(1, "Wrong operator.\n", strlen("Wrong operator.\n"));
                    break;
                }
            }
        }
    }
    return 0;
}