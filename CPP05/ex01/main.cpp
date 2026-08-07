#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(){

    Form f1("Form 1",60,50);
    Bureaucrat b1("Bureaucrat 1",50);
    Bureaucrat b2("Bureaucrat 2",50);
    b1.signForm(f1);
    b1.signForm(f1);
}