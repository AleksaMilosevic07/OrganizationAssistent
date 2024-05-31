#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;
using namespace std;

bool sigma = false, orgPathExist = false, unOrgPathExist = false;
fs::path orgPath, unOrgPath;

void orgFolder()
{
    cout << "\nPath to your organization folder: ";
    cin >> orgPath;
    if (fs::exists(orgPath))
        cout << "Found a folder on specified path, proceed.\n";
    else
    {
        cout << "Invalid path location, please try again.\n";
        orgFolder();
    }
    orgPathExist = true;
}

void unOrgFolder()
{
    cout << "\nPath to your unorganized folder: ";
    cin >> unOrgPath;
    if (fs::exists(unOrgPath))
        cout << "Found a folder on specified path, proceed.\n";
    else
    {
        cout << "Invalid path location, please try again.\n";
        unOrgFolder();
    }
    unOrgPathExist = true;
}

void start()
{
    for (const auto& entry : fs::directory_iterator(unOrgPath))
    {
        string ext = entry.path().extension().string();

        //Text files
        if (ext == ".txt" || ext == ".docx" || ext == ".pdf" || ext == ".rtf" || ext == ".csv")
        {
            try
            {
                fs::path newPath = orgPath / "Texts" / entry.path().filename();
                fs::rename(entry.path(), newPath);
                cout << "File " << entry.path() << " moved to " << newPath << endl;
            }
            catch (const fs::filesystem_error& e)
            {
                cerr << "Error while moving files: " << e.what() << endl;
            }
        }
        //Photos
        else if (ext == ".jpg" || ext == ".png" || ext == ".gif" || ext == ".bmp" || ext == ".svg")
        {
            try
            {
                fs::path newPath = orgPath / "Photos" / entry.path().filename();
                fs::rename(entry.path(), newPath);
                cout << "File " << entry.path() << " moved to " << newPath << endl;
            }
            catch (const fs::filesystem_error& e)
            {
                cerr << "Error while moving files: " << e.what() << endl;
            }
        }
        //Audio
        else if (ext == ".mp3" || ext == ".wav" || ext == ".flac" || ext == ".aac" || ext == ".ogg")
        {
            try
            {
                fs::path newPath = orgPath / "Audio" / entry.path().filename();
                fs::rename(entry.path(), newPath);
                cout << "File " << entry.path() << " moved to " << newPath << endl;
            }
            catch (const fs::filesystem_error& e)
            {
                cerr << "Error while moving files: " << e.what() << endl;
            }
        }
        //Videos
        else if (ext == ".mp4" || ext == ".avi" || ext == ".mov" || ext == ".mkv" || ext == ".wmv")
        {
            try
            {
                fs::path newPath = orgPath / "Videos" / entry.path().filename();
                fs::rename(entry.path(), newPath);
                cout << "File " << entry.path() << " moved to " << newPath << endl;
            }
            catch (const fs::filesystem_error& e)
            {
                cerr << "Error while moving files: " << e.what() << endl;
            }
        }
        //CodeFiles
        else if (ext == ".cpp" || ext == ".c" || ext == ".java" || ext == ".py" || ext == ".html" || ext == ".css"|| ext == ".lua" || ext == ".js")
        {
            try
            {
                fs::path newPath = orgPath / "CodeFiles" / entry.path().filename();
                fs::rename(entry.path(), newPath);
                cout << "File " << entry.path() << " moved to " << newPath << endl;
            }
            catch (const fs::filesystem_error& e)
            {
                cerr << "Error while moving files: " << e.what() << endl;
            }
        }
        //Archives
        else if (ext == ".zip" || ext == ".rar" || ext == ".tar.gz" || ext == ".7z" || ext == ".iso")
        {
            try
            {
                fs::path newPath = orgPath / "Archives" / entry.path().filename();
                fs::rename(entry.path(), newPath);
                cout << "File " << entry.path() << " moved to " << newPath << endl;
            }
            catch (const fs::filesystem_error& e)
            {
                cerr << "Error while moving files: " << e.what() << endl;
            }
        }

    }
}

void setup()
{
    cout << "\n\n\n";
    cout << "First select the path where you want Organization Assistant to make his folders. This includes text files, document files, etc...\n";
    orgFolder();
    fs::create_directories(orgPath / "Texts");
    cout << "Folder for textual files created at " << (orgPath / "Texts").string() << "\n";
    fs::create_directories(orgPath / "Photos");
    cout << "Folder for graphic files created at " << (orgPath / "Photos").string() << "\n";
    fs::create_directories(orgPath / "Audio");
    cout << "Folder for audio files created at " << (orgPath / "Audio").string() << "\n";
    fs::create_directories(orgPath / "Videos");
    cout << "Folder for video files created at " << (orgPath / "Videos").string() << "\n";
    fs::create_directories(orgPath / "CodeFiles");
    cout << "Folder for code files created at " << (orgPath / "CodeFiles").string() << "\n";
    fs::create_directories(orgPath / "Archives");
    cout << "Folder for archive files created at " << (orgPath / "Archives").string() << "\n\n";
    unOrgFolder();
    cout << "All set! You are free to proceed!\n\n";
}

void startup()
{
    int a;
    cout << "\n\n\n";
    cout << "Welcome to Organization Assistant. This program will move all your files in the target folder to the folders you tell them to. \n";
    cout << "Select one of the options below: \n";
    cout << "0. Exit program \n1. Setup \n2. Organization folder path \n3. Unorganized folder path \n4. Start\n";

    cin >> a;
    switch (a)
    {
        case 0:
            sigma = true;
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
            if (orgPathExist && unOrgPathExist)
            {
                start();
            }
            else
                cout << "There is no set path to either Organization folder or the Unorganized folder. Try again.\n";
            break;
        default:
            cout << "Invalid answer, try again.\n";
            break;
    }
}

int main()
{
    while (!sigma)
    {
        startup();
    }
    return 0;
}
