#include "ExceptionCase.h"

#include "Exception/Exception.h"
#include <iostream>

using namespace NPLib;
using namespace std;

void ExceptionCase()
{
    try {
        THROW_EXCEPTION(InvalidParameterException, "Error Test");
//        throw Exception("error_test", __FILE__, __LINE__);
//        throw Exception("test");
//        throw Exception(__FILE__, __LINE__);
    } catch(const ArithmeticException& e) {
        cout << "catch ArithmeticException" << endl;
        cout << e.message() << endl;
        cout << e.location() << endl;
    } catch(const NullPointerException& e) {
        cout << "catch NullPointerException" << endl;
        cout << e.message() << endl;
        cout << e.location() << endl;
    } catch(const IndexOutOfBoundsException& e) {
        cout << "catch IndexOutOfBoundsException" << endl;
        cout << e.message() << endl;
        cout << e.location() << endl;
    } catch(const NoEnoughMemoryException& e) {
        cout << "catch NoEnoughMemoryException" << endl;
        cout << e.message() << endl;
        cout << e.location() << endl;
    } catch(const InvalidParameterException& e) {
        cout << "catch InvalidParameterException" << endl;
        cout << e.message() << endl;
        cout << e.location() << endl;
    } catch(const Exception& e) {
        cout << "catch Exception" << endl;
        cout << e.message() << endl;
        cout << e.location() << endl;
    }
    InvalidOperationExcpetion* e = new InvalidOperationExcpetion("InvalidOperationException", __FILE__, __LINE__);
    delete e;
}
