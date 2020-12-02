#ifndef __PRODUCT_H
#define __PRODUCT_H
class Product
{

public:
	//***************************Declarations*************************************
	enum ProductType {Kids,Electronics,Office,Clothes};
	//***************************Constructors*************************************
	Product(const char* name_of_poduct, int price_of_product, ProductType product_type);
	Product() = default;
	//***************************Copy Ctor****************************************
	Product(const Product& other);
	//***************************Destructor***************************************
	~Product() {delete[] this->nameOfPoduct;}
	//***************************Getters & Setters********************************
	char* GetNameOfProduct() const {return this->nameOfPoduct;}
	int GetPriceOfProduct() const {return this->priceOfProduct;}
	const char* GetProductType() const { return productTypeStr[productType]; }
	void SetPriceOfProduct(int price_of_product) { this->priceOfProduct = price_of_product; }
	void SetProductType(ProductType product_type) {this->productType = product_type;}
	void SetNameOfProduct(char* name_of_poduct);
	//****************************************************************************
private:
	static const char* productTypeStr[4];
	char* nameOfPoduct{};
	int priceOfProduct;
	ProductType productType;
};
#endif 



