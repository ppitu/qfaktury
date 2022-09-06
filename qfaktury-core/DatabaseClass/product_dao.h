#ifndef PRODUCTDAO_H
#define PRODUCTDAO_H

#include <memory>
#include <vector>

#include <QString>

class QSqlDatabase;
class Product;

class ProductDao final
{
public:
  explicit ProductDao(QSqlDatabase& database);
  void init() const;
  void addProduct(Product& product) const;
  void updateProduct(const Product& product) const;
  void removeProduct(int id) const;
  std::vector<Product> products() const;
  virtual ~ProductDao();

private:
  QSqlDatabase& database_;
};

#endif // PRODUCTDAO_H
