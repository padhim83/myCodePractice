#include <iostream>
#include <typeinfo>
#include <exception>

class EncryptionType {
public:
    virtual ~EncryptionType() {} // Polymorphic base class needs a virtual destructor
    virtual void Encrypt() const = 0; // Pure virtual function
};

class AesSymetric : public EncryptionType {
public:
    void Encrypt() const override {
        std::cout << "AesSymetric encryption type" << std::endl;
    }
    void fetch() const {
        std::cout << "Fetching symmetric encryption type" << std::endl;
    }
};

class EccAsymetric : public EncryptionType {
public:
    void Encrypt() const override {
        std::cout << "EccAsymetric encryption type" << std::endl;
    }
    void Digitalsign() const {
        std::cout << "support digital signature" << std::endl;
    }
};

// Custom exception for type casting errors
class BadEncryptionCast : public std::exception {
public:
    BadEncryptionCast(const std::string& type) : message("Bad cast to type: " + type) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
private:
    std::string message;
};

class CustomBadCastException : public std::bad_cast {
public:
    CustomBadCastException() noexcept {}

    const char* what() const noexcept override {
        return "CustomBadCastException: Dynamic cast failed.";
    }
};

void TestCryptographicCast(EncryptionType& encRef)
{
    try {
       EccAsymetric& Ecckey = dynamic_cast<EccAsymetric&>(encRef);
       Ecckey.Digitalsign();
    } 
    catch (const std::bad_cast& e) {
        std::cerr << "BadEncryptionCast exception caught: " << e.what() << std::endl;
    }
}

void CryptographicAction(EncryptionType* encPtr) {
    try {
        if (AesSymetric* Aeskey = dynamic_cast<AesSymetric*>(encPtr)) {
            Aeskey->Encrypt();
            Aeskey->fetch();
        }
        else if (EccAsymetric* Ecckey = dynamic_cast<EccAsymetric*>(encPtr)) {
            Ecckey->Encrypt();
            Ecckey->Digitalsign();
        }
        else {
            if (encPtr == nullptr)
            {
                throw BadEncryptionCast(std::string("Nullptr item"));

            }
            else{
                // Throw an exception if the animal is of an unknown type
                throw BadEncryptionCast(typeid(*encPtr).name());
            }

        }
    }
    catch (const BadEncryptionCast& e) {
        std::cerr << "BadEncryptionCast exception caught: " << e.what() << std::endl;
    }
}
void dynamicConstCast(int* data)
{
    *data = 20;
}

int main() {
    AesSymetric aeskey;
    EccAsymetric eccKey;
    int value = 1;
    const int *const dataPtr = &value;
    dynamicConstCast(const_cast<int *>(dataPtr));
    std::cout << "with const_cast ness removal update variable=" << value <<" pointer value= "<< *dataPtr<< std::endl;

    EncryptionType* Encryptions[] = { &aeskey, &eccKey, nullptr };

    for (EncryptionType* Encryption : Encryptions) {
            CryptographicAction(Encryption);
    }

    std::cout << "typecasting Reference item" <<std::endl;
    TestCryptographicCast(aeskey);

    return 0;
}
