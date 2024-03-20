
/*
    Mô tả chương trình:
    Chương trình gồm 3 hàm
    - Hàm inputInfor: Nhập thông tin hóa đơn
    - Hàm calculateDiscount: Tính khuyến mãi
    - Hàm displayInfor: Hiển thị thông tin hóa đơn

    - Nhập thông tin khách hàng - Tổng tiền sản phẩm - Loại khách hàng
    - Tính khuyến mãi dựa trên loại khách hàng
    - Hiển thị thông tin hóa đơn

    Chương trình được viết vào thời gian 9h15 sáng ngày 20/3/2024
*/

// Trần Đặng thành - 20KTMT2

#include <iostream>
using namespace std;

enum loai
{
    VIP,
    THANTHIET,
    VANGLAI
};
struct hoadon
{
    char hoten[50];
    float khuyenmai, thanhtien, thanhtoan;
    loai khach;
};

void inputInfor(hoadon &bill)
{
    cout << "Nhap ho ten: ";
    cin.getline(bill.hoten, 50);
    cout << "Nhap thanh tien: ";
    cin >> bill.thanhtien;
    cout << "Nhap loai khach hang (0: VIP, 1: THAN THIET, 2: VANGLAI): ";
    int loaiKhach;
    cin >> loaiKhach;
    bill.khach = static_cast<loai>(loaiKhach);
}

float calculateDiscount(hoadon &bill)
{
    float khuyenmai = 0.0;

    switch (bill.khach)
    {
    case VIP:
        khuyenmai = 0.5;
        break;
    case THANTHIET:
        khuyenmai = 0.25;
        break;
    case VANGLAI:
        khuyenmai = 0.1;
        break;
    default:
        break;
    }
    bill.khuyenmai = khuyenmai;
    bill.thanhtoan = bill.thanhtien * (1 - khuyenmai);

    return bill.thanhtoan;
}

void displayInfor(hoadon &bill)
{
    cout << "Ho ten: " << bill.hoten << endl;
    cout << "Thanh tien: " << bill.thanhtien << endl;
    cout << "Khuyen mai: " << bill.khuyenmai << endl;
    cout << "Thanh toan: " << bill.thanhtoan << endl;
}

int main()
{
    hoadon bill;

    inputInfor(bill);
    calculateDiscount(bill);
    displayInfor(bill);

    return 0;
}