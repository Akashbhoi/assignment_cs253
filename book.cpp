class Book
{

    string title;
    string author;
    long long int ISBN; // This is to be automated
    string publication;
    bool isAvailable;
    Date issuDate;
    Date dueDate;
    void bookDetails();

public:
    bool Book_Request(int x);
    void Show_duedate();
    friend class Book_database;
    friend bool operator<(const Book &, const Book &);
    friend class User;
    friend class Professor;
    friend class Student;
    friend class Librarian;
    friend int main();
};

bool operator<(const Book &book1, const Book &book2)
{
    return book1.ISBN > book2.ISBN;
}
void Book::bookDetails()
{
    cout << "Title :" << this->title << endl;
    cout << "Author : " << this->author << endl;
    cout << "ISBN :" << this->ISBN << endl;
    cout << "Publication " << this->publication << endl;
}

bool Book::Book_Request(int x)
{
    if (this->isAvailable)
    {
        cout << "Enter the date(dd/mm/yyyy) :";
        string date;
        cin >> date;
        cin.ignore();
        Date today = Date(date);
        this->issuDate = today;
        this->dueDate = today.add(x);
        this->isAvailable = false;
        return true;
    }

    return false;
}

void Book::Show_duedate()
{
    cout << "The due date for the " << this->title << " is :";
    dueDate.showDate();
    return;
}
