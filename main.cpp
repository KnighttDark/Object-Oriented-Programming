#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;
/*
    class: lớp
    - thuộc tính: attribute
    - phương thức: method, behavior
    - object: đối tượng
*/

/*
    - Encapsulation: Đóng gói
    - Access modifer: Mô tả phạm vi
        + Private
        + Publich
        + Protectd

    - nếu không set thì mặc định là private
    - Hàm tạo constructor: cùng tên với Class, không có kiểu trả về, có thể ghi đè
    - Hàm hủy destructor: cùng tên với Class, không có kiểu trả về và có dẫu ~ phía trước ~Hamhuy();
    - Con trỏ this
    - setter/ getter: xây dựng hàm để lấy giá trị từ private
        + setter: muốn gán lại giá trị cho các thuộc tính
    - biến static: dùng chung cho các Object trong 1 class
    - Friend function , friend Class: không phải là member của class hiện tại nhưng có thể truy cập vào thuộc tính hay phương thức, private của class nào đó

*/

class yourClass;
class myClass;

class myClass
{
    // thuộc tính
    // phương thức
    friend class yourClass; // lớp "yourClass" là bạn của lớp "myClass";
private:
    string id, name;
    int age;
    double gpa;
    static int count;

public:
    myClass();
    // ~myClass();

    // Phương thức
    myClass(string, string, int, double);
    void xinchao();
    void nhap();
    void xuat();
    void dihoc();
    double getGpa();
    void setGpa(double gpa);
    friend void chuanHoa(myClass &);
};

int myClass::count = 0;

void chuanHoa(myClass &a)
{
    string res = "";         // lưu kết quả chuỗi chuẩn hóa
    stringstream ss(a.name); // tách chuỗi của a.name thành các từ(token)
    string token;
    while (ss >> token)
    {
        res += toupper(token[0]); // viết kết quả chữ cái đầu tiên và lưu vào chuỗi res
        for (int i = 0; i < token.length(); i++)
        {
            res += tolower(token[i]); // duyệt qua qua ---> chữ thường  ---> lưu vào chuỗi res
        }
        res += " "; // sau mỗi từ thì thêm 1 khoảng trắng vào
    }
    res.erase(res.length() - 1); // loại bỏ khoảng trắng cuối cùng mà vòng lặp đã thêm vào chuỗi res
    a.name = res;                // gán kết quả vào a.name
}
// Hàm hủy
/*
    myClass::myClass() {
    cout << " Khoi tao ham huy !";
        }
*/

// Hàm tạo

myClass::myClass()
{
}

void myClass::xinchao()
{
    cout << "Hello\n";
}

void myClass::dihoc()
{
    cout << "Di hoc\n";
}

myClass::myClass(string id, string name, int age, double gpa)
{
    this->id = id; // gán giá trị của tham số maso cho biến id
    this->name = name;
    this->age = age;
    this->gpa = gpa;
}

void myClass::nhap()
{
    /*
        ++count;
        this->id = "sv" + string(3 - to_string(count).length(), '0') + to_string(count);
    */
    cout << " Nhap thong tin sinh vien" << endl;
    // cout << "\nID:"; cin >> this->id;
    cout << "\nName: ";
    cin >> this->name;
    // cout << "\nAge: "; cin >> this->age;
    cout << "\nGpa: ";
    cin >> this->gpa;
    cin.ignore();
}

void myClass::xuat()
{
    // cout << "\nID: " << this->id;
    cout << "\nName: " << this->name;
    // cout << "\nAge: " << this->age;
    cout << "\nGpa: " << this->gpa;
}

void myClass::setGpa(double gpa)
{
    this->gpa = gpa;
}

double myClass::getGpa()
{
    return this->gpa;
}

bool cmp(myClass a, myClass b)
{
    return a.getGpa() > b.getGpa();
}

class yourClass
{
private:
    string khoa;

public:
    void update(myClass &);
};

void yourClass::update(myClass &x)
{
    x.gpa = 3.5;
}

int main()
{
    myClass A2;
    // A2.setGpa(2.5);
    A2.nhap();

    yourClass A3;
    A3.update(A2);
    A2.xuat();

    /*
        - có thể dùng màng để nhập thông tin nhiều đối tượng
        myClass A2[100];
        // nhập
        for (int i = 0; i < n; i++)
        {
            A2[i].nhap();
        }
        // xuất
        for (int i = 0; i < n; i++)
        {
            A2[i].xuat();
        }
        // hàm sắp xếp
        sort(A2, A2 + n, cmp);
    */

    return 0;
}