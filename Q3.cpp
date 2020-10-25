#include <iostream>
#include <fstream>

using namespace std;

struct Node{
    struct Node *next;
    struct Node *prev;
    int data;
    static Node *getnode(int data){
        Node * newNode=(Node *)malloc(sizeof(Node));
        newNode->data=data;
        newNode->next=newNode->prev=NULL;
        return newNode;
    }
};


class Deque{

private:
Node *front;
Node *rear;
int Size;

public:
//Constructor
Deque(){
    //Initialization
    front=rear=NULL;
    Size=0;
}

//Functions

void insertFront(int data);
void insertRear(int data);
void deleteFront();
void deleteRear();
int getFront();
int getRear();
int size();
bool isEmpty();
void erase();
void displayList();
bool isPalindrome();
void NotPalindrome();

};

bool Deque::isEmpty(){
    if(front==NULL){
        return 1;
    }else{
        return 0;
    }

}

int Deque::size(){
    return Size;

}


void Deque::insertFront(int data){
    Node *newNode= Node::getnode(data);

    if(newNode==NULL){
        cout<<"\nDeque Full!\n";
    }else{
        //Hiçlikten node oluşursa, front ve rear aynı node u gösterir
        if(front == NULL){
            front=rear=newNode;
        }else{
            //Node u front un önüne(prev) bağlıyor
            newNode->next=front;
            front->prev=newNode;
            front=newNode;

        }
        //Yeni Node Deque nin boyutunu 1 arttırmış oldu.
        Size++;
    }
    
}

void Deque::insertRear(int data){
    //Yeni Node u oluşturduk
    Node * newNode = Node::getnode(data);
    if(newNode==NULL){
        cout<<"\nDeque Full!\n";
    }else{
        if(rear==NULL){
            front=rear=newNode;
        }else{
            newNode->prev=rear;
            rear->next=newNode;
            rear=newNode;


        }
        Size++;
    }
}


void Deque::deleteFront(){
    if(isEmpty()){
        cout<<"\nDeque boş!!!\n";
    }else{
        //fronta pointer koyup frontu bir ileriye attık.
        Node *q=front;
        front=front->next;
        
        if(front==NULL){//bir ileri atınca boşa düşerse 
        //deque tek elemanlıdır.Yani rear da NULL olur.
        
            rear=NULL;
        }else{
            front->prev=NULL;
           
        }
        free(q);
        Size--;

    }

}

void Deque::deleteRear(){
    if(isEmpty()){
        cout<<"\nDeque boş!!!\n";
    }else{
        Node *q=rear;
        rear=rear->prev;
        //rearı bir geri kaydırılınca NULLa düşüyorsa tek elemanlıdır
        if(rear==NULL){
            front=NULL;
        }else{
            rear->next=NULL;

        }
        free(q);
        Size--;


    }
}

int Deque::getFront(){
    if(isEmpty()){
        return -1;
    }else{
        return front->data;
    }


}
int Deque::getRear(){
    if(isEmpty()){
        return -1;
    }else{
        return rear->data;
    }


}

void Deque::erase(){
    
    //Bütün dequeyi siler.
    //reara ihtiyaç yok.(Normal linked list gibi düşünün)
    rear=NULL;
    while(front!=NULL){
        //geçici pointerı fronttan başlattık
        Node *q =front;
        //front ilerledikçe q da bir adım geriden nodeları silerek
        //geliyor.
        front=front->next;
        free(q);
    }
    //sonunda da size 0 oluyor.
    Size=0;
}

void Deque::displayList(){
    
    if(isEmpty()){
        cout<<"\nDeque boş!!!\n";
    }else{
        Node *q=front;
        while(q!=rear->next){
            cout<<q->data<<"\t";
            q=q->next;
        }
    }
}

bool Deque::isPalindrome(){
    if(front == NULL){
        return 1;
    }else{
        while(front!=rear){
            
            if(front->data == rear->data){
                
                deleteFront();
                deleteRear();
                cout<<"\nSonraki Adım:\n";
                displayList();
                if(size()==1){
                    cout<<"Tek eleman var,dolayısıyla palindromedur.\n";
                    return 1;
                }
                
                
            }else{
                cout<<"Birden fazla eleman var, dolayısıyla palindrom değildir\n";
                return 0;
            }
            
        }

    }

return 1;

}



void Deque::NotPalindrome(){
    while(front!=rear){
        if(front->data!=rear->data){
            cout<<"\nBaştaki Silindi\n";
            deleteFront();
            displayList();
            cout<<"\nSondaki Başa Eklendi\n";
            insertFront(rear->data);
            displayList();
            
            
        }else if(front->data==rear->data){
            cout<<"\nBaştaki ve Sondaki Silindi.\n";
            deleteFront();
            deleteRear();
            displayList();
            if(size()==1){
                cout<<"\n";
            
                insertFront(rear->data);
                displayList();
                cout<<"\n";
            }

        }
        
    }


cout<<"\nDolayısıyla Palindromedur!!!\n";
}

int main(){
int opt;
ifstream infile;
//Object
Deque dq;
cout<<"******PROGRAMA HOŞGELDİNİZ******\n";
cout<<"\n1-Ekleme\n2-Kontrol\n3-Düzenle\n4-Listeleme\n5-Çıkış";
while(1)
{

    cout<<"\n";
    cin>>opt;
    switch(opt)
    {
        case 1:
            
            infile.open("data.txt");
            int x;
            while(!infile.eof()){
                //SAYILAR DOSYADA(data.txt) ALT ALTA SIRASIYLA YAZILMALI.SONUNCUYU YAZDIKTAN SONRA
                //AYNI SATIRDA KALINMAYA DİKKAT EDİLMELİ!!!!!!!
                
                //her bir elementi x olarak alığ rear tarafından dequeya
                //ekledik
                infile>>x;
                //cout<<x<<"\n";
                dq.insertRear(x);
            }
            
            if(infile.eof()){
                cout<<"DOSYA SONUNA ULAŞILDI!!!(EOF)\n";
            }
            cout<<"Dequeye Rear Tarafından Eklendi(Kuyruk Mantığına Uygun)";
            infile.close();
            cout<<"\n";
            dq.displayList();
            
            
            break;
    
    
    
        case 2:
            dq.isPalindrome();
            break;
        case 3:
            dq.NotPalindrome();
            exit(-1);
            break;
        case 4:
            cout<<"Kuyruk Mantığına Göre\n";
            dq.displayList();
            
        
        case 5:
            cout<<"\nBaşarıyla Çıkış Yapıldı...\n";
            exit(-1);


    }
}




    return 0;
}