#include<iostream>
#include<string>
/*
std::string * createPoemDynamically(){
    std::string *ppoem;         //declare pointer to string to store the address 
    ppoem = new std::string;    //dynamically allocate memory for a poem string and store its address in the pointer 
    
    *ppoem = "if you know \n";  //put poem inside 

    return ppoem;               //return address 

    delete ppoem;
    ppoem = nullptr;

}


int main(){
    std::string * p;
    p = createPoemDynamically();
    std::cout << *p;

}
*/


int main(){
    int var = 3;
    int *p = &var;
    std::cout << *p << std::endl; //dereference pointer p and prints 3 
    std::cout << p << std::endl; //address of var
    int var2 = *p;               //dereferences p2, prints 3 
    std::cout << var2 << std::endl; //prints 3, var2 is the value in &var
    int *p2 = p;                    //sets pointer p2 equal to p 
    std::cout << *p2 << std::endl;  //dereference p2 and prints 3(same as var)
    *p2 = *p + 7;   //adds 7 to var since p2 points to var 
    std::cout << *p2 << std::endl;
}

/*
int main(){
    std::string book = "Book name";
    std::string *p;
    p = &book;
    std::cout << *p << std::endl;
    std::cout << p << std::endl;


}
*/
