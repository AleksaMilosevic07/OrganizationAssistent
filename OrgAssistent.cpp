#include <bits/stdc++.h>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;
bool sigma = 0;
string orgPath, unOrgPath;

void orgFolder()
{
    cout<<"\n";
    cout<<"Path to your organization folder: ";
    cin>>orgPath;
    if(fs::exists(orgPath)) cout<<"Found a file on specified path, proceed.\n";
    else
    {
        cout<<"Invalid path location, please try again";
        orgFolder();
    }

}

void unOrgFolder()
{
    cout<<"\n";
    cout<<"Path to your unorganized folder: ";
    cin>>unOrgPath;
    if(fs::exists(unOrgPath)) cout<<"Found a file on specified path, proceed.\n";
    else
    {
        cout<<"Invalid path location, please try again";
        orgFolder();
    }
}

void start()
{

}

void setup()
{
    cout<<"\n\n\n";
    cout<<"First select the path where you want Organization Assistant to make his folders. This includes text files, document files, etc...\n";
    orgFolder();
    fs::create_directories(orgPath + "/Texts");
    cout<<"Folder for textual files created at "<<orgPath<<"\Texts\n";
    fs::create_directories(orgPath + "/Photos");
    cout<<"Folder for grahic files created at "<<orgPath<<"\Photos\n";
    fs::create_directories(orgPath + "/Audio");
    cout<<"Folder for audio files created at "<<orgPath<<"\Audio\n";
    fs::create_directories(orgPath + "/Videos");
    cout<<"Folder for video files created at "<<orgPath<<"\Videos\n";
    fs::create_directories(orgPath + "/CodeFiles");
    cout<<"Folder for code files created at "<<orgPath<<"\CodeFiles\n";
    fs::create_directories(orgPath + "/Archives");
    cout<<"Folder for archive files created at "<<orgPath<<"\Archives\n\n";
    unOrgFolder();
    cout<<"All set! You are free to proceed!\n\n";
}

void startup()
{
    int a;
    cout<<"\n\n\n";
    cout<<"Welcome to Organization Assistant. This program will move all your files in the target folder to the folders you tell them to. \n";
    cout<<"Select one of the options bellow: \n";
    cout<<"0. Exit program \n1. Setup \n2. Organization folder path \n3. Unorganized folder path \n4. Start\n";


    cin>>a;
    /*
    if(a == 1) setup();
    else if(a == 2) orgFolder();
    else if(a == 3) unOrgFolder();
    else if(a == 4) start();
    */
    switch(a)
    {
        case 0:
            sigma = 1;
            break;
        case 1:
            setup();
            break;
        case 2:
            orgFolder();
            break;
        case 3:
            unOrgFolder();
            break;
        case 4:
            start();
            break;
        default:
            cout<<"Invalid answer, try again.\n";
            break;
    }


}

int main()
{
    while(!sigma)
    {
        startup();
    }
    return 0;
}
