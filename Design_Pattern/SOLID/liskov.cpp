/* It states that objects of a superclass should be replaceable with objects of 
a subclass without affecting the correctness of the program */
#include <iostream>
#include <map>
#include <memory>

class Cryptography
{
    public:
        virtual void Signature() const = 0;
};

class SymmetricCrypto : public Cryptography
{
    private:
        std::string aesKey;
    public:
        SymmetricCrypto(const std::string& key) : aesKey(key) {}
        void Encrypt()
        {
            std::cout << " Symmetric Encryption " << std::endl;
        }
        void Signature() const
        {
            std::cout << "signing algo not supported in symmetric key = " << this->aesKey << std::endl;
        }
};

class AssymetricCrypto : public Cryptography
{
    private:
        std::string privateK;
        std::string publicK;
    public:
        AssymetricCrypto(const std::string& privateKey,const std::string& publickey) :
            privateK(privateKey) , publicK(publickey){}
        void Encrypt()
        {
            std::cout << " ASymmetric Encryption " << std::endl;
        }
        void Signature() const
        {
            std::cout << "signing algo supported with privateKey = " << this->privateK << " and Public key = " << this->publicK <<std::endl;
        }
};

void IsSignatureSupported(std::multimap<std::string, std::shared_ptr<Cryptography>>& cryptoSuites)
{
    for(const auto& crypto : cryptoSuites)
    {
        std::cout<< "Crypto Type = " << crypto.first << std::endl;
        crypto.second->Signature();
    }
}

int main()
{
    std::multimap<std::string, std::shared_ptr<Cryptography>> cryptoSuite;
    cryptoSuite.insert(std::make_pair(std::string("Symkey"), std::make_shared<SymmetricCrypto>(std::string("Aeskey"))));
    cryptoSuite.insert(std::make_pair(std::string("Symkey"), std::make_shared<SymmetricCrypto>(std::string("Deskey"))));
    cryptoSuite.insert(std::make_pair(std::string("ASymkey"), std::make_shared<AssymetricCrypto>(std::string("rsaPrivKey"), std::string("rsaPublicKey"))));
    cryptoSuite.insert(std::make_pair(std::string("ASymkey"), std::make_shared<AssymetricCrypto>(std::string("eccPrivKey"), std::string("eccPublicKey"))));
    IsSignatureSupported(cryptoSuite);
    return 0;
}

