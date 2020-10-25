#include <iostream>
#include <string>


using namespace std;

class Node{
    public:
    char data;
    Node *next;
};




class Stack{
    private:
    Node *top;
    public:
    
    //constructor
    Stack(){
        top=NULL;
    }
    void push(char x);
    void pop();
    void Display();
    bool isEmpty();
    char stackTop();
    int stackSize();

};

int Stack::stackSize(){
    Node *t=top;
    int size=0;
    while(t!=NULL){
        size++;
        t=t->next;
        

    }
    return size;


}
char Stack::stackTop(){
    if(!isEmpty()){
        return top->data;


    }else{
        return 'x';
    }
}
bool Stack::isEmpty(){
    if(top){
        return 0;

    }else{
        return 1;
    }
    

}
void Stack::push(char x){
    Node *t=new Node;
    if(t==NULL){
        cout<<"Stack is Full\n";
    }else{
        t->data=x;
        t->next=top;
        top=t;

    }
}

void Stack::pop(){
    if(top==NULL){
        cout<<"Stack is empty!\n";
    }else{
        Node *t =top;
        top=top->next;
        delete t;

    }

}

void Stack::Display(){
    Node *p=top;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;

}



int main(){

    Stack stk,stk2;
    int opt;
    int i,j;
    int count,ka,kb;
    int size1,size2; //sizes of the stacks
    cout<<"******PROGRAMA HOŞGELDİNİZ******\n";
    cout<<"\n1-Ekleme\n2-Kontrol\n3-Listeleme\n4-Çıkış\n";
    string myString;
    int len;
    while(1){
        //HOCAM BURADAKİ İF ELSELERİ YAZARAK ANLATMAK COK SIKINTI.GÖRÜŞMEYE GELDİĞİMDE
        //ÇİZEREK ANLATSAM DAHA IYI OLUR.YOKSA KOD DOSYASI ÇOK KARIŞACAK
        cin>>opt;
        cout<<"\n";
        

        switch(opt){
            case 1:
                cout<<"Lütfen sadece 'a' ve 'b' harflerinden oluşan bir String Giriniz"<<"\n";
                cin>>myString;
                len=myString.length();
                if(myString[0] == 'a'){
                    while(myString[i] != 'b'){
                        //ilk harfi 1. Stacke ekliyor
                        stk.push(myString[i]);
                        i++;
                        count =i;
                    }
                    
                    while(count != len){
                        //2.Harfi 2. Stacke ekliyor
                        stk2.push(myString[count]);
                        count++;

                    }
                    
                }else if(myString[0] == 'b'){
                    while(myString[i] != 'a'){
                        //ilk harfi 1. Stacke ekliyor
                        stk.push(myString[i]);
                        i++;
                        count=i;
                    } while(count!=len){
                        //2.Harfi 2. Stacke ekliyor
                        stk2.push(myString[count]);
                        count++;
                    }

                }
                
                    size1= stk.stackSize();
                    size2= stk2.stackSize();
                    cout<<"Stack 1'de Tutulanlar:\n";
                    stk.Display();  
                    cout<<"Stack1 Size:\n";
                    cout<<size1<<"\n";
                    cout<<"Stack 2'de Tutulanlar:\n";
                    stk2.Display();
                    cout<<"Stack2 Size:\n";
                    cout<<size2<<"\n";
                    cout<<"\n1-Ekleme\n2-Kontrol\n3-Listeleme\n4-Çıkış\n";
                
                break;
            
            
            case 2:
                cout<<"Lütfen birbirinin katları olacak şekilde,sırayla a ve b nin katayılarını giriniz:\n\n";
                cout<<"a'nın katsayısı:\n";
                cin>>ka;
                cout<<"\n";
                cout<<"b'nin katsayısı:\n";
                cin>>kb;
                //1.Örnek Formatı
                if(stk2.stackTop() == 'b' && ka>kb && kb*size1 ==ka*size2 ){
                        cout<<"İfade---->\t"<<myString;
                        
                        cout<<"\nHer "<<kb<<" b için "<<ka<<" a silinecektir.";
                        cout<<"\n";
                        for(i=0;i<size2;i++){
                            for(j=0;j<ka;j++){
                                stk.pop();
                                
                                
                            }
                            cout<<i+1<<".adım"<<endl;
                            if(stk.isEmpty()){
                                   
                                    cout<<"-\n";
                                }
                            stk.Display();
                        }
                        
                        if(stk.isEmpty()){
                            cout<<"\nYığın boş olduğu yukarıdaki kurala göre DÜZENLİ İFADEDİR";
                        }
                    //2.Örnek Formatı
                }else if(stk2.stackTop() == 'a' && ka<kb && kb*size2 != ka*size1){
                    cout<<"İfade---->\t"<<myString;
                    cout<<"\nHer "<<ka<<" a için "<<kb<<" b silinecektir.";
                    cout<<"\n";
                    for(i=0;i<size2-ka;i++){
                        for(j=0;j<kb;j++){
                            stk.pop();
                        }
                        cout<<i+1<<".adim"<<endl;
                        stk.Display();
                    }
                    cout<<"\nYığında eleman olduğu için DÜZENLİ İFADE DEĞİLDİR";


                    //3.Örnek Formatı
                }else if(stk2.stackTop() == 'a' && ka>kb && kb*size2 != ka*size1){
                    cout<<"İfade---->\t"<<myString;
                    cout<<"\nHer "<<ka<<" a için "<<kb<<" b silinecektir.";
                    cout<<"\n";
                    for(i=0;i<size2;i++){
                        if((i+1) % ka == 0){
                            
                            for(j=0;j<kb;j++){
                                
                                cout<<"Sonraki adim:\n";
                                
                                stk.pop();
                                stk.Display();
                                if(stk.isEmpty()){
                                   
                                    cout<<"-\n";
                                }
                                cout<<"\n";
                                break;
                            }
                        }
                        
                        
                        
                       
                    }
                    if(size1!=0){
                     
                     cout<<"Stringde "<<size2%ka<<" tane a kaldı";  
                     cout<<"\nString üzerinde tüm elemanlar okunmadığı için DÜZENLİ İFADE DEĞİLDİR.";
                    }   
                }
                
                break;
            case 3:
                break;

            case 4:
                cout<<"\nBaşarıyla Çıkış Yapıldı...\n";
                exit(-1);
            default:
                cout<<"Geçersiz Seçim.Tekrar Deneyiniz...";
                break;
        }

}
    





return 0;


    }
    
    
    
    
    
    
    
    
    
    
    
   