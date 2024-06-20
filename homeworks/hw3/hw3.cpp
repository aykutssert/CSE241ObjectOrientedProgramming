#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Pixel // the class I created to hold the pixels of the image
{

public:
    Pixel() : red(0), green(0), blue(0) {}                                                                      // Default constructor
    Pixel(const int _red, const int _green = 0, const int _blue = 0) : red(_red), green(_green), blue(_blue) {} // constructor called when reading value from file

    inline int getRed() const { return red; }     // Since variables are private, getter functions are functional for use in other classes.
    inline int getGreen() const { return green; } // other getter
    inline int getBlue() const { return blue; }   // other getter

    void setRed(int _red);     // Setter
    void setGreen(int _green); // Setter
    void setBlue(int _blue);   // Setter
    int red, green, blue;      // variables holding pixel values
};

class Image /// A Image Class
{
private:
    bool isRead;             // Did the read function work or not?
    int width;               // width*height shows how many pixels there are
    int height;              // width*height shows how many pixels there are
    int RGB;                 // max pixel value
    vector<Pixel> pixelData; // 1D vector with pixel class

public:
    Image();                     // Default Image constructor
    Image(const string);         // It sends a string to the readPpm function.
    Image(const int, const int); // makes all pixel values 255. Pixels turn white.
    Image(const Image &cpy);     // Copy Constructor

    int readPPM(const string filename);        // function to retrieve data from file
    int writePPM(const string filename) const; // function to write data to file
    // void GrayScale(const float num1, const float num2, const float num3); // function to gray out pixels data

    void fillData(Pixel *first, Pixel *last, const Pixel &val); // This function was used to make the pixels 255 by traversing all the values. It goes from the beginning to the end of the vector.

    bool IsA_filename(string filename) const; // Function used in write and read functions, controlling filename input from user *(for extra error)
    bool getIsRead() const { return isRead; } // Since the variable isRead is private, the get function is written because we need to access this variable in the Menu class.

    inline int getWidth() const { return width; }       // it returns width member data
    inline int getHeight() const { return height; }     // it returns height member data
    vector<Pixel> getData() const { return pixelData; } // it returns pixelData member data

    void setData(vector<Pixel> v); // Setter for pixelData
    void setWidth(int _width);     // Setter for width
    void setHeight(int _height);   // Setter for height
    void printDimension();         // prints dimensions to screen

    Image &operator=(const Image &other); // Assignment operator

    const Pixel &operator[](int index) const; // Read-only operator
    Pixel &operator[](int index);             // returns an element of the vector by reference

    Image operator+(const Image &second); // adds two classes
    Image operator-(const Image &second); // subs two classes

    friend ostream &operator<<(ostream &os, const Image &image); // prints all data to the screen

    int &operator()(const int row, const int col, const int channel);  //Returns pixel value based on channel value
};

// adds two data and writes it to a file
int test_addition(const string filename_image1, const string filename_image2, const string filename_image3)
{

    Image image1(filename_image1);
    Image image2(filename_image2);

    if (image1.getIsRead() == false || image2.getIsRead() == false)
        return 0;
    if (image1.getWidth() != image2.getWidth() || image1.getHeight() != image2.getHeight())
        return 0;
    Image image3 = image1 + image2;

    if (image3.writePPM(filename_image3) == 0)
        return 0;

    return 1;
}

// subs two data and writes it to a file
int test_subtraction(const string filename_image1, const string filename_image2, const string filename_image3)
{
    Image image1(filename_image1);
    Image image2(filename_image2);

    if (image1.getIsRead() == false || image2.getIsRead() == false)
        return 0;
    if (image1.getWidth() != image2.getWidth() || image1.getHeight() != image2.getHeight())
        return 0;
    Image image3 = image2 - image1;

    if (image3.writePPM(filename_image3) == 0)
        return 0;

    return 1;
}

// It browses all the data and swaps it according to the input value.
int swap_channels(Image &image_object_to_be_modified, const int swap_choice)
{
    if (swap_choice == 1 || swap_choice == 2 || swap_choice == 3)
    {
        int row = image_object_to_be_modified.getHeight();
        int col = image_object_to_be_modified.getWidth();
        int red, green, blue;
        for (int i = 1; i <= row; ++i)
        {
            for (int j = 1; j <= col; ++j)
            {

                if (swap_choice == 1)
                {
                    red = image_object_to_be_modified(i, j, 1);
                    image_object_to_be_modified(i, j, 1) = image_object_to_be_modified(i, j, 2);
                    image_object_to_be_modified(i, j, 2) = red;
                }
                if (swap_choice == 2)
                {
                    red = image_object_to_be_modified(i, j, 1);
                    image_object_to_be_modified(i, j, 1) = image_object_to_be_modified(i, j, 3);
                    image_object_to_be_modified(i, j, 3) = red;
                }
                if (swap_choice == 3)
                {
                    green = image_object_to_be_modified(i, j, 2);
                    image_object_to_be_modified(i, j, 2) = image_object_to_be_modified(i, j, 3);
                    image_object_to_be_modified(i, j, 3) = green;
                }
            }
        }
        return 1;
    }
    else
        return 0;
}

// It draws data from the file and writes it to the screen.
int test_print(const string filename_image1)
{

    Image image(filename_image1);

    if (image.getIsRead() == false)
        return 0;

    cout << image;

    return 1;
}

// Tests the read-from-file function.
int read_ppm(const string source_ppm_file_name, Image &destination_object)
{

    destination_object.readPPM(source_ppm_file_name);
    if (destination_object.getIsRead() == true)
        return 1;
    else
        return 0;
}

// Tests the write-to-file function.
int write_ppm(const string destination_ppm_file_name, const Image &source_object)
{

    if (source_object.writePPM(destination_ppm_file_name) == 1)
        return 1;
    else
        return 0;
}

// It takes only one value of the data it will save and makes the others zero.
Image single_color(const Image &source, const int color_choice)
{

    Image newImage(source.getWidth(), source.getHeight());
    int row = newImage.getHeight();
    int col = newImage.getWidth();

    for (int i = 1; i <= row; ++i)
    {
        for (int j = 1; j <= col; ++j)
        {

            if (color_choice == 1)
            {
                newImage(i,j,1) = source[(i - 1) * source.getWidth() + (j - 1)].getRed();
                newImage(i,j,2) = 0;
                newImage(i,j,3) = 0;
            }
             if (color_choice == 2)
            {
                newImage(i,j,1) = 0;
                newImage(i,j,2) = source[(i - 1) * source.getWidth() + (j - 1)].getGreen();
                newImage(i,j,3) = 0;
            }
             if (color_choice == 3)
            {
                newImage(i,j,1) = 0;
                newImage(i,j,2) = 0;
                newImage(i,j,3) = source[(i - 1) * source.getWidth() + (j - 1)].getBlue();
            }

        }
    }

    
    return newImage;
}

int main(int argc, char **argv)
{
    if (argc == 4 || argc == 5)
    {

        int choice_number = atoi(argv[1]); // we converted the input to integer
        string ppm_file_name1 = argv[2];
        string ppm_file_name2 = argv[3];
        string ppm_file_name3;
        Image image;
        Image image2;
        switch (choice_number)
        {
        case 1:
            if (argc == 5)
            {
                ppm_file_name3 = argv[4];
                test_addition(ppm_file_name1, ppm_file_name2, ppm_file_name3);
            }
            else
                exit(1);
            break;
        case 2:
            if (argc == 5)
            {
                ppm_file_name3 = argv[4];
                test_subtraction(ppm_file_name1, ppm_file_name2, ppm_file_name3);
            }
            else
                exit(1);
            break;
        case 3:
            if (read_ppm(ppm_file_name1, image) == 1)
            {
                swap_channels(image, 2);
                write_ppm(ppm_file_name2, image);
            }
            break;
        case 4:
            if (read_ppm(ppm_file_name1, image) == 1)
            {
                swap_channels(image, 3);
                write_ppm(ppm_file_name2, image);
            }
            break;
        case 5:
            if (read_ppm(ppm_file_name1, image) == 1)
            {
                image2 = single_color(image, 1);
                write_ppm(ppm_file_name2, image2);
            }
            break;
        case 6:
            if (read_ppm(ppm_file_name1, image) == 1)
            {
                image2 = single_color(image, 2);
                write_ppm(ppm_file_name2, image2);
            }
            break;
        case 7:
            if (read_ppm(ppm_file_name1, image) == 1)
            {
                image2 = single_color(image, 3);
                write_ppm(ppm_file_name2, image2);
            }
            break;
        default:
            cout << "Invalid value\n";
            break;
        }
    }
    else
        exit(1);

    return 0;
}

void Pixel::setRed(int _red)
{
    if (_red < 0)
        _red = 0;
    if (_red > 255)
        _red = 255;
    red = _red;
}
void Pixel::setGreen(int _green)
{
    if (_green < 0)
        _green = 0;
    if (_green > 255)
        _green = 255;
    green = _green;
}
void Pixel::setBlue(int _blue)
{
    if (_blue < 0)
        _blue = 0;
    if (_blue > 255)
        _blue = 255;
    blue = _blue;
}
Image::Image()
{
    isRead = false;
    width = 0;
    height = 0;
    pixelData.resize(0);
}
Image::Image(const string filename)
{
    isRead = false;
    readPPM(filename);
}
Image::Image(const int _width, const int _height)
{
    if (_width < 0 || _height < 0)
        exit(1);
    isRead = false;
    this->width = _width;
    this->height = _height;
    pixelData.resize(width * height);
    fillData(&pixelData[0], &pixelData[0] + pixelData.size(), Pixel(255, 255, 255));
}

Image::Image(const Image &cpy)
{

    if (this != &cpy)
    {
        this->width = cpy.getWidth();
        this->height = cpy.getHeight();
        this->setData(cpy.getData());
    }
}

void Image::fillData(Pixel *first, Pixel *last, const Pixel &val)
{
    while (first != last)
    {
        *first = val;
        ++first;
    }
}

int Image::readPPM(const string filename) // read from file function
{

    // If the filename is incorrect

    if (IsA_filename(filename) == false) // If the file name does not end with 4 letters or .ppm, it will throw an error.
    {
        exit(1);
        return 0; // reading from file is not successful
    }

    // Successful

    ifstream image(filename); // Input file stream class , variable reading from file

    if (image.is_open()) // does the file open?
    {
        string type; // The variable that holds the ppm format. It should be P3.

        image >> type >> width >> height >> RGB; // READ FROM FILE

        if (type != "P3")
        {
            exit(1);
            return 0; // reading from file is not successful
        }
        if (width < 0 || height < 0)
        {
            exit(1);
            return 0; // reading from file is not successful
        }

        pixelData.resize(height * width); // we make space in the vector according to the width and height we get from the file.

        for (int i = 0; i < width * height; i++) // We are reading pixel by pixel. 1 pixel contains three values. Red, green and blue values.
        {
            int red, green, blue;          // variables holding pixel values
            image >> red >> green >> blue; // Pixels are read from the file.
            if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255)
                exit(1);

            this->operator[](i) = Pixel(red, green, blue); // we store pixels in vector.
        }
        image.close(); // the file is closed.
        isRead = true; // The read function is called
        return 1;      // reading from file is successful
    }

    // If the file does not open
    else
    {
        exit(1);
        return 0; // reading from file is not successful
    }
}

int Image::writePPM(const string filename) const
{
    // If the filename is incorrect
    if (IsA_filename(filename) == false) // If the file name does not end with 4 letters or .ppm, it will throw an error.
    {
        exit(1);
        return 0;
    }

    // Successfull
    ofstream newimage(filename); // Output file stream class , variable writing to file

    newimage << "P3\n"; // The format is written to the file.

    newimage << width << " " << height << "\n"; // width and height are written to the file.

    newimage << 255 << "\n"; // The max pixel value is written.

    for (int i = 0; i < height; i++) // pixels based on width and height are written to the file. Writing under it makes it difficult to see.
    {
        for (int j = 0; j < width; j++)
        {
            int index = i * width + j;                              // Since it is a one-dimensional vector, the index variable is used to pick up where it left off.
            newimage << this->operator[](index).getRed() << " ";    // With the get function, pixel values are called and printed to the file.
            newimage << this->operator[](index).getGreen() << " ";  // With the get function, pixel values are called and printed to the file.
            newimage << this->operator[](index).getBlue() << "   "; // With the get function, pixel values are called and printed to the file.
        }
        newimage << endl;
    }
    newimage.close(); // the file is closed.

    return 1; // print to file successful
}

void Image::setData(vector<Pixel> v)
{
    pixelData = v;
}

void Image::setWidth(int _width)
{
    if (_width < 0)
        _width = 0;

    width = _width;
}

void Image::setHeight(int _height)
{
    if (_height < 0)
        _height = 0;

    height = _height;
}

void Image::printDimension()
{
    cout << "Width: " << width << endl
         << "Height: " << height << endl;
}

Image &Image::operator=(const Image &other) //Assignment operator
{
    if (this != &other)
    {
        this->width = other.getWidth();
        this->height = other.getHeight();
        this->setData(other.getData());
        return *this;
    }
    else
        return *this;
}

const Pixel &Image::operator[](int index) const // Read-Only //Values called using operator
{

    if (index < 0 || index >= (width * height))
        exit(1);

    return pixelData[index];
}

Pixel &Image::operator[](int index) //Values called using operator
{

    if (index < 0 || index >= (width * height))
        exit(1);

    return pixelData[index];
}

Image Image::operator+(const Image &second)
{

    if (this->getWidth() == second.getWidth() && this->getHeight() == second.getHeight())
    {

        vector<Pixel> newData(getWidth() * getHeight());

        for (int i = 0; i < getWidth() * getHeight(); ++i)
        {
            int red = this->operator[](i).getRed() + second[i].getRed(); //Values are called and adds using operator
            int green = this->operator[](i).getGreen() + second[i].getGreen(); //Values are called and adds using operator
            int blue = this->operator[](i).getBlue() + second[i].getBlue(); //Values are called and adds using operator

            if (red > 255)
                red = 255;
            if (green > 255)
                green = 255;
            if (blue > 255)
                blue = 255;

            newData[i] = Pixel(red, green, blue);
        }

        Image image(width, height);

        image.setData(newData);

        return image;
    }
    else
    {
        Image image;
        return image;
    }
}

Image Image::operator-(const Image &second)
{

    if (this->getWidth() == second.getWidth() && this->getHeight() == second.getHeight())
    {

        vector<Pixel> newData(getWidth() * getHeight());

        for (int i = 0; i < getWidth() * getHeight(); ++i)
        {
            int red = this->operator[](i).getRed() - second[i].getRed(); //Values are called and subtracted using operator
            int green = this->operator[](i).getGreen() - second[i].getGreen(); //Values are called and subtracted using operator
            int blue = this->operator[](i).getBlue() - second[i].getBlue(); //Values are called and subtracted using operator
            if (red < 0)
                red = 0;
            if (green < 0)
                green = 0;
            if (blue < 0)
                blue = 0;

            newData[i] = Pixel(red, green, blue);
        }

        Image image(width, height);
        image.setData(newData);
        return image;
    }
    else
    {
        Image image;
        return image;
    }
}

ostream &operator<<(ostream &os, const Image &image)
{

    os << "P3" << endl;
    os << image.getWidth() << " " << image.getHeight() << endl;
    os << "255\n";

    for (int i = 0; i < image.getWidth(); ++i) // pixels based on width and height are written to the file. Writing under it makes it difficult to see.
    {
        for (int j = 0; j < image.getHeight(); ++j)
        {
            int index = i * image.getWidth() + j;  // Since it is a one-dimensional vector, the index variable is used to pick up where it left off.
            os << image[index].getRed() << " ";    // With the get function, pixel values are called and printed to the file.
            os << image[index].getGreen() << " ";  // With the get function, pixel values are called and printed to the file.
            os << image[index].getBlue() << "   "; // With the get function, pixel values are called and printed to the file.
        }
        os << endl;
    }

    return os;
}

int &Image::operator()(const int row, const int col, const int channel)
{
    if (row <= 0 || row > height || col <= 0 || col > width)
        exit(1);

    int index;

    index = (row - 1) * getWidth() + (col - 1); //Index value created to adapt 2d vector to 1d

    if (channel == 1)
        return this->operator[](index).red;
    if (channel == 2)
        return this->operator[](index).green;
    if (channel == 3)
        return this->operator[](index).blue;
    else
        exit(1);
}

/*
void Image::GrayScale(const float num1, const float num2, const float num3)
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
*/
bool Image::IsA_filename(const string filename) const
{

    if (filename.size() < 5 || filename.substr(filename.size() - 4) != ".ppm") // An error is thrown if the entered entry is less than 5 and its extension is not .ppm.
    {
        exit(1);
        return false;
    }
    return true; // otherwise it returns true.
}