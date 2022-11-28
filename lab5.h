/*Add the vector method*/
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

class File
{
private:

    int path;
    int currentPath;
    

public:
    string name;
    string extension;
    int size_in_mb;


    string GetName()
    {
        return name;
    }
    string GetExtension()
    {
        return extension;
    }
    int GetSize_in_mb()
    {
        return size_in_mb;
    }
    File(string name, string extension, int size_in_mb)
    {
        this->name = name;
        this->extension = extension;
        this->size_in_mb = size_in_mb;
    }


    void Print()
    {
        cout << "Name:" << name << endl;
        cout << "Extension:" << extension << endl;
        cout << "Size:" << size_in_mb << endl;
        cout << "Path:" << currentPath << endl;

        

    }
};




class Folder
{
private:

    int path;
    static int currentPath;
    
   

public:
   
    vector <File> fileVector;
    vector <Folder> folderVector;
    Folder() :path(++currentPath) {} int getPath() const { return path; }
    void addFolder(Folder folder) {
        folderVector.push_back(folder);
    }
    void addFile(File path) {
        fileVector.push_back(path);
    }

};
int Folder::currentPath = 0;



int main()
{
    Folder folder; 
    Folder folder1; 
    Folder folder2; 
    Folder folder3; 
    File path1("math answer", ".txt", 149);
    path1.Print();
    cout << "----------------" << endl;
    File path2("eng answer", ".txt", 87);
    path2.Print();
    cout << "----------------" << endl;
    File path3("blabla", ".txt", 54);
    path3.Print();
    cout << "----------------" << endl;
    folder.addFolder(folder1);
    folder1.addFolder(folder2);
    folder2.addFolder(folder3);
    folder3.addFile(path1);
    folder3.addFile(path2);
    folder3.addFile(path3);
}