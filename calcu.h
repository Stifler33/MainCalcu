
#ifndef MAINCALCU_CALCU_H
#define MAINCALCU_CALCU_H
#include <QMainWindow>
#include <QtWidgets/QLineEdit>
#include <iostream>
#include <QString>
#include <exception>
class Calcu: public QMainWindow
{
    Q_OBJECT
    constexpr static const std::initializer_list<char> _sing = {'+', '-', '*', '/'};
    auto type(auto a, auto b, char sing){
        if (sing == '+'){
           return a + b;
        }
        if (sing == '-'){
            return a - b;
        }
        if (sing == '*'){
            return a * b;
        }
        if (sing == '/'){
            return a / b;
        }
    }
    std::string result(std::string& _first,std::string& _second){
        try {
            if ((action == '/' && !dot) &&(std::stoi(_second) == 0 || std::stoi(_first) == 0)){
                throw 1;
            }
            if (dot) {
                auto result = type(std::stod(_first), std::stod(_second), action);
                first = std::to_string(result);
                return std::to_string(result);
            } else if (dot && std::stoi(_first) % std::stoi(_second) != 0) {
                auto result = type(std::stod(_first), std::stod(_second), action);
                first = std::to_string(result);
                return std::to_string(result);
            } else if (!dot && action != '/' && std::stoi(_first) % std::stoi(_second) != 0){
                auto result = type(std::stoi(_first), std::stoi(_second), action);
                first = std::to_string(result);
                return std::to_string(result);
            } else if (!dot && action == '/' && std::stoi(_first) % std::stoi(_second) != 0){
                auto result = type(std::stod(_first), std::stod(_second), action);
                first = std::to_string(result);
                return std::to_string(result);
            } else {
                auto result = type(std::stoi(_first), std::stoi(_second), action);
                first = std::to_string(result);
                return std::to_string(result);
            }
        }
        catch(int i){
            lineEdit->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
            return "ERROR: division by zero !";
        }
        catch(std::invalid_argument& a){
            lineEdit->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
            return "ERROR: invalid argument";
        }
    }
public:
    Calcu(QWidget *widget = nullptr): QMainWindow(widget){}
    QLineEdit *lineEdit = nullptr;
    void plus();
    std::string first;
    std::string second;
    char action;
    bool dot = false;
    bool transition = false;
public slots:
    void slot0(){
    if (!transition){
        first += "0";
    }else second += "0";
    lineEdit->setText(lineEdit->text() + "0");
};
    void slot_dot(){
        if (!transition){
            first += ".";
        }else second += ".";
        lineEdit->setText(lineEdit->text() + ".");
        dot = true;
    };
    void slot_result(){
        lineEdit->setText(result(first, second).c_str());
        action = 0;
        second.clear();
        dot = false;
    };
    void slot1(){
        if (!transition){
            first += "1";
        }else second += "1";
        lineEdit->setText(lineEdit->text() + "1");
    };
    void slot2(){
        if (!transition){
            first += "2";
        }else second += "2";
        lineEdit->setText(lineEdit->text() + "2");
    };
    void slot3(){
        if (!transition){
            first += "3";
        }else second += "3";
        lineEdit->setText(lineEdit->text() + "3");
    };
    void slot4(){
        if (!transition){
            first += "4";
        }else second += "4";
        lineEdit->setText(lineEdit->text() + "4");
    };
    void slot5(){
        if (!transition){
            first += "5";
        }else second += "5";
        lineEdit->setText(lineEdit->text() + "5");
    };
    void slot6(){
        if (!transition){
            first += "6";
        }else second += "6";
        lineEdit->setText(lineEdit->text() + "6");
    };
    void slot7(){
        if (!transition){
            first += "7";
        }else second += "7";
        lineEdit->setText(lineEdit->text() + "7");
    };
    void slot8(){
        if (!transition){
            first += "8";
        }else second += "8";
        lineEdit->setText(lineEdit->text() + "8");
    };
    void slot9(){
        if (!transition){
            first += "9";
        }else second += "9";
        lineEdit->setText(lineEdit->text() + "9");
    };
    void slot_plus(){
        action = '+';
        lineEdit->setText(lineEdit->text() + "+");
        transition = true;
    };
    void slot_minus(){
        action = '-';
        lineEdit->setText(lineEdit->text() + "-");
        transition = true;
    };
    void slot_multiply(){
        action = '*';
        lineEdit->setText(lineEdit->text() + "*");
        transition = true;
    };
    void slot_division(){
        action = '/';
        lineEdit->setText(lineEdit->text() + "/");
        transition = true;
    };
    void slot_clear(){
        lineEdit->setStyleSheet(QString::fromUtf8("color:rgb(0, 170, 0)"));
        action = 0;
        first.clear();
        second.clear();
        transition = false;
        dot = false;
        lineEdit->clear();
    };
    void slot_pressed(){
        std::string line = lineEdit->text().toStdString();
        auto checkDot = [](char i){return i == '.';};
        dot = '.' == *std::find_if(line.begin(), line.end(), checkDot);
        for (auto i : _sing){
            if (i == line[line.find(i)]){
                action = i;
            }
        }
        first = line.substr(0, line.find(*std::find(line.begin(), line.end(), action)));
        second = line.substr(line.find(*std::find(line.begin(), line.end(), action)) + 1, line.size());
        slot_result();
    }
};
#endif //MAINCALCU_CALCU_H
