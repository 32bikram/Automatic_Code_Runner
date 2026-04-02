#include <bits/stdc++.h>
using namespace std;

string failure_reason(string file_path){
    ifstream file(file_path);
    string content = "";
    string line;
    while(getline(file, line)){
        content += line + "\n";
    }
    return content;
}

int main(int argcount, char* arg[]){

    if(argcount<2){
        cout<<"please give proper argument";
        return 0;
    }

    string filename = arg[1];
    // in arg[0] there is runner and arg[1] there will be the filename

    string extension = filename.substr(filename.find_last_of('.')+1);
    string compile_cmd;
    string exe_cmd;

    if(extension=="cpp"){
        compile_cmd =  "g++ " + filename + " -o output 1> /dev/null 2> compile_err.txt";
// in normal cases when it comiples it will discard it, in case of failure it will dtore
// the result in the file. first one uses  stdout second uses stderr.
        cout<<"compiling...... \n";
        if(system(compile_cmd.c_str()) != 0){
            cout<<"Compilation Failed...\n";
            cout<<failure_reason("compile_err.txt");
            return 0;
        }
        cout<<"Compilation Successfull...\n";
        exe_cmd = "./output";
    }

    else if(extension == "py"){
        exe_cmd = "python " + filename;
    }

    else if(extension == "c"){
        compile_cmd =  "gcc " + filename + " -o output 1> /dev/null 2> compile_err.txt";
        cout<<"compiling...... \n";
        if(system(compile_cmd.c_str()) != 0){
            cout<<"Compilation Failed...\n";
            cout<<failure_reason("compile_err.txt");
            return 0;
        }
        cout<<"\\**Compilation Successfull**//\n";
        exe_cmd = "./output";
    }

    else{
        cout<<"invalid file type";
        return 0;
    }

    cout<<"running.......\n";
    system(exe_cmd.c_str());
    return 0;
}