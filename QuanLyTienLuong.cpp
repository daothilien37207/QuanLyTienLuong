#include <iostream> 
#include <string>  
using namespace std; 

class NhanVien { 
    private: 
        string HoTen; 
        string maNV; 
        int namSinh; 
        int ngayVL;  
        int soNgayCong; 
        double luongCB; 
    public: 
    
    
    
    	virtual void in() const {
			
		}
    	virtual int loai() const = 0;
    	virtual double tongLuong() const = 0;

}; 

class NhanVienVanPhong : virtual public NhanVien { 
    protected: 
        string phongBan; 
        double heSoCV; 
        double gioLamThem; 
    public: 
        
	
		int loai() const  {return 1;}
}; 

class NhanVienKyThuat : virtual public NhanVien { 
    protected: 
        string chuyenNganh;
        int soSP; 
        int bacKN; 
    public: 
	
	 
    	int loai() const  {return 2;} 
};

class KySuQuanLy : public NhanVienVanPhong , public NhanVienKyThuat { 
    public: 
	
	 
		int loai() const  {return 3;}
}; 

//Day la phan cau 5 
template <class T> 
void hoanDoi(T a, T b) { 
	T temp = a; 
	a = b; 
	b = temp;
}


//Cau 6 
class PhongNhanSu { 
    private: 
        NhanVienVanPhong *ds;
    public: 


}; 

template <class T>
class DanhSach {
    private:  
        T *a;
        int soLuong; //so luong phan tu hien co 
        int sucChua; //suc chua toi da cua danh sach

        void resize() { 
            T *moi = new T[sucChua*2]; 
            for(int i=0;i<soLuong;i++) moi[i] = a[i]; 
            delete []a; 
            a=moi; 
            sucChua*=2; 
        }
        
    public:  
    	DanhSach(int sc = 10) :sucChua(sc), soLuong(0)  { 
    		a = new T[sucChua];
		} 
		~DanhSach() {  
			xoaHet();
			delete []a;
		} 
		DanhSach(const DanhSach<T> &b) { 
			for (int i=0;i<soLuong;i++) { 
				b[i] = a[i];
			}
		} 
		void them(T& b) { 
			if(soLuong==sucChua) resize(); 
			a[soLuong++] = b; 
			cout<<"Them thanh cong !\n"; 
			
		} 
		void hienThi() const { 
			for(int i=0;i<soLuong; i++) { 
				a[i]->xuat();
			}
		} 
		 
		double tongLuong() const { 
			double tong = 0.0;
			for(int i=0;i<soLuong;i++) { 
				tong+=a[i]->tongLuong();
			} 
			return tong;
		} 
		
		T luongNhoNhat() { 
			int min_index = 0; 
			for(int i=1 ;i<soLuong;i++) { 
				if(a[min_index]->tongLuong() > a[i]->tongLuong()) {	
					min_index = i;
				}
			} 
			return a[min_index];
		}
		
		int dem(int &l) { 
			int dem = 0; 
			for(int i=0;i<soLuong;i++) { 
				if(a[i]->loai() == l ) dem++;
			} 
			return dem;
		} 
		
		double trungBinhLuong(int &l) { 
			double tong = 0; 
			for(int i=0;i<soLuong;i++) { 
				if(a[i]->loai() == l ) tong+=a[i]->tongLuong(); 
			} 
			return (soLuong == 0) ? 0 : tong/soLuong;
		} 
		
		void sapXep() { 
			for(int i=0;i<soLuong-1;i++) { 
				int min_index = i; 
				for(int j = i+1 ;j<soLuong;j++) { 
					if(a[min_index]->tongLuong() < a[i]->tongLuong()) { 
						min_index = j;
					}
				} 
				if(min_index != i) { 
					hoanDoi(a[i],a[min_index]);
				}
			}
		} 
		
		void xoaHet() { 
			for(int i=0;i<soLuong;i++) { 
				delete a[i];
			} 
			soLuong=0;
		}
		
    

}; 


//cau 8 
void menuNhanSu() { 
    PhongNhanSu a;

}

void menuDS() { 
    DanhSach<NhanVien*> ds;

} 

int main() { 
    cout<<"Hello world"<<endl;

    return 0;
}
