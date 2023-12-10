#include "imageanalyzer.h"
#include <QDebug>
#include <opencv2/opencv.hpp>

ImageAnalyzer::ImageAnalyzer()
{

}

void ImageAnalyzer::analyzeImage(QImage image)
{
    qDebug() <<"analyzeImage";
    cv::Mat testImage(image.height(), image.width(),CV_8UC4, image.bits());

    cv::Ptr<cv::ml::ANN_MLP> mlp = cv::ml::ANN_MLP::load("/home/cvlab/trained_digit_model.xml");

    cv::cvtColor(testImage,testImage,cv::COLOR_RGBA2GRAY);
    // Load the image you want to classify

    cv::resize(testImage,testImage,cv::Size(28,28));
    // Flatten the image
    cv::Mat flattenedImage = testImage.reshape(1, 1);
    cv::Mat input;
    flattenedImage.convertTo(input, CV_32F);

    // Perform prediction
    cv::Mat output;
    mlp->predict(input, output);

    std::cout<<output<<std::endl;
    // Find the class with the highest probability
    cv::Point classIdPoint;
    double confidence;
    cv::minMaxLoc(output, nullptr, &confidence, nullptr, &classIdPoint);

    int predictedClass = classIdPoint.x;

    // Display the result
    std::cout << "Predicted class: " << predictedClass << " with confidence: " << confidence << std::endl;

    QString result = "Recognized digit is " + QString::number(predictedClass);
    setResultStr(result);

}

QString ImageAnalyzer::resultStr() const
{
    return m_resultStr;
}

void ImageAnalyzer::setResultStr(const QString &newResultStr)
{
    if (m_resultStr == newResultStr)
        return;
    m_resultStr = newResultStr;
    Q_EMIT resultStrChanged();
}
