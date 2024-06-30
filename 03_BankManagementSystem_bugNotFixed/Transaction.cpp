#include "Transaction.h"

void Transaction::serialize(std::ofstream& out) const {
    size_t typeLength = type.size();
    out.write(reinterpret_cast<const char*>(&typeLength), sizeof(typeLength));
    out.write(type.c_str(), typeLength);
    out.write(reinterpret_cast<const char*>(&amount), sizeof(amount));
}

void Transaction::deserialize(std::ifstream& in) {
    size_t typeLength;
    in.read(reinterpret_cast<char*>(&typeLength), sizeof(typeLength));
    type.resize(typeLength);
    in.read(&type[0], typeLength);
    in.read(reinterpret_cast<char*>(&amount), sizeof(amount));
}
