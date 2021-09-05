#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
struct library{
    string name;
    string author;
    float price;
    int copies;

    void read(){
        cout << "\nEnter the details of the book: \n\n";
        cout << "Name of the book: ";
        cin.clear();
        cin.ignore();
        getline(cin, name);
        cout << "Author of the book: ";
        getline(cin, author);
        cout << "Price of the book: $";
        cin >> price;
        cout << "No. of copies: ";
        cin >> copies;
    }
    void display(){
        cout << "\nThe entered details are: \n\n";
        cout << "Name of the book: ";
        cout << name;
        cout << "\nAuthor of the book: ";
        cout << author;
        cout << "\nPrice of the book: $";
        cout << price;
        cout << "\nNo. of copies: ";
        cout << copies << endl << endl;
    }
    void name_search(string s){
        if(name == s){
            cout<<"The number of copies of the required book are: "<<copies<<endl;
        }
    }
    void author_search(string s){
        if(author == s){
            display();
        }
    }
};
int main(){
    int n, i, a=0, b=0, c=0;
    string x,y;
    cout << "Enter the number of Books: ";
    cin >> n;
    vector<library>l;
    for(i=0; i<n; i++){
        l.push_back(library());
        l[i].read();
    }
    for(i=0; i<n; i++){
        l[i].display();
    }
    while(a!= 4){
        cout<<"\nThe available options are:"<<endl<<"1.Search book by the Name."<<endl<<"2.Search book by the Author name."<<endl<<"3.Sort the collection of books."<<endl<<"4.Quit."<<endl;
        cout<<"Enter the function you want to perform: ";
        cin>>a;
        cout<<endl;
        switch(a){
            case 1:
                b=0;
                cout<<"Enter the name of the book to be searched: ";
                cin.clear();
                cin.ignore();
                getline(cin, x);
                for(i=0;i<n;i++){
                    l[i].name_search(x);
                }
                for(i=0;i<n;i++){
                    if(l[i].name==x){
                        b=1;
                    }
                }
                if(b!=1){
                    cout<<"The book with the entered name is not available."<<endl;
                }
                break;

            case 2:
                c=0;
                cout<<"Enter the author name to be searched: ";
                cin.clear();
                cin.ignore();
                getline(cin,y);
                for(i=0;i<n;i++){
                    l[i].author_search(y);
                }
                for(i=0;i<n;i++){
                    if(l[i].author==y){
                        c=1;
                    }
                }
                if(c!=1){
                        cout<<"The book with enetered Author's name is not available."<<endl;
                }
                break;

            case 3:
                sort(l.begin(), l.end(), [](library a, library b){
                    return a.name < b.name;
                });
                for(i=0;i<n;i++){
                    l[i].display();
                }
                break;

            case 4:
                break;
        }
    }
    return 0;
}
