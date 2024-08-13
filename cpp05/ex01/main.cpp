#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try
    {
        Bureaucrat john("John", 50);
        Bureaucrat alice("Alice", 10);
        Bureaucrat bob("Bob", 1);
        Bureaucrat charlie("Charlie", 150);

        std::cout << john << std::endl;
        std::cout << alice << std::endl;
        std::cout << bob << std::endl;
        std::cout << charlie << std::endl;

        Form formA("FormA", 45, 30);
        Form formB("FormB", 10, 5);
        Form formC("FormC", 1, 1);
        Form formD("FormD", 150, 150);

        std::cout << formA << std::endl;
        std::cout << formB << std::endl;
        std::cout << formC << std::endl;
        std::cout << formD << std::endl;

        std::cout << std::endl;
        std::cout << "Trying to sign FormA with John (grade 50):\n";
        john.signForm(formA);
        std::cout << formA << std::endl;

        std::cout << std::endl;
        std::cout << "Trying to sign FormB with Alice (grade 10):\n";
        alice.signForm(formB);
        std::cout << formB << std::endl;

        std::cout << std::endl;
        std::cout << "Trying to sign FormC with Bob (grade 1):\n";
        bob.signForm(formC);
        std::cout << formC << std::endl;

        std::cout << std::endl;
        std::cout << "Trying to sign FormD with Charlie (grade 150):\n";
        try
        {
            charlie.signForm(formD);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << formD << std::endl;

        std::cout << std::endl;
        std::cout << "Trying to sign already signed FormC with Alice (grade 10):\n";
        try
        {
            alice.signForm(formC);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << std::endl;
        std::cout << "Incrementing John's grade (50 -> 45):\n";
        for (int i = 0; i < 5; i++) john.incrementGrade();
        std::cout << john << std::endl;

        std::cout << std::endl;
        std::cout << "Decrementing Charlie's grade (150 -> 151):\n";
        try
        {
            charlie.decrementGrade();
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << std::endl;
        std::cout << "Trying to create FormE with gradeToSign 0:\n";
        try
        {
            Form formE("FormE", 0, 50);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << std::endl;
        std::cout << "Trying to create FormF with gradeToExecute 151:\n";
        try
        {
            Form formF("FormF", 50, 151);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << std::endl;
        std::cout << "Creating and copying forms:\n";
        Form formG("FormG", 75, 75);
        Form formH = formG;
        Form formI("FormI", 100, 100);
        formI = formG; // all attributes except _isSigned are const, so its useless
        std::cout << formG << std::endl;
        std::cout << formH << std::endl;
        std::cout << formI << std::endl;

        std::cout << std::endl;
        std::cout << "Assigning and modifying Bureaucrats:\n";
        Bureaucrat dan("Dan", 120);
        Bureaucrat emily("Emily", 140);
        std::cout << dan << std::endl;
        std::cout << emily << std::endl;
        emily = dan;
        std::cout << emily << std::endl;
        for (int i = 0; i < 10; i++) emily.incrementGrade();
        std::cout << emily << std::endl;

    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return (0);
}
