/**
 * @file main.cpp
 * @author Dao Ba Khanh
 * @brief BTL Banking Manager
 * @version 0.1
 * @date 2021-01-06
 *
 * @copyright Copyright (c) 2021
 *Phần mềm quản lý tài khoản ngân hàng
// Khi tạo tài khoản xong sẽ hiển thị ID ra màn hình cho người xem
- Đăng nhập:
- Chế độ cho nhân viên quản lý
+ 5 tính năng chính: Tạo tài khoản,  xem thông tin tất cả tài khoản hoặc theo ID, cập nhật thông tin , đóng tài khoản, nạp tiền vào tài khoản cho khách hàng, theo dõi giao dich
- Chế độ cho khách hàng:
+ Đổi mật khẩu mặc định, Chuyển tiền, rút tiền, xem thông tin tài khoản (luôn hiển thị), xem lịch sử giao dịch

 */

#include<iostream>
#include<string>
#include<vector>
#include"./utilities/utilities.h"
#include "./admin/admin.h"
#include"./user/user.h"
#include"./account/account.h"
using namespace std;

int main() {

    
    // listsModesToSignIn();
    choiseModeToSignIn();

}