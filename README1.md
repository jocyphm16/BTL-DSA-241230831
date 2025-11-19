📚 BÁO CÁO BÀI TẬP LỚN: CẤU TRÚC DỮ LIỆU VÀ GIẢI THUẬT🎓 
**THÔNG TIN DỰ ÁN**
1. Sinh viên thực hiện: Phạm Thị Thúy Quỳnh 
2. Mã sinh viên: 241230831 
3. Lớp: CNTT1-K65 
4. Giảng viên hướng dẫn: TS. Hoàng Văn Thông 
5. Trường: Đại học Giao thông Vận tải 
6. Môn học: Cấu trúc Dữ liệu và Giải thuật 
7. Công nghệ sử dụng: C++/IDE/Compiler (Visual Studio / GCCTruyền thống), STL (<list>, <algorithm>, <iostream>,...). 

**PHẦN A: QUẢN LÝ DÃY NHÀ TRỌ SINH VIÊN**
  💡  Dự án sử dụng cấu trúc dữ liệu Danh sách  liên kết (std::list) để quản lý thông tin sinh viên và phòng trọ.

👥 Cấu trúc Class SinhVien
  - Mục tiêu: Quản lý thông tin cá nhân (Họ tên, Quê quán, Ngày sinh, Tiền trọ). 
  - Tính năng: Hỗ trợ các toán tử nhập/xuất (operator>>, operator<<) và so sánh cơ bản (operator<, operator>, v.v.) dựa trên Họ tên.
 
🏠 Cấu trúc Class DanhSachSinhVien
  - Mục tiêu: Quản lý danh sách sinh viên trong một phòng trọ (tiền phòng, số sinh viên, danh sách sinh viên).
  - Chức năng chính: Quản lý phòng: Thêm phòng, Xóa phòng, Hiển thị danh sách các phòng
  - Quản lý sinh viên: Thêm sinh viên, Tìm sinh viên theo tên, Xóa sinh viên theo tên
  - Sắp xếp: Sắp xếp dãy sinh viên theo thứ tự từ điển (A-Z). 
  - Tính toán: Tự động tính tiền trọ sinh viên dựa trên tổng tiền phòng. 
 
**PHẦN B: CẤU TRÚC MAX HEAP & ỨNG DỤNG**
    Phần này tập trung vào việc cài đặt cấu trúc dữ liệu cây nhị phân trừu tượng (Max Heap) và áp dụng vào các bài toán thực tế 
  
🌲 Cấu trúc Class MaxHeap
- Cài đặt: Cây được cài đặt bằng mảng số nguyên. Thao tác cơ bản:
    - push(x): Thêm phần tử, Vun lên (Sift-up). 
    - pop(): Xóa phần tử gốc (lớn nhất), Vun xuống (Push-down/Heapify)
    - top(): Xem giá trị lớn nhất. 
💡 Ứng dụng giải quyết bài toán
    Áp dụng MaxHeap như một Hàng đợi ưu tiên (Priority Queue) để giải quyết 2 bài toán:
  - Bài toán 1: Sắp xếp dãy số giảm dần
    -  Đẩy lần lượt phần tử vào Heap, sau đó liên tục lấy phần tử top() ra in và pop() cho đến khi hết heap
  - Bài toán 2: Nối thanh kim loại (Chi phí tối thiểu)Mục tiêu: Giải bài toán tìm chi phí tối thiểu ($a+b$)
    - Giải thuật (Greedy): Luôn chọn 2 thanh ngắn nhất để nối Kỹ thuật đặc biệt: Vì bài toán yêu cầu tìm giá trị nhỏ nhất (MinHeap) nhưng ta chỉ có MaxHeap, nên ta sử dụng kỹ thuật lưu giá trị âm
    - Phần tử lớn nhất trong MaxHeap (ví dụ: -2) chính là phần tử có trị tuyệt đối nhỏ nhất (độ dài 2)Thực hiện thao tác pop()/push() liên tục với giá trị âm để duy trì cấu trúc. 

📊 Độ phức tạp thuật toán (Time Complexity)
  - Các thao tác push và pop có độ phức tạp là O(logn) 
  - Toàn bộ các giải thuật ứng dụng (Sắp xếp, Tính chi phí) đều đạt độ phức tạp O(nlogn).

🚀 HƯỚNG DẪN VẬN HÀNH CHƯƠNG TRÌNH
  - Biên dịch: Sử dụng trình biên dịch C++ để biên dịch file code.
  - Khởi chạy: Chạy file thực thi (.exe, ./app).
  - Thao tác: Chọn các chức năng trên menu console để trải nghiệm quản lý dãy nhà trọ.
