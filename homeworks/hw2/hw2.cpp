#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Pixel // the class I created to hold the pixels of the image
{
public:
    Pixel() { red = 0, green = 0, blue = 0; }                        // Default constructor
    Pixel(const int _red, const int _green = 0, const int _blue = 0) // constructor called when reading value from file
    {
        red = _red;
        green = _green;
        blue = _blue;
    }

    int getRed() const { return red; }     // Since variables are private, getter functions are functional for use in other classes.
    int getGreen() const { return green; } // other getter
    int getBlue() const { return blue; }   // other getter

private:
    int red, green, blue; // // variables holding pixel values
};

class Image /// A Image Class
{

public:
    Image() // Default Image constructor
    {
        width = 0;
        height = 0;
    }

    int readPPM(string filename);                          // function to retrieve data from file
    int writePPM(string filename) const;                   // function to write data to file
    void GrayScale(float &num1, float &num2, float &num3); // function to gray out pixels data
    /*EXTRA*/ bool IsA_filename(string filename) const;    // Function used in write and read functions, controlling filename input from user *(for extra error)
    bool getIsRead() const { return isRead; }              // Since the variable isRead is private, the get function is written because we need to access this variable in the Menu class.

private:
    bool isRead;             // Did the read function work or not?
    int width;               // width*height shows how many pixels there are
    int height;              //// width*height shows how many pixels there are
    int RGB;                 // max pixel value
    vector<Pixel> pixelData; // 1D vector with pixel class
};

class Menu // The class I created for the menu control
{
public:
    Menu() { MainMenu(); }; // Default Constructor

private:
    void MainMenu();                                             // shows the main menu.
    void OpenAnImageMenu();                                      // Shows the part to read data from the file.
    void SaveAnImageMenu();                                      // shows the part of saving data to file.
    void ScriptsMenu();                                          // Shows the script part.
    void GrayScaleMenu();                                        // The part where we get the graying coefficients
    /*EXTRA*/ bool IsA_positiveinteger(const string &str) const; // checks if the option is entered incorrectly in the menu. *(for extra error)

    Image image; // The image object we created for a single image !!If we want many images we can keep them in one container.
};

int main()
{
    Menu menu;

    return 0;
}

void Menu::MainMenu()
{
    string choice; // string variable that we use for control while getting number input for menu

    int input; // menu input variable
    do
    {

        cout << "MAIN MENU\n";

        cout << "0 - Exit\n";
        cout << "1 - Open An Image(D)\n";
        cout << "2 - Save Image Data(D)\n";
        cout << "3 - Scripts(D)\n";

        cin >> choice; // user is prompted for input

        if (IsA_positiveinteger(choice)) // if string contains only digits
        {
            input = stoi(choice); // string is transferred to the input with the stoi function.
            if (input >= 0)
            {
                switch (input) // Checking which function the input should call
                {
                case 0:
                    exit(1); // If it is zero, the program exits.
                    break;
                case 1:

                    OpenAnImageMenu(); // called function
                    break;
                case 2:

                    if (image.getIsRead() == 0) // If write or grayscale works without the read function, an error is given because there is no data.
                    {
                        MainMenu();
                        break;
                    }

                    SaveAnImageMenu(); // called function
                    break;
                case 3:

                    if (image.getIsRead() == 0) // If write or grayscale works without the read function, an error is given because there is no data.
                    {
                        MainMenu();
                        break;
                    }

                    ScriptsMenu(); // called function
                    break;

                default: // If the input is a different number from 0,1,2,3
                    // I didn't do any extra printing.
                    MainMenu();
                    break;
                }
            }
            else
            {
                // I didn't do any extra printing.
                MainMenu();
            }
        }
        else
        { // I didn't do any extra printing.
            MainMenu();
        }

    } while (true);
}
void Menu::OpenAnImageMenu()
{
    string filename; // variable with filename
    string choice;   // string variable that we use for control while getting number input for menu
    int input;       // menu input variable

    do
    {

        cout << "OPEN AN IMAGE MENU\n";
        cout << "0 - UP\n";
        cout << "1 - Enter The Name Of The Image File\n";

        cin >> choice; // user is prompted for input

        if (IsA_positiveinteger(choice)) // if string contains only digits
        {
            input = stoi(choice); // string is transferred to the input with the stoi function.
            if (input >= 0)
            {
                switch (input) // Checking which function the input should call
                {
                case 0:
                    MainMenu(); // called function
                    break;
                case 1:
                    do
                    {
                        cin >> filename; // user is prompted for input

                        if (image.readPPM(filename) == 1) // if data writing to file is done
                            break;

                    } while (true);
                    break;

                default: // If the input is a different number from 0,1
                         // I didn't do any extra printing.
                    OpenAnImageMenu();
                    break;
                }
            }
            else
            { // I didn't do any extra printing.
                OpenAnImageMenu();
            }
        }
        else
        { // I didn't do any extra printing.
            OpenAnImageMenu();
        }
    } while (true);
}
void Menu::SaveAnImageMenu()
{
    string filename; // variable with filename
    string choice;   // string variable that we use for control while getting number input for menu
    int input;       // menu input variable
    do
    {
        cout << "SAVE IMAGE MENU\n";
        cout << "0 - UP\n";
        cout << "1 - Enter A File Name\n";

        cin >> choice; // user is prompted for input

        if (IsA_positiveinteger(choice)) // if string contains only digits
        {
            input = stoi(choice); // string is transferred to the input with the stoi function.
            if (input >= 0)
            {
                switch (input) // Checking which function the input should call
                {
                case 0:
                    MainMenu();
                    break;
                case 1:

                    do
                    {
                        cin >> filename; // user is prompted for input

                        if (image.writePPM(filename) == 1) // if data writing to file is done
                            break;

                    } while (true);
                    break;
                default:
                    // I didn't do any extra printing.
                    SaveAnImageMenu();
                    break;
                }
            }
            else
            { // I didn't do any extra printing.
                SaveAnImageMenu();
            }
        }
        else
        { // I didn't do any extra printing.
            SaveAnImageMenu();
        }
    } while (true);
}
void Menu::ScriptsMenu()
{
    string choice; // string variable that we use for control while getting number input for menu
    int input;     // menu input variable
    do
    {
        cout << "SCRIPTS MENU\n";
        cout << "0 - UP\n";
        cout << "1 - Convert To Grayscale(D)\n";

        cin >> choice; // user is prompted for input

        if (IsA_positiveinteger(choice)) // if string contains only digits
        {
            input = stoi(choice); // string is transferred to the input with the stoi function.
            if (input >= 0)
            {
                switch (input) // Checking which function the input should call
                {
                case 0:
                    MainMenu();
                    break;
                case 1:
                    GrayScaleMenu(); // coefficient request menu is entered
                    break;
                default:
                    // I didn't do any extra printing.
                    ScriptsMenu();
                    break;
                }
            }
            else
            { // I didn't do any extra printing.
                ScriptsMenu();
            }
        }
        else
        { // I didn't do any extra printing.
            ScriptsMenu();
        }
    } while (true);
}
void Menu::GrayScaleMenu()
{
    string choice;          // string variable that we use for control while getting number input for menu
    int input;              // menu input variable
    float num1, num2, num3; // coefficients
    do
    {

        cout << "CONVERT TO GRAYSCALE MENU\n";
        cout << "0 - UP\n";
        cout << "1 - Enter Coefficients For RED GREEN And BLUE Channels.\n";
        cin >> choice;

        if (IsA_positiveinteger(choice))
        {
            input = stoi(choice); // stringi integera dönüştür
            if (input >= 0)
            {
                switch (input)
                {
                case 0:
                    ScriptsMenu();
                    break;
                case 1:

                    do
                    {
                        cin >> num1 >> num2 >> num3;

                        if (cin.get() != '\n' || cin.fail()) // If a character is entered or more than 3 inputs are entered
                        {
                            // I didn't do any extra printing. It remains empty so that it is asked again and not to exit the loop.
                            exit(1);
                        }
                        else if (num1 < 0 || num1 >= 1 || num2 < 0 || num2 >= 1 || num3 < 0 || num3 >= 1) // If it is not between [0,1)
                        {
                            // I didn't do any extra printing. It remains empty so that it is asked again and not to exit the loop.
                        }
                        else
                        {
                            break; // If the inputs are true, the loop is exited.
                        }

                    } while (true);

                    image.GrayScale(num1, num2, num3); // the grayScale function is called after the numbers are correct
                    break;
                default:
                    // I didn't do any extra printing.
                    GrayScaleMenu();
                    break;
                }
            }
            else
            {
                // I didn't do any extra printing.
                GrayScaleMenu();
            }
        }
        else
        {
            // I didn't do any extra printing.
            GrayScaleMenu();
        }
    } while (true);
}

bool Menu::IsA_positiveinteger(const string &str) const
{

    // Return true if string is non-empty and consists of numbers only
    for (char c : str)
    {
        if (!isdigit(c) || isspace(c))
        {
            // I didn't do any extra printing.
            return false;
        }
    }
    return !str.empty();
}

int Image::readPPM(string filename) // read from file function
{

    if (IsA_filename(filename) == false) // If the file name does not end with 4 letters or .ppm, it will throw an error.
    {
        // I didn't do any extra printing.
        return 0; // reading from file is not successful
    }

    ifstream image(filename); // Input file stream class , variable reading from file

    if (image.is_open()) // does the file open?
    {
        string type; // The variable that holds the ppm format. It should be P3.

        image >> type >> width >> height >> RGB; // READ FROM FILE

        if (type != "P3")
        {
            // I didn't do any extra printing.
            return 0; // reading from file is not successful
        }
        if (width == 0 || height == 0 || width < 0 || height < 0)
        {
            // I didn't do any extra printing.
            return 0; // reading from file is not successful
        }

        pixelData.resize(height * width); // we make space in the vector according to the width and height we get from the file.

        for (int i = 0; i < width * height; i++) // We are reading pixel by pixel. 1 pixel contains three values. Red, green and blue values.
        {
            int red, green, blue;                   // variables holding pixel values
            image >> red >> green >> blue;          // Pixels are read from the file.
            pixelData[i] = Pixel(red, green, blue); // we store pixels in vector.
        }
        image.close(); // the file is closed.
        isRead = true; // The read function is called
        return 1;      // reading from file is successful
    }

    else
    {
        // I didn't do any extra printing.
        return 0; // reading from file is not successful
    }
}

int Image::writePPM(string filename) const
{

    if (IsA_filename(filename) == false) // If the file name does not end with 4 letters or .ppm, it will throw an error.
    {
        // I didn't do any extra printing.
        // print to file is not successful
        return 0;
    }
    ofstream newimage(filename); // Output file stream class , variable writing to file

    newimage << "P3\n"; // The format is written to the file.

    newimage << width << " " << height << "\n"; // width and height are written to the file.

    newimage << RGB << "\n"; // The max pixel value is written.

    for (int i = 0; i < height; i++) // pixels based on width and height are written to the file. Writing under it makes it difficult to see.
    {
        for (int j = 0; j < width; j++)
        {
            int index = i * width + j;                       // Since it is a one-dimensional vector, the index variable is used to pick up where it left off.
            newimage << pixelData[index].getRed() << " ";    // With the get function, pixel values are called and printed to the file.
            newimage << pixelData[index].getGreen() << " ";  // With the get function, pixel values are called and printed to the file.
            newimage << pixelData[index].getBlue() << "   "; // With the get function, pixel values are called and printed to the file.
        }
        newimage << endl;
    }
    newimage.close(); ////the file is closed.

    return 1; // print to file successful
}

void Image::GrayScale(float &num1, float &num2, float &num3)
{

    int grayScale; // variable holding the graying value

    for (int i = 0; i < height * width; i++)
    {
        grayScale = (int)(num1 * pixelData[i].getRed()) + (num2 * pixelData[i].getGreen()) + (num3 * pixelData[i].getBlue());
        if (grayScale > 255)
            grayScale = 255;
        pixelData[i] = Pixel(grayScale, grayScale, grayScale); // As a result of the equation, a value is obtained and this value replaces the red green blue values.
    }
}

bool Image::IsA_filename(string filename) const
{

    if (filename.size() < 5 || filename.substr(filename.size() - 4) != ".ppm") // An error is thrown if the entered entry is less than 5 and its extension is not .ppm.
    {
        // I didn't do any extra printing.
        return false;
    }
    return true; // otherwise it returns true.
}