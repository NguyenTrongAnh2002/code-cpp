**hàm xóa 1 phần tử trong mảng : void xoa(CLASS *a, int &n)
{
    int x;
    cout << "nhap ..... muon xoa: ";
    cin >> x;
    for (int i = 0; i < n; i++)
    {
        if (a[i]....== x)
        {
            for (int j = i; j < n - 1; j++)
            {
                a[j] = a[j + 1];
            }
            n--;
            i--;
        }
    }
}
**hàm chèn thêm phần tử mảng : void chen(CLASS *&a, int &n)
{
    int k;
    do
    {
        cout << "Nhap vi tri  muon chen: ";
        cin >> k;
    } while (k < 1 || k > n);
    cout << "Nhap thong tin muon chen vao: " << endl;
    CLASS a1;
    a1.nhap();
    for (int i = n; i > k; i--)
    {
        a[i] = a[i - 1];
    }
    a[k] = a1;
    n++;
}
**hàm sắp xếp mảng tăng dần : void sapxep(CLASS *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nv[i]....> nv[j]....)
            {
                swap(nv[i], nv[j]);
            }
        }
    }
}
**hàm tìm phần tử trong mảng : void tim(CLASS *a, int n)
{
    char t[20];
    cout << " nhap thong tin muon tim: ";
    fflush(stdin);
    gets(t);
    for (int i = 0; i < n; i++)
    {
        if (// Điều kiện tìm )
        {
            a[i].xuat();
        }
    }
}
**hàm sửa ptu trong mảng : void sua(CLASS *&a, int &n)
{
    char s[20];
    cout << "nhap thong tin muon sua: ";
    fflush(stdin);
    gets(s);
    for (int i = 0; i < n; i++)
    {
        if (// Điều kiện sửa)
        {
            a[i].nhap();
        }
    }
    **hàm nhập cấp phát bộ nhớ động : void nhapds(CLASS * &a, int &n)
    {
        cout << "nhap so luong phan tu : ";
        cin >> n;
        a = new NHANVIEN[n];
        for (int i = 0; i < n; i++)
        {
            cout << "nhap phan tu thu " << i + 1 << endl;
            a[i].nhap();
        }
    }
    **hàm switch case : do
    {
        cout << "\n======CHUONG TRINH quan ly sinh vien=======" << endl;
        cout << "Chon 1 chuc nang" << endl;
        cout << "\t1. xuat danh sach sinh vien" << endl;
        cout << "\t2. them thong tin sinh vien" << endl;
        cout << "\t3. xoa thong tin sinh vien" << endl;
        cout << "\t4. sua thong tin sinh vien" << endl;
        cout << "\t5. tim kiem sinh vien" << endl;
        cout << "\t0. Thoat chuong trinh" << endl;
        int chon;
        cout << "Nhap lua chon cua ban: ";
        cin >> chon;
        switch (chon)
        {
        case 1:
            cout << "\n-----danh sach sinh vien------" << endl;
            xuatds(sv, n);
            break;
        case 2:
            themSV(sv, n);
            cout << "\n-----danh sach sinh vien------" << endl;
            xuatds(sv, n);
            break;
        case 3:
            xoaSV(sv, n);
            cout << "\n-----danh sach sinh vien------" << endl;
            xuatds(sv, n);
            break;
        case 4:
            suaSV(sv, n);
            cout << "\n-----danh sach sinh vien------" << endl;
            xuatds(sv, n);
            break;
        case 5:
            cout << "\n-----danh sach sinh vien------" << endl;
            timSV(sv, n);
            break;
        case 0:
            cout << "Da dong ung dung" << endl;
            return 0;
        default:
            cout << "Lua chon khong hop le" << endl;
        }
    }
    while (true)
        ;
    **tim max : int max = a[0]; // max= a[i].  ...
    for (int i = 0; i < n; i++)
    {
        if (a[i].> max)
        {
            max = a[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i].== max)
        {
            a[i].xuat();
        }
    }