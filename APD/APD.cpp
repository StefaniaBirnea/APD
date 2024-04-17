#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>

using namespace cv;
using namespace std;
using namespace std::chrono;

int main() {
    // Incarca imaginea
    cv::Mat image = cv::imread("poza.jpg");

    // Măsurarea timpului de inceput
    auto start = high_resolution_clock::now();

    // Verifica daca imaginea a fost incarcata cu succes
    if (image.empty()) {
        std::cerr << "Eroare la incarcarea imaginii!" << std::endl;
        return -1;
    }

    // Aplica un filtru de blur
    cv::Mat filteredImage;
    cv::GaussianBlur(image, filteredImage, cv::Size(5, 5), 0);

    // Afiseaza imaginile
    cv::namedWindow("Imagine Originala", cv::WINDOW_NORMAL);
    cv::imshow("Imagine Originala", image);

    cv::namedWindow("Imagine Filtrata", cv::WINDOW_NORMAL);
    cv::imshow("Imagine Filtrata", filteredImage);

    // Masurarea timpului de final
    auto stop = high_resolution_clock::now();

    // Calcularea timpului total de rulare
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Timpul total de rulare: " << duration.count() << " milisecunde." << endl;

    // Asteapta apasarea unei taste pentru a inchide fereastrele
    cv::waitKey(0);

    return 0;
}
