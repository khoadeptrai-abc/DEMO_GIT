#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<sstream>
#include<ctime>

using namespace std;


class CTime
{
private:
	int m_Hour;
	int m_Minute;
	int m_Second;
public:
	CTime() {
		m_Hour = 0;
		m_Minute = 0;
		m_Second = 0;
	}
	CTime(const CTime& other) {
		m_Hour = other.m_Hour;
		m_Minute = other.m_Minute;
		m_Second = other.m_Second;
	}
	CTime(int hour, int minute, int second) {
		this->m_Hour = hour;
		this->m_Minute = minute;
		this->m_Second = second;
	}

	int getSecond() const {
		return m_Second;
	}
	int getMinute() const {
		return m_Minute;
	}
	int getHour() const {
		return m_Hour;
	}

	void  setSecond(int second) {
		m_Second = second;
	}
	void setMinute(int minute) {
		m_Minute = minute;
	}
	void setHour(int hour) {
		m_Hour = hour;
	}

	
	void inputTime(string str) {
		char c;
		stringstream ss(str);
		ss >> this->m_Second >> c >> this->m_Minute >> c >> this->m_Hour;
	};

	friend ostream& operator<<(ostream& os, CTime other);
	friend istream& operator>>(istream& is, CTime& other);
};
ostream& operator<<(ostream& os, CTime other) {
	os << setfill('0') << setw(2) << other.m_Hour << ":" << setw(2) << other.m_Minute << ":" << setw(2)<< other.m_Second;
	return os;
}

istream& operator>>(istream& is, CTime& other) {
	char delimiter;
	is >> other.m_Second >> delimiter >> other.m_Minute >> delimiter >> other.m_Hour;
	return is;
}


class CDate
{
private:
	int m_Day, m_Month, m_Year;
public:
	CDate() : m_Day(0), m_Month(0), m_Year(0) {}


	CDate(int d, int m, int y) : m_Day(d), m_Month(m), m_Year(y) {}

	CDate(const CDate& other) : m_Day(other.m_Day), m_Month(other.m_Month), m_Year(other.m_Year) {}



	int getDay() const {
		return m_Day;
	}
	int getMonth() const {
		return m_Month;
	}
	int getYear() const {
		return m_Year;
	}

	void  setDay(int day) {
		m_Day = day;
	}
	void setMonth(int month) {
		m_Month = month;
	}
	void setYear(int year) {
		m_Year = year;
	}

	bool operator<(const CDate& other)const {
		if (m_Year < other.m_Year) {
			return true;
		}
		else if (m_Year == other.m_Year) {
			if (m_Month < other.m_Month) {
				return true;
			}
			else if (m_Month == other.m_Month) {
				if (m_Day < other.m_Day) {
					return true;
				}
			}
		}
		return false;
	}

	bool operator>(const CDate& other)const {
		if (m_Year > other.m_Year) {
			return true;
		}
		else if (m_Year == other.m_Year) {
			if (m_Month > other.m_Month) {
				return true;
			}
			else if (m_Month == other.m_Month) {
				if (m_Day > other.m_Day) {
					return true;
				}
			}
		}
		return false;
	}
	void inputDate(string str) {
		char c;
		stringstream ss(str);
		ss >> this->m_Day >> c >> this->m_Month >> c >> this->m_Year;
	};

	friend ostream& operator<<(ostream& os, CDate other);
	friend istream& operator>>(istream& is, CDate& other);
};
ostream& operator<<(ostream& os, CDate other) {
	os << setfill('0') << setw(2) << other.m_Day << "/" << setw(2) << other.m_Month << "/" << other.m_Year;
	return os;
}

istream& operator>>(istream& is, CDate& other) {
	char delimiter;
	is >> other.m_Day >> delimiter >> other.m_Month >> delimiter >> other.m_Year;
	return is;
}


class CProduct {
protected:
	string m_Code;
	string m_Name;
	string m_Producer;
	float m_Price;
	int m_Quantity;
public:


	CProduct() {
		m_Code = "";
		m_Name = "";
		m_Producer = "";
		m_Price = 0.0f;
		m_Quantity = 0;
	}


	CProduct(string code, string name, string producer, float price,int quantity) {
		m_Code = code;
		m_Name = name;
		m_Producer = producer;
		m_Price = price;
		m_Quantity = quantity;
	}


	CProduct(const CProduct& other) {
		m_Code = other.m_Code;
		m_Name = other.m_Name;
		m_Producer = other.m_Producer;
		m_Price = other.m_Price;
		m_Quantity = other.m_Quantity;
	}

	string getCode() const { return m_Code; }
	string getName() const { return m_Name; }
	string getProducer() const { return m_Producer; }
	float getPrice() const { return m_Price; }
	int getQuantity() const { 
		return m_Quantity;
	}

	void setCode(const string& code) { m_Code = code; }
	void setName(const string& name) { m_Name = name; }
	void setProducer(const string& producer) { m_Producer = producer; }
	void setPrice(float price) {m_Price = price;}
	void setQuantity(int quantity) {
		m_Quantity = quantity;
	}


	virtual void Input() {
		getline(cin, m_Code, '(');
		m_Code.erase(m_Code.begin() + m_Code.length() - 1);//x�a kho?ng tr?ng sau m� 

		getline(cin, m_Name, ',');
		cin.seekg(1, ios::cur);

		getline(cin, m_Producer, ',');
		cin.seekg(1, ios::cur);

		string price;
		getline(cin, price, ',');
		m_Price = stof(price);
		cin.seekg(1, ios::cur);
	}

	virtual void Output() {
		cout << m_Name << ", " << m_Producer << ", ";
		cout<<  static_cast<int>(m_Price) << ", " << m_Quantity << "." << endl;
	}
};

class CElectronic :public CProduct
{
private:
	string m_Warranty;
	string m_ElectricPower;

public:
	CElectronic() {
		m_Warranty = "";
		m_ElectricPower = "";
	}

	string getWarranty() const { return m_Warranty; }
	string getElectricPower() const { return m_ElectricPower; }

	void setWarranty(const string& warranty) { m_Warranty = warranty; }
	void setElectricPower(const string& electricPower) { m_ElectricPower = electricPower; }

	void Input()override {
		CProduct::Input();
		getline(cin, m_Warranty, ',');
		cin.seekg(1, ios::cur);

		getline(cin, m_ElectricPower, ',');
		cin.seekg(1, ios::cur);

		string quantity;
		getline(cin, quantity, ')');
		m_Quantity = stoi(quantity);
		cin.ignore();
	}
};



class CTerracotta :public CProduct
{
private:
	string m_Material;
public:
	CTerracotta() {
		m_Material = "";
	}

	string getMaterial() const { return m_Material; }

	void setMaterial(const string& material) { m_Material = material; }

	void Input()override {
		CProduct::Input();
		getline(cin, m_Material, ',');
		cin.seekg(1, ios::cur);

		string quantity;
		getline(cin, quantity, ')');
		m_Quantity = stoi(quantity);
		cin.ignore();
	}

};

class CFood :public CProduct
{
private:
	CDate m_MfgDate;
	CDate m_ExpDate;

public:
	CFood() {
		
	}

	CDate getMfgDate() const { return m_MfgDate; }
	CDate getExpDate() const { return m_ExpDate; }

	void setMfgDate(const CDate& mfgDate) { m_MfgDate = mfgDate; }
	void setExpDate(const CDate& expDate) { m_ExpDate = expDate; }


	void Input()override {
		CProduct::Input();
		string date;
		getline(cin, date, ',');
		m_MfgDate.inputDate(date);
		cin.seekg(1, ios::cur);

		getline(cin, date, ',');
		m_ExpDate.inputDate(date);
		cin.seekg(1, ios::cur);

		string quantity;
		getline(cin, quantity, ')');
		m_Quantity = stoi(quantity);
		cin.ignore();
	}

};


class MiniMarket {
private:
	vector<CProduct*>ListProduct;
public:
	MiniMarket() {

	}

	~MiniMarket() {
		for (auto emp : ListProduct) {
			delete emp;
		}
	}

	void Input() {
		if (freopen("INPUT.txt", "rt", stdin) == NULL) {
			cerr << "Cannot open file to read!!!" << endl;
			return;
		}
		while (cin.peek() != EOF) {
			CProduct* temp = nullptr;

			char c;
			c = cin.peek();

			if (c == 'E') {
				temp = new CElectronic();
			}
			else if (c == 'T') {
				temp = new CTerracotta();
			}
			else if (c == 'F') {
				temp = new CFood();
			}
		

			temp->Input();
			ListProduct.push_back(temp);
		}

		fclose(stdin);

	}


	void Output() {
		if (freopen("OUTPUT.txt", "w", stdout) == NULL) {
			cerr << "Cannot open file to read!!!" << endl;
			return;
		}
		int size = ListProduct.size();
		cout << size << " Mặt hàng:" << endl;
		for (int i = 0; i < size; i++) {
			cout << i + 1 << ". ";
			ListProduct[i]->Output();
		}
		fclose(stdout);
	}

	void ViewExpDate() {
		if (freopen("EXPDATE.txt", "w", stdout) == NULL) {
			cerr << "Cannot open file to read!!!" << endl;
			return;
		}
		CDate nowDate;
		time_t t= time(0);
		tm* now = localtime(&t);
		nowDate.setDay(now->tm_mday);
		nowDate.setMonth(now->tm_mon+1);
		nowDate.setYear(now->tm_year+1900);
	
		int size = ListProduct.size();

		for (int i = 0; i < size; i++) {
			if (auto* prog = dynamic_cast<CFood*>(ListProduct[i])) {
				if (prog->getExpDate() < nowDate) {
					cout << prog->getCode() << ", " << prog->getName() << ", ";
					cout<< prog->getQuantity() << ", " << prog->getExpDate() << "." << endl;
				}
			}
		}
		fclose(stdout);

	}

	void Delete() {
		
		if (freopen("con", "rt", stdin) == NULL) {
			cerr << "Cannot open file to read!!!" << endl;
			return;
		}
		cin.clear();
		if (freopen("con", "w", stdout) == NULL) {
			cerr << "Cannot open file to read!!!" << endl;
			return;
		}
		
		string code;
		cout << "Nhap ma cua san pham ma ban muon xoa:";
		getline(cin, code);

		
		auto it = ListProduct.begin();
		bool productFound = false;
		while (it != ListProduct.end()) {
			if ((*it)->getCode() == code) {
				
				delete* it; // Gi?i ph�ng b? nh? c?a ??i t??ng ???c tr? ??n
				it = ListProduct.erase(it); // X�a ph?n t? hi?n t?i v� tr? v? iterator ti?p theo
				productFound = true;
			
			}
			else {
				
				++it;
			}
		}
		if (productFound == true) {
			cout << "Da xoa san pham voi ma '" << code << "'." << endl;
		}
		else {
			cout << "Khong tim thay ma '" << code << "' de xoa." << endl;
		}

		fclose(stdin);
		fclose(stdout);
	}


	void Buy() {
		vector<CProduct*>ListBuyProduct;
		if (freopen("BUY.txt", "rt", stdin) == NULL) {
			cerr << "Cannot open file to read!!!" << endl;
			return;
		}
		
		if (freopen("con", "w", stdout) == NULL) {
			cerr << "Cannot open file to read!!!" << endl;
			return;
		}
		string phoneNumber;
		getline(cin, phoneNumber);

		string code, name, buffer;
		bool check = false;
		int size = ListProduct.size();
		while (cin.peek() != EOF) {
			getline(cin, code, ',');
			cin.seekg(1, ios::cur);

			getline(cin, name, ',');
			cin.seekg(1, ios::cur);
			
			getline(cin, buffer);
			int quantity = stoi(buffer);
			for (int i = 0; i < size; i++) {
				if (code == ListProduct[i]->getCode()) {
					int temp = ListProduct[i]->getQuantity();
					int quantityCL = temp - quantity;
					if (quantityCL >= 0) {
						check = true;
						ListProduct[i]->setQuantity(quantityCL);
						CProduct* boughtProduct = new CProduct(*ListProduct[i]);
						boughtProduct->setQuantity(quantity);
						ListBuyProduct.push_back(boughtProduct);
						
					}
					break;
				}
			}
			if (check == false) {
				cout << "Khong the mua san pham voi ma '" << code << "' nay ." << endl;
				cout << "Vi so luong ban mua lon hon so luong trong cua hang ." << endl;
			}
		}
		
		fclose(stdout);

		if (freopen("INVOICE.txt", "w", stdout) == NULL) {
			cerr << "Cannot open file to read!!!" << endl;
			return;
		}

		CTime nowTime;
		CDate nowDate;

		time_t t = time(0);
		tm* now = localtime(&t);

		nowTime.setSecond(now->tm_sec);
		nowTime.setMinute(now->tm_min);
		nowTime.setHour(now->tm_hour);

		nowDate.setDay(now->tm_mday);
		nowDate.setMonth(now->tm_mon + 1);
		nowDate.setYear(now->tm_year + 1900);
		
		const char* days_of_week[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
		int day_of_week = now->tm_wday;
		string DayOfWeek=days_of_week[day_of_week];

		int sizeBuy = ListBuyProduct.size();
		//in h�a ??n 
		cout << phoneNumber << endl;
		cout << nowTime << " " << DayOfWeek << " " << nowDate << endl;
		
		float priceMoney = 0;
		float totalMoney = 0;
		int  discount = 0;
		int tmp = 0;

		for (int i = 0; i < sizeBuy; i++) {

			priceMoney = ListBuyProduct[i]->getQuantity() * ListBuyProduct[i]->getPrice();
			cout << i + 1 << ". " << ListBuyProduct[i]->getCode() << ", " << ListBuyProduct[i]->getName() << ": ";
			cout << ListBuyProduct[i]->getQuantity() << " x " << static_cast<int>(ListBuyProduct[i]->getPrice());
			cout << " = " << static_cast<int>(priceMoney) << " VNĐ" << endl;

			if (day_of_week == 5) {
				if (auto* prog = dynamic_cast<CFood*>(ListBuyProduct[i])) {
					priceMoney *= 0.8;
					 tmp= priceMoney * 0.2;
				}
			}
			else if (day_of_week==2||day_of_week==3) {
				if (auto* prog = dynamic_cast<CElectronic*>(ListBuyProduct[i])) {
					priceMoney *= 0.85;
					tmp = priceMoney * 0.15;
				}
			}
			else if (day_of_week == 6 || day_of_week == 0) {
				if (auto* prog = dynamic_cast<CTerracotta*>(ListBuyProduct[i])) {
					priceMoney *= 0.7;
					tmp = priceMoney * 0.3;
				}
			}
			totalMoney += priceMoney;
			discount += tmp;
			
			
		}

		if (totalMoney > 5000000) {
			totalMoney *= 0.9;
			discount += totalMoney * 0.1;
		}
		cout << "Giảm giá: " << static_cast<int>(discount) << " VNĐ" << endl;
		cout << "Số tiền thanh toán: " << static_cast<int>(totalMoney) << " VNĐ" << endl;

		fclose(stdin);
		fclose(stdout);
		
	}


	void ViewQuantity() {
		vector<CProduct*>ListNotExists;
		if (freopen("QUANLITY.txt", "w", stdout) == NULL) {
			cerr << "Cannot open file to read!!!" << endl;
			return;
		}
		int size = ListProduct.size();
		for (int i = 0; i < size; i++) {
			if(ListProduct[i]->getQuantity()==0){
				
				ListNotExists.push_back(ListProduct[i]);
			}
		}

		int sizeNotExists = ListNotExists.size();
		cout << sizeNotExists << endl;
		for (int i = 0; i < sizeNotExists; i++) {
			cout << i + 1 << ". " << ListNotExists[i]->getCode() << ", " << ListNotExists[i]->getName() << endl;
		}

		fclose(stdout);
		
	}
	
	
	
};

int main() {
	MiniMarket market;
	market.Input();
	market.Output();
	market.ViewExpDate();
	market.Delete();
	market.Buy();
	market.ViewQuantity();
	return 0;

}