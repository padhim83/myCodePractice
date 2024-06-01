/* Open-close principle demonstrate 
Open for Extension - base abstract use to implement new concrete Class
Close for Modification - concrte classes need not to modify when new classes added 
*/
#include <iostream>
#include <vector>
#include <memory>


class CryptoGraphy
{
    public:
        virtual void Cryptotype() const = 0;
        virtual ~CryptoGraphy() = default;
};

class AesCrypto : public CryptoGraphy
{
    public:
        void Cryptotype() const{
            std::cout << " Aes CryptoType " << std::endl;
        }
};

class DesCrypto : public CryptoGraphy{
    public:
        void Cryptotype() const{
        std::cout << " Des CryptoType " << std::endl;
    }

};

void listCryptoSuite(std::vector<std::shared_ptr<CryptoGraphy>>& cryptosuites)
{
    for(const auto &crypt: cryptosuites)
    {
        crypt->Cryptotype();
    }

}
int main()
{
    std::vector<std::shared_ptr<CryptoGraphy>> cryptoSuite;
    cryptoSuite.push_back(std::make_shared<AesCrypto>());
    cryptoSuite.push_back(std::make_shared<DesCrypto>());
    listCryptoSuite(cryptoSuite);
    return 0;
}