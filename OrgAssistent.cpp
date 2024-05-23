#include <bits/stdc++.h>
#include <filesystem>
using namespace std;
string orgPath, unOrgPath;

void orgFolder()
{
    cout<<"\n";
    cout<<"Path to your organization folder: ";
    cin>>orgPath;
    if(filesystem::exists(orgPath)) printf("Found a file on specified path, proceed.\n");
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
    if(filesystem::exists(unOrgPath)) printf("Found a file on specified path, proceed.\n");
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
    printf("\n\n\n");
    printf("First select the path where you want Organization Assistant to make his folders. This includes text files, document files, spreadsheet files, image files, audio files, video files, code files, archive files\n");
    orgFolder();
    unOrgFolder();
}

void startup()
{
    int a;
    printf("\n\n\n");
    printf("Welcome to Organization Assistant. This program will move all your files in the target folder to the folders you tell them to. \n");
    printf("Select one of the options bellow: \n");
    printf("1. Setup \n2. Organization folder path \n3. Unorganized folder path \n4. Start\n");


    scanf("%d", &a);
    if(a == 1) setup();
    else if(a == 2) orgFolder();
    else if(a == 3) unOrgFolder();
    else if(a == 4) start();

}

int main()
{
    startup();
    return 0;
}
